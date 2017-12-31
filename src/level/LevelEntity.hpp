//=================================================
// @brief Header file for LevelEntity class.
//=================================================

#ifndef INCLUDED_LEVEL_LEVELENTITY_HPP
#define INCLUDED_LEVEL_LEVELENTITY_HPP

// project includes
#include "../utils/Vec2D.hpp"
using game::utils::Vec2D;

// std includes
#include <string>
#include <memory>

namespace game {
namespace level {

/**
 * @brief Contains data about the entity present in the level.
 */
class LevelEntity
{
private:
	Vec2D m_position;
	std::string m_sprite_filename;
public:
	using UnqPtr = std::unique_ptr<LevelEntity>;
	/**
	 * @brief Constructor for an entity based on a position, a sprite filename, and a sprite scale.
	 */
	LevelEntity(const Vec2D& pos, const std::string& sprite_filename);

	/**
	 * @brief Retrieve the position of the entity.
	 */
	const Vec2D& get_position(void) const;

	/**
	 * @brief Retrieve the sprite of the entity.
	 */
	const std::string& get_sprite_filename(void) const;
};

/**
 * @brief Contains data about the player.
 */
class LevelPlayer : public LevelEntity
{
private:
	int m_lives;
	float m_maxspeed;
public:
	/**
	 * @brief Construct a player based on a position, a sprite filename, a maximum speed and an amount of lives.
	 */
	LevelPlayer(const Vec2D& pos, const std::string& sprite_filename, const int lives, const float max_speed);

	/**
	 * @brief Retrieve the maximum speed of the player.
	 */
	int get_lives(void) const;

	/**
	 * @brief Retrieve the mount
	 */
	float get_max_speed(void) const;
};

/**
 * @brief Contains data about an enemy in the level.
 */
class LevelEnemy : public LevelEntity
{
private:
	Vec2D m_direction;
	int m_attack_damage;
public:
	/**
	 * @brief Construct an enemy based on a position, a sprite filename, direction vector and attack damage.
	 */
	LevelEnemy(const Vec2D& pos, const std::string& sprite_filename, const Vec2D& dir, const int attack_damage);

	/**
	 * @brief Retrieve the direction vector of the enemy.
	 */
	const Vec2D& get_direction(void) const;

	/**
	 * @brief Retrieve the attack damage of the enemy. This is the amount of lives the player will lose
	 * when hit by the enemy.
	 */
	int get_attack_damage(void) const;
};

/**
 * @brief Contains data about an obstacle in the level.
 */
class LevelObstacle : public LevelEntity
{
private:
	int m_collision_penalty;
public:
	/**
	 * @brief Construct an obstacle based on a position, a sprite filename and collision penalty.
	 */
	LevelObstacle(const Vec2D& pos, const std::string& sprite_filename, const int collision_penalty);

	/**
	 * @brief Retrieve the collision penalty of the obstacle. This is the amount of lives the player loses
	 * when it crashes into the obstacle.
	 */
	int get_collision_penalty(void) const;

};

}} // namespace game::level

#endif // INCLUDED_LEVEL_LEVELENTITY_HPP
