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
	using ShrPtr = std::shared_ptr<Obstacle>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the obstacle.
	 * @param[in] size The diameter of the obstacle.
	 * @param[in] coll_penalty The amount of lives the player loses on collision with the obstacle.
	 */
	Obstacle(const utils::Vec2D& pos, const float size, const int coll_penalty);

	/**
	 * @brief Get the amount of lives the player loses on collision.
	 */
	int get_penalty(void) const;

	/**
	 * @brief Set the mount of lives the player loses on collision.
	 */
	void set_penalty(const int penalty);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

	/**
	 * @brief Retrieve textual representation of the obstacle.
	 */
	const std::string to_string(void) const override;
};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_OBSTACLE_HPP

