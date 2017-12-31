//===============================================
// @brief Implementation of DynEntityModel.cpp.
//===============================================

#include "DynEntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

DynEntityModel::DynEntityModel(const sf::Vector2f& pos, const sf::Vector2f& dir)
	: EntityModel{pos}, m_dir{dir}
{}

DynEntityModel::~DynEntityModel(void)
{}

const sf::Vector2f& DynEntityModel::get_direction(void) const
{
	return m_dir;
}

void DynEntityModel::set_direction(const sf::Vector2f& dir)
{
	m_dir = dir;
}

}}} // namespace game::MVC::model

