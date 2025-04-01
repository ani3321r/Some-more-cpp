#include <iostream>
#include <string>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
	s_AllocCount++;
	std::cout << "allocating " << size << " bytes\n";
	return malloc(size);
}

#define STRING_VIEW 0

#if STRING_VIEW
void PrintName(std::string_view name) // with the use of string_view we are limiting the number of allocations
{
	std::cout << name << std::endl;
}
#else 
void PrintName(const std::string& name)
{
	std::cout << name << std::endl;
}
#endif

int main()
{
	std::string name = "God Raiden";

#if STRING_VIEW
	std::string_view firstname(name.c_str(), 3);
	std::string_view lastname(name.c_str() + 4, 6);
	
#else
	std::string firstname = name.substr(0, 3);
	std::string lastname = name.substr(4, 6);
#endif

	PrintName(firstname);
	PrintName(lastname);
	PrintName("liu");

	std::cout << s_AllocCount << " allocations\n";
	std::cin.get();
}