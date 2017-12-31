//===========================================
// @brief Implementation of EntityView.hpp.
//===========================================

// include header
#include "EntityView.hpp"

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
namespace view {

/* specialize for PlayerModel */
template <>
void EntityView<PlayerModel>::render(IOhandlers::Window& window)
{
	// render sprite
	this->get_sprite().set_position(this->get_model_ptr()->get_position());

	window.draw(this->get_sprite().get_sfml_sprite());
}

/* Specialize for EnemyModel */
template <>
void EntityView<EnemyModel>::render(IOhandlers::Window& window)
{
	// render sprite
	this->get_sprite().set_position(this->get_model_ptr()->get_position());

	window.draw(this->get_sprite().get_sfml_sprite());
}

/* Specialize for Bullet Model */
template <>
void EntityView<BulletModel>::render(IOhandlers::Window& window)
{
	// render sprite
	this->get_sprite().set_position(this->get_model_ptr()->get_position());

	window.draw(this->get_sprite().get_sfml_sprite());
}


}}} // namespace game::MVC::view











