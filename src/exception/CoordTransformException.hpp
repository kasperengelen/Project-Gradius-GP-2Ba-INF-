//=======================================================
// @brief Header file for exceptions related to the CoordTransform class.
//=======================================================

#ifndef INCLUDED_EXCEPTION_COORDTRANSFORMEXCEPTION_HPP
#define INCLUDED_EXCEPTION_COORDTRANSFORMEXCEPTION_HPP

#include "BaseException.hpp"

namespace game {
namespace exception {
namespace coordtransform {

/**
 * @brief Base class for exceptions related to the
 */
class CoordTransformBaseException : public BaseException
{
protected:
	/**
	 * @brief Constructor based on an exception hierarchy identifier.
	 */
	CoordTransformBaseException(const std::string& identifier)
		: BaseException{"COORDTRANSFORM::" + identifier}
	{}

	/**
	 * @brief Constructor based on an exception hierarchy identifier and a reason.
	 */
	CoordTransformBaseException(const std::string& identifier, const std::string& reason)
		: BaseException{"COORDTRANSFORM::" + identifier, reason}
	{}
};

/**
 * @brief Exception for when a coordinate cannot be converted.
 */
class ToScreenCoordException : public CoordTransformBaseException
{
public:
	ToScreenCoordException(const std::string& reason)
		: CoordTransformBaseException{"TO_SCREEN_COORD", reason}
	{}
};



}}} // namespace game::exceptions::coordtransform


#endif // INCLUDED_EXCEPTION_COORDTRANSFORMEXCEPTION_HPP

