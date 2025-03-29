#include <iostream>
#include <fstream>
#include <string>
#include <optional> // only available cpp 17+

std::optional<std::string> ReadFileAsString( const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		stream.close();
		return result;
	}
	return {};
}

int main()
{
	std::optional<std::string> data = ReadFileAsString("data.txt");

	std::string val = data.value_or("Not present");
	std::cout << val << std::endl;

	if (data.has_value()) {
		std::cout << "File read successfully" << std::endl;
	}
	else
	{
		std::string& string = *data;
		std::cout << "File could not be accessed\n";
	}
	std::cin.get();
}