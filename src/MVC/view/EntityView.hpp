//==================================================
// @brief Header file for EntityView class.
//==================================================

#ifndef MVC_VIEW_ENTITYVIEW_HPP
#define MVC_VIEW_ENTITYVIEW_HPP

#include "../model/EntityModel.hpp"
#include "../../IOhandlers/Window.hpp"
#include "../../IOhandlers/Sprite.hpp"

namespace game {
namespace MVC {
namespace view {

/**
 * @brief Base class that represents a view for entities.
 */
class EntityView
{
protected:
	model::EntityModel::ShrPtr m_model;
	IOhandlers::Sprite m_sprite;
public:
	using UnqPtr = std::unique_ptr<EntityView>;

	/**
	 * @brief Construct a view for the specified EntityModel and the specified Sprite.
	 */
	EntityView(const model::EntityModel::ShrPtr& model_ptr,
			   const IOhandlers::Sprite& entity_sprite);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityView(void);

	/**
	 * @brief Render the view.
	 */
	virtual void render(game::IOhandlers::Window& render_window) = 0;
};

}}} // namespace game::MVC::view

#endif // MVC_VIEW_ENTITYVIEW_HPP
