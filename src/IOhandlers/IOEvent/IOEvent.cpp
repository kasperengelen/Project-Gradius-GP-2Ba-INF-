//========================================
// @brief Implementation of IOEvent.hpp
//========================================

#include "IOEvent.hpp"

namespace game {
namespace IOhandlers {
namespace IOEvent {

IOEvent::IOEvent(const sf::Event& ev)
{

	switch(ev.type)
	{
	case sf::Event::EventType::KeyPressed:
		m_type = EventType::KEY_DOWN;

		// assign key id

		break;

	case sf::Event::EventType::KeyReleased:
		m_type = EventType::KEY_UP;

		// assign key id

		break;

	case sf::Event::EventType::MouseButtonReleased:
		m_type = EventType::MOUSE_UP;

		// assign button id

		break;

	case sf::Event::EventType::MouseButtonPressed:
		m_type = EventType::MOUSE_DOWN;

		// assign button id

		break;

	case sf::Event::EventType::MouseMoved:
		m_type = EventType::MOUSE_MOVE;

		m_mouselocation = {ev.mouseMove.x, ev.mouseMove.y};

		break;

	case sf::Event::EventType::Closed:
		break;

	default:
		// raise exception
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

IOEvent::EventType IOEvent::get_type(void) const
{
	return m_type;
}

IOEvent::Key IOEvent::get_key(void) const
{
	return m_key;
}

IOEvent::MouseButton IOEvent::get_mouse_button(void) const
{
	return m_mousebutton;
}

IOEvent::CursorLocation IOEvent::get_mouse_movement(void) const
{
	return m_mouselocation;
}


}}} // namespace game::IOhandlers::IOEvent
