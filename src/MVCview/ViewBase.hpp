//=====================================
// @brief Header file for ViewBase class.
//=====================================

#ifndef INCLUDED_MVCVIEW_VIEWBASE_HPP
#define INCLUDED_MVCVIEW_VIEWBASE_HPP

#include "../MVCmodel/ModelBase.hpp"

namespace game {
namespace MVCview {

class ViewBase
{
protected:
	MVCmodel::ModelBase::ShrPtr m_model;
public:
	using UnqPtr = std::shared_ptr<MVCview::ViewBase>;

	/**
	 * @brief Constructor.
	 */
	ViewBase(void);

	/**
	 * @brief Destructor.
	 */
	virtual ~ViewBase(void);
};

}} // namespace game::MVCview



#endif // INCLUDED_MVCVIEW_VIEWBASE_HPP
