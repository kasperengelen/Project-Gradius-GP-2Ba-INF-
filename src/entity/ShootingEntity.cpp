//===================================================
// @brief Implementation of ShootingEntity.hpp.
//===================================================

#include "ShootingEntity.hpp"

namespace game {
namespace entity {

ShootingEntity::ShootingEntity(const utils::Vec2D& pos,
			       const float size,
				   const utils::Vec2D& dir,
				   const float bullet_speed,
				   const float bullet_size,
				   const float max_shots_per_second)
	: DynamicEntity{pos, size, dir},
	  m_bullet_speed{bullet_speed},
	  m_bullet_size{bullet_size},
	  m_max_shots_per_second{max_shots_per_second},
	  m_ticks_since_last_shot{0}
{}

float ShootingEntity::get_bullet_speed(void) const
{
	return m_bullet_speed;
}

float ShootingEntity::get_bullet_size(void) const
{
	return m_bullet_size;
}

void ShootingEntity::do_game_tick(void)
{
	m_ticks_since_last_shot++;
}

void  ShootingEntity::shoot(void)
{
	m_ticks_since_last_shot = 0;
}

bool ShootingEntity::can_shoot(void) const
{
	const float ticks_per_shot = 20.0f / m_max_shots_per_second;

	return (float) m_ticks_since_last_shot > ticks_per_shot;
}

float ShootingEntity::get_max_shots_per_second(void) const
{
	return m_max_shots_per_second;
}


}} // namespace game::entity
