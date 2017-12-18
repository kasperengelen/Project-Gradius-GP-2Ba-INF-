//====================================================
// @brief Header file for IOEventBase class.
//====================================================

#ifndef INCLUDED_IOHANDLERS_IOEVENT_IOEVENTBASE_HPP
#define INCLUDED_IOHANDLERS_IOEVENT_IOEVENTBASE_HPP

namespace game {
namespace IOhandlers {
namespace IOEvent {

/**
 * @brief Base class for IO events.
 */
class IOEventBase
{
private:
public:
	IOEventBase(/* event type */);
};

class KeyboardEvent: public IOEventBase
{
	// key id
	// key up, key down
};

class MouseEvent: public IOEventBase
{

};

class MouseMoveEvent: public IOEventBase
{
	// delta_x
	// delta_y
};

class MouseClickEvent: public IOEventBase
{
	// button_id
	// click location
};

}}} // namespace game::IOhandlers::IOEvent


#endif // INCLUDED_IOHANDLERS_IOEVENT_IOEVENTBASE_HPP
