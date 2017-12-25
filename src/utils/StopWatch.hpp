//===================================================
// @brief Header file for StopWatch class.
//===================================================

#ifndef INCLUDED_UTILS_STOPWATCH_HPP
#define INCLUDED_UTILS_STOPWATCH_HPP

#include "../utils/Singleton.hpp"

#include <chrono>

namespace game {
namespace utils {

/**
 * @brief Class that implements a simple stopwatch.
 */
class StopWatch: public game::misc::Singleton<StopWatch>
{
public:
	using TimeStamp = std::chrono::steady_clock::time_point;
	using Clock = std::chrono::steady_clock;
	using NanoSec = std::chrono::nanoseconds;
	using MicroSec = std::chrono::nanoseconds;
	using MilliSec = std::chrono::milliseconds;
	using Sec = std::chrono::seconds;
	using Min = std::chrono::minutes;
	using Hour = std::chrono::hours;

private:
	friend Singleton;
	StopWatch(void) = default;
	virtual ~StopWatch(void) = default;
	StopWatch(const StopWatch&) = delete;
	StopWatch& operator=(const StopWatch&) = delete;

	TimeStamp m_timestamp;
public:
	/**
	 * @brief Retrieve the amount of time that has passed since the last reset.
	 * The template parameter specifies in what time unit the result will be stored.
	 */
	template <typename TimeUnit = Sec>
	const int get(void) const
	{
		const auto delta = std::chrono::duration_cast<TimeUnit>(Clock::now() - m_timestamp);

		return delta.count();
	}

	/**
	 * @brief Reset the stopwatch.
	 */
	void reset(void)
	{
		m_timestamp = Clock::now();
	}
};

}} // namespace game::utils



#endif // INCLUDED_UTILS_STOPWATCH_HPP
