//======================================================
// @brief Implementation of GameModel.hpp
//======================================================

#include "GameModel.hpp"
#include <iostream>
#include <set>
#include <random>
#include <functional>

using game::entity::EntityBase;
using game::entity::Player;
using game::entity::Enemy;
using game::entity::Obstacle;
using game::entity::Bullet;

namespace game {
namespace MVC {



GameModel::GameModel(void)
	: m_player_spawnpoint{0,0}
{}

GameModel::~GameModel(void)
{}

void GameModel::do_game_tick(void)
{
	// do collision detection
	M_handle_collision_detection();

	// forward game tick to player
	m_player->do_game_tick();

	m_ticks_since_last_player_shoot++;

	// forward game tick to enemies
	for(const Enemy::ShrPtr& enemy_ptr : m_enemies)
	{
		enemy_ptr->do_game_tick();
		M_try_enemy_shoot(enemy_ptr);
	}

	// forward game tick to obstacles
	for(const Obstacle::ShrPtr& obstacle_ptr : m_obstacles)
	{
		obstacle_ptr->do_game_tick();
	}

	for(const Bullet::ShrPtr& bullet_ptr : m_bullets_enemy)
	{
		bullet_ptr->do_game_tick();
	}

	for(const Bullet::ShrPtr& bullet_ptr : m_bullets_player)
	{
		bullet_ptr->do_game_tick();
	}

}

void GameModel::set_player(const Player::ShrPtr& player_ptr)
{
	m_player = player_ptr;
	m_player_spawnpoint = player_ptr->get_position();
	M_notify_observers(std::make_shared<observer::PlayerLivesUpdate>(m_player->get_lives()));
}

void GameModel::set_player_direction(const utils::Vec2D& dir)
{
	m_player->set_direction(dir);
}

void GameModel::player_shoot(void)
{
	if(m_player->can_shoot())
	{
		// notify player that a bullet has been shot
		m_player->shoot();

		const float forward_movement = (m_player->get_direction().x > 0) ? m_player->get_direction().x + m_player->get_bullet_speed()
																		 : m_player->get_bullet_speed();

		// create bullet
		const Bullet::ShrPtr bullet_ptr = std::make_shared<Bullet>
															(
																	m_player->get_position(),
																	m_player->get_bullet_size(),
																	utils::Vec2D{forward_movement, 0},
																	1
															);

		// add to bullets
		m_bullets_player.push_back(bullet_ptr);

		// send event to observers that player has shot
		this->M_notify_observers(std::make_shared<observer::PlayerShoot>(bullet_ptr));
		m_ticks_since_last_player_shoot = 0;
	}
}

void GameModel::M_try_enemy_shoot(const Enemy::ShrPtr& enemy_ptr)
{

	if(enemy_ptr->can_shoot())
	{
		enemy_ptr->shoot();

		const float backward_movement = (enemy_ptr->get_direction().x < 0) ? enemy_ptr->get_direction().x - enemy_ptr->get_bullet_speed()
																		   : -(enemy_ptr->get_bullet_speed());

		const Bullet::ShrPtr bullet_ptr = std::make_shared<Bullet>
															(
																	enemy_ptr->get_position(),
																	enemy_ptr->get_bullet_size(),
																	utils::Vec2D{backward_movement, 0},
																	enemy_ptr->get_attack_damage()
															);

		// add to bullets
		m_bullets_enemy.push_back(bullet_ptr);

		// send event to observers that player has shot
		this->M_notify_observers(std::make_shared<observer::EnemyShoot>(bullet_ptr));
	}
}

void GameModel::M_handle_player_death(const int lives_lost)
{
	int lives = m_player->get_lives();

	lives -= lives_lost;

	if(lives <= 0)
	{
		lives = 0;
		m_game_over = true;
		M_notify_observers(std::make_shared<observer::GameOver>());
	}

	m_player->set_lives(lives);
	M_notify_observers(std::make_shared<observer::PlayerLivesUpdate>(lives));

	m_player->set_position(m_player_spawnpoint);

}

void GameModel::M_handle_collision_detection(void)
{
	// player - enemy bullet
	//		-> kill player,
	//		-> kill all bullets
	// obstacle - player
	//		-> kill player
	//		-> kill all bullets
	// obstacle - enemy bullet
	//		-> kill bullet
	// obstacle - player bullet
	//		-> kill bullet
	// obstacle - enemy
	//		-> kill enemy
	// enemy - player bullet
	//		-> kill enemy
	//		-> kill bullet

	// determines if all bullets need to be killed
	bool kill_all_bullets = false;

	// ENEMY BULLET <=> PLAYER
	{
		int lives_lost = 0;
		bool player_death = false;

		for(const auto& bullet_ptr : m_bullets_enemy)
		{
			if(collides(*bullet_ptr, *m_player))
			{
				// determine whether
				lives_lost = std::max(lives_lost, bullet_ptr->get_damage());
				player_death = true;
			}
		}

		if(player_death)
		{
			kill_all_bullets = true;
			M_handle_player_death(lives_lost);
		}
	}

	// ENEMY <=> PLAYER BULLET
	{
		// NOTE: raw pointers are used because it's easier
		// set of bullets that need to be removed
		std::set<const Bullet*> bullet_set;

		// set of enemies that need to be removed
		std::set<const Enemy*> enemy_set;

		for(const auto& bullet_ptr : m_bullets_player)
		{
			for(const auto& enemy_ptr : m_enemies)
			{
				if(collides(*bullet_ptr, *enemy_ptr))
				{
					bullet_set.insert(bullet_ptr.get());
					enemy_set.insert(enemy_ptr.get());
				}
			}
		}

		const auto
		remove_bullet = [&bullet_set](const Bullet::ShrPtr& ptr)
		{
			return bullet_set.count(ptr.get());
		};

		const auto
		remove_enemy = [&enemy_set](const Enemy::ShrPtr& ptr)
		{
			return enemy_set.count(ptr.get());
		};

		m_bullets_player.erase(std::remove_if(m_bullets_player.begin(), m_bullets_player.end(), remove_bullet), m_bullets_player.end());
		m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(), remove_enemy), m_enemies.end());
	}

