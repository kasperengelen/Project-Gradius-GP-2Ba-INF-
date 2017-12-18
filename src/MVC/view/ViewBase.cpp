//========================================
// @brief Implementation of ViewBase.hpp
//========================================

#include "ViewBase.hpp"

namespace game {
namespace MVC {
namespace view {

ViewBase::ViewBase(const ModelBase::ShrPtr& model_ptr)
	: m_model(model_ptr)
{}

ViewBase::~ViewBase(void)
{}



}}} // namespace game::MVC::view

