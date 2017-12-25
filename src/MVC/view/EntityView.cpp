//==================================================
// @brief Implementation of EntityView.hpp
//==================================================

#include "EntityView.hpp"

namespace game {
namespace MVC {
namespace view {

EntityView::EntityView(const model::EntityModel::ShrPtr& model_ptr,
					   const IOhandlers::Sprite& entity_sprite)
	: m_model{model_ptr}, m_sprite{entity_sprite}
{}

EntityView::~EntityView(void)
{}

}}} // namespace game::MVC::view
