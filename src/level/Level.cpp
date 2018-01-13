//===================================
// @brief Implementation of Level.hpp
//===================================

// header
#include "Level.hpp"

// project includes
#include "../exception/LevelException.hpp"

// library includes
#include "../lib/json.hpp"
using nlohmann::json;

// std includes
#include <iostream>
#include <fstream>

namespace game {
namespace level {

Level::Level(const unsigned int width,
			 const unsigned int height,
			 const float max_x,
			 const float max_y)
	: m_width{width},
	  m_height{height},
	  m_max_x_coord_on_screen{max_x},
	  m_max_y_coord_on_screen{max_y}
{}

unsigned int Level::get_height(void) const
{
	return m_height;
}

unsigned int Level::get_width(void) const
{
	return m_width;
}

float Level::get_max_x_coord(void) const
{
	return m_max_x_coord_on_screen;
}

float Level::get_max_y_coord(void) const
{
	return m_max_y_coord_on_screen;
}

void Level::add_entity(const LevelEntity::ShrPtr& entity_ptr)
{
	m_data.push_back(entity_ptr);
}

const Level::ConstIterator Level::begin(void) const
{
	return m_data.cbegin();
}

const Level::ConstIterator Level::end(void) const
{
	return m_data.cend();
}

}} // namespace game::level

