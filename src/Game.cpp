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

#include "IOhandlers/Window.hpp"
#include "utils/LoopTimer.hpp"
#include <iostream>

namespace game {

Game::Game(void)
{}

void Game::run(void)
{
	const GameModel::ShrPtr model = std::make_shared<GameModel>();                     // contains logic
	const GameController::UnqPtr controller = std::make_unique<GameController>(model); // sends input to the model
	const GameView::UnqPtr view = std::make_unique<GameView>(model);                   // renders the model

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

			// todo send event to controller
			controller->handle_event(ev);
		}

		while(timer.is_tick_needed())
		{
			// todo check if ok
			controller->handle_tick();
			timer.report_tick_done();
		}

		window.clear(); // our "render" consists of a clear to black.
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

