//================================================
// @brief Implementation of GameView.hpp
//================================================

#include "GameView.hpp"

#include <iostream>

namespace game {
namespace MVC {

GameView::GameView(const GameModel::ShrPtr& model_ptr)
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

void GameView::add_entity_representation(const EntityRepresentation::ShrPtr& entity_rep_ptr)
{
	m_entity_views.push_back(entity_rep_ptr);
}

}} // namespace game::MVC



