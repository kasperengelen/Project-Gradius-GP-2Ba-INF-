//===================================================
// @brief Header file for ShootingEntity class.
//===================================================

#ifndef INCLUDED_ENTITY_SHOOTINGENTITY_HPP
#define INCLUDED_ENTITY_SHOOTINGENTITY_HPP

#include "../utils/Vec2D.hpp"
#include "DynamicEntity.hpp"

namespace game {
namespace entity {

/**
 * @brief Base class for entities that can shoot bullets.
 */
class ShootingEntity : public DynamicEntity
{
private:
	float m_bullet_speed;
	float m_bullet_size;
	float m_max_shots_per_second;

	int m_ticks_since_last_shot;
public:
	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the entity.
	 * @param[in] size The diameter of the entity.
	 * @param[in] dir The direction vector of the entity.
	 * @param[in] bullet_speed The speed of the bullets that the entity shoots.
	 * @param[in] bullet_size The diameter of the bullets that the entity shoots.
	 * @param[in] max_shots_per_second The maximum amount of times the entity can shoot per second.
	 */
	ShootingEntity(const utils::Vec2D& pos,
			       const float size,
				   const utils::Vec2D& dir,
				   const float bullet_speed,
				   const float bullet_size,
				   const float max_shots_per_second);

	/**
	 * @brief Retrieve the speed of the bullets that the entity shoots.
	 */
	float get_bullet_speed(void) const;

	/**
	 * @brief Retrieve the size of the bullets that the entity shoots.
	 */
	float get_bullet_size(void) const;

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

	/**
	 * @brief Notify the entity that it has shot a bullet.
	 */
	void shoot(void);

	/**
	 * @brief Determine wether the entity is ready to shoot a bullet.
	 */
	bool can_shoot(void) const;

	/**
	 * @brief Retrieve the maximum amount of times per second the entity can shoot a bullet.
	 */
	float get_max_shots_per_second(void) const;
};

}} // namespace game::entity


#endif // INCLUDED_ENTITY_SHOOTINGENTITY_HPP
