//===============================================
// @brief Header file for IOEvent class.
//===============================================

#ifndef INCLUDED_IOHANDLERS_IOEVENT_IOEVENT_HPP
#define INCLUDED_IOHANDLERS_IOEVENT_IOEVENT_HPP

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
	 * @brief Enumeration of keys.
	 */
	enum class Key
	{
		UNKNOWN = -1,
		A = 0,
		B, /* equals 1 */
		C, /* equals 2 */
		D, /* ... */
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		ESCAPE,
		SPACE,
		ENTER,
		TAB,
		LCTRL,
		RCTRL,
		LSHIFT,
		RSHIFT,
		LALT,
		RALT,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		Num0,
		Num1,
		Num2,
		Num3,
		Num4,
		Num5,
		Num6,
		Num7,
		Num8,
		Num9,
		Numpad0,
		Numpad1,
		Numpad2,
		Numpad3,
		Numpad4,
		Numpad5,
		Numpad6,
		Numpad7,
		Numpad8,
		Numpad9,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12
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
		int x;
		int y;
	};
private:
	EventType m_type;

	Key m_key;

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
	EventType get_type(void) const;

	/**
	 * @brief Retrieve the id of the key.
	 */
	Key get_key(void) const;

	/**
	 * @brief Retrieve the id of the mousebutton.
	 */
	MouseButton get_mouse_button(void) const;

	/**
	 * @brief Retrieve the new location of the cursor.
	 */
	CursorLocation get_mouse_movement(void) const;
};

}}} // namespace game::IOhandlers::IOEvent

#endif // INCLUDED_IOHANDLERS_IOEVENT_IOEVENT_HPP
