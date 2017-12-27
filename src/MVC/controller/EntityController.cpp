//========================================
// @brief Implementation of EntityController.hpp
//========================================

// include header
#include "EntityController.hpp"

// include entities
#include "../model/PlayerModel.hpp"
#include "../model/EnemyModel.hpp"

#include <iostream>

namespace game {
namespace MVC {
namespace controller {

/* Specialize for PlayerModel */
template <>
void EntityController<model::PlayerModel>::handle_ioevent(const IOhandlers::IOEvent& ev)
{
	// handle event for Player
}

template <>
void EntityController<model::PlayerModel>::handle_game_tick(void)
{
	// forward game tick for Player
}

/* Specialize for EnemyModel */
template <>
void EntityController<model::EnemyModel>::handle_ioevent(const IOhandlers::IOEvent& ev)
{
	// handle event for Enemy
}

template <>
void EntityController<model::EnemyModel>::handle_game_tick(void)
{
	// forward game tick for player
}

}}} // namespace game::MVC::controller
