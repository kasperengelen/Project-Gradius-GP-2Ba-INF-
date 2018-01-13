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
	: m_type{}, m_key{}
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

	case sf::Event::EventType::Closed:
		m_type = EventType::WINDOW_CLOSE;
		break;

	case sf::Event::EventType::Resized:
		m_type = EventType::WINDOW_RESIZE;
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
	case sf::Event::EventType::Resized:
		return true;
	default:
		return false;
	}
}

IOEvent::EventType IOEvent::get_type(void) const
{
	return m_type;
}

Keyboard::KeyCode IOEvent::get_key(void) const
{
	return m_key;
}


}} // namespace game::IOhandlers::IOEvent
