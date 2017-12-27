//=========================================
// @brief Implementation of EntityController.hpp
//=========================================

#include "EntityControllerBase.hpp"

namespace game {
namespace MVC {
namespace controller {

EntityControllerBase::EntityControllerBase(const model::EntityModel::ShrPtr& model_ptr)
	: m_modelptr{model_ptr}
{}

EntityControllerBase::~EntityControllerBase(void)
{}

const model::EntityModel::ShrPtr& EntityControllerBase::get_model(void) const
{
	return m_modelptr;
}

}}} // namespace game::MVC::controllers
