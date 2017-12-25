//====================================================
// @brief Implementation of Sprite.hpp.
//====================================================

#include "Sprite.hpp"
#include "../exception/SpriteException.hpp"

namespace game {
namespace IOhandlers {

Sprite::Sprite(const std::string& filename)
{
	if(not m_tex.loadFromFile(filename))
	{
		throw exception::IOhandlers::sprite::LoadFromFileException{filename};
	}

	m_sprite.setTexture(m_tex);
	m_sprite.setOrigin(m_tex.getSize().x / 2.0f, m_tex.getSize().y / 2.0f);
}

void Sprite::set_position(const float x, const float y)
{
	m_sprite.setPosition(x, y);
}

const sf::Sprite& Sprite::get_sfml_sprite(void) const
{
	return m_sprite;
}

const sf::Texture& Sprite::get_sfml_texture(void) const
{
	return m_tex;
}

}} // namespace game::IOhandlers
