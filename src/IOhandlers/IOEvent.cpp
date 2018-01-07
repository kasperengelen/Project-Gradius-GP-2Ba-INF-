//========================================
// @brief Implementation of IOEvent.hpp
//========================================

// include header
#include "IOEvent.hpp"

// project includes
#include "../exception/IOEventException.hpp"
using game::exception::IOEvent::IOEventInitException;

namespace game {
namespace IOhandlers {

IOEvent::IOEvent(const sf::Event& ev)
	: m_type{}, m_key{}, m_mousebutton{}, m_mouselocation{0,0}
{
	switch(ev.type)
	{
	case sf::Event::EventType::KeyPressed:
		m_type = EventType::KEY_DOWN;
		m_key = Keyboard::translate_keycode_from_sfml(ev.key.code);

		break;

	case sf::Event::EventType::KeyReleased:
		m_type = EventType::KEY_UP;
		m_key = Keyboard::translate_keycode_from_sfml(ev.key.code);

		break;

	case sf::Event::EventType::MouseButtonReleased:
		m_type = EventType::MOUSE_UP;
		m_mousebutton = Mouse::translate_buttoncode_from_sfml(ev.mouseButton.button);
		m_mouselocation = {ev.mouseMove.x, ev.mouseMove.y};

		break;

	case sf::Event::EventType::MouseButtonPressed:
		m_type = EventType::MOUSE_DOWN;
		m_mousebutton = Mouse::translate_buttoncode_from_sfml(ev.mouseButton.button);
		m_mouselocation = {ev.mouseMove.x, ev.mouseMove.y};

		break;

	case sf::Event::EventType::MouseMoved:
		m_type = EventType::MOUSE_MOVE;
		m_mouselocation = {ev.mouseMove.x, ev.mouseMove.y};

		break;

	case sf::Event::EventType::Closed:
		m_type = EventType::WINDOW_CLOSE;
		break;

	default:
		throw IOEventInitException{"Specified sf::Event::EventType not supported by the IOEvent class."};
		break;
	}
}

bool IOEvent::is_useful(const sf::Event::EventType& type)
{
	switch(type)
	{
	case sf::Event::EventType::Closed:
		return true;
	case sf::Event::EventType::KeyPressed:
		return true;
	case sf::Event::EventType::KeyReleased:
		return true;
	case sf::Event::EventType::MouseButtonPressed:
		return true;
	case sf::Event::EventType::MouseButtonReleased:
		return true;
	case sf::Event::EventType::MouseMoved:
		return true;
	default:
		return false;
	}
}

const IOEvent::EventType IOEvent::get_type(void) const
{
	return m_type;
}

const Keyboard::KeyCode IOEvent::get_key(void) const
{
	return m_key;
}

const Mouse::ButtonCode IOEvent::get_mouse_button(void) const
{
	return m_mousebutton;
}

const Mouse::CursorLocation IOEvent::get_mouse_movement(void) const
{
	return m_mouselocation;
}


}} // namespace game::IOhandlers::IOEvent
