//==================================================
// @brief Implementation of FinishLine.hpp.
//==================================================

#include "FinishLine.hpp"
#include <sstream>

namespace game {
namespace entity {

FinishLine::FinishLine(const utils::Vec2D& pos,
		   	   	   	   const float size)
	: EntityBase{pos, size}
{}

void FinishLine::do_game_tick(void)
{}

const std::string FinishLine::to_string(void) const
{
	std::stringstream out;

	out << "==FINISH==" << std::endl;
	out << "Pos: " << this->get_position().to_string() << std::endl;
	out << "Size: " << this->get_size() << std::endl;

	return out.str();
}

}} // namespace game::entity


