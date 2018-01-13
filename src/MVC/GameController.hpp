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

#include <queue>

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

	// contains a queue of filenames of level JSON files.
	std::queue<std::string> m_level_queue;

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

	/**
	 * @brief Specify the filenames of the JSON files that are used to load the levels.
	 * The first level in the vector will be played first, the second after that, etc.
	 */
	void set_level_queue(const std::vector<std::string>& level_list);

	/**
	 * @brief Load the next level in the level queue.
	 * If the last level is over, the game is won.
	 */
	void load_next_level(void);
};

}} // namespace game::MVC


#endif // INCLUDED_MVC_GAMECONTROLLER_HPP


