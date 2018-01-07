//=========================================================
// @brief Header file for GameController class.
//=========================================================

#ifndef INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP
#define INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP

// project includes
#include "GameModel.hpp"
using game::MVC::GameModel;
#include "GameView.hpp"
using game::MVC::GameView;
#include "../IOhandlers/IOEvent.hpp"
using game::IOhandlers::IOEvent;
#include "../level/Level.hpp"
using game::level::Level;

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
	void handle_event(const IOEvent& event);

	// TODO remove debug method
	void debug_load_level(const Level& level);

	// TODO remove debug method
	void debug_add_entity(const EntityBase::ShrPtr& entity_model_ptr, const EntityRepresentation::ShrPtr& entity_rep_ptr);

};

}} // namespace game::MVC


#endif // INCLUDED_MVC_CONTROLLER_GAMECONTROLLER_HPP


