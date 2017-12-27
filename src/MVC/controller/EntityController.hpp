//=========================================
// @brief Header file for EntityController class.
//=========================================

#ifndef INCLUDED_MVC_CONTROLLER_ENTITYCONTROLLER_HPP
#define INCLUDED_MVC_CONTROLLER_ENTITYCONTROLLER_HPP

// include base
#include "EntityControllerBase.hpp"

namespace game {
namespace MVC {
namespace controller {

/**
 * @brief Templatized controller for entities.
 */
template <typename EntityType>
class EntityController final: public EntityControllerBase
{
private:
public:
	using UnqPtr = std::unique_ptr<EntityController<EntityType>>;

	/**
	 * @brief Constructor based on a model pointer.
	 */
	EntityController(const typename EntityType::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	~EntityController(void);

	/**
	 * @brief Notify the controller that the specified event has occurred.
	 */
	void handle_ioevent(const IOhandlers::IOEvent& ev) override;

	/**
	 * @brief Notify the controller that a game tick needs to be performed.
	 */
	void handle_game_tick(void) override;
};

template <typename EntityType>
EntityController<EntityType>::EntityController(const typename EntityType::ShrPtr& model_ptr)
	: EntityControllerBase{model_ptr}
{}

template <typename EntityType>
EntityController<EntityType>::~EntityController(void)
{}

}}} // namespace game::MVC::controller

#endif // INCLUDED_MVC_CONTROLLER_ENTITYCONTROLLER_HPP
