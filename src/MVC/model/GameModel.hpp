//================================================
// @brief Header file for GameModel class.
//================================================

#ifndef INCLUDED_MVC_MODEL_GAMEMODEL_HPP
#define INCLUDED_MVC_MODEL_GAMEMODEL_HPP

// project includes
#include "EntityModel.hpp"

#include "PlayerModel.hpp"
#include "EnemyModel.hpp"

// include obstacle model
// include worldborder model

// std includes
#include <memory>
#include <vector>

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Model class that encompasses the entire model of the game.
 */
class GameModel final
{
private:
	std::vector<EntityModel::ShrPtr> m_entity_models;

	// todo vectors for enemies, player, bullets, obstacles, worldborder.
public:
	using ShrPtr = std::shared_ptr<GameModel>;

	/**
	 * @brief Construct the model.
	 */
	GameModel(void);

	/**
	 * @brief Destructor.
	 */
	~GameModel(void);

	/**
	 * @brief Notify the model that a game tick is to be performed.
	 */
	void do_game_tick(void);

	/**
	 * @brief Set the player.
	 */
	void set_player(const PlayerModel::ShrPtr& player_ptr);

	/**
	 * @brief Add enemy.
	 */
	void add_enemy(const EnemyModel::ShrPtr& enemy_ptr);

	//TODO REMOVE DEBUG method
	void debug_add_entity_model(const EntityModel::ShrPtr& entity_model_ptr);

};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_GAMEMODEL_HPP
