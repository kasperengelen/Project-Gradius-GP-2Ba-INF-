//===============================================
// @brief Implementation of DynamicEntity.cpp.
//===============================================

#include "DynamicEntity.hpp"

namespace game {
namespace entity {

DynamicEntity::DynamicEntity(const utils::Vec2D& pos, const float size, const utils::Vec2D& dir)
	: EntityBase{pos, size}, m_dir{dir}
{}

DynamicEntity::~DynamicEntity(void)
{}

const utils::Vec2D& DynamicEntity::get_direction(void) const
{
	return m_dir;
}

void DynamicEntity::set_direction(const utils::Vec2D& dir)
{
	m_dir = dir;
}

void DynamicEntity::do_game_tick(void)
{
	this->set_position(this->get_position() + this->get_direction());
}

}} // namespace game::entity

