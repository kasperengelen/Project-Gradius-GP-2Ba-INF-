//====================================================
// @brief Implementation of Sprite.hpp.
//====================================================

#include "Sprite.hpp"
#include "../exception/SpriteException.hpp"

namespace game {
namespace IOhandlers {

Sprite::Sprite(const std::string& filename)
{
	if(not m_texture.loadFromFile(filename))
	{
		throw exception::sprite::LoadFromFileException{filename};
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2.0f, m_texture.getSize().y / 2.0f);
}

Sprite::Sprite(const Sprite& old)
{
	// copy texture
	m_texture = old.m_texture;
	// create new sf::Sprite based on the texture since sf::Sprite's are just handles.
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2.0f, m_texture.getSize().y / 2.0f);
}

void Sprite::set_position(const utils::Vec2D& pos)
{
	m_sprite.setPosition(pos.to_sfml());
}

utils::Vec2D Sprite::get_position(void) const
{
	return m_sprite.getPosition();
}

void Sprite::set_scale(const float scale)
{
	m_sprite.setScale(scale, scale);
}

unsigned int Sprite::get_width(void) const
{
	return m_texture.getSize().x;
}

unsigned int Sprite::get_height(void) const
{
	return m_texture.getSize().y;
}

const sf::Sprite& Sprite::get_sfml_sprite(void) const
{
	return m_sprite;
}

const sf::Texture& Sprite::get_sfml_texture(void) const
{
	return m_texture;
}

}} // namespace game::IOhandlers
