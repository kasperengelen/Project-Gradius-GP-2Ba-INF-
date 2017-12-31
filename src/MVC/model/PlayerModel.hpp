//================================================
// @brief Header file for PlayerModel class.
//================================================

#ifndef INCLUDED_MVC_MODEL_PLAYERMODEL_HPP
#define INCLUDED_MVC_MODEL_PLAYERMODEL_HPP

#include "DynEntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Model class for Player entity.
 */
class PlayerModel final : public DynEntityModel
{
private:
	int m_lives;
public:
	using ShrPtr = std::shared_ptr<PlayerModel>;

	/**
	 * @brief Constructor based on a position, direction vector and a number of lives.
	 *
	 */
	PlayerModel(const sf::Vector2f& pos, const int lives);

	/**
	 * @brief Destructor.
	 */
	~PlayerModel(void);

	/**
	 * @brief Retrieve the amount of lives the player has.
	 */
	int get_lives(void) const;

	/**
	 * @brief Set the mount of lives the player has.
	 */
	void set_lives(const int lives);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_PLAYERMODEL_HPP

