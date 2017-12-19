//=======================================
// @brief Main file.
//=======================================

#include "Game.hpp"
#include "utils/Settings.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>


class Temp
{
public:
	enum class t
	{
		A,
		B,
		C
	};
};

/**
 * @brief Main function.
 */
int main(int argc, char** argv)
{

	game::Game app{};
	app.run();

	return 0;
}
