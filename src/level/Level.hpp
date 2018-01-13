//==================================================
// @brief Header file for Level class.
//==================================================

#ifndef INCLUDED_LEVEL_LEVEL_HPP
#define INCLUDED_LEVEL_LEVEL_HPP

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
	std::vector<LevelEntity::ShrPtr> m_data;

	// we specify the height and width with integers
	// since they need to be natural numbers.
	unsigned int m_width;
	unsigned int m_height;

	// whats the range of x and y coordinates that are rendered on screen.
	float m_max_x_coord_on_screen;
	float m_max_y_coord_on_screen;
public:
	using ConstIterator = std::vector<LevelEntity::ShrPtr>::const_iterator;

	/**
	 * @brief Construct a level with the specified height and width.
	 *
	 * @param[in] width of the level.
	 * @param[in] height of the level.
	 * @param[in] max_x Range of horizontal coordinates that will be displayed on screen.
	 * @param[in] max_y Range of vertical coordinates that will be displayed on screen.
	 */
	Level(const unsigned int width,
		  const unsigned int height,
		  const float max_x,
		  const float max_y);

	/**
	 * @brief Retrieve the height of the level.
	 */
	unsigned int get_height(void) const;

	/**
	 * @brief Retrieve the width of the level.
	 */
	unsigned int get_width(void) const;

	/**
	 * @brief Retrieve the maximum horizontal model coordinate that is rendered on screen.
	 */
	float get_max_x_coord(void) const;

	/**
	 * @brief Retrieve the maximum vertical model coordinate that is rendered on screen.
	 */
	float get_max_y_coord(void) const;

	/**
	 * @brief Add an entity to the level.
	 */
	void add_entity(const LevelEntity::ShrPtr& entity_ptr);

	/**
	 * @brief Iterator that marks the beginning.
	 */
	const ConstIterator begin(void) const;

	/**
	 * @brief Iterator that marks one past the end.
	 */
	const ConstIterator end(void) const;
};

}} // namespace game::level

#endif // INCLUDED_LEVEL_LEVEL_HPP
