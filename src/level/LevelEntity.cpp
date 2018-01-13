//=================================================
// @brief Implementation of LevelEntity.hpp.
//=================================================

#include "LevelEntity.hpp"

namespace game {
namespace level {

///////////////////////////////////////////
// LevelEntity
///////////////////////////////////////////

LevelEntity::LevelEntity(const utils::Vec2D& pos,
						 const std::string& sprite_filename,
						 const float size)
	: m_position{pos},
	  m_sprite_filename{sprite_filename},
	  m_size{size}
{}

LevelEntity::~LevelEntity(void)
{

}

const utils::Vec2D& LevelEntity::get_position(void) const
{
	return m_position;
}

const std::string& LevelEntity::get_sprite_filename(void) const
{
	return m_sprite_filename;
}

float LevelEntity::get_size(void) const
{
	return m_size;
}

///////////////////////////////////////////
// LevelPlayer
///////////////////////////////////////////

LevelPlayer::LevelPlayer(const utils::Vec2D& pos,
						 const std::string& sprite_filename,
						 const float size,
						 const float bullet_speed,
						 const float bullet_size,
						 const float max_shots_per_second,
						 const int lives,
						 const float speed)
	: LevelEntity{pos, sprite_filename, size},
	  m_bullet_speed{bullet_speed},
	  m_bullet_size{bullet_size},
	  m_max_shots_per_second{max_shots_per_second},
	  m_lives{lives},
	  m_speed{speed}
{}

float LevelPlayer::get_bullet_speed(void) const
{
	return m_bullet_speed;
}

float LevelPlayer::get_bullet_size(void) const
{
	return m_bullet_size;
}

int LevelPlayer::get_lives(void) const
{
	return m_lives;
}

float LevelPlayer::get_speed(void) const
{
	return m_speed;
}

float LevelPlayer::get_max_shots_per_second(void) const
{
	return m_max_shots_per_second;
}

///////////////////////////////////////////
// LevelEnemy
///////////////////////////////////////////

LevelEnemy::LevelEnemy(const utils::Vec2D& pos,
					   const std::string& sprite_filename,
					   const float size,
					   const utils::Vec2D& dir,
					   const float bullet_speed,
					   const float bullet_size,
					   const float max_shots_per_second,
					   const int attack_damage)
	: LevelEntity{pos, sprite_filename, size},
	  m_direction{dir},
	  m_bullet_speed{bullet_speed},
	  m_bullet_size{bullet_size},
	  m_max_shots_per_second{max_shots_per_second},
	  m_attack_damage{attack_damage}
{}

float LevelEnemy::get_bullet_speed(void) const
{
	return m_bullet_speed;
}

float LevelEnemy::get_bullet_size(void) const
{
	return m_bullet_size;
}

const utils::Vec2D& LevelEnemy::get_direction(void) const
{
	return m_direction;
}

int LevelEnemy::get_attack_damage(void) const
{
	return m_attack_damage;
}

float LevelEnemy::get_max_shots_per_second(void) const
{
	return m_max_shots_per_second;
}

///////////////////////////////////////////
// LevelObstacle
///////////////////////////////////////////

LevelObstacle::LevelObstacle(const utils::Vec2D& pos,
							 const std::string& sprite_filename,
							 const float size,
							 const int collision_penalty)
	: LevelEntity{pos, sprite_filename, size},
	  m_collision_penalty{collision_penalty}
{}

int LevelObstacle::get_collision_penalty(void) const
{
	return m_collision_penalty;
}

///////////////////////////////////////////
// LevelFinishLine
///////////////////////////////////////////

LevelFinishLine::LevelFinishLine(const utils::Vec2D& pos,
								 const std::string& sprite_filename,
								 const float size)
	: LevelEntity{pos, sprite_filename, size}
{}

}} // namespace game::level



