//=======================================
// @brief Main file.
//=======================================

#include "Game.hpp"
#include "utils/Settings.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

/**
 * @brief Main function.
 */
int main(int argc, char** argv)
{
	game::Game app{};
	app.run();

	return 0;
}
