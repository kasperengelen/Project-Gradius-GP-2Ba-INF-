//=====================================
// @brief Header file for the Keyboard class.
//=====================================

#ifndef IOHANDLERS_KEYBOARD_HPP
#define IOHANDLERS_KEYBOARD_HPP

#include <map>

namespace game {
namespace IOhandlers {

/**
 * @brief Class that encapsulates the keyboard and provides access to information about keypresses.
 */
class Keyboard
{
private:
	struct KeyState
	{
		bool pressed;
		bool update_processed;
	};

	//todo encapsulate sfml keys?
	std::map</*keycode*/ int, KeyState> m_keymap;
public:
	Keyboard(void);

	/**
	 * @brief This prompts the Keyboard class redetermine for all keys whether they are pressed or not.
	 */
	void update_keys(void);

	/**
	 * @brief Determine whether the specified key is pressed.
	 *
	 * @return True when the key is currently pressed.
	 * @return False when the key is currently released.
	 */
	bool get_key_state(void) const;

	/**
	 * @brief Determine whether the specified key has had a change in key state that has not been processed.
	 */
	bool get_key_change_processed(void) const;

	/**
	 * @brief Notify the Keyboard class that the change in key state for the specified key has been processed.
	 *
	 * @throw MissingKeyChange This error is thrown, when a change for a key is marked as processed while there was no change
	 * to be processed.
	 */
	bool set_key_change_processed(void);
};

}} // namespace game::IOhandlers



#endif // IOHANDLERS_KEYBOARD_HPP
