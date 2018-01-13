//=================================================
// @brief Header file for Bullet class.
//=================================================

#ifndef INCLUDED_ENTITY_BULLET_HPP
#define INCLUDED_ENTITY_BULLET_HPP

#include "DynamicEntity.hpp"
#include "../utils/Vec2D.hpp"

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
	using ShrPtr = std::shared_ptr<Bullet>;
	using WkPtr = std::weak_ptr<Bullet>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The initial position of the bullet.
	 * @param[in] size The diameter of the bullet.
	 * @param[in] dir The direction of the bullet.
	 * @param[in] damage Amount of lives the player loses on collision with the player.
	 */
	Bullet(const utils::Vec2D& pos,
		   const float size,
		   const utils::Vec2D& dir,
		   const int damage);

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

	/**
	 * @brief Retrieve textual representation of the bullet.
	 */
	std::string to_string(void) const override;
};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_BULLET_HPP


