//======================================================
// @brief Implementation of LevelParser.hpp.
//======================================================

#include "LevelParser.hpp"
#include "LevelEntity.hpp"
#include "Level.hpp"

#include "../lib/json.hpp"

#include "../exception/LevelException.hpp"

#include "../utils/Vec2D.hpp"

#include <map>
#include <string>
#include <fstream>
#include <iostream>

using nlohmann::json;
using game::exception::level::LevelLoadException;
using game::utils::Vec2D;

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
	virtual LevelEntity::ShrPtr to_level_entity(const Vec2D& pos) const = 0;
};

/**
 * @brief Class to store player specifications.
 */
class PlayerTemplate final: public EntityTemplate
{
private:
	const std::string m_sprite_filename;
	const float       m_size;
	const float       m_bullet_speed;
	const float       m_bullet_size;
	const float       m_max_shots_per_sec;
	const int         m_lives;
	const float       m_speed;
public:
	/**
	 * @brief Constructor.
	 */
	PlayerTemplate(const std::string& sprite_filename,
				   const float size,
				   const float bullet_speed,
				   const float bullet_size,
				   const float max_shots_per_sec,
				   const int lives,
				   const float speed)
		: m_sprite_filename{sprite_filename},
		  m_size{size},
		  m_bullet_speed{bullet_speed},
		  m_bullet_size{bullet_size},
		  m_max_shots_per_sec{max_shots_per_sec},
		  m_lives{lives},
		  m_speed{speed}
	{}

	/**
	 * @brief Convert to level entity.
	 */
	LevelEntity::ShrPtr to_level_entity(const Vec2D& pos) const override
	{
		return std::make_shared<LevelPlayer>
										(
												pos,
												m_sprite_filename,
												m_size,
												m_bullet_speed,
												m_bullet_size,
												m_max_shots_per_sec,
												m_lives,
												m_speed
										);
	}
};

/**
 * @brief Class to store enemy specifications.
 */
class EnemyTemplate final: public EntityTemplate
{
private:
	const std::string m_sprite_filename;
	const float       m_size;
	const Vec2D       m_direction;
	const float       m_bullet_speed;
	const float       m_bullet_size;
	const float       m_max_shots_per_sec;
	const int         m_attack_damage;
public:
	/**
	 * @brief Constructor.
	 */
	EnemyTemplate(const std::string& sprite_filename,
				  const float size,
				  const Vec2D& dir,
				  const float bullet_speed,
				  const float bullet_size,
				  const float m_max_shots_per_sec,
				  const int attack_damage)
		: m_sprite_filename{sprite_filename},
		  m_size{size},
		  m_direction{dir},
		  m_bullet_speed{bullet_speed},
		  m_bullet_size{bullet_size},
		  m_max_shots_per_sec{m_max_shots_per_sec},
		  m_attack_damage{attack_damage}
	{}

	/**
	 * @brief Convert to level entity.
	 */
	LevelEntity::ShrPtr to_level_entity(const Vec2D& pos) const override
	{
		return std::make_shared<LevelEnemy>
									(
											pos,
											m_sprite_filename,
											m_size,
											m_direction,
											m_bullet_speed,
											m_bullet_size,
											m_max_shots_per_sec,
											m_attack_damage
									);
	}
};

/**
 * @brief Class to store Obstacle specifications.
 */
class ObstacleTemplate final: public EntityTemplate
{
private:
	const std::string m_sprite_filename;
	const float       m_size;
	const int 		  m_collision_penalty;
public:
	/**
	 * @brief Constructor.
	 */
	ObstacleTemplate(const std::string& sprite_filename,
					 const float size,
					 const int collision_penalty)
		: m_sprite_filename{sprite_filename},
		  m_size{size},
		  m_collision_penalty{collision_penalty}
	{}

	/**
	 * @brief Convert to level entity.
	 */
	LevelEntity::ShrPtr to_level_entity(const Vec2D& pos) const override
	{
		return std::make_shared<LevelObstacle>(pos, m_sprite_filename, m_size, m_collision_penalty);
	}
};

/**
 * @brief Class to store FinishLine specifications.
 */
class FinishLineTemplate final : public EntityTemplate
{
private:
	const std::string m_sprite_filename;
	const float       m_size;
public:
	/**
	 * @brief Constructor.
	 */
	FinishLineTemplate(const std::string& sprite_filename,
					   const float size)
		: m_sprite_filename{sprite_filename}, m_size{size}
	{}

