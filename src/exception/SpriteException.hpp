//====================================================
// @brief Header file for exceptions related to the Sprite class.
//====================================================

#ifndef INCLUDED_EXCEPTION_SPRITEEXCEPTION_HPP
#define INCLUDED_EXCEPTION_SPRITEEXCEPTION_HPP

#include "BaseException.hpp"

namespace game {
namespace exception {
namespace sprite {

/**
 * @brief Base class for exceptions related to the Sprite class.
 */
class SpriteException: public BaseException
{
private:
public:
	/**
	 * @brief Constructor based on an exception hierarchy identifier.
	 */
	SpriteException(const std::string& identifier)
		: BaseException{"IOHANDLERS::SPRITE::" + identifier}
	{}

	/**
	 * @brief Constructor based on an exception hierarchy identifier and a reason.
	 */
	SpriteException(const std::string& identifier, const std::string& reason)
		: BaseException{"IOHANDLERS::SPRITE::" + identifier, reason}
	{}
};

/**
 * @brief Exception for when a texture file cannot be loaded.
 */
class LoadFromFileException: public SpriteException
{
private:
public:
	/**
	 * @brief Constructor based on a filename.
	 */
	LoadFromFileException(const std::string filename)
		: SpriteException{"LOAD_FROM_FILE", "Cannot load file: '" + filename + "'."}
	{}
};

}}} // namespace game::exception::sprite

#endif // INCLUDED_EXCEPTION_SPRITEEXCEPTION_HPP

