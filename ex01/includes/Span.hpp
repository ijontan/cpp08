#pragma once

#include <exception>
#include <iterator>
#include <set>
class Span
{
public:
	Span(unsigned int max);
	~Span(void);
	Span(const Span &src);
	Span &operator=(const Span &rhs);
	void addNumber(int num);
	template <class T>
	void addRange(typename T::iterator start, typename T::iterator end){
		typename T::iterator it;
		for (it = start; it != end; it++)
			addNumber(*it);
	}
	void addNRand(int n, int min, int max, bool shouldPrint);
	int shortestSpan(void);
	int longestSpan(void);

	class Err : std::exception
	{
		const char *what() const throw()
		{
			return "error";
		}
	};

private:
	unsigned int _max_size;
	unsigned int _size;
	std::set<int> _set;
	int _current_shortest;
	int _current_longest;
};