	/**
	 * @brief Convert to level entity.
	 */
	LevelEntity::ShrPtr to_level_entity(const Vec2D& pos) const override
	{
		return std::make_shared<LevelFinishLine>(pos, m_sprite_filename, m_size);
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
	std::string player_symbol;

	try
	{
		player_symbol = json_data.at("PlayerData").at("Symbol").get<std::string>();

		EntityTemplate::UnqPtr player_templ
				= std::make_unique<PlayerTemplate>
								(
									json_data.at("PlayerData").at("Sprite").get<std::string>(),
									json_data.at("PlayerData").at("Size").get<float>(),
									json_data.at("PlayerData").at("BulletSpeed").get<float>(),
									json_data.at("PlayerData").at("BulletSize").get<float>(),
									json_data.at("PlayerData").at("MaxShotsPerSecond").get<float>(),
									json_data.at("PlayerData").at("Lives").get<int>(),
									json_data.at("PlayerData").at("Speed").get<float>()
								);

		if(entity_templates.count(player_symbol)) {
			throw LevelLoadException{json_filename, "Duplicate symbol: '" + player_symbol + "'."};
		} else if (player_symbol == ".") {
			throw LevelLoadException{json_filename, "Cannot use '.' as symbol."};
		}

		entity_templates.insert(std::make_pair(player_symbol, std::move(player_templ)));
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
	// load "FinishLine"
	////////////////////////////////////////////////////////////////////
	std::string finishline_symbol;

	try
	{
		finishline_symbol = json_data.at("FinishLine").at("Symbol").get<std::string>();

		EntityTemplate::UnqPtr finishline_templ
				= std::make_unique<FinishLineTemplate>
								(
									json_data.at("FinishLine").at("Sprite").get<std::string>(),
									json_data.at("FinishLine").at("Size").get<float>()
								);

		if(entity_templates.count(finishline_symbol)) {
			throw LevelLoadException{json_filename, "Duplicate symbol: '" + finishline_symbol + "'."};
		} else if (finishline_symbol == ".") {
			throw LevelLoadException{json_filename, "Cannot use '.' as symbol."};
		}

		entity_templates.insert(std::make_pair(finishline_symbol, std::move(finishline_templ)));
	}
	catch(const LevelLoadException& e)
	{
		// rethrow custom exception.
		throw;
	}
	catch(...)
	{
		throw LevelLoadException{json_filename, "Cannot retrieve finish line data."};
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
										iterated_enemy.at("Size").get<float>(),
							json_to_vec(iterated_enemy.at("Direction")),
										iterated_enemy.at("BulletSpeed").get<float>(),
										iterated_enemy.at("BulletSize").get<float>(),
										iterated_enemy.at("MaxShotsPerSecond").get<float>(),
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
										iterated_obstacle.at("Size").get<float>(),
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

	const float max_x = json_data.at("MaxXCoord").get<float>();
	const float max_y = json_data.at("MaxYCoord").get<float>();


	// create level object
	Level retval{grid.at(0).size(), grid.size(), max_x, max_y};

	if(retval.get_width() < max_x)
	{
		throw LevelLoadException{json_filename, "Not enough columns in level grid."};
	}

	if(retval.get_height() < max_y)
	{
		throw LevelLoadException{json_filename, "Not enough rows in level grid."};
	}

	// track whether player is found
	bool player_found = false;

	// track whether
	bool finishline_found = false;

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
				col++;
				continue;
			}
			else if(entity_templates.count(symbol))
			{
				// special case for unique player
				if(symbol == player_symbol)
				{
					if(player_found)
					{
						throw LevelLoadException{json_filename, "Duplicate player."};
					}
					else
					{
						player_found = true;
					}
				}
				else if(symbol == finishline_symbol)
				{
					finishline_found = true;
				}

				// add entity to level.
				retval.add_entity(entity_templates.at(symbol)->to_level_entity(Vec2D{(float)col + 0.5f, (float) row + 0.5f}));
			}
			else
			{
				throw LevelLoadException{json_filename, "Unknown symbol '" + symbol + "' in level grid."};
			}

			col++;
		}
		row++;
	}

	if(not player_found)
	{
		throw LevelLoadException{json_filename, "Player not specified in level grid."};
	}

	if(not finishline_found)
	{
		throw LevelLoadException{json_filename, "Finish line not specified in level grid."};
	}

	// return level
	return retval;

}

}} // namespace game::level


