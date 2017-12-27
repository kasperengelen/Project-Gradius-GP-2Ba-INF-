//=============================================
// @brief Implementation of EntityViewBase.hpp
//=============================================

#include "EntityViewBase.hpp"

namespace game {
namespace MVC {
namespace view {

EntityViewBase::EntityViewBase(const model::EntityModel::ShrPtr& model_ptr, const IOhandlers::Sprite& sprite)
	: m_modelptr{model_ptr}, m_sprite{sprite}
{}

EntityViewBase::~EntityViewBase(void)
{}

const IOhandlers::Sprite& EntityViewBase::get_sprite(void) const
{
	return m_sprite;
}

}}} // namespace game::MVC::view
