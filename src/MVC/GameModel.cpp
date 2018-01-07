//======================================================
// @brief Implementation of GameModel.hpp
//======================================================

#include "GameModel.hpp"

#include <iostream>

namespace game {
namespace MVC {

GameModel::GameModel(void)
{}

GameModel::~GameModel(void)
{}

void GameModel::do_game_tick(void)
{
	// forward game tick
	for(const EntityBase::ShrPtr& model_ptr : m_entity_models)
	{
		model_ptr->do_game_tick();
	}

	// forward game tick to player
	m_player->do_game_tick();

	// forward game tick to enemies

	// forward game tick to obstacles


}

void GameModel::set_player(const Player::ShrPtr& player_ptr)
{
	m_player = player_ptr;
}

void GameModel::set_player_direction(const Vec2D& dir)
{
	m_player->set_direction(dir);
}

const Vec2D GameModel::get_player_position(void) const
{
	return m_player->get_position();
}

const Vec2D GameModel::get_player_direction(void) const
{
	return m_player->get_direction();
}

void GameModel::clear_entity_models(void)
{
	m_entity_models.clear();
}

void GameModel::debug_add_entity_model(const EntityBase::ShrPtr& entity_model_ptr)
{
	m_entity_models.push_back(entity_model_ptr);
}


}} // namespace game::MVC

