//=============================================
// @brief Implementation of EntityRepresentation.hpp
//=============================================

#include "EntityRepresentation.hpp"

namespace game {
namespace entity {

EntityRepresentation::EntityRepresentation(const EntityBase::ShrPtr& model_ptr, const IOhandlers::Sprite& sprite)
	: m_entityptr{model_ptr}, m_sprite{sprite}
{}

EntityRepresentation::~EntityRepresentation(void)
{}

void EntityRepresentation::render(IOhandlers::Window& window)
{
	m_sprite.set_position(m_entityptr->get_position());
	window.draw(m_sprite.get_sfml_sprite());
}

}} // namespace game::entity


