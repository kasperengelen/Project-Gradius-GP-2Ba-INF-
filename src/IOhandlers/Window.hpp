//=================================================
// @brief Header file for Window class.
//=================================================


#ifndef INCLUDED_IOHANDLERS_WINDOW_HPP
#define INCLUDED_IOHANDLERS_WINDOW_HPP

#include <SFML/Graphics.hpp>

namespace game {
namespace IOhandlers {

/**
 * @brief Encapsulates an SFML window to implement a window.
 */
class Window
{
private:
	sf::RenderWindow m_window;
public:
	/**
	 * @brief Constructor specifying title, width and height of the window.
	 *
	 * @param[in] window_title std::string containing the title of the window.
	 * @param[in] dim_width The width of the window in pixels.
	 * @param[in] dim_height The height of the window in pixels.
	 *
	 * @post The window will be initialized and ready for use.
	 */
	Window(const std::string& window_title,
			   const unsigned int dim_width,
			   const unsigned int dim_height);

	/**
	 * @brief Clears the window to black.
	 *
	 * @post The window area will only contain black pixels.
	 */
	void clear(void);

	/**
	 * @brief Draw the specified sf::Drawable to the window.
	 */
	void draw(const sf::Drawable&);

	/**
	 * @brief Update the view.
	 */
	void update_view(void);

	/**
	 * @brief Swaps the buffers.
	 */
	void swap_buffers(void);

	/**
	 * @brief Determines if event has occurred. If so, the data will be placed inside the specified event.
	 *
	 * @param[in] ev Event data.
	 *
	 * @return True if events occurred.
	 * @return False if no events occurred.
	 */
	// TODO convert to IOEvent?
	bool poll_event(sf::Event& ev);
};

}} // namespace game::IOhandlers



#endif // INCLUDED_IOHANDLERS_WINDOW_HPP
