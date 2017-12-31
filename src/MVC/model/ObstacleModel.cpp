//========================================================
// @brief Implementation of ObstacleModel.hpp.
//========================================================

#include "ObstacleModel.hpp"

namespace game {
namespace MVC {
namespace model {

ObstacleModel::ObstacleModel(const sf::Vector2f& pos, const int coll_penalty)
	: EntityModel{pos}, m_coll_penalty{coll_penalty}
{}

int ObstacleModel::get_penalty(void) const
{
	return m_coll_penalty;
}

void ObstacleModel::set_penalty(const int penalty)
{
	m_coll_penalty = penalty;
}

}}} // namespace game::MVC::model


