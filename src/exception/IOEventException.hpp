//===============================================
// @brief Header file for exceptions related to the IOEvent class.
//===============================================

#ifndef INCLUDED_EXCEPTION_IOEVENTEXCEPTION_HPP
#define INCLUDED_EXCEPTION_IOEVENTEXCEPTION_HPP

#include "BaseException.hpp"

namespace game {
namespace exception {
namespace IOEvent {

/**
 * @brief Base class for exceptions related to the IOEvent class.
 */
class IOEventBaseException : public BaseException
{
protected:
	/**
	 * @brief Constructor based on an exception hierarchy identifier.
	 */
	IOEventBaseException(const std::string& identifier)
		: BaseException{"IOHANDLERS::IOEVENT::" + identifier}
	{}

	/**
	 * @brief Constructor based on an exception hierarchy identifier and a reason.
	 */
	IOEventBaseException(const std::string& identifier, const std::string& reason)
		: BaseException{"IOHANDLERS::IOEVENT::" + identifier, reason}
	{}
};

/**
 * @brief Exception for when the constructor of an IOEvent fails.
 */
class IOEventInitException : public IOEventBaseException
{
public:
	/**
	 * @brief Constructor based on a reason that the error occurred.
	 */
	IOEventInitException(const std::string& reason)
		: IOEventBaseException{"INIT", reason}
	{}
};


}}} // namespace game::exception::IOEvent

#endif // INCLUDED_EXCEPTION_IOEVENTEXCEPTION_HPP
