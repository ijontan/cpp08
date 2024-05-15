#include "Span.hpp"
#include <set>

/***********************************
 * Constructors
 ***********************************/

Span::Span(unsigned int max) : _max_size(max)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(const Span &rhs)
{
	_set = rhs._set;
	_max_size = rhs._max_size;
	_size = rhs._size;
	_current_longest = rhs._current_longest;
	_current_shortest = rhs._current_shortest;
	return *this;
}

/***********************************
 * Destructors
 ***********************************/

Span::~Span(void)
{
}

void Span::addNumber(int num)
{
	std::set<int>::iterator it = _set.find(num);
	if (it != _set.end())
	{
		_set.insert(num);
		return;
	}
	_set.insert(num);
	it = _set.find(num);
	if (it != _set.begin())
	{
		int previous = *(--it);
		if (previous - *it < _current_shortest)
			_current_shortest = previous - *it;
	}
	if (it != --_set.end())
	{
		int next = *(++it);
		if (next - *it < _current_shortest)
			_current_shortest = next - *it;
	}
	if (it == _set.begin() || it == (--_set.end()))
		_current_longest = *_set.end() - *_set.begin();
}

int Span::shortestSpan(void)
{
	return _current_shortest;
}

int Span::longestSpan(void)
{
	return _current_longest;
}
