//==========================================
// @brief Implementation of Enemy.hpp
//==========================================

#include "Enemy.hpp"

namespace game {
namespace entity {

Enemy::Enemy(const Vec2D& pos, const Vec2D& dir)
	: DynamicEntity{pos, dir}
{}

Enemy::~Enemy(void)
{}

void Enemy::do_game_tick(void)
{
	this->set_position(this->get_position() + this->get_direction());
}

}} // namespace game::entity

