//========================================
// @brief Header file for GameView class.
//========================================

#ifndef INCLUDED_MVC_VIEW_GAMEVIEW_HPP
#define INCLUDED_MVC_VIEW_GAMEVIEW_HPP

#include "../model/GameModel.hpp"
using game::MVC::model::GameModel;
#include "EntityView.hpp"

#include "../../IOhandlers/Window.hpp"

#include <memory>

namespace game {
namespace MVC {
namespace view {

/**
 * @brief View class that encompasses the entire view component of the game.
 */
class GameView final
{
private:
	model::GameModel::ShrPtr m_model;

	std::vector<EntityView::UnqPtr> m_entity_views;
public:
	using UnqPtr = std::unique_ptr<GameView>;

	/**
	 * @brief Construct a game view for the specified model.
	 */
	GameView(const GameModel::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	virtual ~GameView(void);

	/**
	 * @brief Render the view to the specified window.
	 */
	void render(game::IOhandlers::Window& render_window);

	//TODO REMOVE DEBUG
	void debug_add_entity_view(EntityView::UnqPtr entity_model_ptr);
};

}}} // namespace game::MVC::view

#endif // INCLUDED_MVC_VIEW_GAMEVIEW_HPP
