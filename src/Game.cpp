//=======================================
// @brief Implementation of Game.hpp
//=======================================


#include "Game.hpp"

#include "MVC/GameModel.hpp"
#include "MVC/GameController.hpp"
#include "MVC/GameView.hpp"

#include "IOhandlers/Window.hpp"
#include "utils/LoopTimer.hpp"
#include "utils/CoordTransform.hpp"
#include "utils/Settings.hpp"

#include "level/LevelParser.hpp"

using game::MVC::GameController;
using game::MVC::GameModel;
using game::MVC::GameView;

#include <iostream>

namespace game {

Game::Game(void)
{}

void Game::run(void)
{
	utils::Settings::get_instance().load_from_file("./resources/settings.json");


	/* CREATE MODEL, CONTROLLER, VIEW */
	GameModel::ShrPtr model = std::make_shared<GameModel>();
	GameView::ShrPtr view = std::make_shared<GameView>
				(IOhandlers::Sprite{utils::Settings::get_instance().get_player_bullet_sprite_filename()},
				 IOhandlers::Sprite{utils::Settings::get_instance().get_enemy_bullet_sprite_filename()},
				 utils::Settings::get_instance().get_font_filename());
	model->attach_observer(view);
	GameController controller{model, view};

	controller.set_level_queue(utils::Settings::get_instance().get_level_json_filenames());
	controller.load_next_level(); // load first level.

	game::IOhandlers::Window window{"Gradius",
									utils::Settings::get_instance().get_screen_width(),
									utils::Settings::get_instance().get_screen_height()};
	utils::CoordTransform::get_instance().update_screen_size(window.get_width(), window.get_height());
	window.clear();

	game::utils::LoopTimer timer{20};
	bool running = true;
	while(running)
	{
		timer.report_new_iteration();

		sf::Event ev;
		while(window.poll_event(ev))
		{
			// determine if event is useful
			if (IOhandlers::IOEvent::is_useful(ev.type))
			{

				const IOhandlers::IOEvent io_ev{ev};

				if(io_ev.get_type() == IOhandlers::IOEvent::EventType::WINDOW_CLOSE)
				{
					running = false;
				}
				else if (io_ev.get_type() == IOhandlers::IOEvent::EventType::WINDOW_RESIZE)
				{
					window.update_view();
					utils::CoordTransform::get_instance().update_screen_size(window.get_width(), window.get_height());
				}
				else if(io_ev.get_type() == IOhandlers::IOEvent::EventType::KEY_DOWN
							and io_ev.get_key() == utils::Settings::get_instance().get_key_quit())
				{
					running = false;
				}

				controller.handle_event(io_ev);
			}
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

