//========================================================
// @brief Implementation of Obstacle.hpp.
//========================================================

#include "Obstacle.hpp"
#include <sstream>

namespace game {
namespace entity {

Obstacle::Obstacle(const utils::Vec2D& pos,
				   const float size,
				   const int coll_penalty)
	: EntityBase{pos, size},
	  m_coll_penalty{coll_penalty}
{}

int Obstacle::get_penalty(void) const
{
	return m_coll_penalty;
}

void Obstacle::set_penalty(const int penalty)
{
	m_coll_penalty = penalty;
}

void Obstacle::do_game_tick(void)
{}

const std::string Obstacle::to_string(void) const
{
	std::stringstream out;

	out << "==OBSTACLE==" << std::endl;
	out << "Pos: " << this->get_position().to_string() << std::endl;
	out << "Size: " << this->get_size() << std::endl;
	out << "CollisionPenalty: " << this->get_penalty() << std::endl;

	return out.str();
}

}} // namespace game::entity


