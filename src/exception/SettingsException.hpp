//====================================================================
// @brief Header file for exceptions related to the Settings class.
//====================================================================

#ifndef INCLUDED_EXCEPTION_SETTINGSEXCEPTION_HPP
#define INCLUDED_EXCEPTION_SETTINGSEXCEPTION_HPP

#include "BaseException.hpp"

#include <string>

namespace game {
namespace exception {
namespace settings {

/**
 * @brief Base class for all exceptions related to the Settings class.
 */
class SettingsBaseException: public BaseException
{
protected:
	/**
	 * @brief Constructor based on an exception hierarchy identifier.
	 */
	SettingsBaseException(const std::string& identifier)
		: BaseException{"SETTINGS::" + identifier}
	{}

	/**
	 * @brief Constructor based on an exception hierarchy identifier and a reason.
	 */
	SettingsBaseException(const std::string& identifier, const std::string& reason)
		: BaseException{"SETTINGS::" + identifier, reason}
	{}
};

/**
 * @brief Exception for when the settings cannot be loaded from a file.
 */
class LoadFromFileException : public SettingsBaseException
{
public:
	LoadFromFileException(const std::string& reason)
		: SettingsBaseException("LOAD_FROM_FILE", reason)
	{}
};


}}} // namespace game::exceptions::settings

#endif // INCLUDED_EXCEPTION_SETTINGSEXCEPTION_HPP
