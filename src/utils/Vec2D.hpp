//=================================================
// @brief Header file for Vec2D class.
//=================================================

#ifndef INCLUDED_UTILS_VEC2D_HPP
#define INCLUDED_UTILS_VEC2D_HPP

#include <SFML/Graphics.hpp>

namespace game {
namespace utils {

/**
 * @brief Represents a 2D vector.
 */
struct Vec2D
{
	float x;
	float y;

	/**
	 * @brief Construct a vector from a x and y value.
	 */
	Vec2D(const float x, const float y);

	/**
	 * @brief Construct a vector from an sf::Vector2f
	 */
	Vec2D(const sf::Vector2f& vec);

	/**
	 * @brief Comparison operator.
	 */
	bool operator<(const Vec2D& rhs) const;

	/**
	 * @brief Scalar multiplication.
	 */
	Vec2D& operator*=(const double factor);

	/**
	 * @brief Addition.
	 */
	Vec2D operator+(const Vec2D& rhs) const;

	/**
	 * @brief Convert to a sf::Vector2f
	 */
	sf::Vector2f to_sfml(void) const;

	/**
	 * @brief Retrieve the textual representation of the vector.
	 */
	std::string to_string(void) const;
};

}} // namespace game::utils

#endif // INCLUDED_UTILS_VEC2D_HPP


