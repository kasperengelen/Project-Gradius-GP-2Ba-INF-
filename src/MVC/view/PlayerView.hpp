/*
 * PlayerView.hpp
 *
 *  Created on: Dec 20, 2017
 *      Author: kasper
 */

#ifndef MVC_VIEW_PLAYERVIEW_HPP
#define MVC_VIEW_PLAYERVIEW_HPP

#include "EntityView.hpp"
#include "../model/PlayerModel.hpp"
#include "../../IOhandlers/Sprite.hpp"

namespace game {
namespace MVC {
namespace view {

/**
 * @brief Class that represents a view for a player.
 */
class PlayerView: public EntityView
{
private:

public:
	using UnqPtr = std::unique_ptr<PlayerView>;

	/**
	 * @brief Construct a PlayerView for the specified PlayerModel and the specified sprite.
	 */
	PlayerView(const model::PlayerModel::ShrPtr& model_ptr,
				const IOhandlers::Sprite& player_sprite);

	/**
	 * @brief Destructor.
	 */
	virtual ~PlayerView(void);

	/**
	 * @brief Render view to the specified window.
	 */
	void render(game::IOhandlers::Window& render_window) override;

};

}}} // namespace game::MVC::model

#endif // MVC_VIEW_PLAYERVIEW_HPP
