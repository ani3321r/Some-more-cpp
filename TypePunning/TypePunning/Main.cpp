#include <iostream>

struct Entity
{
	int x, y;
};

// basically getting the type as a ptr and casting to a different ptr then dereferencing it (type punning)

int main()
{
	int a = 50;
	// double val = a; // when we do this implicitely then their are type issues
	double& val = *(double*)&a; // by this the allocation is perfect(as we are coping the address rather than value)
	std::cout << val << std::endl;

	// practical example
	Entity e = { 4, 8 };
	int* position = (int*)&e; // by doing this we are accessing the struct mems as array

	int y = *(int*)((char*)&e + 4); // taking e as a char ptr and then going 4 bytes to access the 2nd element then making it int ptr and dereferencing it

	std::cout << y << std::endl;

	std::cout << position[0] << ", " << position[1] << std::endl;

	std::cin.get();
}