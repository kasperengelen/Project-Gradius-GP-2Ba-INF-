//===========================================
// @brief header file for PlayerController class.
//===========================================

#ifndef MVC_CONTROLLER_PLAYERCONTROLLER_HPP
#define MVC_CONTROLLER_PLAYERCONTROLLER_HPP

#include "EntityController.hpp"
#include "../model/PlayerModel.hpp"

namespace game {
namespace MVC {
namespace controller {

class PlayerController: public EntityController
{
private:
public:
	using UnqPtr = std::unique_ptr<PlayerController>;

	/**
	 * @brief Constructor.
	 */
	PlayerController(const model::PlayerModel::ShrPtr& player_model);

	/**
	 * @brief Destructor.
	 */
	virtual ~PlayerController(void);

	/**
	 * @brief Handle a game tick.
	 */
	virtual void handle_tick(void);

	/**
	 * @brief Handle an IOEvent.
	 */
	virtual void handle_event(const IOhandlers::IOEvent& event);
};

}}} // namespace game::MVC::controller

#endif /* MVC_CONTROLLER_PLAYERCONTROLLER_HPP_ */
