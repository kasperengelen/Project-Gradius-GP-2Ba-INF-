//=================================================
// @brief Header file for GameWindow class.
//=================================================


#ifndef INCLUDED_GAMEWINDOW_HPP
#define INCLUDED_GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>

namespace game {
namespace IO_handlers {

/**
 * @brief Encapsulates an SFML window to implement a game window.
 */
class GameWindow
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
	 */
	GameWindow(const std::string& window_title,
			   const unsigned int dim_width,
			   const unsigned int dim_height);

	/**
	 * @brief Clears the window to black.
	 */
	void clear(void);

	/**
	 * @brief Swaps the buffers.
	 */
	void swap_buffers(void);
};



}} // namespace game::IO_handlers



#endif // INCLUDED_GAMEWINDOW_HPP
