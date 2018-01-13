//=========================================
// @brief Header file for EntityRepresentation class.
//=========================================


#ifndef INCLUDED_ENTITY_ENTITYREPRESENTATION_HPP
#define INCLUDED_ENTITY_ENTITYREPRESENTATION_HPP

#include "EntityBase.hpp"
#include "../IOhandlers/Sprite.hpp"
#include "../IOhandlers/Window.hpp"

#include "../observer/Observer.hpp"

namespace game {
namespace entity {

/**
 * @brief Base class for entity views.
 */
class EntityRepresentation : public observer::Observer
{
public:
	/**
	 * @brief Specifies what should be done if two entityrepresentations overlap.
	 */
	enum class Depth
	{
		BACKGROUND,
		MIDDLE,
		FOREGROUND
	};
private:
	EntityBase::WkPtr m_entityptr;
	IOhandlers::Sprite m_sprite;

	utils::Vec2D m_entitypos;
	Depth m_depth;

	float m_size;

public:
	using ShrPtr = std::shared_ptr<EntityRepresentation>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] entity_ptr Weak pointer to the entity. This is to check if the entity is still alive.
	 * @param[in] sprite The sprite that is drawn to the screen.
	 * @param[in] init_pos The initial position of the entity (in model coordinates, not screen coordinates).
	 * @param[in] depth The Z-value of the entity: Background, middle or foreground.
	 * @param[in] size The diameter of the entity. This is used to scale the sprite to the proportions of the entity.
	 */
	EntityRepresentation(const EntityBase::WkPtr& entity_ptr,
						 const IOhandlers::Sprite& sprite,
						 const utils::Vec2D& init_pos,
						 const Depth& depth,
						 const float size);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityRepresentation(void);

	/**
	 * @brief Render the entity view to a window.
	 */
	void render(IOhandlers::Window& window);

	/**
	 * @brief Determine if the entity that is represented by the EntityRepresentation is still alive.
	 */
	bool is_alive(void) const;

	/**
	 * @brief Retrieve the depth of the entity representation.
	 */
	const Depth& get_depth(void) const;

	/**
	 * @brief Event handler method for the Observer Pattern.
	 */
	void handle_event(const observer::Event::ShrPtr& event_ptr);

	/**
	 * @brief Less than operator so that EntityRepresentations can be sorted.
	 */
	bool operator<(const EntityRepresentation& other) const;
};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_ENTITYREPRESENTATION_HPP

