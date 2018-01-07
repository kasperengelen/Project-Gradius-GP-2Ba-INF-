//==========================================
// @brief Implementation of EntityBase.cpp
//==========================================

#include "EntityBase.hpp"

namespace game {
namespace entity {

EntityBase::EntityBase(const Vec2D& pos)
	: m_pos{pos}
{}

EntityBase::~EntityBase(void)
{}

const Vec2D& EntityBase::get_position(void) const
{
	return m_pos;
}

void EntityBase::set_position(const Vec2D& pos)
{
	m_pos = pos;
}

}} // namespace game::entity
