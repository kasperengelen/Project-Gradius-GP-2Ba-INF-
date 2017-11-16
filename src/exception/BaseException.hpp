/*
 * BaseException.hpp
 *
 *  Created on: Nov 15, 2017
 *      Author: kasper
 */

#ifndef INCLUDED_BASEEXCEPTION_HPP
#define INCLUDED_BASEEXCEPTION_HPP

#include <exception>
#include <string>

namespace game {
namespace exception {

class BaseException: public std::exception
{
private:
	/* Specifies what role the exception plays in the exception hierarchy. i.e. "GAME::WINDOW::INIT:: ..." */
	const std::string m_except_identifier;

	/* Specific reason why the exception was thrown. i.e. "Cannot initialize OpenGL." */
	const std::string m_reason;

	/* Complete message that will be returned by the what() method and will be displayed in the terminal. */
	const std::string m_full_message;

protected:
	/**
	 * @brief Contructor for when only the identifier of the exception is known. The what() method will return "EXCEPT::<identifier>".
	 *
	 * @param[in] identifier std::string containing the identifier of the exception. The identifier specifies what role the exception plays in the hierarchy.
	 */
	BaseException(const std::string& identifier)
		: m_except_identifier("EXCEPT::" + identifier), m_reason(""), m_full_message(m_except_identifier)
	{}

	/**
	 * @brief Constructor for when both the reason and the identifier for the exception is known. The what method will return "EXCEPT::<identifier>::<reason>"
	 */
	BaseException(const std::string& identifier, const std::string& reason)
		: m_except_identifier("EXCEPT::" + identifier), m_reason(reason), m_full_message(m_except_identifier + "::" + reason)
	{}

public:
	/**
	 * @brief Returns the identifier of the exception. This shows what role the exception plays in the hierarchy.
	 *
	 * @return Something like "EXCEPT::CONTAINERS::ARRAY_TYPE::INIT"
	 */
	virtual const std::string& get_identifier(void) const
	{
		return m_except_identifier;
	}

	/**
	 * @brief Returns the reason why the exception was thrown. This shows specifically why the exception occurred.
	 *
	 * @return Something like "Index error", "Cannot initialize window", "UNKNOWN ERROR"
	 */
	virtual const std::string& get_reason(void) const
	{
		return m_reason;
	}

	/**
	 * @brief Returns the full error message. This is more or less the identifier followed by the reason.
	 *
	 * @return Something like "EXCEPT::CONTAINERS::ARRAY_TYPE::ACCESS::IndexError"
	 */
	virtual const std::string& get_full_message(void) const
	{
		return m_full_message;
	}

	/**
	 * @returns Returns a C-string with the same contents as get_full_message().
	 */
	virtual const char* what(void) const noexcept
	{
		return this->get_full_message().c_str();
	}
};

}
} // namespace game::exception




#endif // INCLUDED_BASEEXCEPTION_HPP
