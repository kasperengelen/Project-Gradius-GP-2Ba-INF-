//=================================================
// @brief Header file for Bullet class.
//=================================================

#ifndef INCLUDED_ENTITY_BULLET_HPP
#define INCLUDED_ENTITY_BULLET_HPP

#include "DynamicEntity.hpp"

namespace game {
namespace entity {

/**
 * @brief Class that represents a bullet.
 */
class Bullet : public DynamicEntity
{
private:
	int m_damage;
public:
	/**
	 * @brief Construct bullet based on a position, direction, amount of damage.
	 */
	Bullet(const Vec2D& pos, const Vec2D& dir, const int damage);

	/**
	 * @brief Retrieve the damage of the bullet.
	 */
	int get_damage(void) const;

	/**
	 * @brief Set the damage of the bullet.
	 */
	void set_damage(const int damage);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;
};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_BULLET_HPP


