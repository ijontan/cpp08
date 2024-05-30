#include "Span.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

int main()
{
	srand(time(NULL));
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "1000 numbers:" << std::endl;
	{
		Span sp = Span(1000);
		sp.addNRand(1000, 1, 100, false);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "10000 numbers:" << std::endl;
	{
		Span sp = Span(10000);
		sp.addNRand(10000, 1000, 1001, false);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "ranged numbers:" << std::endl;
	{
		std::list<int> l;
		for (int i = 0; i < 100; i++)
		{
			l.push_back(i);
		}

		Span sp(100);
		sp.addRange<std::list<int> >(l.begin(), l.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "10,000,000 numbers:" << std::endl;
	{
		Span sp = Span(10000000);
		sp.addNRand(10000000, 1, 500, false);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}
