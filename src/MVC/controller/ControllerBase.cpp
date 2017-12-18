//======================================
// @brief Implementation of ControllerBase.hpp
//======================================

#include "ControllerBase.hpp"
#include "../model/ModelBase.hpp"
using game::MVC::model::ModelBase;

namespace game {
namespace MVC {
namespace controller {

ControllerBase::ControllerBase(const ModelBase::ShrPtr& model_ptr)
	: m_model(model_ptr)
{}

ControllerBase::~ControllerBase(void)
{}

}}} // namespace game::MVC::controller


