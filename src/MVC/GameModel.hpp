//================================================
// @brief Header file for GameModel class.
//================================================

#ifndef INCLUDED_MVC_GAMEMODEL_HPP
#define INCLUDED_MVC_GAMEMODEL_HPP

// project includes
#include "../utils/Vec2D.hpp"

#include "../entity/EntityBase.hpp"
#include "../entity/Enemy.hpp"
#include "../entity/Player.hpp"
#include "../entity/Bullet.hpp"
#include "../entity/Obstacle.hpp"
#include "../entity/FinishLine.hpp"

#include "../observer/Observable.hpp"

// std includes
#include <memory>
#include <vector>

namespace game {
namespace MVC {

/**
 * @brief Model class that encompasses the entire model of the game.
 */
class GameModel final : public observer::Observable
{
private:
	// list of players
	entity::Player::ShrPtr m_player;

	// amount of ticks that passed since the player has shot the last bullet
	int m_ticks_since_last_player_shoot{0};

	// the respawn point of the player
	utils::Vec2D m_player_spawnpoint;

	// list of obstacles
	std::vector<entity::Obstacle::ShrPtr> m_obstacles;

	// list of enemies
	std::vector<entity::Enemy::ShrPtr> m_enemies;

	// list of enemy bullets
	std::vector<entity::Bullet::ShrPtr> m_bullets_enemy;

	// list of player bullets
	std::vector<entity::Bullet::ShrPtr> m_bullets_player;

	// keeps track of whether the player has lost.
	bool m_game_over{false};

	// keeps track of whether the player has won.
	bool m_game_won{false};

	// keeps track of whether the level is completed.
	bool m_level_complete{false};

	// list of finish lines
	std::vector<entity::FinishLine::ShrPtr> m_finish_lines;

	/**
	 * @brief Request the specified enemy to shoot. The bullet will only be fire if the rate of fire
	 * is respected and if the random generator returns true;
	 */
	void M_try_enemy_shoot(const entity::Enemy::ShrPtr& enemy_ptr);

	/**
	 * @brief Handle the death of a player (respawn, decrease lives, etc);
	 */
	void M_handle_player_death(const int lives_lost);

	/**
	 * @brief Perform collision detection.
	 */
	void M_handle_collision_detection(void);

public:
	using ShrPtr = std::shared_ptr<GameModel>;

	/**
	 * @brief Constructor.
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
	void set_player(const entity::Player::ShrPtr& player_ptr);

	/**
	 * @brief Retrieve the current direction of the player.
	 */
	utils::Vec2D get_player_direction(void) const;

	/**
	 * @brief Retrieve the speed of the player.
	 */
	float get_player_speed(void) const;

	/**
	 * @brief Update the player direction.
	 */
	void set_player_direction(const utils::Vec2D& dir);

	/**
	 * @brief Lets the player shoot a bullet.
	 */
	void player_shoot(void);

	/**
	 * @brief Add enemy.
	 */
	void add_enemy(const entity::Enemy::ShrPtr& enemy_ptr);

	/**
	 * @brief Add obstacles.
	 */
	void add_obstacle(const entity::Obstacle::ShrPtr& obstacle_ptr);

	/**
	 * @brief Add finish line.
	 */
	void add_finish_line(const entity::FinishLine::ShrPtr& finish_line);

	/**
	 * @brief Determine if the player has lost.
	 */
	bool game_over(void) const;

	/**
	 * @brief Determine if the level is complete.
	 */
	bool level_complete(void) const;

	/**
	 * @brief Determine whether the player has won the game.
	 */
	bool get_game_won(void) const;

	/**
	 * @brief Notify the model that there are no more levels to be played.
	 */
	void set_game_won(void);

	/**
	 * @brief Reset the model.
	 */
	void reset_model(void);

};

}} // namespace game::MVC

#endif // INCLUDED_MVC_GAMEMODEL_HPP
