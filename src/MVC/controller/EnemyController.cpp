//===========================================
// @brief Implementation of EnemyController.hpp
//===========================================

#include "EnemyController.hpp"

namespace game {
namespace MVC {
namespace controller {

EnemyController::EnemyController(const model::EnemyModel::ShrPtr& model_ptr)
	: EntityController{model_ptr}
{}

EnemyController::~EnemyController(void)
{}

void EnemyController::handle_tick(void)
{}

void EnemyController::handle_event(const IOhandlers::IOEvent& event)
{}

}}} // namespace game::MVC::controller
