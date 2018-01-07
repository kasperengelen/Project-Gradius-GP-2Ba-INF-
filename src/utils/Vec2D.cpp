//======================================================
// @brief Implementation of Vec2D.hpp.
//======================================================

#include "Vec2D.hpp"

namespace game {
namespace utils {

Vec2D::Vec2D(const float x, const float y)
	: x{x}, y{y}
{}

Vec2D::Vec2D(const sf::Vector2f& vec)
	: x{vec.x}, y{vec.y}
{}

bool Vec2D::operator<(const Vec2D& rhs) const
{
	return std::tie(x, y) < std::tie(rhs.x, rhs.y);
}

Vec2D& Vec2D::operator*=(const double factor)
{
	x *= factor;
	y *= factor;

	return *this;
}

Vec2D Vec2D::operator+(const Vec2D& rhs) const
{
	return {x + rhs.x, y + rhs.y};
}

const sf::Vector2f Vec2D::to_sfml(void) const
{
	return {x, y};
}

const std::string Vec2D::to_string(void) const
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

}} // namespace game::utils
