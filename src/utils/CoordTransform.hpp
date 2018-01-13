//============================================
// @brief Header file for CoordTransform class.
//============================================

#ifndef INCLUDED_UTILS_COORDTRANSFORM_HPP
#define INCLUDED_UTILS_COORDTRANSFORM_HPP

#include "Singleton.hpp"
#include "Vec2D.hpp"

namespace game {
namespace utils {

class CoordTransform: public Singleton<CoordTransform>
{
private:
	friend Singleton;
	CoordTransform(void) = default;
	virtual ~CoordTransform(void) = default;
	CoordTransform(const CoordTransform&) = delete;
	CoordTransform& operator=(const CoordTransform&) = delete;

	unsigned int m_screen_height{0};
	unsigned int m_screen_width{0};

	int m_level_width{0};
	int m_level_height{0};

	float m_max_x{0};
	float m_max_y{0};

	Vec2D m_player_pos{0,0};

public:
	/**
	 * @brief Convert the a coordinate belonging to the coordinate system of
	 * GameModel to a screen coordinate.
	 */
	Vec2D to_screen_coord(const Vec2D& model_coords) const;

	/**
	 * @brief Update the width and height of the screen
	 */
	void update_screen_size(const unsigned int width, const unsigned int height);

	/**
	 * @brief Specify the total width of the level.
	 */
	void update_level_width(const unsigned int width);

	/**
	 * @brief Specify the total height of the level.
	 */
	void update_level_height(const unsigned int height);

	/**
	 * @brief Retrieve the maximum x coordinate that is present on the screen.
	 */
	float get_max_x_coord(void) const;

	/**
	 * @brief Retrieve the maximum y coordinate that is present of the screen.
	 */
	float get_max_y_coord(void) const;

	/**
	 * @brief Set the maximum x coordinate that is present on the screen.
	 */
	void set_max_x_coord(const float max_x);

	/**
	 * @brief Set the maximum y coordinate that is present on the screen.
	 */
	void set_max_y_coord(const float max_y);

	/**
	 * @brief Notify the Transformation class of the current
	 * location of the player.
	 */
	void update_player_pos(const Vec2D& player_coord);

};



}} // namespace gamme::utils

#endif // INCLUDED_UTILS_COORDTRANSFORM_HPP
