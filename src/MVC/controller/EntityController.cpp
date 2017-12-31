//========================================
// @brief Implementation of EntityController.hpp
//========================================

// include header
#include "EntityController.hpp"

// project includes
#include "../../IOhandlers/Keyboard.hpp"
using game::IOhandlers::Keyboard;

// include entities
#include "../model/PlayerModel.hpp"
using game::MVC::model::PlayerModel;
#include "../model/EnemyModel.hpp"
using game::MVC::model::EnemyModel;
#include "../model/BulletModel.hpp"
using game::MVC::model::BulletModel;

#include <iostream>

namespace game {
namespace MVC {
namespace controller {

/* Specialize for PlayerModel */
template <>
void EntityController<PlayerModel>::handle_ioevent(const IOhandlers::IOEvent& ev)
{
	// handle event for Player
}

template <>
void EntityController<PlayerModel>::handle_game_tick(void)
{
	// we can use a static cast here since the constructor guarantees that the model pointer points to a PlayerModel.
	PlayerModel* player_ptr = static_cast<PlayerModel*>(this->get_model_ptr());

	// todo set direction

	sf::Vector2f dir = player_ptr->get_direction();

	// decrease speed
	dir.x *= 0.9;
	dir.y *= 0.9;

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::Z))
	{
		dir.y += 5;
	}

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::S))
	{
		dir.y -= 5;
	}

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::Q))
	{
		dir.x -= 5;
	}

	if(Keyboard::get_instance().get_key_state(Keyboard::KeyCode::D))
	{
		dir.x += 5;
	}

	player_ptr->set_direction(dir);
}

/* Specialize for EnemyModel */
template <>
void EntityController<EnemyModel>::handle_ioevent(const IOhandlers::IOEvent& ev)
{
	// handle event for Enemy
}

template <>
void EntityController<EnemyModel>::handle_game_tick(void)
{
	// forward game tick for enemy
}

/* Specialize for Bullet */
template <>
void EntityController<BulletModel>::handle_ioevent(const IOhandlers::IOEvent& ev)
{
	//
}

template <>
void EntityController<BulletModel>::handle_game_tick(void)
{
	//
}



}}} // namespace game::MVC::controller




