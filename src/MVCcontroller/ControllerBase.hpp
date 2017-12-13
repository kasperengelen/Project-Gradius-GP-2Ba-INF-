//=========================================
// @brief Header file for ControllerBase class.
//=========================================

#ifndef INCLUDED_MVCCONTROLLER_CONTROLLERBASE_HPP
#define INCLUDED_MVCCONTROLLER_CONTROLLERBASE_HPP

#include "../MVCmodel/ModelBase.hpp"

#include <memory>

using game::MVCmodel::ModelBase;

namespace game {
namespace MVCcontroller {

/**
 * @brief Abstract base class for controller classes.
 */
class ControllerBase
{
protected:
	MVCmodel::ModelBase::ShrPtr m_model;
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
};

}} // namespace game::MVCcontroller



#endif // INCLUDED_MVCCONTROLLER_CONTROLLERBASE_HPP
