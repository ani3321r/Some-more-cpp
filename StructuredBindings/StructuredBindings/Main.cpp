#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> CreatePerson() 
{
	return std::make_tuple( "Raiden", 26 );
}

int main() {
	auto [name, age] = CreatePerson(); // structured binding only available in C++17
	std::cout << name;
	std::cin.get();
}