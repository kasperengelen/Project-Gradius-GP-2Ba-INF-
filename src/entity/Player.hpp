//================================================
// @brief Header file for Player class.
//================================================

#ifndef INCLUDED_ENTITY_PLAYER_HPP
#define INCLUDED_ENTITY_PLAYER_HPP

#include "ShootingEntity.hpp"

namespace game {
namespace entity {

/**
 * @brief Model class for Player entity.
 */
class Player final : public ShootingEntity
{
private:
	int m_lives;
	float m_speed;

public:
	using ShrPtr = std::shared_ptr<Player>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The initial position of the player.
	 * @param[in] size The diameter of the player.
	 * @param[in] bullet_speed The speed of the bullets that the player shoots.
	 * @param[in] bullet_size The size of the bullets that the player shoots.
	 * @param[in] max_shots_per_second The maximum amount of times per second the player can shoot.
	 * @param[in] lives The amount of lives the player starts with.
	 * @param[in] speed The amount that the direction vector increments for each tick that a movement button is pressed.
	 *
	 */
	Player(const utils::Vec2D& pos,
		   const float size,
		   const float bullet_speed,
		   const float bullet_size,
		   const float max_shots_per_sec,
		   const int lives,
		   const float speed);

	/**
	 * @brief Destructor.
	 */
	~Player(void);

	/**
	 * @brief Retrieve the amount of lives the player has.
	 */
	int get_lives(void) const;

	/**
	 * @brief Set the mount of lives the player has.
	 */
	void set_lives(const int lives);

	/**
	 * @brief Retrieve the speed of the player.
	 */
	float get_speed(void) const;

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

	/**
	 * @brief Retrieve textual representation of the player.
	 */
	const std::string to_string(void) const override;

};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_PLAYER_HPP

