//==============================================
// @brief Header file for PlayerModel class
//==============================================

#ifndef MVC_MODEL_PLAYERMODEL_HPP
#define MVC_MODEL_PLAYERMODEL_HPP

#include "EntityModel.hpp"

#include <memory>

namespace game {
namespace MVC {
namespace model {

class PlayerModel: public EntityModel
{
private:
public:
	using ShrPtr = std::shared_ptr<PlayerModel>;

	/**
	 * @brief Constructor.
	 *
	 * @post The constructor entity will be located at (0,0).
	 */
	PlayerModel(void);

	/**
	 * @brief Constructor based on a position.
	 */
	PlayerModel(const sf::Vector2f& pos);

	/**
	 * @brief Destructor.
	 */
	virtual ~PlayerModel(void);

	/**
	 * @brief Perform a game tick on the player model.
	 */
	void do_game_tick(void) override;
};

}}} // namespace game::MVC::model

#endif // MVC_MODEL_PLAYERMODEL_HPP
