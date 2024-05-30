#pragma once
#include <algorithm>
#include <exception>
#include <iterator>
#include <memory>


class Err: public std::exception{
	virtual const char * what() const throw() { return "Not found!!"; }
};

template <template <typename, typename> class T, typename V>
typename T<V, std::allocator<V> >::iterator easyfind(
	T<V, std::allocator<V> > &container, V value)
{
	typename T<V, std::allocator<V> >::iterator it;
	if ((it = std::find(container.begin(), container.end(), value)) != container.end())
		return it;
	throw Err();
}
