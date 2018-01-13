//=========================================
// @brief Implementation of Player.hpp
//=========================================

#include "Player.hpp"
#include "../utils/CoordTransform.hpp"

#include <iostream>
#include <sstream>

namespace game {
namespace entity {

Player::Player(const utils::Vec2D& pos,
			   const float size,
			   const float bullet_speed,
			   const float bullet_size,
			   const float max_shots_per_sec,
			   const int lives,
			   const float speed)
	: ShootingEntity{pos, size, utils::Vec2D{0,0}, bullet_speed, bullet_size, max_shots_per_sec},
	  m_lives{lives},
	  m_speed{speed}
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

float Player::get_speed(void) const
{
	return m_speed;
}

void Player::do_game_tick(void)
{
	DynamicEntity::do_game_tick();
	ShootingEntity::do_game_tick();

	utils::CoordTransform::get_instance().update_player_pos(this->get_position());
}

const std::string Player::to_string(void) const
{
	std::stringstream out;

	out << "==PLAYER==" << std::endl;
	out << "Pos: " << this->get_position().to_string() << std::endl;
	out << "Size: " << this->get_size() << std::endl;
	out << "BulletSpeed: " << this->get_bullet_speed() << std::endl;
	out << "BulletSize: " << this->get_bullet_size() << std::endl;
	out << "MaxShotsPerSec: " << this->get_max_shots_per_second() << std::endl;
	out << "Lives: " << this->get_lives() << std::endl;
	out << "Speed: " << this->get_speed() << std::endl;

	return out.str();
}

}} // namespace game::entity


