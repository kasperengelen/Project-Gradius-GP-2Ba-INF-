//=================================================
// @brief Implementation of LevelEntity.hpp.
//=================================================

#include "LevelEntity.hpp"

namespace game {
namespace level {

LevelEntity::LevelEntity(const Vec2D& pos, const std::string& sprite_filename)
	: m_position{pos}, m_sprite_filename{sprite_filename}
{}

const Vec2D& LevelEntity::get_position(void) const
{
	return m_position;
}

const std::string& LevelEntity::get_sprite_filename(void) const
{
	return m_sprite_filename;
}

LevelPlayer::LevelPlayer(const Vec2D& pos, const std::string& sprite_filename, const int lives, const float max_speed)
	: LevelEntity{pos, sprite_filename}, m_lives{lives}, m_maxspeed{max_speed}
{}

int LevelPlayer::get_lives(void) const
{
	return m_lives;
}

float LevelPlayer::get_max_speed(void) const
{
	return m_maxspeed;
}

LevelEnemy::LevelEnemy(const Vec2D& pos, const std::string& sprite_filename, const Vec2D& dir, const int attack_damage)
	: LevelEntity{pos, sprite_filename}, m_direction{dir}, m_attack_damage{attack_damage}
{}

const Vec2D& LevelEnemy::get_direction(void) const
{
	return m_direction;
}

int LevelEnemy::get_attack_damage(void) const
{
	return m_attack_damage;
}

LevelObstacle::LevelObstacle(const Vec2D& pos, const std::string& sprite_filename, const int collision_penalty)
	: LevelEntity{pos, sprite_filename}, m_collision_penalty{collision_penalty}
{}

int LevelObstacle::get_collision_penalty(void) const
{
	return m_collision_penalty;
}


}} // namespace game::level
