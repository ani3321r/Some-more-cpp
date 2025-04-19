#include <iostream>
#include "Vector.h"

int main()
{
	Vector<std::string> vals;
	vals.EmplaceBack("1");
	vals.EmplaceBack("2");
	vals.EmplaceBack("3");
	vals.EmplaceBack("4");
	vals.EmplaceBack("5");

	std::cout << "not using iters\n";
	for (int i = 0; i < vals.Size(); i++)
	{
		std::cout << vals[i] << std::endl;
	}

	std::cout << "range based for loop\n";
	for (auto& val : vals)
		std::cout << val << std::endl;

	std::cout << "iterators\n";
	for (Vector<std::string>::Iterator it = vals.begin();
		it != vals.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cin.get();
}