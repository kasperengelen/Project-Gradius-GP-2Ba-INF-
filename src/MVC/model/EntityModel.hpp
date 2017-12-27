//===================================================
// @brief Header file for EntityModel class.
//===================================================

#ifndef INCLUDED_MVC_MODEL_ENTITYMODEL_HPP
#define INCLUDED_MVC_MODEL_ENTITYMODEL_HPP

#include <SFML/Graphics.hpp>

#include <memory>

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Base class for all entity models. This represents an Entity that has a position.
 */
class EntityModel
{
private:
	sf::Vector2f m_pos; // current position in world

public:
	using ShrPtr = std::shared_ptr<EntityModel>;

	/**
	 * @brief Constructor for an EntityModel based on a position.
	 */
	EntityModel(const sf::Vector2f& pos);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityModel(void);

	/**
	 * @brief Retrieve the position of the entity.
	 */
	const sf::Vector2f& get_position(void) const;

	/**
	 * @brief Set the position of the entity.
	 */
	void set_position(const sf::Vector2f& pos);

	/**
	 * @brief Handle a game tick.
	 */
	virtual void do_game_tick(void) = 0;

};


}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_ENTITYMODEL_HPP

