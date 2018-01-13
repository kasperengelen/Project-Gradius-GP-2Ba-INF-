//==========================================
// @brief Implementation of EntityBase.cpp
//==========================================

#include "EntityBase.hpp"

namespace game {
namespace entity {

EntityBase::EntityBase(const utils::Vec2D& pos, const float size)
	: m_pos{pos}, m_size{size}
{}

EntityBase::~EntityBase(void)
{}

const utils::Vec2D& EntityBase::get_position(void) const
{
	return m_pos;
}

void EntityBase::set_position(const utils::Vec2D& pos)
{
	m_pos = pos;
	M_notify_observers(std::make_shared<observer::EntityMove>(observer::EntityMove{this->get_position()}));
}

float EntityBase::get_size(void) const
{
	return m_size;
}

bool collides(const EntityBase& a, const EntityBase& b)
{
	const float distance = std::sqrt(std::pow(a.get_position().x - b.get_position().x, 2)
								   + std::pow(a.get_position().y - b.get_position().y, 2));

	// we add the two radii together to calculate the minimal distance
	const float needed_distance = (a.get_size() / 2.0f) + (b.get_size() / 2.0f);

	return distance <= needed_distance;
}

}} // namespace game::entity



