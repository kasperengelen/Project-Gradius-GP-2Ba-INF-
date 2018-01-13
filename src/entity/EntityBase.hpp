//===================================================
// @brief Header file for EntityBase class.
//===================================================

#ifndef INCLUDED_ENTITY_ENTITYBASE_HPP
#define INCLUDED_ENTITY_ENTITYBASE_HPP

#include "../utils/Vec2D.hpp"
#include "../observer/Observable.hpp"

#include <memory>

namespace game {
namespace entity {

/**
 * @brief Base class for all entity models. This represents an Entity that has a position.
 */
class EntityBase : public observer::Observable
{
private:
	utils::Vec2D m_pos; // current position in world
	float m_size;

public:
	using ShrPtr = std::shared_ptr<EntityBase>;
	using WkPtr = std::weak_ptr<EntityBase>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos Initial position of the entity.
	 * @param[in] size Diameter of the entity.
	 */
	EntityBase(const utils::Vec2D& pos, const float size);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityBase(void);

	/**
	 * @brief Retrieve the position of the entity.
	 */
	const utils::Vec2D& get_position(void) const;

	/**
	 * @brief Set the position of the entity.
	 */
	void set_position(const utils::Vec2D& pos);

	/**
	 * @brief Retrieve the size of the entity.
	 */
	float get_size(void) const;

	/**
	 * @brief Handle a game tick.
	 */
	virtual void do_game_tick(void) = 0;


	/**
	 * @brief Retrieve textual representation of the entity.
	 */
	virtual const std::string to_string(void) const = 0;

};

/**
 * @brief Determine if two enemies collide based on position and entity size.
 */
bool collides(const EntityBase& a, const EntityBase& b);

}} // namespace game::entity

#endif // INCLUDED_ENTITY_ENTITYBASE_HPP

