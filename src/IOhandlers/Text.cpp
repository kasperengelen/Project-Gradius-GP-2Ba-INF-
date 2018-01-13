//=============================================
// @brief Implementation of Text.hpp.
//=============================================

#include "Text.hpp"

#include <iostream>
#include <fstream>

namespace game {
namespace IOhandlers {

void Text::M_center_text(void)
{
	//SOURCE: https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
	sf::FloatRect text_rect = m_text.getLocalBounds();
	m_text.setOrigin(text_rect.left + text_rect.width  / 2.0f,
					 text_rect.top  + text_rect.height / 2.0f);
}

Text::Text(const bool centered)
	: m_centered{centered}
{}

void Text::set_string(const std::string& new_content)
{
	m_text.setString(new_content);

	if(m_centered)
		M_center_text();
}

bool Text::set_font(const std::string& font_filename, const FontColor& color, const unsigned int size)
{

	if(not m_font.loadFromFile(font_filename))
	{
		return false;
	}

	m_text.setFont(m_font);

	m_text.setCharacterSize(size);

	switch(color)
	{
	case FontColor::RED:
		m_text.setColor(sf::Color::Red);
		break;
	case FontColor::GREEN:
		m_text.setColor(sf::Color::Green);
		break;
	case FontColor::BLUE:
		m_text.setColor(sf::Color::Blue);
		break;
	case FontColor::BLACK:
		m_text.setColor(sf::Color::Black);
		break;
	case FontColor::WHITE:
		m_text.setColor(sf::Color::White);
		break;
	}

	if(m_centered)
		M_center_text();

	return true;
}

void Text::set_position(const utils::Vec2D& pos)
{
	m_text.setPosition(pos.to_sfml());
}

const sf::Text& Text::to_sfml(void) const
{
	return m_text;
}


}} // namespace game::IOhandlers

