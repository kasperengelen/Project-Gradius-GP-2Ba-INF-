//=======================================
// @brief Main file.
//=======================================

#include "Game.hpp"
#include "exception/BaseException.hpp"

#include <iostream>


/**
 * @brief Main function.
 */
int main(int argc, char** argv)
{

	try
	{
		game::Game app{};
		app.run();
	}
	catch(const game::exception::BaseException& e)
	{
		std::cout << "An error occurred:" << std::endl;
		std::cout << e.what() << std::endl;
	}


	return 0;
}

