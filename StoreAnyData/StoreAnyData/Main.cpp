#include <iostream>
#include <any>

int main()
{
	std::any data;
	data = 23;
	data = "Raiden";
	std::string& string = std::any_cast<std::string&>(data);

	std::cin.get();
}