//=================================================
// @brief Header file for BulletModel class.
//=================================================

#ifndef INCLUDED_MVC_MODEL_BULLETMODEL_HPP
#define INCLUDED_MVC_MODEL_BULLETMODEL_HPP

#include "DynEntityModel.hpp"

#include <SFML/Graphics.hpp>

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Class that represents a bullet.
 */
class BulletModel : public DynEntityModel
{
private:
	int m_damage;
public:
	/**
	 * @brief Construct bullet based on a position, direction, amount of damage.
	 */
	BulletModel(const sf::Vector2f& pos, const sf::Vector2f& dir, const int damage);

	/**
	 * @brief Retrieve the damage of the bullet.
	 */
	int get_damage(void) const;

	/**
	 * @brief Set the damage of the bullet.
	 */
	void set_damage(const int damage);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;
};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_BULLETMODEL_HPP


