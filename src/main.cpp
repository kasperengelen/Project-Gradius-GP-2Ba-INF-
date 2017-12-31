//=======================================
// @brief Main file.
//=======================================

#include "Game.hpp"

#include "level/LevelParser.hpp"

/**
 * @brief Main function.
 */
int main(int argc, char** argv)
{
	game::level::parse_level("./resources/levels/test_level.json");

	//game::Game app{};
	//app.run();

	return 0;
}
