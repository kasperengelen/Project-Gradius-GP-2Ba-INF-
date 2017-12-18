//================================================
// @brief Header file for GameModel class.
//================================================

#ifndef INCLUDED_MVC_MODEL_GAMEMODEL_HPP
#define INCLUDED_MVC_MODEL_GAMEMODEL_HPP

#include "ModelBase.hpp"

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Model class that encompasses the entire model of the game.
 */
class GameModel: public ModelBase
{
private:

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
	virtual void do_game_tick(void);
};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_GAMEMODEL_HPP
