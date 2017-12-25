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
}

void GameModel::debug_add_entity_model(const EntityModel::ShrPtr& entity_model_ptr)
{
	m_entity_models.push_back(entity_model_ptr);
}

}}} // namespace game::MVC::model

