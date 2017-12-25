//==================================================
// @brief Header file for EntityController class.
//==================================================

#ifndef MVC_CONTROLLER_ENTITYCONTROLLER_HPP
#define MVC_CONTROLLER_ENTITYCONTROLLER_HPP

#include "../model/EntityModel.hpp"

#include "../../IOhandlers/IOEvent.hpp"

namespace game {
namespace MVC {
namespace controller {

class EntityController
{
protected:
	model::EntityModel::ShrPtr m_model;

public:
	using UnqPtr = std::unique_ptr<EntityController>;

	/**
	 * @brief Constructor.
	 */
	EntityController(const model::EntityModel::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	virtual ~EntityController(void);

	/**
	 * @brief Handle a game tick.
	 */
	virtual void handle_tick(void) = 0;

	/**
	 * @brief Handle an IOEvent.
	 */
	virtual void handle_event(const IOhandlers::IOEvent& event) = 0;
};

}}} // namespace game::MVC::controller

#endif // MVC_CONTROLLER_ENTITYCONTROLLER_HPP
