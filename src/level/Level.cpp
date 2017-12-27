//===================================
// @brief Implementation of Level.hpp
//===================================

// header
#include "Level.hpp"

// project includes
#include "../exception/LevelException.hpp"

// library includes
#include "../lib/json.hpp"
using nlohmann::json;

// std includes
#include <iostream>
#include <fstream>

namespace game {
namespace level {

Level::Level(const std::string& json_filename)
{
	try
	{

		m_height = 0;
		m_width = 0;

		// open file
		std::ifstream json_file{json_filename};

		// load file into json object
		json json_data;
		json_file >> json_data;

		// open "LevelGrid"
		const auto matrix = json_data.at("LevelGrid").get<std::vector<std::vector<std::string>>>();

		// set height and width of level
		m_height = matrix.size();
		m_width = matrix.at(0).size();

		unsigned int row = 0;

		// reverse iterate since lowest coordinate is at bottom of grid
		for(auto it = matrix.crbegin(); it != matrix.crend(); it++)
		{
			const auto& vec = *it;

			// ensure that matrix rows have correct length.
			if(vec.size() != m_width)
			{
				throw exception::level::LevelLoadException{json_filename, "Level data matrix has incorrect dimensions."};
			}

			unsigned int col = 0;
			for(const auto& vec_entry: vec)
			{
				GridCoordinate cur_coord{row, col};

				if(vec_entry == "E")
				{
					std::cout << "Enemy ";
				}
				else if(vec_entry == "P")
				{
					std::cout << "Player ";
				}
				else if(vec_entry == "O")
				{
					std::cout << "Obstackle ";
				}
				else if(vec_entry == "W")
				{
					std::cout << "World ";
				}
				else if(vec_entry == ".")
				{
					std::cout << "Empty ";
				}
				else
				{
					throw exception::level::LevelLoadException{json_filename, "Unknown entity id: '" + vec_entry + "'."};
				}
				col++;
			}

			std::cout << std::endl;
			row++;
		}


		// iterate over elements


	}
	catch(const exception::level::LevelLoadException& e)
	{
		// rethrow
		throw;
	}
	catch(...)
	{
		throw exception::level::LevelLoadException{json_filename};
	}
	// determine height and width



}

int Level::get_height(void) const
{
	return m_height;
}

int Level::get_width(void) const
{
	return m_width;
}

bool Level::has_entity_at(const GridCoordinate& coord) const
{
	return m_data.count(coord);
}

const GridEntity& Level::get_entity_at(const GridCoordinate& coord) const
{
	return m_data.at(coord);
}

}} // namespace game::level

