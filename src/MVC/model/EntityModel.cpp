//==========================================
// @brief Implementation of EntityModel.cpp
//==========================================

#include "EntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

EntityModel::EntityModel(const sf::Vector2f& pos)
	: m_pos{pos}
{}

EntityModel::~EntityModel(void)
{}

const sf::Vector2f& EntityModel::get_position(void) const
{
	return m_pos;
}

void EntityModel::set_position(const sf::Vector2f& pos)
{
	m_pos = pos;
}

}}} // namespace game::MVC::model
