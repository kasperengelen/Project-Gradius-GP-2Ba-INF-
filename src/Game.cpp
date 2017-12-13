//=======================================
// @brief Implementation of Game.hpp
//=======================================


#include "Game.hpp"

#include "utils/LoopTimer.hpp"
#include <iostream>
#include "IOhandlers/Window.hpp"

namespace game {

Game::Game(void)
{

}

void Game::run(void)
{
	// create model
	// create controller
	// create view

	game::utils::LoopTimer timer{20};
	game::IOhandlers::Window window{"Gradius", 800, 600};
	window.clear();

	bool running = true;
	while(running)
	{
		timer.report_new_iteration();

		sf::Event ev;

		while(window.poll_event(ev))
		{
			if(ev.type == sf::Event::Closed)
				running = false;
		}

		while(timer.is_tick_needed())
		{
			// update controller
			// update model
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

