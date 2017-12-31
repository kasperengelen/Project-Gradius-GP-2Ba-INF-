//=========================================
// @brief Implementation of EntityController.hpp
//=========================================

#include "EntityControllerBase.hpp"

namespace game {
namespace MVC {
namespace controller {

const EntityModel* EntityControllerBase::get_model_ptr(void) const
{
	return m_modelptr.get();
}

EntityModel* EntityControllerBase::get_model_ptr(void)
{
	return m_modelptr.get();
}

EntityControllerBase::EntityControllerBase(const model::EntityModel::ShrPtr& model_ptr)
	: m_modelptr{model_ptr}
{}

EntityControllerBase::~EntityControllerBase(void)
{}

}}} // namespace game::MVC::controllers
