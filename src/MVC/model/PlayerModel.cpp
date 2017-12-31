//=========================================
// @brief Implementation of PlayerModel.hpp
//=========================================

#include "PlayerModel.hpp"

#include <iostream>

namespace game {
namespace MVC {
namespace model {

PlayerModel::PlayerModel(const sf::Vector2f& pos, const int lives)
	: DynEntityModel{pos, sf::Vector2f{0,0}}, m_lives{lives}
{}

PlayerModel::~PlayerModel(void)
{}

int PlayerModel::get_lives(void) const
{
	return m_lives;
}

void PlayerModel::set_lives(const int lives)
{
	m_lives = lives;
}

void PlayerModel::do_game_tick(void)
{
	// do movement
	this->set_position(this->get_position() + this->get_direction());
}


}}} // namespace game::MVC::model
