//==================================================
// @brief Header file for Text class.
//==================================================

#ifndef INCLUDED_IOHANDLERS_TEXT_HPP
#define INCLUDED_IOHANDLERS_TEXT_HPP

#include "../utils/Vec2D.hpp"

#include <SFML/Graphics.hpp>
#include <string>

namespace game {
namespace IOhandlers {

class Text
{
public:
	enum class FontColor
	{
		RED,
		GREEN,
		BLUE,
		WHITE,
		BLACK
	};

private:
	sf::Text m_text;
	sf::Font m_font;
	bool m_centered;

	void M_center_text(void);

public:
	/**
	 * @brief Initialize a text object.
	 *
	 * @param[in] centered Specifies whether the text should be centered.
	 */
	Text(const bool centered);

	/**
	 * @brief Set the text.
	 */
	void set_string(const std::string& new_content);

	/**
	 * @brief Select the font and the font color that the text will be rendered with.
	 *
	 * @param[in] font_filename The filename of the font.
	 * @param[in] color The color of the text.
	 * @param[in] size The size of the text.
	 */
	bool set_font(const std::string& font_filename, const FontColor& color, const unsigned int size);

	/**
	 * @brief Set the position where the text needs to be located.
	 */
	void set_position(const utils::Vec2D& pos);

	/**
	 * @brief Retrieve the underlying sf::Text object.
	 */
	const sf::Text& to_sfml(void) const;
};

}} // namespace game::IOhandlers

#endif // INCLUDED_IOHANDLERS_TEXT_HPP
