//=======================================
// @brief Main file.
//=======================================

#include "Game.hpp"
#include "utils/Settings.hpp"
#include "IOhandlers/Window.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include "exception/SpriteException.hpp"

/**
 * @brief Main function.
 */
int main(int argc, char** argv)
{
	game::Game app{};
	app.run();

	return 0;
}
