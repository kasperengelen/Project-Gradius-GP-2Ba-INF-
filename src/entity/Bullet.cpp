//==================================================
// @brief Implementation of Bullet.hpp.
//==================================================

#include "Bullet.hpp"


namespace game {
namespace entity {

Bullet::Bullet(const Vec2D& pos, const Vec2D& dir, const int damage)
	: DynamicEntity{pos, dir}, m_damage{damage}
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
	this->set_position(this->get_position() + this->get_direction());
}

}} // namespace game::entity








