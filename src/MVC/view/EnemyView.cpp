//======================================
// @brief Implementation of EnemyView.hpp
//======================================

#include "EnemyView.hpp"

namespace game {
namespace MVC {
namespace view {

EnemyView::EnemyView(const model::EnemyModel::ShrPtr& model_ptr,
			const IOhandlers::Sprite& enemy_sprite)
	: EntityView{model_ptr, enemy_sprite}
{

}

EnemyView::~EnemyView(void)
{

}

void EnemyView::render(game::IOhandlers::Window& render_window)
{

}

}}} // namespace game::MVC::view
