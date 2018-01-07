//=====================================
// @brief Header file for all exceptions related to the Level class.
//=====================================

#ifndef INCLUDED_EXCEPTION_LEVELEXCEPTION_HPP
#define INCLUDED_EXCEPTION_LEVELEXCEPTION_HPP

#include "BaseException.hpp"

namespace game {
namespace exception {
namespace level {

/**
 * @brief Base class for all exceptions related to the Level class.
 */
class LevelBaseException: public BaseException
{
protected:
	/**
	 * @brief Constructor based on an exception hierarchy identifier.
	 */
	LevelBaseException(const std::string& identifier)
		: BaseException{"LEVEL::" + identifier}
	{}

	/**
	 * @brief Constructor based on an exception hierarchy identifier and a reason.
	 */
	LevelBaseException(const std::string& identifier, const std::string& reason)
		: BaseException{"LEVEL::" + identifier, reason}
	{}
};

/**
 * @brief Exception for when loading a level cannot be loaded.
 */
class LevelLoadException: public LevelBaseException
{
public:
	/**
	 * @brief Constructor based on the filename of the level file.
	 */
	LevelLoadException(const std::string& filename)
		: LevelBaseException{"LOAD_FROM_FILE", "Cannot load level from file: '" + filename + "'."}
	{}

	/**
	 * @brief Constructor based on the filename of the level file and the reason.
	 */
	LevelLoadException(const std::string& filename, const std::string& reason)
		: LevelBaseException{"LOAD_FROM_FILE",
						     "Cannot load level from file: '" + filename + "'.\nReason: " + reason}
	{}
};

}}} // namespace game::exception

#endif // INCLUDED_EXCEPTION_LEVELEXCEPTION_HPP
