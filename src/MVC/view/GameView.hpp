//========================================
// @brief Header file for GameView class.
//========================================

#ifndef INCLUDED_MVC_VIEW_GAMEVIEW_HPP
#define INCLUDED_MVC_VIEW_GAMEVIEW_HPP

#include "ViewBase.hpp"

#include "../model/GameModel.hpp"
using game::MVC::model::GameModel;

namespace game {
namespace MVC {
namespace view {

/**
 * @brief View class that encompasses the entire view component of the game.
 */
class GameView: public ViewBase
{
private:
public:
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
	virtual void render(const game::IOhandlers::Window& render_window);
};

}}} // namespace game::MVC::view

#endif // INCLUDED_MVC_VIEW_GAMEVIEW_HPP
