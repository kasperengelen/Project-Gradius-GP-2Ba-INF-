//================================================
// @brief Header file for GameModel class.
//================================================

#ifndef INCLUDED_MVC_MODEL_GAMEMODEL_HPP
#define INCLUDED_MVC_MODEL_GAMEMODEL_HPP

// project includes
#include "../utils/Vec2D.hpp"
using game::utils::Vec2D;
#include "../entity/Enemy.hpp"
using game::entity::Enemy;
#include "../entity/EntityBase.hpp"
using game::entity::EntityBase;
#include "../entity/Player.hpp"
using game::entity::Player;
#include "../entity/Bullet.hpp"
using game::entity::Bullet;

// std includes
#include <memory>
#include <vector>

namespace game {
namespace MVC {

/**
 * @brief Model class that encompasses the entire model of the game.
 */
class GameModel final
{
private:
	std::vector<EntityBase::ShrPtr> m_entity_models;

	// TODO enemy list
	// TODO obstacle list
	// TODO player
	Player::ShrPtr m_player;


	// TODO bool level_completed;

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
	void set_player(const Player::ShrPtr& player_ptr);

	/**
	 * @brief Retrieve the current position of the player.
	 */
	const Vec2D get_player_position(void) const;

	/**
	 * @brief Retrieve the current direction of the player.
	 */
	const Vec2D get_player_direction(void) const;

	/**
	 * @brief Update the player direction.
	 */
	void set_player_direction(const Vec2D& dir);

	/**
	 * @brief Add enemy.
	 */
	void add_enemy(const Enemy::ShrPtr& enemy_ptr);

	/**
	 * @brief Remove the entity models stored in the game model.
	 */
	void clear_entity_models(void);

	//TODO remove debug method
	void debug_add_entity_model(const EntityBase::ShrPtr& entity_model_ptr);

};

}} // namespace game::MVC

#endif // INCLUDED_MVC_MODEL_GAMEMODEL_HPP
