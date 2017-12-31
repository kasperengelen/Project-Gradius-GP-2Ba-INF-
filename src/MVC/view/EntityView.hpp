//======================================
// @brief Header file for EntityView class.
//======================================

#ifndef INCLUDED_MVC_VIEW_ENTITYVIEW_HPP
#define INCLUDED_MVC_VIEW_ENTITYVIEW_HPP

#include "EntityViewBase.hpp"

namespace game {
namespace MVC {
namespace view {

/**
 * @brief Templatized view for entities.
 */
template <typename EntityType>
class EntityView final: public EntityViewBase
{
private:
public:
	using UnqPtr = std::unique_ptr<EntityView<EntityType>>;

	/**
	 * @brief Constructor based on a model pointer and a sprite.
	 */
	EntityView(const typename EntityType::ShrPtr& model_ptr, const IOhandlers::Sprite& sprite);

	/**
	 * @brief Destructor.
	 */
	~EntityView(void);

	/**
	 * @brief Render the entity view to the specified window.
	 */
	void render(IOhandlers::Window& window) override;

};


template <typename EntityType>
EntityView<EntityType>::EntityView(const typename EntityType::ShrPtr& model_ptr, const IOhandlers::Sprite& sprite)
	: EntityViewBase{model_ptr, sprite}
{}

template <typename EntityType>
EntityView<EntityType>::~EntityView(void)
{}


}}} // namespace game::MVC::view

#endif // INCLUDED_MVC_VIEW_ENTITYVIEW_HPP
