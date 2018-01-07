//================================================
// @brief Header file for Player class.
//================================================

#ifndef INCLUDED_ENTITY_PLAYER_HPP
#define INCLUDED_ENTITY_PLAYER_HPP

#include "DynamicEntity.hpp"

namespace game {
namespace entity {

/**
 * @brief Model class for Player entity.
 */
class Player final : public DynamicEntity
{
private:
	int m_lives;
public:
	using ShrPtr = std::shared_ptr<Player>;

	/**
	 * @brief Constructor based on a position, direction vector and a number of lives.
	 *
	 */
	Player(const Vec2D& pos, const int lives);

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
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_PLAYER_HPP

