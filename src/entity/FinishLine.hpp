//======================================================
// @brief Header file for FinishLine class.
//======================================================

#ifndef INCLUDED_ENTITY_FINISHLINE_HPP
#define INCLUDED_ENTITY_FINISHLINE_HPP

#include "EntityBase.hpp"

namespace game {
namespace entity {

class FinishLine : public EntityBase
{
private:
public:
	using ShrPtr = std::shared_ptr<FinishLine>;

	/**
	 * @brief Constructor.
	 *
	 * @param[in] pos The position of the entity.
	 * @param[in] size The diameter of the entity.
	 */
	FinishLine(const utils::Vec2D& pos,
			   const float size);

	/**
	 * @brief Perform a game tick.
	 */
	void do_game_tick(void) override;

	/**
	 * @brief Retrieve a textual representation of the entity.
	 */
	std::string to_string(void) const override;

};

}} // namespace game::entity

#endif // INCLUDED_ENTITY_FINISHLINE_HPP
