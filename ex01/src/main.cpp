#include "Span.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

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
	{
		Span sp = Span(1000);
		sp.addNRand(1000, 1, 100, false);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(10000);
		sp.addNRand(10000, 1000, 1001, false);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(10000000);
		sp.addNRand(10000000, 1, 500, false);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	// if I really want to speed this up I would have to implement my own binary tree

	return 0;
}
