//======================================
//	@brief Implementation of LoopTimer.hpp
//======================================

#include "LoopTimer.hpp"

#include <iostream>

namespace game {
namespace utils {

using clock = std::chrono::steady_clock;

LoopTimer::LoopTimer(const float tps)
{
	m_ticks_per_sec = tps;

	m_timestamp_last_loop = clock::now();
	m_ticks_todo = 0;

	m_tick_counter = 0;
	m_frame_counter = 0;
	m_tracker_reset_timestamp = clock::now();
}

void LoopTimer::report_new_iteration(void)
{
	// determine seconds since beginning of last loop
	const std::chrono::duration<double> delta = clock::now() - m_timestamp_last_loop;

	// new ticks = seconds * ticks per second
	m_ticks_todo += (delta.count() * m_ticks_per_sec);

	m_timestamp_last_loop = clock::now();
}

void LoopTimer::report_tick_done(void)
{
	m_ticks_todo--;
	m_tick_counter++;
}

void LoopTimer::report_render_done(void)
{
	m_frame_counter++;
}

bool LoopTimer::is_tick_needed(void) const
{
	return m_ticks_todo >= 1;
}

bool LoopTimer::needs_performance_printout(void) const
{
	// DETERMINE IF THE LAST PRINTOUT WAS >= 1 SEC AGO

	const std::chrono::duration<double> secs_since_last_reset = clock::now() - m_tracker_reset_timestamp;

	return (secs_since_last_reset.count() > 1);
}

LoopTimer::PerformanceInfo LoopTimer::get_performance_info(void) const
{
	const std::chrono::duration<double> secs_since_last_reset = clock::now() - m_tracker_reset_timestamp;

	const double tps = (double) m_tick_counter / secs_since_last_reset.count();
	const double fps = (double) m_frame_counter / secs_since_last_reset.count();

	return {fps, tps};
}

void LoopTimer::reset_performance_tracker(void)
{
	m_tick_counter = 0;
	m_frame_counter = 0;
	m_tracker_reset_timestamp = clock::now();
}

}} // namespace game::utils

