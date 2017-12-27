//========================================
// @brief Header file for DynEntityModel class.
//========================================

#ifndef INCLUDED_MVC_MODEL_DYNENTITYMODEL_HPP
#define INCLUDED_MVC_MODEL_DYNENTITYMODEL_HPP

#include "EntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Base class for entities that have both a position and a direction vector.
 */
class DynEntityModel : public EntityModel
{
private:
	sf::Vector2f m_dir;
public:
	using ShrPtr = std::shared_ptr<DynEntityModel>;

	/**
	 * @brief Constructor based on a position and a direction vector.
	 */
	DynEntityModel(const sf::Vector2f& pos, const sf::Vector2f& dir);

	/**
	 * @brief Destructor.
	 */
	virtual ~DynEntityModel(void);

	/**
	 * @brief Retrieve the direction vector of the entity.
	 */
	const sf::Vector2f& get_dir(void) const;

	/**
	 * @brief Set the direction vector of the entity.
	 */
	void set_dir(const sf::Vector2f& dir);

	/**
	 * @brief Perform a game tick.
	 */
	virtual void do_game_tick(void) override = 0;
};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_DYNENTITYMODEL_HPP

