//============================================
// @brief Header file for Transformation class.
//============================================

#ifndef INCLUDED_UTILS_TRANSFORMATION_HPP
#define INCLUDED_UTILS_TRANSFORMATION_HPP

#include "Singleton.hpp"
#include "Vec2D.hpp"

namespace game {
namespace utils {

class Transformation : public Singleton<Transformation>
{
private:
	friend Singleton;

	Transformation(void) = default;
	virtual ~Transformation(void) = default;
	Transformation(const Transformation&) = delete;
	Transformation& operator=(const Transformation&) = delete;

	unsigned int m_screen_width{0};
	unsigned int m_screen_height{0};

public:
	/**
	 * @brief Convert the specified model coordinates to screen coordinates.
	 */
	Vec2D to_screen_coords(const Vec2D& model_coord) const;

	/**
	 * @brief Notify the Transformation class that the screen size has changed.
	 */
	void update_screen_size(const unsigned int width, const unsigned int height);
};

}} // namespace game::utils




#endif // INCLUDED_UTILS_TRANSFORMATION_HPP
