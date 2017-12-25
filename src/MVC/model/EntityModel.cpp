//==================================================
// @brief Implementation of EntityModel.hpp
//==================================================

#include "EntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

EntityModel::EntityModel(void)
	: m_position{0.0f,0.0f}, m_direction{0.0f,0.0f}
{}

EntityModel::~EntityModel(void)
{}

const sf::Vector2f EntityModel::get_position(void) const
{
	return m_position;
}

void EntityModel::set_position(const sf::Vector2f& pos)
{
	m_position = pos;
}

const sf::Vector2f EntityModel::get_direction(void) const
{
	return m_direction;
}

void EntityModel::set_direction(const sf::Vector2f& dir)
{
	m_direction = dir;
}

}}} // namespace game::MVC::model
