//=======================================
// @brief Implementation of Game.hpp
//=======================================


#include "Game.hpp"

#include "MVC/model/GameModel.hpp"
#include "MVC/controller/GameController.hpp"
#include "MVC/view/GameView.hpp"

using game::MVC::controller::GameController;
using game::MVC::model::GameModel;
using game::MVC::view::GameView;

#include "MVC/model/PlayerModel.hpp"
#include "MVC/controller/EntityController.hpp"
#include "MVC/view/EntityView.hpp"

using game::MVC::model::PlayerModel;
using game::MVC::controller::EntityController;
using game::MVC::view::EntityView;

#include "MVC/model/EnemyModel.hpp"
using game::MVC::model::EnemyModel;

#include "MVC/model/BulletModel.hpp"
using game::MVC::model::BulletModel;

#include "MVC/model/EntityModel.hpp"
#include "MVC/controller/EntityControllerBase.hpp"
#include "MVC/view/EntityViewBase.hpp"

using game::MVC::model::EntityModel;
using game::MVC::controller::EntityControllerBase;
using game::MVC::view::EntityViewBase;

#include "IOhandlers/Window.hpp"
#include "IOhandlers/Sprite.hpp"
#include "utils/LoopTimer.hpp"
#include <iostream>

namespace game {

Game::Game(void)
{}

void Game::run(void)
{

	GameModel::ShrPtr model = std::make_shared<GameModel>();                     // contains logic
	GameController::UnqPtr controller = std::make_unique<GameController>(model); // sends input to the model
	GameView::UnqPtr view = std::make_unique<GameView>(model);                   // renders the model


	// add player to Game
	{
		PlayerModel::ShrPtr player_model = std::make_shared<PlayerModel>(sf::Vector2f{1,1}, 5);
		EntityController<PlayerModel>::UnqPtr player_controller
				= std::make_unique<EntityController<PlayerModel>>(player_model);
		EntityView<PlayerModel>::UnqPtr player_view
				= std::make_unique<EntityView<PlayerModel>>(player_model, IOhandlers::Sprite{"./resources/textures/playership.png"});

		model->debug_add_entity_model(player_model);
		controller->debug_add_entity_controller(std::move(player_controller));
		view->debug_add_entity_view(std::move(player_view));
	}

	// add enemy to Game
	for(const int i : {100,200,300,400,500})
	{
		EnemyModel::ShrPtr enemy_model = std::make_shared<EnemyModel>(sf::Vector2f{1000,i}, sf::Vector2f{-5, 0});
		EntityController<EnemyModel>::UnqPtr enemy_controller
				= std::make_unique<EntityController<EnemyModel>>(enemy_model);
		EntityView<EnemyModel>::UnqPtr enemy_view
				= std::make_unique<EntityView<EnemyModel>>(enemy_model, IOhandlers::Sprite{"./resources/textures/enemyship.png"});

		model->debug_add_entity_model(enemy_model);
		controller->debug_add_entity_controller(std::move(enemy_controller));
		view->debug_add_entity_view(std::move(enemy_view));
	}

	// add bullet to the game
	{
		BulletModel::ShrPtr bullet_model
				= std::make_shared<BulletModel>(sf::Vector2f{1000, 500}, sf::Vector2f{-15, 0}, 50);
		EntityController<BulletModel>::UnqPtr bullet_controller
				= std::make_unique<EntityController<BulletModel>>(bullet_model);
		EntityView<BulletModel>::UnqPtr bullet_view
				= std::make_unique<EntityView<BulletModel>>(bullet_model, IOhandlers::Sprite{"./resources/textures/bullet.png"});

		model->debug_add_entity_model(bullet_model);
		controller->debug_add_entity_controller(std::move(bullet_controller));
		view->debug_add_entity_view(std::move(bullet_view));
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
				controller->handle_event(IOhandlers::IOEvent{ev});
		}

		while(timer.is_tick_needed())
		{
			controller->handle_tick();
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

