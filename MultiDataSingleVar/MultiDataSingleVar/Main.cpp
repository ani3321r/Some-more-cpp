#include <iostream>
#include <variant>

enum class ErrCode
{
	None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, ErrCode> ReadFileAsStr() // for returning optional types the variant is very useful
{
	return {};
}

int main()
{
	// variants are much more typesafe than unions
	std::variant<std::string, int> data;

	std::cout << sizeof(data) << std::endl; // the variant stores the size of both the datatypes

	data = "Raiden";
	std::cout << std::get<std::string>(data) << std::endl;
	
	if (auto val = std::get_if<std::string>(&data)) // just to be exception safe
	{
		std::string& v = *val;
	}
	else
	{

	}
	
	data = 23;

	std::cout << std::get<std::string>(data) << std::endl; // in order to handle this case
	std::cout << std::get<int>(data) << std::endl;

	std::cin.get();
}