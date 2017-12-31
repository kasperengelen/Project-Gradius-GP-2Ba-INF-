//======================================================
// @brief Implementation of LevelParser.hpp.
//======================================================

#include "LevelParser.hpp"
#include "LevelEntity.hpp"
#include "Level.hpp"

#include "../lib/json.hpp"
using nlohmann::json;

#include "../exception/LevelException.hpp"

#include "../utils/Vec2D.hpp"
using game::utils::Vec2D;

#include <map>
#include <string>
#include <fstream>
#include <iostream>

namespace game {
namespace level {


namespace
{
	const Vec2D json_to_vec(const json& j)
	{
		return {j.at(0).get<float>(), j.at(1).get<float>()};
	}
}

/**
 * @brief Base class for enemy, obstacle and player specifications stored in the level file.
 */
struct EntityTemplate
{
public:
	enum class TemplateType
	{
		PLAYER,
		ENEMY,
		OBSTACLE
	};

	using UnqPtr = std::unique_ptr<EntityTemplate>;

public:
	// specifies
	const TemplateType templ_type;

protected:
	// make constructor protected
	EntityTemplate(const TemplateType& templ_type)
		: templ_type{templ_type}
	{}
};

struct PlayerTemplate: public EntityTemplate
{
	const std::string sprite_filename;
	const int lives;
	const float max_speed;

	PlayerTemplate(const std::string& sprite_filename, const int lives, const float max_speed)
		: EntityTemplate{EntityTemplate::TemplateType::PLAYER},
		  sprite_filename{sprite_filename},
		  lives{lives},
		  max_speed{max_speed}
	{}
};

struct EnemyTemplate: public EntityTemplate
{
	const std::string sprite_filename;
	const Vec2D direction;
	const int attack_damage;

	EnemyTemplate(const std::string& sprite_filename, const Vec2D& dir, const int attack_damage)
		: EntityTemplate{EntityTemplate::TemplateType::ENEMY},
		  sprite_filename{sprite_filename},
		  direction{dir},
		  attack_damage{attack_damage}
	{}
};

struct ObstacleTemplate: public EntityTemplate
{
	const std::string sprite_filename;
	const int collision_penalty;

	ObstacleTemplate(const std::string& sprite_filename, const int collision_penalty)
		: EntityTemplate{EntityTemplate::TemplateType::OBSTACLE},
		  sprite_filename{sprite_filename},
		  collision_penalty{collision_penalty}
	{}
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
		throw exception::level::LevelLoadException{json_filename, "Cannot load file."};
	}

	// load "PlayerData"
	try
	{
		// iterate over this
		const auto player_data = json_data.at("PlayerData");

		const std::string sprite_filename = player_data.at("Sprite").get<std::string>();
		const int lives                   = player_data.at("Lives").get<int>();
		const float max_speed             = player_data.at("MaxSpeed").get<float>();

		EntityTemplate::UnqPtr player_templ = std::make_unique<PlayerTemplate>(sprite_filename, lives, max_speed);

		const std::string symbol = player_data.at("Symbol").get<std::string>();


		entity_templates.insert(std::make_pair(symbol, std::move(player_templ)));
	}
	catch(const exception::level::LevelLoadException& e)
	{
		throw;
	}
	catch(...)
	{
		throw exception::level::LevelLoadException{json_filename, "Cannot retrieve player data."};
	}

	// load "EnemyTypes"
	try
	{
		const auto enemy_data_list = json_data.at("EnemyTypes");

		// iterate over enemies
		for(const auto& iterated_enemy : enemy_data_list)
		{
			const std::string sprite_filename = iterated_enemy.at("Sprite").get<std::string>();
			const Vec2D dir       = json_to_vec(iterated_enemy.at("Direction"));
			const int attack_damage           = iterated_enemy.at("AttackDamage").get<int>();

			EntityTemplate::UnqPtr enemy_templ
					= std::make_unique<EnemyTemplate>(sprite_filename, dir, attack_damage);

			const std::string symbol = iterated_enemy.at("Symbol");

			if(entity_templates.count(symbol)) {
				throw exception::level::LevelLoadException{json_filename, "Duplicate symbol: '" + symbol + "'."};
			}

			entity_templates.insert(std::make_pair(symbol, std::move(enemy_templ)));
		}
	}
	catch(const exception::level::LevelLoadException& e)
	{
		throw;
	}
	catch(...)
	{
		throw exception::level::LevelLoadException{json_filename, "Cannot retrieve enemy data."};
	}



	// load "ObstacleTypes"
	try
	{
		const auto obstacle_data_list = json_data.at("ObstacleTypes");

		// iterate over obstacles
		for(const auto iterated_obstacle: obstacle_data_list)
		{
			const std::string sprite_filename = iterated_obstacle.at("Sprite").get<std::string>();
			const int collision_penalty       = iterated_obstacle.at("CollisionPenalty").get<int>();

			EntityTemplate::UnqPtr obstacle_templ
							 = std::make_unique<ObstacleTemplate>(sprite_filename, collision_penalty);

			const std::string symbol = iterated_obstacle.at("Symbol");

			if(entity_templates.count(symbol)) {
				throw exception::level::LevelLoadException{json_filename, "Duplicate symbol: '" + symbol + "'."};
			}

			entity_templates.insert(std::make_pair(symbol, std::move(obstacle_templ)));
		}
	}
	catch(const exception::level::LevelLoadException& e)
	{
		throw;
	}
	catch(...)
	{
		throw exception::level::LevelLoadException{json_filename, "Cannot retrieve obstacle data."};
	}

	// create level object with dimensions.

	// fill grid based on entity data

	return Level{10, 10};

}

}} // namespace game::level


