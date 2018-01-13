//===================================================
// @brief Header file for the Observable class.
//===================================================

#ifndef INCLUDED_OBSERVER_OBSERVABLE_HPP
#define INCLUDED_OBSERVER_OBSERVABLE_HPP

#include "Observer.hpp"
#include "Event.hpp"

#include <vector>
#include <algorithm>

namespace game {
namespace observer {

/**
 * @brief Abstract base class that provides the interface of an Observable.
 *
 * @note See Observer pattern.
 */
class Observable
{
private:
	std::vector<Observer::ShrPtr> m_observers;

protected:
	/**
	 * @brief Notify all the observers than the specified occurred.
	 *
	 * @note This is protected because only the observable itself should be able to
	 * initiate events.
	 */
	virtual void M_notify_observers(const Event::ShrPtr& event_ptr) const;

public:

	Observable(void) = default;
	virtual ~Observable(void) = default;

	/**
	 * @brief Add an observer that is to be notified.
	 */
	void attach_observer(const Observer::ShrPtr& observer_ptr);

	/**
	 * @brief Add an observer that is to be notified.
	 */
	void detach_observer(const Observer::ShrPtr& observer_ptr);
};

inline void Observable::M_notify_observers(const Event::ShrPtr& event_ptr) const
{
	// forward event.
	for(const auto& observer : m_observers)
	{
		observer->handle_event(event_ptr);
	}
}

inline void Observable::attach_observer(const Observer::ShrPtr& observer_ptr)
{
	m_observers.push_back(observer_ptr);
}

inline void Observable::detach_observer(const Observer::ShrPtr& observer_ptr)
{
	m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer_ptr), m_observers.end());
}


}} // namespace game::observer

#endif // INCLUDED_OBSERVER_OBSERVABLE_HPP
