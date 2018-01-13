//=============================================
// @brief Implementation of EntityRepresentation.hpp
//=============================================

#include "EntityRepresentation.hpp"
#include "../observer/Event.hpp"
#include "../utils/CoordTransform.hpp"
#include "../utils/Settings.hpp"

#include <iostream>

using namespace game::observer;
using game::utils::CoordTransform;

namespace game {
namespace entity {

EntityRepresentation::EntityRepresentation(const EntityBase::WkPtr& entity_ptr,
										   const IOhandlers::Sprite& sprite,
										   const utils::Vec2D& init_pos,
										   const Depth& depth,
										   const float size)
	: m_entityptr{entity_ptr},
	  m_sprite{sprite},
	  m_entitypos{init_pos},
	  m_depth{depth},
	  m_size{size}
{}

EntityRepresentation::~EntityRepresentation(void)
{}

void EntityRepresentation::render(IOhandlers::Window& window)
{
	// entities that are slightly off screen still need to be rendered
	const float margin_x = (float) window.get_width() * 0.20f;
	const float margin_y = (float) window.get_height() * 0.20f;

	m_sprite.set_position(CoordTransform::get_instance().to_screen_coord(m_entitypos));

	// rescale sprite
	const float delta_y = (float) window.get_height() / utils::CoordTransform::get_instance().get_max_y_coord();
	const float new_height = m_size * delta_y;
	const float scale_y = new_height / (float) m_sprite.get_height();

	const float delta_x = (float) window.get_width() / utils::CoordTransform::get_instance().get_max_x_coord();
	const float new_width = m_size * delta_x;
	const float scale_x = new_width / (float) m_sprite.get_width();


	m_sprite.set_scale(std::fmin(scale_y, scale_x));


	if(m_sprite.get_position().x <= (window.get_width() + margin_x)
			and m_sprite.get_position().x >= 0 - margin_x
			and m_sprite.get_position().y <= window.get_height() + margin_y
			and m_sprite.get_position().y >= 0 - margin_y)
	{

		window.draw(m_sprite.get_sfml_sprite());

		if(utils::Settings::get_instance().get_show_hitboxes())
		{
			// create circle
			sf::CircleShape hitbox_outline{(m_size / 2.0f) * delta_x};

			// set colors
			hitbox_outline.setFillColor(sf::Color::Transparent);
			hitbox_outline.setOutlineColor(sf::Color::Green);
			hitbox_outline.setOutlineThickness(2);

			// set position
			hitbox_outline.setPosition(CoordTransform::get_instance().to_screen_coord(m_entitypos).to_sfml());
			hitbox_outline.setOrigin(hitbox_outline.getRadius(), hitbox_outline.getRadius());

			// draw
			window.draw(hitbox_outline);
		}
	}
}

bool EntityRepresentation::is_alive(void) const
{
	return not m_entityptr.expired();
}

void EntityRepresentation::handle_event(const observer::Event::ShrPtr& event_ptr)
{
	const Event* p = event_ptr.get();

	if(const EntityMove* em_ptr = dynamic_cast<const EntityMove*>(p))
	{
		m_entitypos = em_ptr->new_pos;
	}
}

const EntityRepresentation::Depth& EntityRepresentation::get_depth(void) const
{
	return m_depth;
}

bool EntityRepresentation::operator<(const EntityRepresentation& other) const
{
	if(m_depth == other.m_depth)
	{
		return m_entityptr.lock().get() < other.m_entityptr.lock().get();
	}
	else
	{
		return m_depth < other.m_depth;
	}
}

}} // namespace game::entity


