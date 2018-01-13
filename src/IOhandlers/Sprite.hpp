//====================================================
// @brief Header file for Sprite class.
//====================================================

#include "../utils/Vec2D.hpp"
#include <SFML/Graphics.hpp>

#ifndef INCLUDED_IOHANDLERS_SPRITE_HPP
#define INCLUDED_IOHANDLERS_SPRITE_HPP

namespace game {
namespace IOhandlers {

/**
 * @brief Class that represents a sprite.
 */
class Sprite
{
private:
	sf::Texture m_texture;
	sf::Sprite  m_sprite;
public:
	/**
	 * @brief Construct a sprite from an image file.
	 */
	Sprite(const std::string& filename);

	/**
	 * @brief Copy constructor.
	 */
	Sprite(const Sprite& old);

	/**
	 * @brief Retrieve the position of the sprite.
	 */
	utils::Vec2D get_position(void) const;

	/**
	 * @brief Set the position of the sprite.
	 */
	void set_position(const utils::Vec2D& vec);

	/**
	 * @brief Set the scale of the sprite.
	 */
	void set_scale(const float scale);

	/**
	 * @brief Retrieve the width of the sprite in pixels (does not take the scale into account).
	 */
	unsigned int get_width(void) const;

	/**
	 * @brief Retrieve the height of the sprite in pixels (does not take the scale into account).
	 */
	unsigned int get_height(void) const;

	/**
	 * @brief Retrieve the sf::Sprite.
	 */
	const sf::Sprite& get_sfml_sprite(void) const;

	/**
	 * @brief Retrieve the sf::Texture.
	 */
	const sf::Texture& get_sfml_texture(void) const;
};

}} // namespace game::IOhandlers


#endif // INCLUDED_IOHANDLERS_SPRITE_HPP
