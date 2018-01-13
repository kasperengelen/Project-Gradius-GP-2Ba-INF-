//=======================================
// @brief Header file for Settings class.
//=======================================

#ifndef INCLUDED_UTILS_SETTINGS_HPP
#define INCLUDED_UTILS_SETTINGS_HPP

#include "Singleton.hpp"

#include "../IOhandlers/Keyboard.hpp"

#include <string>
#include <vector>

namespace game {
namespace utils {

class Settings : public Singleton<Settings>
{
private:
	friend Singleton;
	Settings(void) = default;
	virtual ~Settings(void) = default;
	Settings(const Settings&) = delete;
	Settings& operator=(const Settings&) = delete;

	std::vector<std::string> m_levels;

	// movement keys
	IOhandlers::Keyboard::KeyCode m_key_up;
	IOhandlers::Keyboard::KeyCode m_key_down;
	IOhandlers::Keyboard::KeyCode m_key_right;
	IOhandlers::Keyboard::KeyCode m_key_left;
	IOhandlers::Keyboard::KeyCode m_key_shoot;
	IOhandlers::Keyboard::KeyCode m_key_quit;

	// aethetics
	std::string m_font_filename;
	std::string m_player_bullet_sprite;
	std::string m_enemy_bullet_sprite;

	// debug
	bool m_show_hitbox;

	// screen properties
	unsigned int m_screen_width;
	unsigned int m_screen_height;

public:
	/**
	 * @brief Load settings data from the specified filename;
	 */
	void load_from_file(const std::string& filename);

	/**
	 * @brief Retrieve the key code for the movement key for upwards player movement.
	 */
	IOhandlers::Keyboard::KeyCode get_key_up(void) const;

	/**
	 * @brief Retrieve the key code for the movement key for downwards player movement.
	 */
	IOhandlers::Keyboard::KeyCode get_key_down(void) const;

	/**
	 * @brief Retrieve the key code for the movement key for rightwards player movement.
	 */
	IOhandlers::Keyboard::KeyCode get_key_right(void) const;

	/**
	 * @brief Retrieve the key code for the movement key for leftwards player movement.
	 */
	IOhandlers::Keyboard::KeyCode get_key_left(void) const;

	/**
	 * @brief Retrieve the key code for commanding the player to shoot a bullet.
	 */
	IOhandlers::Keyboard::KeyCode get_key_shoot(void) const;

	/**
	 * @brief Retrieve the key code for closing the game.
	 */
	IOhandlers::Keyboard::KeyCode get_key_quit(void) const;

	/**
	 * @brief Retrieve the filename for the font used for printing text.
	 */
	const std::string& get_font_filename(void) const;

	/**
	 * @brief Retrieve the filename of the sprite used to represent player bullets.
	 */
	const std::string& get_player_bullet_sprite_filename(void) const;

	/**
	 * @brief Retrieve the filename of the sprite used to represent enemy bullets.
	 */
	const std::string& get_enemy_bullet_sprite_filename(void) const;

	/**
	 * @brief Determine whether hitboxes of entities need to be rendered.
	 */
	bool get_show_hitboxes(void) const;

	/**
	 * @brief Retrieve the screen width in pixels.
	 */
	unsigned int get_screen_width(void) const;

	/**
	 * @brief Retrieve the screen height in pixels.
	 */
	unsigned int get_screen_height(void) const;

	/**
	 * @brief Retrieve the filenames for the level JSON files.
	 */
	const std::vector<std::string>& get_level_json_filenames(void) const;


};


}} // namespace game::utils

#endif // INCLUDED_UTILS_SETTINGS_HPP
