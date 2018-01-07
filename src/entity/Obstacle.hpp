//==================================================
// @brief Header file for Obstacle class
//==================================================

#ifndef INCLUDED_ENTITY_OBSTACLE_HPP
#define INCLUDED_ENTITY_OBSTACLE_HPP

#include "EntityBase.hpp"

namespace game {
namespace entity {

/**
 * @brief Entity that is an obstacle.
 */
class Obstacle : public EntityBase
{
private:
	int m_coll_penalty;
public:
	/**
	 * @brief Constructor based on a position and a collision penalty.
	 */
	Obstacle(const Vec2D& pos, const int coll_penalty);

	/**
	 * @brief Get the amount of lives the player loses on collision.
	 */
	int get_penalty(void) const;

	/**
	 * @brief Set the mount of lives the player loses on collision.
	 */
	void set_penalty(const int penalty);

};


}} // namespace game::entity

#endif // INCLUDED_ENTITY_OBSTACLE_HPP

