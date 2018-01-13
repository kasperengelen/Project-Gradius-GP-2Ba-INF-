//==================================================
// @brief Implementation of Transformation.hpp.
//==================================================

#include "Transformation.hpp"

namespace game {
namespace utils {

Vec2D Transformation::to_screen_coords(const Vec2D& model_coord) const
{
	const float delta_width = (float) m_screen_width / 8.0f;   // [-4, 4]
	const float delta_height = (float) m_screen_height / 6.0f; // [-3, 3]

	const float screen_mid_x = (float) m_screen_width / 2.0f;
	const float screen_mid_y = (float) m_screen_height / 2.0f;

	const float screen_x = screen_mid_x + (model_coord.x * delta_width);
	const float screen_y = screen_mid_y - (model_coord.y * delta_height);

	return {screen_x, screen_y};
}

void Transformation::update_screen_size(const unsigned int width, const unsigned int height)
{
	m_screen_width = width;
	m_screen_height = height;
}

}} // namespace game::utils


