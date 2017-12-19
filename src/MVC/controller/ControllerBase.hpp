//=========================================
// @brief Header file for ControllerBase class.
//=========================================

#ifndef INCLUDED_MVC_CONTROLLER_CONTROLLERBASE_HPP
#define INCLUDED_MVC_CONTROLLER_CONTROLLERBASE_HPP

#include "../model/ModelBase.hpp"
using game::MVC::model::ModelBase;
#include "../../IOhandlers/IOEvent.hpp"

#include <SFML/Window.hpp>

#include <memory>

namespace game {
namespace MVC {
namespace controller {

/**
 * @brief Abstract base class for controller classes.
 */
class ControllerBase
{
protected:
	ModelBase::ShrPtr m_model;
public:
	using UnqPtr = std::shared_ptr<ControllerBase>;

	/**
	 * @brief Construct a controller for a model.
	 */
	ControllerBase(const ModelBase::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	virtual ~ControllerBase(void);

	/**
	 * @brief Notify the controller that a game tick has to be performed.
	 */
	virtual void handle_tick(void) = 0;

	/**
	 * @brief Send the specified event to the controller.
	 */
	virtual void handle_event(const IOhandlers::IOEvent& event) = 0;
};

}}} // namespace game::MVC::controller



#endif // INCLUDED_MVC_CONTROLLER_CONTROLLERBASE_HPP
