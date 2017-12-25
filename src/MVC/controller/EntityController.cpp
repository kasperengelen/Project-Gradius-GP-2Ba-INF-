//==================================================
// @brief Implementation of EntityController.hpp
//==================================================

#include "EntityController.hpp"

namespace game {
namespace MVC {
namespace controller {

EntityController::EntityController(const model::EntityModel::ShrPtr& model_ptr)
	: m_model{model_ptr}
{}

EntityController::~EntityController(void)
{}

}}} // namespace game::MVC::controller
