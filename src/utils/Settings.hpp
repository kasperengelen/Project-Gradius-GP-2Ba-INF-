//=======================================
// @brief Header file for Settings class.
//=======================================

#ifndef INCLUDED_UTILS_SETTINGS_HPP
#define INCLUDED_UTILS_SETTINGS_HPP

#include <map>
#include <string>
#include <memory>
#include <iostream>

namespace game {
namespace utils {

class Value {};

template <typename T>
class ValueTemplate: public Value
{
private:
	T m_val;
public:
	ValueTemplate(void)
	{}

	ValueTemplate(const T& val)
		: m_val{val}
	{}

	const T& get_val(void)
	{
		return m_val;
	}

	void set_val(const T& new_val)
	{
		m_val = new_val;
	}
};

/**
 * @brief Class that serves as a container for application settings.
 */
class Settings
{
private:
	std::map<std::string, Value*> m_value_map;
public:
	Settings(void)
	{}

	/**
	 * @brief Load settings from settings file.
	 */
	void load_file(const std::string& file_name);

	/**
	 * @brief Save settings to settings file.
	 */
	void save_file(const std::string& file_name) const;

	bool has_value(const std::string& param_name) const
	{
		return m_value_map.count(param_name);
	}

	/**
	 * @brief Retrieve the value of the specified parameter.
	 */
	template <typename T>
	const T& get_value(const std::string& param_name)
	{
		if(auto* p = static_cast<ValueTemplate<T>*>(m_value_map.at(param_name)))
		{
			return p->get_val();
		}
		else
		{
			throw std::runtime_error{"Invalid type for specified parameter."};
		}
	}

	/**
	 * @brief Set the value of the specified parameter.
	 */
	template <typename T>
	void set_value(const std::string& param_name, const T& value)
	{
		// if value in map:
		//		-> cast to ValueTemplate<T>
		//		-> p -> set value
		// if not
		//		-> create new ValueTemplate<T> with value;

		if(not m_value_map.count(param_name))
		{
			m_value_map.insert({param_name, new ValueTemplate<T>{value}});
		}
		else if (auto* p = static_cast<ValueTemplate<T>*>(m_value_map.at(param_name)))
		{
			p->set_val(value);
		}
		else
		{
			throw std::runtime_error{"Invalid type for specified parameter."};
		}
	}
};

}}

#endif // INCLUDED_UTILS_SETTINGS_HPP
