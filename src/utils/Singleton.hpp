//====================================
// @brief Header file for Singleton class.
//====================================

#ifndef MISC_SINGLETON_HPP
#define MISC_SINGLETON_HPP

namespace game {
namespace misc {

template <typename T>
class Singleton
{
protected:
	Singleton(void) = default;
	virtual ~Singleton(void) = default;

	Singleton(const Singleton<T>&) = delete;
	Singleton<T> operator=(const Singleton<T>&) = delete;

public:
	static T& get_instance(void)
	{
		static T instance;

		return instance;
	}
};

}} // namespace game::misc



#endif // MISC_SINGLETON_HPP
