//==================================================
// @brief Implementation of BulletModel.hpp.
//==================================================

#include "BulletModel.hpp"


namespace game {
namespace MVC {
namespace model {


BulletModel::BulletModel(const sf::Vector2f& pos, const sf::Vector2f& dir, const int damage)
	: DynEntityModel{pos, dir}, m_damage{damage}
{

}

int BulletModel::get_damage(void) const
{
	return m_damage;
}

void BulletModel::set_damage(const int damage)
{
	m_damage = damage;
}

void BulletModel::do_game_tick(void)
{
	this->set_position(this->get_position() + this->get_direction());
}

}}} // namespace game::MVC::model








