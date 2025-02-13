#include <iostream>
#include "Log.h" // just to include the func defination

void InitLog()
{
	Log("Initialized Log");
}

// the function defination is only here so no linking errors
// as the function doesn't have body in other files
void Log(const char* message)
{
	std::cout << message << std::endl;
}