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

EnemyModel::~EnemyModel(void)
{}

void EnemyModel::do_game_tick(void)
{
	this->set_position(this->get_position() + this->get_direction());
}

}}} // namespace game::MVC::model

