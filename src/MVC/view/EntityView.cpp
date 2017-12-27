//===========================================
// @brief Implementation of EntityView.hpp.
//===========================================

// include header
#include "EntityView.hpp"

// include entities
#include "../model/PlayerModel.hpp"
#include "../model/EnemyModel.hpp"

namespace game {
namespace MVC {
namespace view {

/* specialize for PlayerModel */
template <>
void EntityView<model::PlayerModel>::render(const IOhandlers::Window& window)
{

}

/* Specialize for EnemyModel */
template <>
void EntityView<model::EnemyModel>::render(const IOhandlers::Window& window)
{

}


}}} // namespace game::MVC::view











