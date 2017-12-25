//===========================================
// @brief Header file for EnemyController class.
//===========================================

#ifndef MVC_CONTROLLER_ENEMYCONTROLLER_HPP
#define MVC_CONTROLLER_ENEMYCONTROLLER_HPP

#include "EnemyController.hpp"
#include "../model/EnemyModel.hpp"
#include "EntityController.hpp"

namespace game {
namespace MVC {
namespace controller {

/**
 * @brief Class that represents a controller for an enemy.
 */
class EnemyController: public EntityController
{
private:
public:
	/**
	 * @brief Construct a controller based on a pointer to an EnemyModel.
	 */
	EnemyController(const model::EnemyModel::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	virtual ~EnemyController(void);

	/**
	 * @brief Handle a game tick.
	 */
	virtual void handle_tick(void) override;

	/**
	 * @brief Handle an IOEvent.
	 */
	virtual void handle_event(const IOhandlers::IOEvent& event) override;

};

}}} // namespace game::MVC::controller

#endif // MVC_CONTROLLER_ENEMYCONTROLLER_HPP
