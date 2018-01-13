//========================================
// @brief Header file for GameView class.
//========================================

#ifndef INCLUDED_MVC_GAMEVIEW_HPP
#define INCLUDED_MVC_GAMEVIEW_HPP

#include "GameModel.hpp"
#include "../entity/EntityRepresentation.hpp"
#include "../IOhandlers/Window.hpp"
#include "../IOhandlers/Text.hpp"
#include "../observer/Observer.hpp"

#include <set>
#include <memory>

namespace game {
namespace MVC {

/**
 * @brief View class that encompasses the entire view component of the game.
 */
class GameView final : public observer::Observer
{
private:

	//std::vector<entity::EntityRepresentation::ShrPtr> m_entity_reps;

	struct EntityRepShrPtrComp
	{
		bool operator()(const entity::EntityRepresentation::ShrPtr& lhs, const entity::EntityRepresentation::ShrPtr& rhs)
		{
			return *lhs < *rhs;
		}
	};

	std::set<entity::EntityRepresentation::ShrPtr, EntityRepShrPtrComp> m_entity_reps;

	IOhandlers::Text m_player_lives_text;

	IOhandlers::Sprite m_player_bullet_sprite;
	IOhandlers::Sprite m_enemy_bullet_sprite;

	IOhandlers::Text m_game_over_text;
	bool m_game_over{false};

	IOhandlers::Text m_game_won_text;
	bool m_game_won{false};

public:
	using ShrPtr = std::shared_ptr<GameView>;

	/**
	 * @brief Construct a game view;
	 *
	 * @param[in] player_bullet The sprite that is used to represent a player bullet.
	 * @param[in] enemy_bullet The sprite that is used to represent an enemy bullet.
	 */
	GameView(const IOhandlers::Sprite& player_bullet,
		     const IOhandlers::Sprite& enemy_bullet);

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
	void add_entity_representation(const entity::EntityRepresentation::ShrPtr& entity_rep_ptr);

	/**
	 * @brief Event handler method for the Observer Pattern.
	 */
	void handle_event(const observer::Event::ShrPtr& event_ptr);

	/**
	 * @brief Specify what sprite needs to be used to represent player bullets.
	 */
	void set_player_bullet_sprite(const IOhandlers::Sprite& sprite);

	/**
	 * @brief Specify what sprite needs to be used to represent enemy bullets.
	 */
	void set_enemy_bullet_sprite(const IOhandlers::Sprite& sprite);
};

}} // namespace game::MVC

#endif // INCLUDED_MVC_GAMEVIEW_HPP
