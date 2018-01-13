//===================================================
// @brief Header file for exceptions related to the GameView class.
//===================================================

#ifndef INCLUDED_EXCEPTION_GAMEVIEWEXCEPTION_HPP
#define INCLUDED_EXCEPTION_GAMEVIEWEXCEPTION_HPP

#include "BaseException.hpp"

namespace game {
namespace exception {
namespace gameview {

/**
 * @brief Base class for exceptions related to the GameView class.
 */
class GameViewBaseException : public BaseException
{
protected:
	/**
	 * @brief Constructor based on an exception hierarchy identifier.
	 */
	GameViewBaseException(const std::string& identifier)
		: BaseException{"GAMEVIEW::" + identifier}
	{}

	/**
	 * @brief Constructor based on an exception hierarchy identifier and a reason.
	 */
	GameViewBaseException(const std::string& identifier, const std::string& reason)
		: BaseException{"GAMEVIEW::" + identifier, reason}
	{}
};

class GameViewInitException : public GameViewBaseException
{
public:
	GameViewInitException(const std::string& reason)
		: GameViewBaseException{"INIT", reason}
	{}
};

}}} // namespace game::exception::gameview

#endif // INCLUDED_EXCEPTION_GAMEVIEWEXCEPTION_HPP
