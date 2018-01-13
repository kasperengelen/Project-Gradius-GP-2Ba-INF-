//============================================
// @brief Implementation of Settings.hpp
//============================================

#include "Settings.hpp"
#include "../lib/json.hpp"
#include "../exception/SettingsException.hpp"

#include <fstream>

using nlohmann::json;


namespace game {
namespace utils {

void Settings::load_from_file(const std::string& filename)
{
	json json_data;

	// load json file
	try
	{
		std::ifstream json_file{filename};
		json_file >> json_data;

		m_levels = json_data.at("LEVEL_LIST").get<std::vector<std::string>>();

		m_key_up = json_data.at("KEY_UP").get<IOhandlers::Keyboard::KeyCode>();
		m_key_down = json_data.at("KEY_DOWN").get<IOhandlers::Keyboard::KeyCode>();
		m_key_right = json_data.at("KEY_RIGHT").get<IOhandlers::Keyboard::KeyCode>();
		m_key_left = json_data.at("KEY_LEFT").get<IOhandlers::Keyboard::KeyCode>();
		m_key_shoot = json_data.at("KEY_SHOOT").get<IOhandlers::Keyboard::KeyCode>();
		m_key_quit = json_data.at("KEY_QUIT").get<IOhandlers::Keyboard::KeyCode>();

		m_show_hitbox = json_data.at("SHOW_HITBOX").get<bool>();

	}
	catch(...)
	{
		throw exception::settings::LoadFromFileException{"Cannot load settings from file."};
	}

}

IOhandlers::Keyboard::KeyCode Settings::get_key_up(void) const
{
	return m_key_up;
}

IOhandlers::Keyboard::KeyCode Settings::get_key_down(void) const
{
	return m_key_down;
}

IOhandlers::Keyboard::KeyCode Settings::get_key_right(void) const
{
	return m_key_right;
}

IOhandlers::Keyboard::KeyCode Settings::get_key_left(void) const
{
	return m_key_left;
}

IOhandlers::Keyboard::KeyCode Settings::get_key_shoot(void) const
{
	return m_key_shoot;
}

IOhandlers::Keyboard::KeyCode Settings::get_key_quit(void) const
{
	return m_key_quit;
}

bool Settings::get_show_hitboxes(void) const
{
	return m_show_hitbox;
}

const std::vector<std::string>& Settings::get_level_json_filenames(void) const
{
	return m_levels;
}

}} // namespace game::utils

