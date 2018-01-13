//============================================
// @brief Implementation of Transformation.hpp.
//============================================

#include "CoordTransform.hpp"

#include "../exception/CoordTransformException.hpp"

#include <iostream>

namespace game {
namespace utils {


Vec2D CoordTransform::to_screen_coord(const Vec2D& model_coord) const
{
	// check if coordinate is in range
	const float height_delta = (float) m_screen_height / m_max_y;
	const float width_delta = (float) m_screen_width / m_max_x;


	//const float screen_y = m_screen_height - (height_delta * model_coord.y);

	float screen_y;
	if(m_player_pos.y >= (m_max_y / 2.0f) and m_player_pos.y <= (m_level_height - (m_max_y / 2.0f)))
	{
		const float screen_middle = (float) m_screen_height / 2.0f;
		const float dev_from_center = (model_coord.y - m_player_pos.y) * height_delta;

		screen_y = screen_middle - dev_from_center;
	}
	else if(m_player_pos.y < (m_max_y / 2.0f))
	{
		screen_y = m_screen_height - (height_delta * model_coord.y);
	}
	else if (m_player_pos.y > (m_level_height - (m_max_y / 2.0f)))
	{
		screen_y = (m_level_height - model_coord.y) * height_delta;
	}
	else
	{
		throw exception::coordtransform::ToScreenCoordException{"Invalid error while transforming y-coordinate."};
	}

	// determine x coordinate
	float screen_x;
	if(m_player_pos.x >= (m_max_x / 2.0f) and m_player_pos.x <= (m_level_width - (m_max_x / 2.0f)))
	// world borders arent on screen, position needs to be in range of player
	{
		// middle of the screen
		const float screen_middle = (float) m_screen_width / 2.0f;

		// we determine the amount of pixels that the object deviates from the center.
		const float dev_from_center = (model_coord.x - m_player_pos.x) * width_delta;

		screen_x = screen_middle + dev_from_center;

	}
	else if (m_player_pos.x < (m_max_x / 2.0f))
	// left world border on screen
	{
		// direct map from original coords to screen coords
		screen_x = width_delta * model_coord.x;
	}
	else if (m_player_pos.x > (m_level_width - (m_max_x / 2.0f)))
	// right world border on screen
	{
		screen_x = (model_coord.x - (m_level_width - m_max_x)) * width_delta;
	}
	else
	{
		throw exception::coordtransform::ToScreenCoordException{"Invalid error while transforming x-coordinate."};
	}

	return {screen_x, screen_y};
}

void CoordTransform::update_screen_size(const unsigned int width, const unsigned int height)
{
	m_screen_width = width;
	m_screen_height = height;
}

void CoordTransform::update_level_width(const unsigned int width)
{
	m_level_width = width;
}

void CoordTransform::update_level_height(const unsigned int height)
{
	m_level_height = height;
}

void CoordTransform::update_player_pos(const Vec2D& player_coord)
{
	m_player_pos = player_coord;
}

float CoordTransform::get_max_x_coord(void) const
{
	return m_max_x;
}

float CoordTransform::get_max_y_coord(void) const
{
	return m_max_y;
}

void CoordTransform::set_max_x_coord(const float max_x)
{
	m_max_x = max_x;
}

void CoordTransform::set_max_y_coord(const float max_y)
{
	m_max_y = max_y;
}

}} // namespace game::utils
