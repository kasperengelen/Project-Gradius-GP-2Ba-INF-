//=================================================
// @brief Header file for LevelEntity class.
//=================================================

#ifndef INCLUDED_LEVEL_LEVELENTITY_HPP
#define INCLUDED_LEVEL_LEVELENTITY_HPP

// project includes
#include "../utils/Vec2D.hpp"

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
	utils::Vec2D m_position;
	std::string m_sprite_filename;
	float m_size;
public:
	using ShrPtr = std::shared_ptr<LevelEntity>;
	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the entity.
	 * @param[in] sprite_filename The filename of the sprite of the entity.
	 * @param[in] size The diameter of the entity.
	 */
	LevelEntity(const utils::Vec2D& pos, const std::string& sprite_filename, const float size);

	/**
	 * @brief Destructor.
	 */
	virtual ~LevelEntity(void);

	/**
	 * @brief Retrieve the position of the entity.
	 */
	const utils::Vec2D& get_position(void) const;

	/**
	 * @brief Retrieve the sprite of the entity.
	 */
	const std::string& get_sprite_filename(void) const;

	/**
	 * @brief Retrieve the size of the entity. This is the diameter of the entity.
	 */
	float get_size(void) const;
};

/**
 * @brief Contains data about the player.
 */
class LevelPlayer : public LevelEntity
{
private:
	float m_bullet_speed;
	float m_bullet_size;
	float m_max_shots_per_second;
	int m_lives;
	float m_speed;
public:
	using ShrPtr = std::shared_ptr<LevelPlayer>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the player.
	 * @param[in] sprite_filename The filename of the sprite of the player.
	 * @param[in] size The diameter of the entity.
	 * @param[in] bullet_speed The speed of the bullets that the player shoots.
	 * @param[in] bullet_size The diameter of the bullets that the player shoots.
	 * @param[in] max_shots_per_sec The maximum amount of times per second the player can shoot.
	 * @param[in] speed The speed of the player.
	 */
	LevelPlayer(const utils::Vec2D& pos,
			    const std::string& sprite_filename,
				const float size,
				const float bullet_speed,
				const float bullet_size,
				const float max_shots_per_sec,
				const int lives,
				const float speed);

	/**
	 * @brief Retrieve the speed of the player that the player shoots.
	 */
	float get_bullet_speed(void) const;

	/**
	 * @brief Retrieve the diameter of the bullets that the player shoots.
	 */
	float get_bullet_size(void) const;

	/**
	 * @brief Retrieve the amount of lives the player has.
	 */
	int get_lives(void) const;

	/**
	 * @brief Retrieve the speed of the player.
	 */
	float get_speed(void) const;

	/**
	 * @brief Retrieve the maximum amount of times per second a player can shoot.
	 */
	float get_max_shots_per_second(void) const;
};

/**
 * @brief Contains data about an enemy in the level.
 */
class LevelEnemy : public LevelEntity
{
private:
	utils::Vec2D m_direction;
	float m_bullet_speed;
	float m_bullet_size;
	float m_max_shots_per_second;
	int m_attack_damage;
public:
	using ShrPtr = std::shared_ptr<LevelEnemy>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the enemy.
	 * @param[in] sprite_filename The filename of the sprite of the enemy.
	 * @param[in] size The diameter of the entity.
	 * @param[in] dir The direction vector of the enemy.
	 * @param[in] bullet_speed The speed of the bullets that the player shoots.
	 * @param[in] bullet_size The diameter of the bullets that the player shoots.
	 * @param[in] max_shots_per_sec The maximum amount of times per second the player can shoot.
	 * @param[in] attack_damage The amount of lives the player loses when hit by the enemy.
	 */
	LevelEnemy(const utils::Vec2D& pos,
			   const std::string& sprite_filename,
			   const float size,
			   const utils::Vec2D& dir,
			   const float bullet_speed,
			   const float bullet_size,
			   const float max_shots_per_sec,
			   const int attack_damage);

	/**
	 * @brief Retrieve the speed of the enemy that the player shoots.
	 */
	float get_bullet_speed(void) const;

	/**
	 * @brief Retrieve the diameter of the bullets that the enemy shoots.
	 */
	float get_bullet_size(void) const;

	/**
	 * @brief Retrieve the direction vector of the enemy.
	 */
	const utils::Vec2D& get_direction(void) const;

	/**
	 * @brief Retrieve the attack damage of the enemy. This is the amount of lives the player will lose
	 * when hit by the enemy.
	 */
	int get_attack_damage(void) const;

	/**
	 * @brief Retrieve the maximum amount of times per second a player can shoot.
	 */
	float get_max_shots_per_second(void) const;
};

/**
 * @brief Contains data about an obstacle in the level.
 */
class LevelObstacle : public LevelEntity
{
private:
	int m_collision_penalty;
public:
	using ShrPtr = std::shared_ptr<LevelObstacle>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the obstacle.
	 * @param[in] sprite_filename The filename of the sprite of the obstacle.
	 * @param[in] size The diameter of the entity.
	 * @param[in] collision_penalty The amount of lives the player loses on collision with the obstacle.
	 */
	LevelObstacle(const utils::Vec2D& pos,
			      const std::string& sprite_filename,
				  const float size,
				  const int collision_penalty);

	/**
	 * @brief Retrieve the collision penalty of the obstacle. This is the amount of lives the player loses
	 * when it crashes into the obstacle.
	 */
	int get_collision_penalty(void) const;

};

/**
 * @brief Contains data about a finish line in the level.
 */
class LevelFinishLine : public LevelEntity
{
public:
	using ShrPtr = std::shared_ptr<LevelFinishLine>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the finish line.
	 * @param[in] sprite_filename The filename of the sprite of the finish line.
	 * @param[in] size The diameter of the entity.
	 */
	LevelFinishLine(const utils::Vec2D& pos,
					const std::string& sprite_filename,
					const float size);

};

}} // namespace game::level

#endif // INCLUDED_LEVEL_LEVELENTITY_HPP
