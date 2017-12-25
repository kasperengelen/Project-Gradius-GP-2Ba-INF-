//====================================================
// @brief Header file for exceptions related to the Sprite class.
//====================================================

#ifndef EXCEPTION_SPRITEEXCEPTION_HPP
#define EXCEPTION_SPRITEEXCEPTION_HPP

#include "BaseException.hpp"

namespace game {
namespace exception {
namespace IOhandlers {
namespace sprite {

class SpriteException: public BaseException
{
private:
public:
	SpriteException(const std::string& identifier)
		: BaseException{"IOHANDLERS::SPRITE::" + identifier}
	{}

	SpriteException(const std::string& identifier, const std::string& reason)
		: BaseException{"IOHANDLERS::SPRITE::" + identifier, reason}
	{}
};

class LoadFromFileException: public SpriteException
{
private:
public:
	LoadFromFileException(const std::string filename)
		: SpriteException{"LOAD_FROM_FILE", "Cannot load file: '" + filename + "'."}
	{}

};


}}}} // namespace game::exception::IOhandlers::sprite


#endif // EXCEPTION_SPRITEEXCEPTION_HPP



