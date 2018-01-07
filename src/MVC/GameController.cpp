//================================================
// @brief Implemenation of GameController.hpp
//================================================

#include "GameController.hpp"
#include "../IOhandlers/Keyboard.hpp"
using game::IOhandlers::Keyboard;
#include "../entity/EntityRepresentation.hpp"
using game::entity::EntityRepresentation;
#include <iostream>

namespace game {
namespace MVC {

GameController::GameController(const GameModel::ShrPtr& model_ptr, const GameView::ShrPtr& view_ptr)
	: m_model_ptr{model_ptr}, m_view_ptr{view_ptr}
{}

GameController::~GameController(void)
{}

void GameController::handle_tick(void)
{
	using IOhandlers::Keyboard;


	// update player movement
	Vec2D dir = m_model_ptr->get_player_direction();

	dir *= 0.9;

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::Z))
	{
		dir.y += 1;
	}

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::S))
	{
		dir.y -= 1;
	}

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::D))
	{
		dir.x += 1;
	}

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::Q))
	{
		dir.x -= 1;
	}

	m_model_ptr->set_player_direction(dir);

	// do shoot
	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::SPACE)
			and not Keyboard::get_instance().get_key_change_processed(Keyboard::KeyCode::SPACE))
	{
		// shoot bullet from player.

		Bullet::ShrPtr bullet_model
				= std::make_shared<Bullet>(m_model_ptr->get_player_position(), Vec2D{15, 0}, 50);
		EntityRepresentation::ShrPtr bullet_view
				= std::make_shared<EntityRepresentation>(bullet_model, IOhandlers::Sprite{"./resources/textures/bullet.png"});

		m_model_ptr->debug_add_entity_model(bullet_model);
		m_view_ptr->add_entity_representation(bullet_view);

		Keyboard::get_instance().set_key_change_processed(Keyboard::KeyCode::SPACE);
	}

	// forward game tick
	m_model_ptr->do_game_tick();
}

/**
 * NOTE: actually we don't fully "handle" the events here, we only update our IO systems. The tick handler
 * will update the model to accomodate for IO infuence on the model.
 */
void GameController::handle_event(const IOEvent& event)
{
	// update keyboard
	switch(event.get_type())
	{
	case IOEvent::EventType::KEY_UP:
		Keyboard::get_instance().release_key(event.get_key());
		break;

	case IOEvent::EventType::KEY_DOWN:
		if(not Keyboard::get_instance().get_key_state(event.get_key()))
		{
			Keyboard::get_instance().press_key(event.get_key());
		}
		break;

	case IOEvent::EventType::MOUSE_UP:

		break;

	case IOEvent::EventType::MOUSE_DOWN:

		break;

	case IOEvent::EventType::MOUSE_MOVE:

		break;

	case IOEvent::EventType::WINDOW_CLOSE:

		break;
	default:
		break;
	}

}

void GameController::debug_add_entity(const EntityBase::ShrPtr& entity_model_ptr,
									  const EntityRepresentation::ShrPtr& entity_rep_ptr)
{
	m_model_ptr->debug_add_entity_model(entity_model_ptr);
	m_view_ptr->add_entity_representation(entity_rep_ptr);
}

void GameController::debug_load_level(const Level& level)
{
	// clear all data
	//		-> controllers
	//		-> models
	//		-> views

	// clear all entities in model
	// iterate over level and add each entity
	for(const auto& level_entity : level)
	{
		// extract info out of entity
		//		-> add controller
		//		-> add model
		//		-> add view (needs viewptr)
	}
}


}} // namespace game::MVC





