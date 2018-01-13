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
}

void Window::draw(const sf::Drawable& drawable)
{
	m_window.draw(drawable);
}

void Window::update_view(void)
{
	m_window.setView(sf::View{sf::FloatRect{0,0, m_window.getSize().x, m_window.getSize().y}});
}

unsigned int Window::get_width(void) const
{
	return m_window.getSize().x;
}

unsigned int Window::get_height(void) const
{
	return m_window.getSize().y;
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


