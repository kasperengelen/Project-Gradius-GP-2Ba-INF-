//=================================================
// @brief Implementation of GameWindow.hpp
//=================================================

#include "../IO_handlers/GameWindow.hpp"

namespace game {
namespace IO_handlers {

GameWindow::GameWindow(const std::string& window_title,
		               const unsigned int dim_width,
					   const unsigned int dim_height)
	: m_window(sf::VideoMode{dim_width, dim_height}, window_title)
{}

void GameWindow::clear(void)
{
	m_window.clear();
	m_window.display();
}

void GameWindow::swap_buffers(void)
{
	m_window.display();
}


}} // namespace game::IO_handlers


