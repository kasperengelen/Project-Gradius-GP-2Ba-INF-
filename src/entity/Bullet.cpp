//==================================================
// @brief Implementation of Bullet.hpp.
//==================================================

#include "Bullet.hpp"

#include <sstream>

namespace game {
namespace entity {

Bullet::Bullet(const utils::Vec2D& pos,
			   const float size,
			   const utils::Vec2D& dir,
			   const int damage)
	: DynamicEntity{pos, size, dir},
	  m_damage{damage}
{}

int Bullet::get_damage(void) const
{
	return m_damage;
}

void Bullet::set_damage(const int damage)
{
	m_damage = damage;
}

void Bullet::do_game_tick(void)
{
	DynamicEntity::do_game_tick();
}

const std::string Bullet::to_string(void) const
{
	std::stringstream out;

	out << "==BULLET==" << std::endl;
	out << "Pos: " << this->get_position().to_string() << std::endl;
	out << "Size: " << this->get_size() << std::endl;
	out << "Dir: " << this->get_direction().to_string() << std::endl;
	out << "Damage: " << this->get_damage() << std::endl;

	return out.str();
}

}} // namespace game::entity








