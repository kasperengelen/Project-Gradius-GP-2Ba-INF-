//==================================================
// @brief Header file for Level class.
//==================================================

#ifndef INCLUDED_LEVEL_LEVEL_HPP
#define INCLUDED_LEVEL_LEVEL_HPP

#include "../utils/Vec2D.hpp"
using game::utils::Vec2D;

#include "LevelEntity.hpp"

#include <vector>

namespace game {
namespace level {

/**
 * @brief Class that represents a game level.
 */
class Level
{
public:

private:
	// stores entities
	std::vector<LevelEntity::UnqPtr> m_data;

	// we specify the height and width with integers
	// since they need to be natural numbers.
	unsigned int m_width;
	unsigned int m_height;
public:
	/**
	 * @brief Construct a level with the specified height and width.
	 */
	Level(const unsigned int width, const unsigned int height);

	/**
	 * @brief Retrieve the height of the level.
	 */
	unsigned int get_height(void) const;

	/**
	 * @brief Retrieve the width of the level.
	 */
	unsigned int get_width(void) const;

	/**
	 * @brief Add an entity to the level.
	 */
	void add_entity(LevelEntity::UnqPtr entity_ptr);

};

}} // namespace game::level

#endif // INCLUDED_LEVEL_LEVEL_HPP
