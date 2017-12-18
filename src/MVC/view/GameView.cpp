//================================================
// @brief Implementation of GameView.hpp
//================================================

#include "GameView.hpp"


namespace game {
namespace MVC {
namespace view {

GameView::GameView(const GameModel::ShrPtr& model_ptr): ViewBase{model_ptr}
{}

GameView::~GameView(void)
{}

void GameView::render(const game::IOhandlers::Window& render_window)
{}

}}} // namespace game::MVC::view
