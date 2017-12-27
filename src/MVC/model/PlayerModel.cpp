//=========================================
// @brief Implementation of PlayerModel.hpp
//=========================================

#include "PlayerModel.hpp"

namespace game {
namespace MVC {
namespace model {

PlayerModel::PlayerModel(const sf::Vector2f& pos, const sf::Vector2f& dir, const int lives)
	: DynEntityModel{pos, dir}, m_lives{lives}
{}

PlayerModel::~PlayerModel(void)
{}

int PlayerModel::get_lives(void) const
{
	return m_lives;
}

void PlayerModel::set_lives(const int lives)
{
	m_lives = lives;
}

void PlayerModel::do_game_tick(void)
{

}


}}} // namespace game::MVC::model
