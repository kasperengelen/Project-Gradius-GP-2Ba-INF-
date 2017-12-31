//================================================
// @brief Implemenation of GameController.hpp
//================================================

#include "GameController.hpp"
#include "../model/GameModel.hpp"

#include <iostream>

namespace game {
namespace MVC {
namespace controller {

GameController::GameController(const model::GameModel::ShrPtr& model_ptr)
	: m_model{model_ptr}
{}

GameController::~GameController(void)
{}

void GameController::handle_tick(void)
{
	using IOhandlers::Keyboard;

	// forward game tick
	for(const auto& ent_ctrl: m_entity_controllers)
	{
		ent_ctrl->handle_game_tick();
	}

	m_model->do_game_tick();
}

/**
 * NOTE: actually we don't fully "handle" the events here, we only update our IO systems. The tick handler
 * will update the model to accomodate for IO infuence on the model.
 */
void GameController::handle_event(const IOhandlers::IOEvent& event)
{
	// update keyboard
	switch(event.get_type())
	{
	case IOhandlers::IOEvent::EventType::KEY_UP:
		IOhandlers::Keyboard::get_instance().release_key(event.get_key());
		break;

	case IOhandlers::IOEvent::EventType::KEY_DOWN:
		if(not IOhandlers::Keyboard::get_instance().get_key_state(event.get_key()))
		{
			IOhandlers::Keyboard::get_instance().press_key(event.get_key());
		}
		break;

	case IOhandlers::IOEvent::EventType::MOUSE_UP:

		break;

	case IOhandlers::IOEvent::EventType::MOUSE_DOWN:

		break;

	case IOhandlers::IOEvent::EventType::MOUSE_MOVE:

		break;

	case IOhandlers::IOEvent::EventType::WINDOW_CLOSE:

		break;
	default:
		break;
	}

	// forward event to sub controllers.

	for(const auto& ent_ctrl: m_entity_controllers)
	{
		ent_ctrl->handle_ioevent(event);
	}

}

void GameController::debug_add_entity_controller(EntityControllerBase::UnqPtr entity_controller_ptr)
{
	m_entity_controllers.push_back(std::move(entity_controller_ptr));
}


}}} // namespace game::MVC::controller





