//===============================================
// @brief Implementation of DynamicEntity.cpp.
//===============================================

#include "DynamicEntity.hpp"

namespace game {
namespace entity {

DynamicEntity::DynamicEntity(const Vec2D& pos, const Vec2D& dir)
	: EntityBase{pos}, m_dir{dir}
{}

DynamicEntity::~DynamicEntity(void)
{}

const Vec2D& DynamicEntity::get_direction(void) const
{
	return m_dir;
}

void DynamicEntity::set_direction(const Vec2D& dir)
{
	m_dir = dir;
}

}} // namespace game::entity

