//======================================================
// @brief Implementation of LevelParser.hpp.
//======================================================

#include "LevelParser.hpp"
#include "LevelEntity.hpp"
#include "Level.hpp"

#include "../lib/json.hpp"
using nlohmann::json;

#include "../exception/LevelException.hpp"
using game::exception::level::LevelLoadException;

#include "../utils/Vec2D.hpp"
using game::utils::Vec2D;

#include <map>
#include <string>
#include <fstream>
#include <iostream>

namespace game {
namespace level {

/**
 * @brief Convert a JSON object to a Vec2D object.
 */
const Vec2D json_to_vec(const json& j)
{
	return {j.at(0).get<float>(), j.at(1).get<float>()};
}

/**
 * @brief Base class for enemy, obstacle and player specifications stored in the level file.
 */
struct EntityTemplate
{
private:
public:
	using UnqPtr = std::unique_ptr<EntityTemplate>;

	/**
	 * @brief Constructor.
	 */
	EntityTemplate(void)
	{}

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityTemplate(void)
	{}

	/**
	 * @brief Convert the stored specification to an actual LevelEntity.
	 */
	virtual LevelEntity::UnqPtr to_level_entity(const Vec2D& pos) const = 0;
};

/**
 * @brief Class to store player specifications.
 */
class PlayerTemplate final: public EntityTemplate
{
private:
	const std::string m_sprite_filename;
	const int         m_lives;
	const float       m_max_speed;
public:
	/**
	 * @brief Constructor.
	 */
	PlayerTemplate(const std::string& sprite_filename, const int lives, const float max_speed)
		: m_sprite_filename{sprite_filename},
		  m_lives{lives},
		  m_max_speed{max_speed}
	{}

	/**
	 * @brief Convert to level entity.
	 */
	LevelEntity::UnqPtr to_level_entity(const Vec2D& pos) const override
	{
		return std::make_unique<LevelPlayer>(pos, m_sprite_filename, m_lives, m_max_speed);
	}
};

/**
 * @brief Class to store enemy specifications.
 */
class EnemyTemplate final: public EntityTemplate
{
private:
	const std::string m_sprite_filename;
	const Vec2D       m_direction;
	const int         m_attack_damage;
public:
	/**
	 * @brief Constructor.
	 */
	EnemyTemplate(const std::string& sprite_filename, const Vec2D& dir, const int attack_damage)
		: m_sprite_filename{sprite_filename},
		  m_direction{dir},
		  m_attack_damage{attack_damage}
	{}

	/**
	 * @brief Convert to level entity.
	 */
	LevelEntity::UnqPtr to_level_entity(const Vec2D& pos) const override
	{
		return std::make_unique<LevelEnemy>(pos, m_sprite_filename, m_direction, m_attack_damage);
	}
};

/**
 * @brief Class to store Obstacle specifications.
 */
class ObstacleTemplate final: public EntityTemplate
{
private:
	const std::string m_sprite_filename;
	const int 		  m_collision_penalty;
public:
	/**
	 * @brief Constructor.
	 */
	ObstacleTemplate(const std::string& sprite_filename, const int collision_penalty)
		: m_sprite_filename{sprite_filename},
		  m_collision_penalty{collision_penalty}
	{}

