//========================================================
// @brief Implementation of Obstacle.hpp.
//========================================================

#include "Obstacle.hpp"

namespace game {
namespace entity {

Obstacle::Obstacle(const Vec2D& pos, const int coll_penalty)
	: EntityBase{pos}, m_coll_penalty{coll_penalty}
{}

int Obstacle::get_penalty(void) const
{
	return m_coll_penalty;
}

void Obstacle::set_penalty(const int penalty)
{
	m_coll_penalty = penalty;
}

}} // namespace game::entity


