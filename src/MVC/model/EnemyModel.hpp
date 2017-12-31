//==========================================
// @brief Header file for EnemyModel class.
//==========================================

#ifndef INCLUDED_MVC_MODEL_ENEMYMODEL_HPP
#define INCLUDED_MVC_MODEL_ENEMYMODEL_HPP

#include "DynEntityModel.hpp"

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Model class for enemy entities.
 */
class EnemyModel final: public DynEntityModel
{
private:

public:
	using ShrPtr = std::shared_ptr<EnemyModel>;

	/**
	 * @brief Constructor based on a position and a direction.
	 */
	EnemyModel(const sf::Vector2f& pos, const sf::Vector2f& dir);

	/**
	 * @brief Destructor.
	 */
	~EnemyModel(void);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_ENEMYMODEL_HPP
