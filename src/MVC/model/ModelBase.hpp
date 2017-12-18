//=============================================
// @brief Header file for ModelBase class.
//=============================================

#ifndef INCLUDED_MVC_MODEL_MODELBASE_HPP
#define INCLUDED_MVC_MODEL_MODELBASE_HPP

#include <memory>

namespace game {
namespace MVC {
namespace model {

/**
 * @brief Abstract base class for model classes.
 */
class ModelBase
{
protected:

public:
	using ShrPtr = std::shared_ptr<ModelBase>;

	/**
	 * @brief Constructor.
	 */
	ModelBase(void);

	/**
	 * @brief Destructor.
	 */
	virtual ~ModelBase(void);

	/**
	 * @brief Notify the model that a game tick is to be performed.
	 */
	virtual void do_game_tick(void) = 0;
};

}}} // namespace game::MVC::model

#endif // INCLUDED_MVC_MODEL_MODELBASE_HPP
