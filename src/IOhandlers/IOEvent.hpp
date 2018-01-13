//===============================================
// @brief Header file for IOEvent class.
//===============================================

#ifndef INCLUDED_IOHANDLERS_IOEVENT_HPP
#define INCLUDED_IOHANDLERS_IOEVENT_HPP

#include "Keyboard.hpp"

#include <SFML/Window.hpp>

namespace game {
namespace IOhandlers {

/**
 * @brief Wrapper class for IO events.
 */
class IOEvent
{
public:
	/**
	 * @brief Enumeration of event types.
	 */
	enum class EventType
	{
		WINDOW_CLOSE,  // game window is closed
		WINDOW_RESIZE, // game window is resized
		KEY_UP,        // keyboard key released
		KEY_DOWN,      // keyboard key pressed
	};

private:
	EventType m_type;

	Keyboard::KeyCode m_key;

public:
	/**
	 * @brief Constructor based on an sf::Event
	 */
	IOEvent(const sf::Event& ev);

	/**
	 * @brief Determine if the specified sf::Event type is useful and can be converted to
	 * an IOEvent.
	 */
	static bool is_useful(const sf::Event::EventType& type);

	/**
	 * @brief Retrieve the type of the IOEvent.
	 */
	EventType get_type(void) const;

	/**
	 * @brief Retrieve the id of the key.
	 */
	Keyboard::KeyCode get_key(void) const;

};

}} // namespace game::IOhandlers::IOEvent

#endif // INCLUDED_IOHANDLERS_IOEVENT_HPP

