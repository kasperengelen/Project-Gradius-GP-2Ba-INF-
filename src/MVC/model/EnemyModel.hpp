//====================================
// @brief Header file for EnemyModel class.
//====================================

#ifndef MVC_MODEL_ENEMYMODEL_HPP
#define MVC_MODEL_ENEMYMODEL_HPP

#include "EntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

class EnemyModel: public EntityModel
{
private:

public:
	/**
	 * @brief Constructor.
	 *
	 * @post The constructor entity will be located at (0,0).
	 */
	EnemyModel(void);

	/**
	 * @brief Constructor based on a position.
	 */
	EnemyModel(const sf::Vector2f& pos);

	/**
	 * @brief Destructor.
	 */
	virtual ~EnemyModel(void);

	/**
	 * @brief Perform game tick on model.
	 */
	virtual void do_game_tick(void) override;
};

}}} // namespace game::MVC::model

#endif // MVC_MODEL_ENEMYMODEL_HPP
