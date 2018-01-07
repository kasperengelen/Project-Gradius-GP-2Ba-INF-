//=========================================
// @brief Header file for EntityRepresentation class.
//=========================================


#ifndef INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP
#define INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP

#include "EntityBase.hpp"
using game::entity::EntityBase;
#include "../IOhandlers/Sprite.hpp"
#include "../IOhandlers/Window.hpp"

namespace game {
namespace entity {

/**
 * @brief Base class for entity views.
 */
class EntityRepresentation
{
private:
	EntityBase::ShrPtr m_entityptr;
	IOhandlers::Sprite m_sprite;
public:
	using UnqPtr = std::unique_ptr<EntityRepresentation>;
	using ShrPtr = std::shared_ptr<EntityRepresentation>;

	/**
	 * @brief Construct a view based on a pointer to a model and a sprite.
	 */
	EntityRepresentation(const EntityBase::ShrPtr& model_ptr, const IOhandlers::Sprite& sprite);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityRepresentation(void);

	/**
	 * @brief Render the entity view to a window.
	 */
	virtual void render(IOhandlers::Window& window);
};

}} // namespace game::entity

#endif // INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP

