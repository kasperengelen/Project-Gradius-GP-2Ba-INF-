//=========================================
// @brief Header file for EntityViewBase class.
//=========================================


#ifndef INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP
#define INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP

#include "../model/EntityModel.hpp"
#include "../../IOhandlers/Sprite.hpp"
#include "../../IOhandlers/Window.hpp"

namespace game {
namespace MVC {
namespace view {

/**
 * @brief Base class for entity views.
 */
class EntityViewBase
{
private:
	model::EntityModel::ShrPtr m_modelptr;
	IOhandlers::Sprite m_sprite;
public:
	/**
	 * @brief Construct a view based on a pointer to a model and a sprite.
	 */
	EntityViewBase(const model::EntityModel::ShrPtr& model_ptr, const IOhandlers::Sprite& sprite);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityViewBase(void);

	/**
	 * @brief Retrieve the sprite of the view.
	 */
	const IOhandlers::Sprite& get_sprite(void) const;

	/**
	 * @brief Render the entity view to a window.
	 */
	virtual void render(const IOhandlers::Window& window) = 0;
};

}}} // namespace game::MVC::view

#endif // INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP

