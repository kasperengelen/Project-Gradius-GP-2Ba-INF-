//=========================================================
// @brief Header file for GameController class.
//=========================================================

#ifndef INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP
#define INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP

#include "../controller/ControllerBase.hpp"
#include "../model/GameModel.hpp"

namespace game {
namespace MVC {
namespace controller {

/**
 * @brief Controller class that encompasses the entire controller component of the game.
 */
class GameController final: public ControllerBase
{
private:

public:
	/**
	 * @brief Controller specifying a pointer to a model.
	 */
	GameController(const model::GameModel::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	virtual ~GameController(void);

	/**
	 * @brief Notify the controller that a game tick has to be performed.
	 */
	void handle_tick(void) override final;

	/**
	 * @brief Send an event to the controller.
	 */
	void handle_event(const IOhandlers::IOEvent& event) override final;
};

}}} // namespace game::MVC::controller


#endif // INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP
