#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>
#include <utility>

/***********************************
 * Constructors
 ***********************************/

Span::Span(unsigned int max)
	: _max_size(max), _size(0), _current_shortest(INT_MAX), _current_longest(0)
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
	if (_size >= _max_size)
		throw Err();
	std::pair<std::set<int>::iterator, bool> pair = _set.insert(num);
	_size++;
	if (!pair.second)
	{
		_current_shortest = 0;
		return;
	}

	std::set<int>::iterator it = pair.first;
	if (it != _set.begin())
	{
		int current = *it--;
		int prev = *it;
		int diff = current - prev;
		if (diff < _current_shortest)
			_current_shortest = diff;
	}
	if (it != --_set.end())
	{
		int current = *it++;
		int next = *it;
		int diff = next - current;
		if (diff < _current_shortest)
			_current_shortest = diff;
	}
	if (it == _set.begin() || it == (--_set.end()))
		_current_longest = *(--_set.end()) - *_set.begin();
}

void Span::addNRand(int n, int min, int max, bool shouldPrint)
{
	if (min > max)
		throw Err();
	int size = max - min + 1;
	for (int i = 0; i < n; i++)
	{
		int r = (long)rand() * size / RAND_MAX + min;
		addNumber(r);
		if (shouldPrint)
			std::cout << r << " ";
	}
	if (shouldPrint)
		std::cout << std::endl;
}

int Span::shortestSpan(void)
{
	return _current_shortest;
}

int Span::longestSpan(void)
{
	return _current_longest;
}
