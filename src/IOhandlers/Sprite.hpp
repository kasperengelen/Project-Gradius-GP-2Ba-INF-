//====================================================
// @brief Header file for Sprite class.
//====================================================

#include <SFML/Graphics.hpp>

#ifndef IOHANDLERS_SPRITE_HPP
#define IOHANDLERS_SPRITE_HPP

namespace game {
namespace IOhandlers {

/**
 * @brief Class that represents a sprite.
 */
class Sprite
{
private:
	sf::Sprite m_sprite;
	sf::Texture m_tex;
public:
	/**
	 * @brief Construct a sprite from an image file.
	 */
	Sprite(const std::string& filename);

	/**
	 * @brief Set the position of the sprite.
	 */
	void set_position(const float x, const float y);

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


#endif // IOHANDLERS_SPRITE_HPP
