//==================================================
// @brief Header file for ObstacleModel class
//==================================================

#ifndef INCLUDED_MVC_MODEL_OBSTACLEMODEL_HPP
#define INCLUDED_MVC_MODEL_OBSTACLEMODEL_HPP

#include "EntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Entity that is an obstacle.
 */
class ObstacleModel : public EntityModel
{
private:
	int m_coll_penalty;
public:
	/**
	 * @brief Constructor based on a position and a collision penalty.
	 */
	ObstacleModel(const sf::Vector2f& pos, const int coll_penalty);

	/**
	 * @brief Get the amount of lives the player loses on collision.
	 */
	int get_penalty(void) const;

	/**
	 * @brief Set the mount of lives the player loses on collision.
	 */
	void set_penalty(const int penalty);

};


}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_OBSTACLEMODEL_HPP
