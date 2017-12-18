//=======================================
// @brief Header file for Mouse class.
//=======================================

#ifndef IOHANDLERS_MOUSE_HPP
#define IOHANDLERS_MOUSE_HPP

#include <SFML/Window/Mouse.hpp>
#include <map>

namespace game {
namespace IOhandlers {

/**
 * @brief Class that encapsulates the mouse.
 */
class Mouse
{
public:
	/**
	 * @brief Contains the state of a mousebutton.
	 */
	struct ButtonState
	{
		bool is_pressed;
		bool update_processed;
	};

	/**
	 * @brief Identifiers a mouse button.
	 */
	enum class ButtonCode
	{
		UNKNOWN = -1,
		LEFT = 0,
		MIDDLE,
		RIGHT
	};

	/**
	 * @brief Contains the location of a cursor.
	 */
	struct CursorLocation
	{
		int x;
		int y;
	};

	static const ButtonCode translate_buttoncode_from_sfml(const sf::Mouse::Button& button_code);

private:
	std::map<ButtonCode, ButtonState> m_buttonstates;
public:
	Mouse(void);

	bool get_button_state(const ButtonCode& button) const;

	bool get_button_change_processed(const ButtonCode& button) const;

	bool set_button_change_processed(const ButtonCode& button) const;

	const CursorLocation get_cursor_location(void) const;
};

}} // namespace game::IOhandlers



#endif // IOHANDLERS_MOUSE_HPP
