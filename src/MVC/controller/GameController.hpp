//=========================================================
// @brief Header file for GameController class.
//=========================================================

#ifndef INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP
#define INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP

// project includes
#include "../model/GameModel.hpp"
#include "../../IOhandlers/Keyboard.hpp"
#include "../../IOhandlers/IOEvent.hpp"

#include "EntityControllerBase.hpp"

namespace game {
namespace MVC {
namespace controller {

/**
 * @brief Controller class that encompasses the entire controller component of the game.
 */
class GameController final
{
private:
	model::GameModel::ShrPtr m_model;
	std::vector<EntityControllerBase::UnqPtr> m_entity_controllers;

public:
	using UnqPtr = std::unique_ptr<GameController>;

	/**
	 * @brief Controller specifying a pointer to a model.
	 */
	GameController(const model::GameModel::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	~GameController(void);

	/**
	 * @brief Notify the controller that a game tick has to be performed.
	 */
	void handle_tick(void);

	/**
	 * @brief Send an event to the controller.
	 */
	void handle_event(const IOhandlers::IOEvent& event);

	// TODO remove debug method
	void debug_add_entity_controller(EntityControllerBase::UnqPtr entity_controller_ptr);

};

}}} // namespace game::MVC::controller


#endif // INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP
