//=======================================================
// @brief Header file for the Observer class.
//=======================================================

#ifndef INCLUDED_OBSERVER_OBSERVER_HPP
#define INCLUDED_OBSERVER_OBSERVER_HPP

#include "Event.hpp"

#include <memory>

namespace game {
namespace observer {

/**
 * @brief Abstract base class that provides the interface of an Observer.
 *
 * @note See Observer pattern.
 */
class Observer
{
private:

public:
	using ShrPtr = std::shared_ptr<Observer>;

	Observer(void) = default;
	virtual ~Observer(void) = default;

	/**
	 * @brief Handle the specified event.
	 */
	virtual void handle_event(const Event::ShrPtr& entity_ptr) = 0;
};

}} // namespace game::observer


#endif // INCLUDED_OBSERVER_OBSERVER_HPP
