#pragma once

#include <deque>
#include <stack>
template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void){};
	~MutantStack(void){};
	MutantStack(const MutantStack<T> &src)
	{
		*this = src;
	};
	MutantStack<T> &operator=(const MutantStack<T> &rhs)
	{
		std::stack<T, Container>::operator=(rhs);
		return *this;
	};

	typedef typename Container::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator rbegin()
	{
		return this->c.rbegin();
	}
	iterator end()
	{
		return this->c.end();
	}
	iterator rend()
	{
		return this->c.rend();
	}
};
