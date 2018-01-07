//========================================
// @brief Header file for DynamicEntity class.
//========================================

#ifndef INCLUDED_ENTITY_DYNAMICENTITY_HPP
#define INCLUDED_ENTITY_DYNAMICENTITY_HPP

#include "EntityBase.hpp"


namespace game {
namespace entity {

/**
 * @brief Base class for entities that have both a position and a direction vector.
 */
class DynamicEntity : public EntityBase
{
private:
	Vec2D m_dir;
public:
	using ShrPtr = std::shared_ptr<DynamicEntity>;

	/**
	 * @brief Constructor based on a position and a direction vector.
	 */
	DynamicEntity(const Vec2D& pos, const Vec2D& dir);

	/**
	 * @brief Destructor.
	 */
	virtual ~DynamicEntity(void);

	/**
	 * @brief Retrieve the direction vector of the entity.
	 */
	const Vec2D& get_direction(void) const;

	/**
	 * @brief Set the direction vector of the entity.
	 */
	void set_direction(const Vec2D& dir);

	/**
	 * @brief Perform a game tick.
	 */
	virtual void do_game_tick(void) override = 0;
};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_DYNAMICENTITY_HPP

