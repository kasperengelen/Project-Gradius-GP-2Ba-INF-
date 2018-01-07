//=========================================
// @brief Implementation of Player.hpp
//=========================================

#include <iostream>
#include "Player.hpp"

namespace game {
namespace entity {

Player::Player(const Vec2D& pos, const int lives)
	: DynamicEntity{pos, Vec2D{0,0}}, m_lives{lives}
{}

Player::~Player(void)
{}

int Player::get_lives(void) const
{
	return m_lives;
}

void Player::set_lives(const int lives)
{
	m_lives = lives;
}

void Player::do_game_tick(void)
{
	// do movement
	this->set_position(this->get_position() + this->get_direction());
}

}} // namespace game::entity


