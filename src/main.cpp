//=======================================
// @brief Main file.
//=======================================

#include "Game.hpp"

#include "level/Level.hpp"
#include "MVC/model/PlayerModel.hpp"
#include "MVC/controller/EntityController.hpp"

#include <memory>

/**
 * @brief Main function.
 */
int main(int argc, char** argv)
{
	using game::MVC::model::PlayerModel;
	using game::MVC::controller::EntityController;
	using game::IOhandlers::IOEvent;

	PlayerModel::ShrPtr ptr = std::make_shared<PlayerModel>(sf::Vector2f{1,1}, sf::Vector2f{2,2}, 5);

	EntityController<PlayerModel> player_controller{ptr};

	IOEvent ev{sf::Event{}};

	player_controller.handle_ioevent(ev);

	//game::Game app{};
	//app.run();

	return 0;
}
