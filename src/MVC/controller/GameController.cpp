//================================================
// @brief Implemenation of GameController.hpp
//================================================

#include "GameController.hpp"
#include "../model/GameModel.hpp"

#include <iostream>

namespace game {
namespace MVC {
namespace controller {

GameController::GameController(const model::GameModel::ShrPtr& model_ptr)
	: ControllerBase(model_ptr)
{}

GameController::~GameController(void)
{}

void GameController::handle_tick(void)
{
	std::cout << "CONTROLLER: FORWARDING GAME TICK" << std::endl;

	m_model->do_game_tick();
}

void GameController::handle_event(const sf::Event& ev)
{
	std::cout << "CONTROLLER: HANDLING EVENT" << std::endl;
}

}}} // namespace game::MVC::controller

