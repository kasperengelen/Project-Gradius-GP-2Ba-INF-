//=================================================
// @brief Header file for EnemyView class.
//=================================================

#ifndef MVC_VIEW_ENEMYVIEW_HPP
#define MVC_VIEW_ENEMYVIEW_HPP

#include "EntityView.hpp"
#include "../model/EnemyModel.hpp"

namespace game {
namespace MVC {
namespace view {

/**
 * @brief Class that represents a view for an enemy.
 */
class EnemyView: public EntityView
{
private:
public:

	/**
	 * @brief Construct a view based on a pointer to an enemy and a sprite.
	 */
	EnemyView(const model::EnemyModel::ShrPtr& model_ptr,
				const IOhandlers::Sprite& enemy_sprite);

	/**
	 * @brief Destructor.
	 */
	virtual ~EnemyView(void);

	/**
	 * @brief Render view to the specified window.
	 */
	void render(game::IOhandlers::Window& render_window) override;

};

}}} // namespace game::MVC::view

#endif // MVC_VIEW_ENEMYVIEW_HPP
