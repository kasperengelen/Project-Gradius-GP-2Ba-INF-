//================================================
// @brief Header file for GameModel class.
//================================================

#ifndef INCLUDED_MVC_MODEL_GAMEMODEL_HPP
#define INCLUDED_MVC_MODEL_GAMEMODEL_HPP

#include "EntityModel.hpp"
#include <memory>
#include <vector>

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Model class that encompasses the entire model of the game.
 */
class GameModel final
{
private:
	std::vector<EntityModel::ShrPtr> m_entity_models;
public:
	using ShrPtr = std::shared_ptr<GameModel>;

	/**
	 * @brief Construct the model.
	 */
	GameModel(void);

	/**
	 * @brief Destructor.
	 */
	virtual ~GameModel(void);

	/**
	 * @brief Notify the model that a game tick is to be performed.
	 */
	void do_game_tick(void);

	//TODO REMOVE DEBUG
	void debug_add_entity_model(const EntityModel::ShrPtr& entity_model_ptr);

};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_GAMEMODEL_HPP
