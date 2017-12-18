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

}} // namespace game::IOhandlers
