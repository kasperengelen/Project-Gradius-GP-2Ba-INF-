//==========================================
// @brief Implementation of Enemy.hpp
//==========================================

#include "Enemy.hpp"
#include <sstream>

namespace game {
namespace entity {

Enemy::Enemy(const utils::Vec2D& pos,
			 const float size,
			 const utils::Vec2D& dir,
			 const float bullet_speed,
			 const float bullet_size,
			 const float max_shots_per_second,
			 const int attack_damage)
	: ShootingEntity{pos, size, dir, bullet_speed, bullet_size, max_shots_per_second},
	  m_attack_damage{attack_damage}
{}

Enemy::~Enemy(void)
{}

int Enemy::get_attack_damage(void) const
{
	return m_attack_damage;
}

void Enemy::set_attack_damage(const int attack_damage)
{
	m_attack_damage = attack_damage;
}

void Enemy::do_game_tick(void)
{
	DynamicEntity::do_game_tick();
	ShootingEntity::do_game_tick();
}

std::string Enemy::to_string(void) const
{
	std::stringstream out;

	out << "==ENEMY==" << std::endl;
	out << "Pos: " << this->get_position().to_string() << std::endl;
	out << "Size: " << this->get_size() << std::endl;
	out << "Dir: " << this->get_direction().to_string() << std::endl;
	out << "BulletSpeed: " << this->get_bullet_speed() << std::endl;
	out << "BulletSize: " << this->get_bullet_size() << std::endl;
	out << "MaxShotsPerSec: " << this->get_max_shots_per_second() << std::endl;

	return out.str();
}

}} // namespace game::entity

