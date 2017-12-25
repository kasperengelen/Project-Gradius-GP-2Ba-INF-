//===========================================
// @brief Implementation of PlayerModel.hpp
//===========================================

#include "PlayerModel.hpp"
#include "iostream"

namespace game {
namespace MVC {
namespace model {


PlayerModel::PlayerModel(void)
{}

PlayerModel::PlayerModel(const sf::Vector2f& pos)
{
	this->set_position(pos);
}

PlayerModel::~PlayerModel(void)
{}

void PlayerModel::do_game_tick(void)
{
	// update position based on speed

	m_position.x += m_direction.x;
	m_position.y += m_direction.y;
}

}}} // namespace game::MVC::model
