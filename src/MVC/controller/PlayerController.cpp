//==============================================
// @brief Implementation of PlayerController.hpp
//==============================================

#include "PlayerController.hpp"
// TODO remove
#include "GameController.hpp"
#include <iostream>

namespace game {
namespace MVC {
namespace controller {

PlayerController::PlayerController(const model::PlayerModel::ShrPtr& player_model)
	: EntityController(player_model)
{}

PlayerController::~PlayerController(void)
{}

void PlayerController::handle_tick(void)
{

	sf::Vector2f cur_dir = m_model->get_direction();

	cur_dir.x *= 0.7;
	cur_dir.y *= 0.7;

	if(IOhandlers::Keyboard::get_instance().get_key_state(IOhandlers::Keyboard::KeyCode::Z))
	{
		// UP KEY
		cur_dir.y += 2;
	}

	if(IOhandlers::Keyboard::get_instance().get_key_state(IOhandlers::Keyboard::KeyCode::S))
	{
		// UP KEY
		cur_dir.y -= 2;
	}

	if(IOhandlers::Keyboard::get_instance().get_key_state(IOhandlers::Keyboard::KeyCode::D))
	{
		// UP KEY
		cur_dir.x += 2;
	}

	if(IOhandlers::Keyboard::get_instance().get_key_state(IOhandlers::Keyboard::KeyCode::Q))
	{
		// UP KEY
		cur_dir.x -= 2;
	}

	m_model->set_direction(cur_dir);


	m_model->do_game_tick();
}

void PlayerController::handle_event(const IOhandlers::IOEvent& event)
{

}

}}} // namespace game::MVC::controller
