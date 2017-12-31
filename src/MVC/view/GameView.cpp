//================================================
// @brief Implementation of GameView.hpp
//================================================

#include "GameView.hpp"


namespace game {
namespace MVC {
namespace view {

GameView::GameView(const model::GameModel::ShrPtr& model_ptr)
	: m_model{model_ptr}
{}

GameView::~GameView(void)
{}


void GameView::render(game::IOhandlers::Window& render_window)
{
	// forward render
	for(const auto& entity_view: m_entity_views)
	{
		entity_view->render(render_window);
	}
}

void GameView::debug_add_entity_view(EntityViewBase::UnqPtr entity_model_ptr)
{
	m_entity_views.push_back(std::move(entity_model_ptr));
}


}}} // namespace game::MVC::view
