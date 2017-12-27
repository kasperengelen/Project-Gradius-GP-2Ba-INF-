//=================================================
// @brief Header file for EnemyControllerBase class.
//=================================================

#ifndef INCLUDED_MVC_CONTROLLER_ENTITYCONTROLLERBASE_HPP
#define INCLUDED_MVC_CONTROLLER_ENTITYCONTROLLERBASE_HPP

#include "../model/EntityModel.hpp"
#include "../../IOhandlers/IOEvent.hpp"

namespace game {
namespace MVC {
namespace controller {

/**
 * @brief Base class for entity controllers.
 */
class EntityControllerBase
{
private:
	model::EntityModel::ShrPtr m_modelptr;
public:
	using UnqPtr = std::unique_ptr<EntityControllerBase>;

	/**
	 * @brief Constructor based on a pointer to a model.
	 */
	EntityControllerBase(const model::EntityModel::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityControllerBase(void);

	/**
	 * @brief Retrieve the model that the controller controls.
	 */
	const model::EntityModel::ShrPtr& get_model(void) const;

	/**
	 * @brief Notifies the controller that the specified event has occurred.
	 */
	virtual void handle_ioevent(const IOhandlers::IOEvent& ev) = 0;

	/**
	 * @brief Notify the controller that a game tick needs to be performed.
	 */
	virtual void handle_game_tick(void) = 0;
};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_CONTROLLER_ENTITYCONTROLLERBASE_HPP
