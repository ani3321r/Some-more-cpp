#include <iostream>
#include <string>
#include <algorithm>

namespace apple {
	namespace func { // nested namespaces
		void print(const char* text)
		{
			std::cout << text << std::endl;
		}
	}

	void print_again(){}
}

namespace orange {
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

int main()
{
	// using apple::print_again; // if we wanna only use a specific func from a namespace
	// using namespace orange; // in order to use all the functions of only orange
	// namespace a = apple; // alliases for namespaces

	using namespace apple;
	using namespace func;

	print("HI");

	std::cin.get();
}