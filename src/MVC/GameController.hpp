//=========================================================
// @brief Header file for GameController class.
//=========================================================

#ifndef INCLUDED_MVC_GAMECONTROLLER_HPP
#define INCLUDED_MVC_GAMECONTROLLER_HPP

// project includes
#include "GameModel.hpp"
#include "GameView.hpp"
#include "../IOhandlers/IOEvent.hpp"
#include "../level/Level.hpp"

namespace game {
namespace MVC {

/**
 * @brief Controller class that encompasses the entire controller component of the game.
 */
class GameController final
{
private:
	GameModel::ShrPtr m_model_ptr;
	GameView::ShrPtr  m_view_ptr;

	// TODO level file queue
	// TODO function for "load_next_level()"

public:
	/**
	 * @brief Controller specifying a pointer to a model and a pointer to a view.
	 */
	GameController(const GameModel::ShrPtr& model_ptr, const GameView::ShrPtr& view_ptr);

	/**
	 * @brief Destructor.
	 */
	~GameController(void);

	/**
	 * @brief Notify the controller that a game tick has to be performed.
	 */
	void handle_tick(void);

	/**
	 * @brief Send an event to the controller.
	 */
	void handle_event(const IOhandlers::IOEvent& event);

	// TODO remove debug method
	void debug_load_level(const level::Level& level);
};

}} // namespace game::MVC


#endif // INCLUDED_MVC_GAMECONTROLLER_HPP


