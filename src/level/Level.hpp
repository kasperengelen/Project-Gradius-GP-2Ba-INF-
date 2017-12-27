//==================================================
// @brief Header file for Level class.
//==================================================

#ifndef INCLUDED_LEVEL_LEVEL_HPP
#define INCLUDED_LEVEL_LEVEL_HPP

#include "../IOhandlers/Sprite.hpp"

#include <string>
#include <tuple>
#include <map>

namespace game {
namespace level {

/**
 * @brief Struct that represents a coordinate in a level.
 */
struct GridCoordinate
{
	double x;
	double y;

	bool operator<(const GridCoordinate& rhs) const
	{
		return std::tie(x, y) < std::tie(rhs.x, rhs.y);
	}
};

/**
 * @brief Class that represents the entity located at a certain coordinate.
 */
class GridEntity
{
public:
	enum class EntityType
	{
		PLAYER,
		ENEMY,
		WORLD_BORDER,
		OBSTACKLE
	};
private:
	EntityType m_type;
	IOhandlers::Sprite m_sprite;
public:
	/**
	 * @brief Constructor based on a type and a sprite.
	 */
	GridEntity(const EntityType& type, const IOhandlers::Sprite& sprite)
		: m_type{type}, m_sprite{sprite}
	{}

	/**
	 * @brief Retrieve the type of the entity.
	 */
	const EntityType get_type(void) const
	{
		return m_type;
	}

	/**
	 * @brief Retrieve the sprite of the entity.
	 */
	const IOhandlers::Sprite& get_sprite(void) const
	{
		return m_sprite;
	}
};

/**
 * @brief Class that represents a game level.
 */
class Level
{
public:

private:
	// stores entities present
	std::map<GridCoordinate, GridEntity> m_data;

	unsigned int m_height;
	unsigned int m_width;
public:
	/**
	 * @brief Construct a level from a json file.
	 */
	Level(const std::string& json_filename);

	/**
	 * @brief Retrieve the height of the level.
	 */
	int get_height(void) const;

	/**
	 * @brief Retrieve the width of the level.
	 */
	int get_width(void) const;

	/**
	 * @brief Determine if there's an entity at the specified coordinate.
	 */
	bool has_entity_at(const GridCoordinate& coord) const;

	/**
	 * @brief Retrieve the entity at the specified coordinate.
	 */
	const GridEntity& get_entity_at(const GridCoordinate& coord) const;

};

}} // namespace game::level

#endif // INCLUDED_LEVEL_LEVEL_HPP
