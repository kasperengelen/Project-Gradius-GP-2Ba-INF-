//===============================================
// @brief Header file for IOEvent class.
//===============================================

#ifndef INCLUDED_IOHANDLERS_IOEVENT_IOEVENT_HPP
#define INCLUDED_IOHANDLERS_IOEVENT_IOEVENT_HPP

#include "../Keyboard.hpp"

#include <SFML/Window.hpp>

namespace game {
namespace IOhandlers {
namespace IOEvent {

/**
 * @brief Wrapper class for IO events.
 */
class IOEvent
{
public:
	/**
	 * @brief Enumeration of keyboard types.
	 */
	enum class EventType
	{
		WINDOW_CLOSE, // game window is closed
		KEY_UP,       // keyboard key released
		KEY_DOWN,     // keyboard key pressed
		MOUSE_UP,     // mouse button released
		MOUSE_DOWN,   // mouse button pressed
		MOUSE_MOVE    // mouse has moved
	};

	/**
	 * @brief Enumeration of Mouse buttons
	 */
	enum class MouseButton
	{
		LEFT,
		MIDDLE,
		RIGHT
	};

	/**
	 * @brief Struct that contains the location of the cursor.
	 */
	struct CursorLocation
	{
		int x{0};
		int y{0};
	};
private:
	EventType m_type;

	Keyboard::KeyCode m_key;

	MouseButton m_mousebutton;

	CursorLocation m_mouselocation;

public:
	/**
	 * @brief Constructor based on an sf::Event
	 */
	IOEvent(const sf::Event& ev);

	/**
	 * @brief Determine if the specified sf::Event type is usefull and can be converted to
	 * an IOEvent.
	 */
	static bool is_useful(const sf::Event::EventType& type);

	/**
	 * @brief Retrieve the type of the IOEvent.
	 */
	const EventType get_type(void) const;

	/**
	 * @brief Retrieve the id of the key.
	 */
	const Keyboard::KeyCode get_key(void) const;

	/**
	 * @brief Retrieve the id of the mousebutton.
	 */
	const MouseButton get_mouse_button(void) const;

	/**
	 * @brief Retrieve the new location of the cursor.
	 */
	const CursorLocation get_mouse_movement(void) const;
};

}}} // namespace game::IOhandlers::IOEvent

#endif // INCLUDED_IOHANDLERS_IOEVENT_IOEVENT_HPP
