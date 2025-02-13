#include <iostream>

// just a declaration, the compiler beliefs there is
// some function in other cpp file with this function signature
void Log(const char* message);

int main()
{
	Log("Hello World");
	std::cin.get();
}