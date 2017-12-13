//======================================
// @brief Implementation of ControllerBase.hpp
//======================================

#include "ControllerBase.hpp"

namespace game {
namespace MVCcontroller {

ControllerBase::ControllerBase(const ModelBase::ShrPtr& model_ptr)
	: m_model(model_ptr)
{}

ControllerBase::~ControllerBase(void)
{}

}} // namespace game::MVCcontroller


