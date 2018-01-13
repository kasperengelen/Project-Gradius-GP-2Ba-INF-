//==========================================================
// @brief Header file for LevelParser.
//==========================================================

#ifndef INCLUDED_LEVEL_LEVELPARSER_HPP
#define INCLUDED_LEVEL_LEVELPARSER_HPP

#include "Level.hpp"

#include <string>

namespace game {
namespace level {

Level parse_level(const std::string& json_filename);

}} // namespace game::level

#endif // INCLUDED_LEVEL_LEVELPARSER_HPP
