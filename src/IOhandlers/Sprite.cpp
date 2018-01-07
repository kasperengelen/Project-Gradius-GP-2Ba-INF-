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
		throw exception::sprite::LoadFromFileException{filename};
	}

	m_sprite.setTexture(m_tex);
	m_sprite.setOrigin(m_tex.getSize().x / 2.0f, m_tex.getSize().y / 2.0f);
}

Sprite::Sprite(const Sprite& old)
{
	// copy texture
	m_tex = old.m_tex;
	// create new sf::Sprite based on the texture since sf::Sprite's are just handles.
	m_sprite.setTexture(m_tex);
	m_sprite.setOrigin(m_tex.getSize().x / 2.0f, m_tex.getSize().y / 2.0f);
}

void Sprite::set_position(const Vec2D& pos)
{
	m_sprite.setPosition(pos.to_sfml());
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
