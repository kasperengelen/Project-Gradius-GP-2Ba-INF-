//====================================================
// @brief Header file for Sprite class.
//====================================================

#include "../utils/Vec2D.hpp"
using game::utils::Vec2D;
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
	sf::Texture m_tex;
	sf::Sprite m_sprite;
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
	 * @brief Set the position of the sprite.
	 */
	void set_position(const Vec2D& vec);

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
