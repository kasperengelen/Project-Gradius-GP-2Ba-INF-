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
	utils::Vec2D m_dir;
public:
	using ShrPtr = std::shared_ptr<DynamicEntity>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The initial position of the entity.
	 * @param[in] size The diameter of the entity.
	 * @param[in] dir The direction vector of the entity.
	 */
	DynamicEntity(const utils::Vec2D& pos,
				  const float size,
				  const utils::Vec2D& dir);

	/**
	 * @brief Destructor.
	 */
	virtual ~DynamicEntity(void);

	/**
	 * @brief Retrieve the direction vector of the entity.
	 */
	const utils::Vec2D& get_direction(void) const;

	/**
	 * @brief Set the direction vector of the entity.
	 */
	void set_direction(const utils::Vec2D& dir);

	/**
	 * @brief Perform a game tick.
	 */
	virtual void do_game_tick(void) override;
};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_DYNAMICENTITY_HPP

