//==========================================
// @brief Header file for Enemy class.
//==========================================

#ifndef INCLUDED_ENTITY_ENEMY_HPP
#define INCLUDED_ENTITY_ENEMY_HPP

#include "ShootingEntity.hpp"

namespace game {
namespace entity {

/**
 * @brief Model class for enemy entities.
 */
class Enemy final: public ShootingEntity
{
private:
	int m_attack_damage;

public:
	using ShrPtr = std::shared_ptr<Enemy>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The initial position of the enemy.
	 * @param[in] size The diameter of the enemy.
	 * @param[in] bullet_speed The speed of the bullets that the enemy shoots.
	 * @param[in] bullet_size The size of the bullets that the enemy shoots.
	 * @param[in] max_shots_per_second The maximum amount of times per second the player can shoot.
	 * @param[in] attack_damage The amount of lives the player loses when hit by the enemy.
	 */
	Enemy(const utils::Vec2D& pos,
		  const float size,
		  const utils::Vec2D& dir,
		  const float bullet_speed,
		  const float bullet_size,
		  const float max_shots_per_second,
		  const int attack_damage);

	/**
	 * @brief Destructor.
	 */
	~Enemy(void);

	/**
	 * @brief Retrieve the amount of attack damage the enemy deals. This is the
	 * amount of lives the player loses when hit by the enemy.
	 */
	int get_attack_damage(void) const;

	/**
	 * @brief Set the amount of attack damage the enemy deals. This is the
	 * amount of lives the player loses when hit by the enemy.
	 */
	void set_attack_damage(const int attack_damage);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

	/**
	 * @brief Retrieve textual representation of the enemy.
	 */
	std::string to_string(void) const override;

};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_ENEMY_HPP
