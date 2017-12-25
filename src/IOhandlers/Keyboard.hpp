//=====================================
// @brief Header file for the Keyboard class.
//=====================================

#ifndef IOHANDLERS_KEYBOARD_HPP
#define IOHANDLERS_KEYBOARD_HPP

#include "../utils/Singleton.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <set>

namespace game {
namespace IOhandlers {

/**
 * @brief Class that encapsulates the keyboard.
 */
class Keyboard: public game::misc::Singleton<Keyboard>
{
public:
	/**
	 * @brief Contains the state of a Key
	 */
	struct KeyState
	{
		bool pressed          = false;
		bool update_processed = true;
	};

	/**
	 * @brief Enum for key codes.
	 */
	enum class KeyCode
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
		F12,

		NR_OF_KEYS
	};

	/**
	 * @brief Given an SFML keycode, translate to our keycode system.
	 */
	static const KeyCode translate_keycode_from_sfml(const sf::Keyboard::Key& key_code);

private:
	friend Singleton;
	Keyboard(void);
	virtual ~Keyboard(void) = default;
	Keyboard(const Keyboard&) = delete;
	Keyboard& operator=(const Keyboard&) = delete;

	std::map<KeyCode, KeyState> m_keymap;
public:
	/**
	 * @brief Mark the key as pressed.
	 */
	void press_key(const KeyCode& key_code);

	/**
	 * @brief Mark the key as unpressed.
	 */
	void release_key(const KeyCode& key_code);

	/**
	 * @brief Determine whether the specified key is pressed.
	 *
	 * @return True when the key is currently pressed.
	 * @return False when the key is currently released.
	 */
	bool get_key_state(const KeyCode& key_code) const;

	/**
	 * @brief Determine whether the specified key has had a change in key state that has not been processed.
	 */
	bool get_key_change_processed(const KeyCode& key_code) const;

	/**
	 * @brief Notify the Keyboard class that the change in key state for the specified key has been processed.
	 *
	 * @throw MissingKeyChange This error is thrown, when a change for a key is marked as processed while there was no change
	 * to be processed.
	 */
	void set_key_change_processed(const KeyCode& key_code);

	/**
	 * @brief Determine whether the Keyboard is keeping track of the specified key.
	 */
	bool has_key(const KeyCode& key_code) const;
};

}} // namespace game::IOhandlers



#endif // IOHANDLERS_KEYBOARD_HPP
