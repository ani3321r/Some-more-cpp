#include <iostream>
#include "Log.h" 
// log.cpp(contains the log body) -> Log.h -> Math.cpp

void InitLog();

static int Multiply(int a, int b)
{
	InitLog();
	Log("Multiply");
	return a * b;
}

int main()
{
	std::cout << Multiply(3, 6) << std::endl;
	

	int a = 5;
	bool checkIfEqual = a == 5;
	if (checkIfEqual) {
		Log("Hello World");
	}
	std::cin.get();
}