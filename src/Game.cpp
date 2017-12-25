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

#include "MVC/model/EntityModel.hpp"
#include "MVC/controller/EntityController.hpp"
#include "MVC/view/EntityView.hpp"

using game::MVC::controller::EntityController;
using game::MVC::model::EntityModel;
using game::MVC::view::EntityView;

#include "MVC/model/PlayerModel.hpp"
#include "MVC/controller/PlayerController.hpp"
#include "MVC/view/PlayerView.hpp"

using game::MVC::controller::PlayerController;
using game::MVC::model::PlayerModel;
using game::MVC::view::PlayerView;

#include "IOhandlers/Window.hpp"
#include "IOhandlers/Sprite.hpp"
#include "utils/LoopTimer.hpp"
#include <iostream>

namespace game {

Game::Game(void)
{}

void Game::run(void)
{
	const IOhandlers::Sprite sprite{"./resources/textures/playership.png"};

	const PlayerModel::ShrPtr playermodel = std::make_shared<MVC::model::PlayerModel>();
	PlayerController::UnqPtr playercontroller = std::make_unique<MVC::controller::PlayerController>(playermodel);
	PlayerView::UnqPtr playerview = std::make_unique<MVC::view::PlayerView>(playermodel, sprite);

	const GameModel::ShrPtr model = std::make_shared<GameModel>();                     // contains logic
	const GameController::UnqPtr controller = std::make_unique<GameController>(model); // sends input to the model
	const GameView::UnqPtr view = std::make_unique<GameView>(model);                   // renders the model

	model->debug_add_entity_model(playermodel);
	controller->debug_add_entity_controller(std::move(playercontroller));
	view->debug_add_entity_view(std::move(playerview));

	game::IOhandlers::Window window{"Gradius", 800, 600};
	window.clear();

	game::utils::LoopTimer timer{20};
	bool running = true;
	while(running)
	{
		timer.report_new_iteration();

		sf::Event ev;
		while(window.poll_event(ev))
		{
			if(ev.type == sf::Event::Closed)
				running = false;
			else if(ev.type == sf::Event::Resized)
				window.update_view();

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

