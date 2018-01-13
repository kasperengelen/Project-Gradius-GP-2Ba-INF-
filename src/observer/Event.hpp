//=======================================
// @brief Header file for event class.
//=======================================

#ifndef INCLUDED_OBSERVER_EVENT_HPP
#define INCLUDED_OBSERVER_EVENT_HPP

#include "../utils/Vec2D.hpp"
#include <memory>
#include <iostream>

namespace game {

namespace entity {
class Bullet;
}

namespace observer {

/**
 * @brief Base class for events that occur within the context of the
 * observer pattern.
 */
struct Event
{
	using ShrPtr = std::shared_ptr<Event>;

	Event(void) = default;
	virtual ~Event(void) = default;
};

struct GameEvent : public Event
{};

struct PlayerShoot : public GameEvent
{
	const std::shared_ptr<entity::Bullet> bullet_ptr;

	PlayerShoot(const std::shared_ptr<entity::Bullet>& bullet_ptr)
		: bullet_ptr{bullet_ptr}
	{}
};

struct EnemyShoot : public GameEvent
{
	const std::shared_ptr<entity::Bullet> bullet_ptr;

	EnemyShoot(const std::shared_ptr<entity::Bullet>& bullet_ptr)
		: bullet_ptr{bullet_ptr}
	{}
};

struct PlayerLivesUpdate : public GameEvent
{
	const int new_lives; // updated amount of lives

	PlayerLivesUpdate(const int new_lives)
		: new_lives{new_lives}
	{}
};

struct GameOver : public GameEvent
{};

struct GameWon : public GameEvent
{};

struct EntityEvent : public Event
{};

struct EntityMove : public EntityEvent
{
	const utils::Vec2D new_pos;

	EntityMove(const utils::Vec2D& new_pos)
		: new_pos{new_pos}
	{}
};

}} // namespace game::observer

#endif // INCLUDED_OBSERVER_EVENT_HPP