	// OBSTACLE <=> PLAYER
	for(const Obstacle::ShrPtr& obstacle_ptr : m_obstacles)
	{
		if(collides(*obstacle_ptr, *m_player))
		{
			kill_all_bullets = true;
			M_handle_player_death(obstacle_ptr->get_penalty());
		}
	}

	// OBSTACLE <=> ENEMY
	for(const Obstacle::ShrPtr& obstacle_ptr : m_obstacles)
	{
		// remove all enemies that collide with this obstacle

		const auto
		cond = [&obstacle_ptr](const Enemy::ShrPtr& enemy_ptr) -> bool
		{
			return collides(*obstacle_ptr, *enemy_ptr);
		};

		m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(), cond), m_enemies.end());
	}

	// OBSTACLE <=> PLAYER BULLET
	for(const Obstacle::ShrPtr& obstacle_ptr : m_obstacles)
	{
		// remove all enemies that collide with this obstacle

		const auto
		cond = [&obstacle_ptr](const Bullet::ShrPtr& enemy_ptr) -> bool
		{
			return collides(*obstacle_ptr, *enemy_ptr);
		};

		m_bullets_player.erase(std::remove_if(m_bullets_player.begin(), m_bullets_player.end(), cond), m_bullets_player.end());
	}

	// OBSTACLE <=> ENEMY BULLET
	for(const Obstacle::ShrPtr& obstacle_ptr : m_obstacles)
	{
		// remove all enemies that collide with this obstacle

		const auto
		cond = [&obstacle_ptr](const Bullet::ShrPtr& enemy_ptr) -> bool
		{
			return collides(*obstacle_ptr, *enemy_ptr);
		};

		m_bullets_enemy.erase(std::remove_if(m_bullets_enemy.begin(), m_bullets_enemy.end(), cond), m_bullets_enemy.end());
	}

	// do this after all checks so that bullets can still be used for other checks
	if(kill_all_bullets)
	{
		m_bullets_enemy.clear();
		m_bullets_player.clear();
	}


}

utils::Vec2D GameModel::get_player_direction(void) const
{
	return m_player->get_direction();
}

float GameModel::get_player_speed(void) const
{
	return m_player->get_speed();
}

void GameModel::add_enemy(const Enemy::ShrPtr& enemy_ptr)
{
	m_enemies.push_back(enemy_ptr);
}

void GameModel::add_obstacle(const Obstacle::ShrPtr& obstacle_ptr)
{
	m_obstacles.push_back(obstacle_ptr);
}

void GameModel::add_finish_line(const entity::FinishLine::ShrPtr& finish_line)
{
	m_finish_lines.push_back(finish_line);
}

void GameModel::clear_entities(void)
{
	m_enemies.clear();
	m_obstacles.clear();
	m_bullets_enemy.clear();
	m_bullets_player.clear();
	m_finish_lines.clear();
}

bool GameModel::game_over(void) const
{
	return m_game_over;
}

void GameModel::debug_kill_player(void)
{
	M_handle_player_death(1);
}

}} // namespace game::MVC

