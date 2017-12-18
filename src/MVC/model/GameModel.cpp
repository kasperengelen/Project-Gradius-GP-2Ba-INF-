//======================================================
// @brief Implementation of GameModel.hpp
//======================================================

#include "GameModel.hpp"

#include <iostream>

namespace game {
namespace MVC {
namespace model {

GameModel::GameModel(void)
{}

GameModel::~GameModel(void)
{}

void GameModel::do_game_tick(void)
{
	std::cout << "MODEL: GAME TICK PERFORMED." << std::endl;
}

}}} // namespace game::MVC::model

