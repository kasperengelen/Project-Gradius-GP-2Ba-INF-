//=====================================
// @brief Header file for ViewBase class.
//=====================================

#ifndef INCLUDED_MVC_VIEW_VIEWBASE_HPP
#define INCLUDED_MVC_VIEW_VIEWBASE_HPP

#include "../model/ModelBase.hpp"
using game::MVC::model::ModelBase;

#include "../../IOhandlers/Window.hpp"

namespace game {
namespace MVC {
namespace view {

/**
 * @brief Abstract base class for view classes.
 */
class ViewBase
{
protected:
	ModelBase::ShrPtr m_model;
public:
	using UnqPtr = std::shared_ptr<ViewBase>;

	/**
	 * @brief Constructor.
	 */
	ViewBase(const ModelBase::ShrPtr& model_ptr);

	/**
	 * @brief Destructor.
	 */
	virtual ~ViewBase(void);

	/**
	 * @brief Render the view to the specified window.
	 */
	virtual void render(const game::IOhandlers::Window& render_window) = 0;
};

}}} // namespace game::MVC::view



#endif // INCLUDED_MVC_VIEW_VIEWBASE_HPP
