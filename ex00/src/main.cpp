#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

int main(void)
{
	cout << "vector int example: " << endl;
	{
		vector<int> intvec;
		for (int i = 0; i < 100; i++)
			intvec.push_back(i);

		vector<int>::iterator it = easyfind(intvec, 30);
		cout << "it: " << *it << endl;

		try
		{
			vector<int>::iterator it = easyfind(intvec, 100);
			cout << "it: " << *it << endl;
		}
		catch (std::exception &e)
		{
			cerr << e.what() << endl;
		}

		try
		{
			vector<int>::iterator it = easyfind(intvec, -1);
			cout << "it: " << *it << endl;
		}
		catch (std::exception &e)
		{
			cerr << e.what() << endl;
		}
	}

	cout << "\nvector string example: " << endl;
	{
		vector<string> strvec;
		strvec.push_back("ok0");
		strvec.push_back("ok1");
		strvec.push_back("ok2");

		string s1("ok0");
		vector<string>::iterator it = easyfind(strvec, s1);
		cout << "it: " << *it << endl;

		try
		{
			string s1("ok3");
			vector<string>::iterator it = easyfind(strvec, s1);
			cout << "it: " << *it << endl;
		}
		catch (std::exception &e)
		{
			cerr << e.what() << endl;
		}

		try
		{
			string s1("ok");
			vector<string>::iterator it = easyfind(strvec, s1);
			cout << "it: " << *it << endl;
		}
		catch (std::exception &e)
		{
			cerr << e.what() << endl;
		}
	}
}
