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

Level::Level(const unsigned int width, const unsigned int height)
	: m_width{width}, m_height{height}
{}

unsigned int Level::get_height(void) const
{
	return m_height;
}

unsigned int Level::get_width(void) const
{
	return m_width;
}

void Level::add_entity(LevelEntity::UnqPtr entity_ptr)
{
	m_data.push_back(std::move(entity_ptr));
}

}} // namespace game::level

