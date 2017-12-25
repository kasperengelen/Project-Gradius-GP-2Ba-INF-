//==================================================
// @brief Header file for EntityModel class.
//==================================================

#ifndef MVC_MODEL_ENTITYMODEL_HPP
#define MVC_MODEL_ENTITYMODEL_HPP

#include <SFML/Graphics.hpp>
#include <memory>

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Base class for EntityModels
 */
class EntityModel
{
protected:
	sf::Vector2f m_position;  // current position of the entity.
	sf::Vector2f m_direction; // direction and speed the entity.

public:
	using ShrPtr = std::shared_ptr<EntityModel>;

	/**
	 * @brief Constructor.
	 *
	 * @post The constructor entity will be located at (0,0).
	 */
	EntityModel(void);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityModel(void);

	/**
	 * @brief Handle a game tick.
	 */
	virtual void do_game_tick(void) = 0;

	/**
	 * @brief Retrieve the position of the entity.
	 */
	const sf::Vector2f get_position(void) const;

	/**
	 * @brief Set the position of the entity.
	 */
	void set_position(const sf::Vector2f& pos);

	/**
	 * @brief Retrieve the direction vector of the entity.
	 */
	const sf::Vector2f get_direction(void) const;

	/**
	 * @brief Set the the direction vector of the entity.
	 */
	void set_direction(const sf::Vector2f& dir);

};

}}} // namespace game::MVC::model

#endif // MVC_MODEL_ENTITYMODEL_HPP
