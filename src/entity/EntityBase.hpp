//===================================================
// @brief Header file for EntityBase class.
//===================================================

#ifndef INCLUDED_ENTITY_ENTITYBASE_HPP
#define INCLUDED_ENTITY_ENTITYBASE_HPP

#include "../utils/Vec2D.hpp"
using game::utils::Vec2D;

#include <memory>

namespace game {
namespace entity {

/**
 * @brief Base class for all entity models. This represents an Entity that has a position.
 */
class EntityBase
{
private:
	Vec2D m_pos; // current position in world

public:
	using ShrPtr = std::shared_ptr<EntityBase>;

	/**
	 * @brief Constructor for an EntityModel based on a position.
	 */
	EntityBase(const Vec2D& pos);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityBase(void);

	/**
	 * @brief Retrieve the position of the entity.
	 */
	const Vec2D& get_position(void) const;

	/**
	 * @brief Set the position of the entity.
	 */
	void set_position(const Vec2D& pos);

	/**
	 * @brief Handle a game tick.
	 */
	virtual void do_game_tick(void) = 0;

};


}} // namespace game::entity

#endif // INCLUDED_ENTITY_ENTITYBASE_HPP

