//=========================================
// @brief Header file for EntityViewBase class.
//=========================================


#ifndef INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP
#define INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP

#include "../model/EntityModel.hpp"
using game::MVC::model::EntityModel;
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
	EntityModel::ShrPtr m_modelptr;
	IOhandlers::Sprite m_sprite;
protected:
	/**
	 * @brief Method so that inherited classes can access the model.
	 *
	 * @note Returns a raw pointer. This is to prevent the lifetime of the model from being manipulated.
	 */
	const EntityModel* get_model_ptr(void) const;

	/**
	 * @brief Method so that inherited classes can access and manipulate the model.
	 *
	 * @note Returns a raw pointer. This is to prevent the lifetime of the model from being manipulated.
	 */
	EntityModel* get_model_ptr(void);

	/**
	 * @brief Method so that inherited classes can access the sprite.
	 */
	const IOhandlers::Sprite& get_sprite(void) const;

	/**
	 * @brief Method so that inherited classes can access and manipulate the sprite.
	 */
	IOhandlers::Sprite& get_sprite(void);

public:
	using UnqPtr = std::unique_ptr<EntityViewBase>;

	/**
	 * @brief Construct a view based on a pointer to a model and a sprite.
	 */
	EntityViewBase(const model::EntityModel::ShrPtr& model_ptr, const IOhandlers::Sprite& sprite);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityViewBase(void);

	/**
	 * @brief Render the entity view to a window.
	 */
	virtual void render(IOhandlers::Window& window) = 0;
};

}}} // namespace game::MVC::view

#endif // INCLUDED_MVC_VIEW_ENTITYVIEWBASE_HPP

