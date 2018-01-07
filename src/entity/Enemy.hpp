//==========================================
// @brief Header file for Enemy class.
//==========================================

#ifndef INCLUDED_ENTITY_ENEMY_HPP
#define INCLUDED_ENTITY_ENEMY_HPP

#include "DynamicEntity.hpp"

namespace game {
namespace entity {

/**
 * @brief Model class for enemy entities.
 */
class Enemy final: public DynamicEntity
{
private:

public:
	using ShrPtr = std::shared_ptr<Enemy>;

	/**
	 * @brief Constructor based on a position and a direction.
	 */
	Enemy(const Vec2D& pos, const Vec2D& dir);

	/**
	 * @brief Destructor.
	 */
	~Enemy(void);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_ENEMY_HPP
