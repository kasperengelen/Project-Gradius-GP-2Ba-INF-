//==============================================
// @brief Implemenation of Mouse.hpp
//==============================================

#include "Mouse.hpp"


namespace game {
namespace IOhandlers {

const Mouse::ButtonCode Mouse::translate_buttoncode_from_sfml(const sf::Mouse::Button& button_code)
{
	switch(button_code)
	{
	case sf::Mouse::Button::Left:
		return ButtonCode::LEFT;

	case sf::Mouse::Button::Middle:
		return ButtonCode::MIDDLE;

	case sf::Mouse::Button::Right:
		return ButtonCode::RIGHT;

	default:
		return ButtonCode::UNKNOWN;
	}
}

Mouse::Mouse(void)
	: m_buttonstates {
		{ButtonCode::LEFT, {}},
		{ButtonCode::MIDDLE, {}},
		{ButtonCode::RIGHT, {}}
	}
{}

bool Mouse::get_button_state(const ButtonCode& button) const
{
	return m_buttonstates.at(button).is_pressed;
}

bool Mouse::get_button_change_processed(const ButtonCode& button) const
{
	return m_buttonstates.at(button).update_processed;
}

void Mouse::set_button_change_processed(const ButtonCode& button)
{
	m_buttonstates.at(button).update_processed = true;
}

const Mouse::CursorLocation Mouse::get_cursor_location(void) const
{
	return m_location;
}

}} // namespace game::IOhandlers
