//=======================================
// @brief Main file.
//=======================================

#include "Game.hpp"

#include "level/LevelParser.hpp"
#include <iostream>


class A
{
public:
	A(void)
	{
		std::cout << "A::A(void)" << std::endl;
	}

	virtual ~A(void)
	{
		std::cout << "A::~A(void)" << std::endl;
	};

	virtual void virt_method(void)
	{
		std::cout << "A::virt_method(void)" << std::endl;
	}

};

class B: public A
{
public:
	B(void)
	{
		std::cout << "B::B(void)" << std::endl;
	}

	virtual ~B(void)
	{
		std::cout << "B::~B(void)" << std::endl;
	}

	void virt_method(void) override
	{
		std::cout << "B::virt_method(void)" << std::endl;
		std::cout << "SOME EXTRA COUT" << std::endl;
	}
};

#include <memory>

/**
 * @brief Main function.
 */
int main(int argc, char** argv)
{
	game::Game app{};
	app.run();

	return 0;
}
