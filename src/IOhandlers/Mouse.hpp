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
		bool is_pressed = false;
		bool update_processed = true;
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

	CursorLocation m_location;
public:
	/**
	 * @brief Mouse constructor.
	 */
	Mouse(void);

	/**
	 * @brief Determine whether the specified mouse button is pressed.
	 */
	bool get_button_state(const ButtonCode& button) const;

	/**
	 * @brief Determine whether the last button press or release was processed.
	 */
	bool get_button_change_processed(const ButtonCode& button) const;

	/**
	 * @brief Notify the mouse that the last button press or release has been processed.
	 */
	void set_button_change_processed(const ButtonCode& button);

	/**
	 * @brief Retrieve the location of the cursor.
	 */
	const CursorLocation get_cursor_location(void) const;
};

}} // namespace game::IOhandlers



#endif // IOHANDLERS_MOUSE_HPP
