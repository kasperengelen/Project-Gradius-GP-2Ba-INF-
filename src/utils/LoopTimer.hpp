//======================================
//	@brief Header file for LoopTimer class.
//======================================

#ifndef INCLUDED_UTILS_LOOPTIMER_HPP
#define INCLUDED_UTILS_LOOPTIMER_HPP

#include <chrono>

namespace game {
namespace utils
{

/**
 * @brief Class that is responsible for handling the main loop.
 */
class LoopTimer
{
private:
	double m_ticks_per_sec;

	double m_ticks_todo;
	std::chrono::steady_clock::time_point m_timestamp_last_loop;


	unsigned int m_tick_counter;
	unsigned int m_frame_counter;
	std::chrono::steady_clock::time_point m_tracker_reset_timestamp;

public:
	struct PerformanceInfo
	{
		const double fps;
		const double tps;
	};

	/**
	 * @brief Constructor specifying the amount of ticks per second.
	 */
	LoopTimer(const float tps);

	/**
	 * @brief Report that a new iteration is being initiated.
	 */
	void report_new_iteration(void);

	/**
	 * @brief Report that a game tick has been completed.
	 */
	void report_tick_done(void);

	/**
	 * @brief Report that a render has been completed.
	 */
	void report_render_done(void);

	/**
	 * @brief Query whether a tick needs to be performed.
	 */
	bool is_tick_needed(void) const;

	/**
	 * @brief Query whether a performance readout needs to be performed.
	 */
	bool needs_performance_printout(void) const;

	/**
	 * @brief Retrieve information about the performance. This will return the TPS and FPS.
	 */
	const PerformanceInfo get_performance_info(void) const;

	/**
	 * @brief Reset the performance profiler.
	 */
	void reset_performance_tracker(void);
};

}} // namespace game::utils



#endif // INCLUDED_UTILS_LOOPTIMER_HPP