	/**
	 * @brief Convert to level entity.
	 */
	LevelEntity::UnqPtr to_level_entity(const Vec2D& pos) const override
	{
		return std::make_unique<LevelObstacle>(pos, m_sprite_filename, m_collision_penalty);
	}
};

const Level parse_level(const std::string& json_filename)
{
	// create a set of level entities from data in the level
	// store in maps


	json json_data;
	std::map<std::string, EntityTemplate::UnqPtr> entity_templates;

	// load json file
	try
	{
		std::ifstream json_file{json_filename};
		json_file >> json_data;
	}
	catch(...)
	{
		throw LevelLoadException{json_filename, "Cannot load file."};
	}

	////////////////////////////////////////////////////////////////////
	// load "PlayerData"
	////////////////////////////////////////////////////////////////////
	try
	{
		EntityTemplate::UnqPtr player_templ
				= std::make_unique<PlayerTemplate>
								(
									json_data.at("PlayerData").at("Sprite").get<std::string>(),
									json_data.at("PlayerData").at("Lives").get<int>(),
									json_data.at("PlayerData").at("MaxSpeed").get<float>()
								);

		const std::string symbol = json_data.at("PlayerData").at("Symbol").get<std::string>();

		if(entity_templates.count(symbol)) {
			throw LevelLoadException{json_filename, "Duplicate symbol: '" + symbol + "'."};
		} else if (symbol == ".") {
			throw LevelLoadException{json_filename, "Cannot use '.' as symbol."};
		}

		entity_templates.insert(std::make_pair(symbol, std::move(player_templ)));
	}
	catch(const LevelLoadException& e)
	{
		// rethrow custom exception.
		throw;
	}
	catch(...)
	{
		throw LevelLoadException{json_filename, "Cannot retrieve player data."};
	}

	////////////////////////////////////////////////////////////////////
	// load "EnemyTypes"
	////////////////////////////////////////////////////////////////////
	try
	{
		// iterate over enemies
		for(const auto& iterated_enemy : json_data.at("EnemyTypes"))
		{
			EntityTemplate::UnqPtr enemy_templ
					= std::make_unique<EnemyTemplate>
									(
										iterated_enemy.at("Sprite").get<std::string>(),
							json_to_vec(iterated_enemy.at("Direction")),
										iterated_enemy.at("AttackDamage").get<int>()
									);

			const std::string symbol = iterated_enemy.at("Symbol").get<std::string>();

			if(entity_templates.count(symbol)) {
				throw LevelLoadException{json_filename, "Duplicate symbol: '" + symbol + "'."};
			} else if (symbol == ".") {
				throw LevelLoadException{json_filename, "Cannot use '.' as symbol."};
			}

			entity_templates.insert(std::make_pair(symbol, std::move(enemy_templ)));
		}
	}
	catch(const LevelLoadException& e)
	{
		throw;
	}
	catch(...)
	{
		throw LevelLoadException{json_filename, "Cannot retrieve enemy data."};
	}

	////////////////////////////////////////////////////////////////////
	// load "ObstacleTypes"
	////////////////////////////////////////////////////////////////////
	try
	{
		// iterate over obstacles
		for(const auto iterated_obstacle: json_data.at("ObstacleTypes"))
		{
			EntityTemplate::UnqPtr obstacle_templ
					= std::make_unique<ObstacleTemplate>
									(
										iterated_obstacle.at("Sprite").get<std::string>(),
										iterated_obstacle.at("CollisionPenalty").get<int>()
									);

			const std::string symbol = iterated_obstacle.at("Symbol").get<std::string>();

			if(entity_templates.count(symbol)) {
				throw LevelLoadException{json_filename, "Duplicate symbol: '" + symbol + "'."};
			} else if (symbol == ".") {
				throw LevelLoadException{json_filename, "Cannot use '.' as symbol."};
			}

			entity_templates.insert(std::make_pair(symbol, std::move(obstacle_templ)));
		}
	}
	catch(const LevelLoadException& e)
	{
		throw;
	}
	catch(...)
	{
		throw LevelLoadException{json_filename, "Cannot retrieve obstacle data."};
	}

	////////////////////////////////////////////////////////////////////
	// Load entities into Level
	////////////////////////////////////////////////////////////////////

	// list of lists, outer list needs to be reversed, inner list is in correct order
	const auto& grid = json_data.at("LevelGrid").get<std::vector<std::vector<std::string>>>();

	// create level object
	Level retval{grid.at(0).size(), grid.size()};

	// reverse iterate since the lowest row of the grid has the lowest coordinate
	// but appears last
	int row = 0;
	for(auto cr_it = grid.crbegin(); cr_it != grid.crend(); cr_it++)
	{
		// assert here that the row has correct length.
		if(not (cr_it->size() == retval.get_width()))
		{
			throw LevelLoadException{json_filename, "Rows in level grid need to be of equal length."};
		}

		int col = 0;
		for(const auto& symbol : *cr_it)
		{
			if(symbol == ".")
			{
				// empty spot
				continue;
			}
			else if(entity_templates.count(symbol))
			{
				// add entity to level.
				retval.add_entity(entity_templates.at(symbol)->to_level_entity(Vec2D{col, row}));
			}
			else
			{
				throw LevelLoadException{json_filename, "Unknown symbol '" + symbol + "' in level grid."};
			}

			col++;
		}
		row++;
	}

	// return level
	return retval;

}

}} // namespace game::level


