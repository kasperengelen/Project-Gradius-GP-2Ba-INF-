//========================================
// @brief Header file for GameView class.
//========================================

#ifndef INCLUDED_MVC_VIEW_GAMEVIEW_HPP
#define INCLUDED_MVC_VIEW_GAMEVIEW_HPP

#include "../entity/EntityRepresentation.hpp"
using game::entity::EntityRepresentation;
#include "GameModel.hpp"

#include "../IOhandlers/Window.hpp"


#include <memory>

namespace game {
namespace MVC {

/**
 * @brief View class that encompasses the entire view component of the game.
 */
class GameView final
{
private:
	GameModel::ShrPtr m_model;

	std::vector<EntityRepresentation::ShrPtr> m_entity_views;
public:
	using ShrPtr = std::shared_ptr<GameView>;

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

	/**
	 * @brief Add an EntityRepresentation to the GameView.
	 */
	void add_entity_representation(const EntityRepresentation::ShrPtr& entity_rep_ptr);

};

}} // namespace game::MVC

#endif // INCLUDED_MVC_VIEW_GAMEVIEW_HPP
