//=======================================
// @brief Implementation of Game.hpp
//=======================================


#include "Game.hpp"

#include "MVC/GameModel.hpp"
#include "MVC/GameController.hpp"
#include "MVC/GameView.hpp"

using game::MVC::GameController;
using game::MVC::GameModel;
using game::MVC::GameView;

#include "entity/Player.hpp"
#include "entity/EntityRepresentation.hpp"

using game::entity::Player;
using game::entity::EntityRepresentation;

#include "entity/Enemy.hpp"
using game::entity::Enemy;

#include "entity/Bullet.hpp"
using game::entity::Bullet;

#include "IOhandlers/Window.hpp"
#include "IOhandlers/Sprite.hpp"
#include "utils/LoopTimer.hpp"
#include <iostream>

namespace game {

Game::Game(void)
{}

void Game::run(void)
{

	GameModel::ShrPtr model = std::make_shared<GameModel>();                           // contains logic
	GameView::ShrPtr view = std::make_shared<GameView>(model);                         // renders the model
	GameController controller{model, view}; // sends input to the model


	// add player to Game
	{
		Player::ShrPtr player_model = std::make_shared<Player>(Vec2D{1,1}, 5);
		EntityRepresentation::ShrPtr player_view
				= std::make_shared<EntityRepresentation>
					(player_model, IOhandlers::Sprite{"./resources/textures/playership.png"});

		// TODO ADD_PLAYER
		model->set_player(player_model);
		view->add_entity_representation(player_view);
	}

	// add enemy to Game
	for(const int i : {100,200,300,400,500})
	{
		Enemy::ShrPtr enemy_model = std::make_shared<Enemy>(Vec2D{1000,(float)i}, Vec2D{-5, 0});
		EntityRepresentation::ShrPtr enemy_view
				= std::make_shared<EntityRepresentation>
					(enemy_model, IOhandlers::Sprite{"./resources/textures/enemyship.png"});

		controller.debug_add_entity(enemy_model, enemy_view);
	}

	// add bullet to the game
	{
		Bullet::ShrPtr bullet_model
				= std::make_shared<Bullet>(Vec2D{1000, 500}, Vec2D{-15, 0}, 50);
		EntityRepresentation::ShrPtr bullet_view
				= std::make_shared<EntityRepresentation>
					(bullet_model, IOhandlers::Sprite{"./resources/textures/bullet.png"});

		controller.debug_add_entity(bullet_model, bullet_view);
	}

	game::IOhandlers::Window window{"Gradius", 1100, 600};
	window.clear();

	game::utils::LoopTimer timer{20};
	bool running = true;
	while(running)
	{
		timer.report_new_iteration();

		sf::Event ev;
		while(window.poll_event(ev))
		{
			// basic event handling
			if(ev.type == sf::Event::Closed)
				running = false;
			else if(ev.type == sf::Event::Resized)
				window.update_view();
			else if(ev.type == sf::Event::KeyPressed and ev.key.code == sf::Keyboard::Escape)
				running = false;
			// determine if event is useful
			if (IOhandlers::IOEvent::is_useful(ev.type))
				controller.handle_event(IOhandlers::IOEvent{ev});
		}

		while(timer.is_tick_needed())
		{
			controller.handle_tick();
			timer.report_tick_done();
		}

		window.clear();
		// draw view to window
		view->render(window);
		window.swap_buffers();
		timer.report_render_done();

		if(timer.needs_performance_printout())
		{
			std::cout << "FPS: " << timer.get_performance_info().fps << std::endl;
			std::cout << "TPS: " << timer.get_performance_info().tps << std::endl;
			std::cout << "--" << std::endl;

			timer.reset_performance_tracker();
		}
	}
}

} // namespace game

