//=============================================
// @brief Implementation of PlayerView.hpp
//=============================================

#include "PlayerView.hpp"
#include <iostream>

namespace game {
namespace MVC {
namespace view {

PlayerView::PlayerView(const model::PlayerModel::ShrPtr& model_ptr,
						const IOhandlers::Sprite& player_sprite)
	: EntityView{model_ptr, player_sprite}
{}

PlayerView::~PlayerView(void)
{}

void PlayerView::render(game::IOhandlers::Window& render_window)
{

	m_sprite.set_position(m_model->get_position().x, m_model->get_position().y);



	render_window.draw(m_sprite.get_sfml_sprite());
}



}}} // namespace game::MVC::view
