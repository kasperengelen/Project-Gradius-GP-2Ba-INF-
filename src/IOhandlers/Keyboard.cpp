//=======================================
// @brief Implementation of Keyboard.hpp
//=======================================

#include "Keyboard.hpp"

namespace game {
namespace IOhandlers {

const Keyboard::KeyCode Keyboard::translate_keycode_from_sfml(const sf::Keyboard::Key& key_code)
{
	switch(key_code)
	{
	case sf::Keyboard::A:
		return KeyCode::A;
	case sf::Keyboard::B:
		return KeyCode::B;
	case sf::Keyboard::C:
		return KeyCode::C;
	case sf::Keyboard::D:
		return KeyCode::D;
	case sf::Keyboard::E:
		return KeyCode::E;
	case sf::Keyboard::F:
		return KeyCode::F;
	case sf::Keyboard::G:
		return KeyCode::G;
	case sf::Keyboard::H:
		return KeyCode::H;
	case sf::Keyboard::I:
		return KeyCode::I;
	case sf::Keyboard::J:
		return KeyCode::J;
	case sf::Keyboard::K:
		return KeyCode::K;
	case sf::Keyboard::L:
		return KeyCode::L;
	case sf::Keyboard::M:
		return KeyCode::M;
	case sf::Keyboard::N:
		return KeyCode::N;
	case sf::Keyboard::O:
		return KeyCode::O;
	case sf::Keyboard::P:
		return KeyCode::P;
	case sf::Keyboard::Q:
		return KeyCode::Q;
	case sf::Keyboard::R:
		return KeyCode::R;
	case sf::Keyboard::S:
		return KeyCode::S;
	case sf::Keyboard::T:
		return KeyCode::T;
	case sf::Keyboard::U:
		return KeyCode::U;
	case sf::Keyboard::V:
		return KeyCode::V;
	case sf::Keyboard::W:
		return KeyCode::W;
	case sf::Keyboard::X:
		return KeyCode::X;
	case sf::Keyboard::Y:
		return KeyCode::Y;
	case sf::Keyboard::Z:
		return KeyCode::Z;
	case sf::Keyboard::Escape:
		return KeyCode::ESCAPE;
	case sf::Keyboard::Space:
		return KeyCode::SPACE;
	case sf::Keyboard::Return:
		return KeyCode::ENTER;
	case sf::Keyboard::Tab:
		return KeyCode::TAB;
	case sf::Keyboard::LControl:
		return KeyCode::LCTRL;
	case sf::Keyboard::RControl:
		return KeyCode::RCTRL;
	case sf::Keyboard::LShift:
		return KeyCode::LSHIFT;
	case sf::Keyboard::RShift:
		return KeyCode::RSHIFT;
	case sf::Keyboard::LAlt:
		return KeyCode::LALT;
	case sf::Keyboard::RAlt:
		return KeyCode::RALT;
	case sf::Keyboard::Up:
		return KeyCode::UP;
	case sf::Keyboard::Down:
		return KeyCode::DOWN;
	case sf::Keyboard::Left:
		return KeyCode::LEFT;
	case sf::Keyboard::Right:
		return KeyCode::RIGHT;
	case sf::Keyboard::Num0:
		return KeyCode::Num0;
	case sf::Keyboard::Num1:
		return KeyCode::Num1;
	case sf::Keyboard::Num2:
		return KeyCode::Num2;
	case sf::Keyboard::Num3:
		return KeyCode::Num3;
	case sf::Keyboard::Num4:
		return KeyCode::Num4;
	case sf::Keyboard::Num5:
		return KeyCode::Num5;
	case sf::Keyboard::Num6:
		return KeyCode::Num6;
	case sf::Keyboard::Num7:
		return KeyCode::Num7;
	case sf::Keyboard::Num8:
		return KeyCode::Num8;
	case sf::Keyboard::Num9:
		return KeyCode::Num9;
	case sf::Keyboard::Numpad0:
		return KeyCode::Numpad0;
	case sf::Keyboard::Numpad1:
		return KeyCode::Numpad1;
	case sf::Keyboard::Numpad2:
		return KeyCode::Numpad2;
	case sf::Keyboard::Numpad3:
		return KeyCode::Numpad3;
	case sf::Keyboard::Numpad4:
		return KeyCode::Numpad4;
	case sf::Keyboard::Numpad5:
		return KeyCode::Numpad5;
	case sf::Keyboard::Numpad6:
		return KeyCode::Numpad6;
	case sf::Keyboard::Numpad7:
		return KeyCode::Numpad7;
	case sf::Keyboard::Numpad8:
		return KeyCode::Numpad8;
	case sf::Keyboard::Numpad9:
		return KeyCode::Numpad9;
	case sf::Keyboard::F1:
		return KeyCode::F1;
	case sf::Keyboard::F2:
		return KeyCode::F2;
	case sf::Keyboard::F3:
		return KeyCode::F3;
	case sf::Keyboard::F4:
		return KeyCode::F4;
	case sf::Keyboard::F5:
		return KeyCode::F5;
	case sf::Keyboard::F6:
		return KeyCode::F6;
	case sf::Keyboard::F7:
		return KeyCode::F7;
	case sf::Keyboard::F8:
		return KeyCode::F8;
	case sf::Keyboard::F9:
		return KeyCode::F9;
	case sf::Keyboard::F10:
		return KeyCode::F10;
	case sf::Keyboard::F11:
		return KeyCode::F11;
	case sf::Keyboard::F12:
		return KeyCode::F12;
	default:
		return KeyCode::UNKNOWN;
	}
}

Keyboard::Keyboard(void)
{}

void Keyboard::update_keys(void)
{
	// iterate over keymap
	//    value = is_pressed(key)

}

bool Keyboard::get_key_state(void) const
{
	// return keymap(key).state
}

bool Keyboard::get_key_change_processed() const
{
	// return keymap(key).processed
}

bool Keyboard::set_key_change_processed(void)
{
	// keymap(key).processed = true
}

}} // namespace game::IOhandlers

