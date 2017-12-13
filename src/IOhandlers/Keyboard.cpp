//=======================================
// @brief Implementation of Keyboard.hpp
//=======================================

#include "Keyboard.hpp"

namespace game {
namespace IOhandlers {

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

