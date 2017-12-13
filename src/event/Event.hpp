//====================================================
// @brief Header file for event class.
//====================================================

#ifndef INCLUDED_EVENT_EVENT_HPP
#define INCLUDED_EVENT_EVENT_HPP

namespace game {
namespace event {

class EventBase
{
private:
public:
};

class KeyboardEvent: public EventBase
{
	// key id
	// key up, key down
};

class MouseEvent: public EventBase
{

};

class MouseMoveEvent: public MouseEvent
{
	// delta_x
	// delta_y
};

class MouseClickEvent: public MouseEvent
{
	// button_id
	// click location
};

}} // namespace game::event



#endif // INCLUDED_EVENT_EVENT_HPP
