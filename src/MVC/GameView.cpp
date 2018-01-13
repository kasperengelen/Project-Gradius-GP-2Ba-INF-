//================================================
// @brief Implementation of GameView.hpp
//================================================

#include "GameView.hpp"

#include "../observer/Event.hpp"
using namespace game::observer;
using game::entity::EntityRepresentation;
#include "../exception/GameViewException.hpp"


#include <iostream>

namespace game {
namespace MVC {

GameView::GameView(const IOhandlers::Sprite& player_bullet,
				   const IOhandlers::Sprite& enemy_bullet,
				   const std::string& font_filename)
	: m_player_lives_text{false},
	  m_player_bullet_sprite{player_bullet},
	  m_enemy_bullet_sprite{enemy_bullet},
	  m_game_over_text{true},
	  m_game_won_text{true}
{

	if(not m_player_lives_text.set_font
			(font_filename, IOhandlers::Text::FontColor::WHITE, 26))
	{
		throw exception::gameview::GameViewInitException{"Cannot initialize font: '" + font_filename + "'"};
	}

	m_player_lives_text.set_string("Lives: ?");
	m_player_lives_text.set_position({0,0});


	if(not m_game_over_text.set_font
			(font_filename, IOhandlers::Text::FontColor::WHITE, 50))
	{
		throw exception::gameview::GameViewInitException{"Cannot initialize font: '" + font_filename + "'"};
	}
	m_game_over_text.set_string("GAME OVER!");

	if(not m_game_won_text.set_font
			(font_filename, IOhandlers::Text::FontColor::WHITE, 50))
	{
		throw exception::gameview::GameViewInitException{"Cannot initialize font: '" + font_filename + "'"};
	}
	m_game_won_text.set_string("WINNER!");
}

GameView::~GameView(void)
{}


void GameView::render(game::IOhandlers::Window& render_window)
{
	if(m_game_over)
	{
		m_game_over_text.set_position({render_window.get_width() / 2.0f, render_window.get_height() / 2.0f});
		render_window.draw(m_game_over_text.to_sfml());

		return;
	}
	else if(m_game_won)
	{
		m_game_won_text.set_position({render_window.get_width() / 2.0f, render_window.get_height() / 2.0f});
		render_window.draw(m_game_won_text.to_sfml());

		return;
	}

	// iterate over entity reps, render those that are valid, remove those that are invalid.
	// SOURCE: http://thispointer.com/erase-elements-from-a-set-while-iterating-in-c-generic-erase_if/
	for(auto it = m_entity_reps.begin(); it != m_entity_reps.end(); )
	{
		if(not (*it)->is_alive())
		{
			it = m_entity_reps.erase(it);
		}
		else
		{
			(*it)->render(render_window);
			it++;
		}
	}

	// render player lives
	render_window.draw(m_player_lives_text.to_sfml());
}

void GameView::add_entity_representation(const EntityRepresentation::ShrPtr& entity_rep_ptr)
{
	m_entity_reps.insert(entity_rep_ptr);
	//m_entity_reps.push_back(entity_rep_ptr);
}

void GameView::handle_event(const observer::Event::ShrPtr& event_ptr)
{
	const Event* p = event_ptr.get();


	// check for enemy shoot
	if(const EnemyShoot* es_ptr = dynamic_cast<const EnemyShoot*>(p))
	{
		const EntityRepresentation::ShrPtr entityrep_ptr
			= std::make_shared<EntityRepresentation>
				(entity::Enemy::WkPtr{es_ptr->bullet_ptr},
				 m_enemy_bullet_sprite,
				 es_ptr->bullet_ptr->get_position(),
				 EntityRepresentation::Depth::FOREGROUND,
				 es_ptr->bullet_ptr->get_size());

		// register observer
		es_ptr->bullet_ptr->attach_observer(entityrep_ptr);

		this->add_entity_representation(entityrep_ptr);
	}
	// check for player shoot
	else if (const PlayerShoot* ps_ptr = dynamic_cast<const PlayerShoot*>(p))
	{
		const EntityRepresentation::ShrPtr entityrep_ptr
			= std::make_shared<EntityRepresentation>
				(entity::Player::WkPtr{ps_ptr->bullet_ptr},
				 m_player_bullet_sprite,
				 ps_ptr->bullet_ptr->get_position(),
				 EntityRepresentation::Depth::FOREGROUND,
				 ps_ptr->bullet_ptr->get_size());

		// register observer
		ps_ptr->bullet_ptr->attach_observer(entityrep_ptr);

		this->add_entity_representation(entityrep_ptr);
	}
	// check for player death
	else if (const PlayerLivesUpdate* pd_ptr = dynamic_cast<const PlayerLivesUpdate*>(p))
	{
		m_player_lives_text.set_string("Lives: " + std::to_string(pd_ptr->new_lives));
	}
	// check for game over
	else if (const GameOver* go_ptr = dynamic_cast<const GameOver*>(p))
	{
		m_game_over = true;
	}
	else if (const GameWon* gw_ptr = dynamic_cast<const GameWon*>(p))
	{
		m_game_won = true;
	}
	// other events arent important
	else
	{
		// ignore
	}

}

void GameView::set_player_bullet_sprite(const IOhandlers::Sprite& sprite)
{
	m_player_bullet_sprite = sprite;
}

void GameView::set_enemy_bullet_sprite(const IOhandlers::Sprite& sprite)
{
	m_enemy_bullet_sprite = sprite;
}

}} // namespace game::MVC



