#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <ostream>

int main()
{
	{

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout <<std::endl;
	}
	{

		MutantStack<int, std::list<int> > mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int, std::list<int> >::iterator it = mstack.begin();
		MutantStack<int, std::list<int> >::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout <<std::endl;
	}
	return 0;
}
