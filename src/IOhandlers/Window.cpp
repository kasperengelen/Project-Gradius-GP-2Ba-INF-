//=================================================
// @brief Implementation of GameWindow.hpp
//=================================================

#include "Window.hpp"

namespace game {
namespace IOhandlers {

Window::Window(const std::string& window_title,
		               const unsigned int dim_width,
					   const unsigned int dim_height)
	: m_window{sf::VideoMode{dim_width, dim_height}, window_title}
{}

void Window::clear(void)
{
	m_window.clear();
	m_window.display();
}

void Window::swap_buffers(void)
{
	m_window.display();
}

bool Window::poll_event(sf::Event& ev)
{
	return m_window.pollEvent(ev);
}


}} // namespace game::IOhandlers


