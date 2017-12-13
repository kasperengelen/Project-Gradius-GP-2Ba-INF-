//=======================================
// @brief Header file for Settings class.
//=======================================

#ifndef UTILS_SETTINGS_HPP
#define UTILS_SETTINGS_HPP

namespace game {
namespace utils {

/**
 * @brief Class that serves as a container for application settings.
 */
class Settings
{
private:
	// map
public:
	Settings(void);

	/**
	 * @brief Load settings from settings file.
	 */
	void load_file(const std::string& file_name);

	/**
	 * @brief Save settings to settings file.
	 */
	void save_file(const std::string& file_name) const;

	/**
	 * @brief Retrieve the value of the specified parameter.
	 */
	void get_value(const std::string& param_name);

	/**
	 * @brief Set the value of the specified parameter.
	 */
	void set_value(const std::string& param_name, const int value);
};

}}

#endif // UTILS_SETTINGS_HPP
