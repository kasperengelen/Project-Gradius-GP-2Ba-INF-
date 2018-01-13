//================================================
// @brief Implemenation of GameController.hpp
//================================================

#include "GameController.hpp"
#include "../IOhandlers/Keyboard.hpp"
#include "../entity/EntityRepresentation.hpp"
#include "../utils/CoordTransform.hpp"
#include "../utils/Settings.hpp"
#include "../level/LevelEntity.hpp"
#include "../level/LevelParser.hpp"
#include <iostream>

using game::IOhandlers::Keyboard;
using game::IOhandlers::IOEvent;

using game::level::Level;

using game::level::LevelEntity;
using game::level::LevelPlayer;
using game::level::LevelEnemy;
using game::level::LevelObstacle;
using game::level::LevelFinishLine;

using game::entity::EntityBase;
using game::entity::Player;
using game::entity::Enemy;
using game::entity::Obstacle;
using game::entity::EntityRepresentation;
using game::entity::FinishLine;

namespace game {
namespace MVC {

GameController::GameController(const GameModel::ShrPtr& model_ptr, const GameView::ShrPtr& view_ptr)
	: m_model_ptr{model_ptr}, m_view_ptr{view_ptr}
{}

GameController::~GameController(void)
{}

void GameController::handle_tick(void)
{
	using IOhandlers::Keyboard;

	if(m_model_ptr->game_over() or m_model_ptr->get_game_won())
	{
		return;
	} else if (m_model_ptr->level_complete()) {
		this->load_next_level();
		return;
	}

	// update player movement
	utils::Vec2D dir = m_model_ptr->get_player_direction();

	dir *= 0.9;

	const float dir_increment = m_model_ptr->get_player_speed();

	if(Keyboard::get_instance().get_key_state(utils::Settings::get_instance().get_key_up()))
	{
		dir.y += dir_increment;
	}

	if(Keyboard::get_instance().get_key_state(utils::Settings::get_instance().get_key_down()))
	{
		dir.y -= dir_increment;
	}

	if(Keyboard::get_instance().get_key_state(utils::Settings::get_instance().get_key_right()))
	{
		dir.x += dir_increment;
	}

	if(Keyboard::get_instance().get_key_state(utils::Settings::get_instance().get_key_left()))
	{
		dir.x -= dir_increment;
	}

	m_model_ptr->set_player_direction(dir);

	// do shoot
	if(Keyboard::get_instance().get_key_state(utils::Settings::get_instance().get_key_shoot())
			and not Keyboard::get_instance().get_key_change_processed(utils::Settings::get_instance().get_key_shoot()))
	{

		m_model_ptr->player_shoot();

		Keyboard::get_instance().set_key_change_processed(utils::Settings::get_instance().get_key_shoot());
	}

	// forward game tick
	m_model_ptr->do_game_tick();
}

/**
 * NOTE: actually we don't fully "handle" the events here, we only update our IO systems. The tick handler
 * will update the model to accomodate for IO infuence on the model.
 */
void GameController::handle_event(const IOEvent& event)
{
	// update keyboard
	switch(event.get_type())
	{
	case IOEvent::EventType::KEY_UP:
		Keyboard::get_instance().release_key(event.get_key());
		break;

	case IOEvent::EventType::KEY_DOWN:
		if(not Keyboard::get_instance().get_key_state(event.get_key()))
		{
			Keyboard::get_instance().press_key(event.get_key());
		}
		break;

	case IOEvent::EventType::WINDOW_CLOSE:

		break;
	default:
		break;
	}
}

void GameController::set_level_queue(const std::vector<std::string>& level_list)
{
	for(const auto& level_name : level_list)
	{
		m_level_queue.push(level_name);
	}
}

void GameController::load_next_level(void)
{
	// check if there are any more levels to player
	if(m_level_queue.empty())
	{
		m_model_ptr->set_game_won();
		return;
	}

	const Level next_level = level::parse_level(m_level_queue.front());
	m_level_queue.pop();

	// clear all entities in model
	m_model_ptr->clear_entities();

	// update CoordTransform

	utils::CoordTransform::get_instance().update_level_width(next_level.get_width());
	utils::CoordTransform::get_instance().update_level_height(next_level.get_height());

	utils::CoordTransform::get_instance().set_max_x_coord(next_level.get_max_x_coord());
	utils::CoordTransform::get_instance().set_max_y_coord(next_level.get_max_y_coord());

	// iterate over level and add each entity
	for(const auto& level_entity : next_level)
	{
		// extract info out of entity
		//		-> add entity to model
		//		-> add entity rep to view

		if(LevelPlayer* lp_ptr = dynamic_cast<LevelPlayer*>(level_entity.get()))
		{
			Player::ShrPtr player_ptr = std::make_shared<Player>
															(
																lp_ptr->get_position(),
																lp_ptr->get_size(),
																lp_ptr->get_bullet_speed(),
																lp_ptr->get_bullet_size(),
																lp_ptr->get_max_shots_per_second(),
																lp_ptr->get_lives(),
																lp_ptr->get_speed()
															);

			EntityRepresentation::ShrPtr ent_rep = std::make_shared<EntityRepresentation>
															(
																Player::WkPtr{player_ptr},
																IOhandlers::Sprite{lp_ptr->get_sprite_filename()},
																lp_ptr->get_position(),
																EntityRepresentation::Depth::MIDDLE,
																lp_ptr->get_size()
															);


			player_ptr->attach_observer(ent_rep);
			m_model_ptr->set_player(player_ptr);
			m_view_ptr->add_entity_representation(ent_rep);

		}
		else if(LevelEnemy* le_ptr = dynamic_cast<LevelEnemy*>(level_entity.get()))
		{
			Enemy::ShrPtr enemy_ptr = std::make_shared<Enemy>
															(
																le_ptr->get_position(),
																le_ptr->get_size(),
																le_ptr->get_direction(),
																le_ptr->get_bullet_speed(),
																le_ptr->get_bullet_size(),
																le_ptr->get_max_shots_per_second(),
																le_ptr->get_attack_damage()
															);

			EntityRepresentation::ShrPtr ent_rep = std::make_shared<EntityRepresentation>
															(
																Enemy::WkPtr{enemy_ptr},
																IOhandlers::Sprite{le_ptr->get_sprite_filename()},
																le_ptr->get_position(),
																EntityRepresentation::Depth::MIDDLE,
																le_ptr->get_size()
															);

			enemy_ptr->attach_observer(ent_rep);
			m_model_ptr->add_enemy(enemy_ptr);
			m_view_ptr->add_entity_representation(ent_rep);
		}
		else if(LevelObstacle* lo_ptr = dynamic_cast<LevelObstacle*>(level_entity.get()))
		{
			Obstacle::ShrPtr obstacle_ptr = std::make_shared<Obstacle>
															(
																lo_ptr->get_position(),
																lo_ptr->get_size(),
																lo_ptr->get_collision_penalty()
															);

			EntityRepresentation::ShrPtr ent_rep = std::make_shared<EntityRepresentation>
															(
																Obstacle::WkPtr{obstacle_ptr},
																IOhandlers::Sprite{lo_ptr->get_sprite_filename()},
																lo_ptr->get_position(),
																EntityRepresentation::Depth::BACKGROUND,
																lo_ptr->get_size()
															);

			obstacle_ptr->attach_observer(ent_rep);
			m_model_ptr->add_obstacle(obstacle_ptr);
			m_view_ptr->add_entity_representation(ent_rep);

		}
		else if(LevelFinishLine* lfl_ptr = dynamic_cast<LevelFinishLine*>(level_entity.get()))
		{
			FinishLine::ShrPtr finish_ptr = std::make_shared<FinishLine>
															(
																lfl_ptr->get_position(),
																lfl_ptr->get_size()
															);

			EntityRepresentation::ShrPtr ent_rep = std::make_shared<EntityRepresentation>
															(
																FinishLine::WkPtr{finish_ptr},
																IOhandlers::Sprite{lfl_ptr->get_sprite_filename()},
																lfl_ptr->get_position(),
																EntityRepresentation::Depth::BACKGROUND,
																lfl_ptr->get_size()
															);

			finish_ptr->attach_observer(ent_rep);
			m_model_ptr->add_finish_line(finish_ptr);
			m_view_ptr->add_entity_representation(ent_rep);
		}
	}
}


}} // namespace game::MVC





