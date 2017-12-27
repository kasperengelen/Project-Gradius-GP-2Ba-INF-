//==========================================
// @brief Implementation of EnemyModel.hpp
//==========================================

#include "EnemyModel.hpp"

namespace game {
namespace MVC {
namespace model {

EnemyModel::EnemyModel(const sf::Vector2f& pos, const sf::Vector2f& dir)
	: DynEntityModel{pos, dir}
{}

void EnemyModel::do_game_tick(void)
{

}

}}} // namespace game::MVC::model

