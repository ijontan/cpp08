#pragma once

#include <set>
class Span
{
public:
	Span(unsigned int max);
	~Span(void);
	Span(const Span &src);
	Span &operator=(const Span &rhs);
	void addNumber(int num);
	int  shortestSpan(void);
	int  longestSpan(void);

private:
	unsigned int _max_size;
	unsigned int _size;
	std::set<int> _set;
	int _current_shortest;
	int _current_longest;
};
