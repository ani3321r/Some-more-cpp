#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const // the const at the last means the class members cant be modified
	{
		m_DebugCount++;
		return m_Name;
	}
};

int main() 
{
	const Entity e;
	e.GetName(); // if we dont mention the function params as const this will give an error

	int x = 8;
	// if we wanna pass by value and also modify the value we need to make the lambda mutable
	auto f = [=]() mutable
		{
			x++;
			std::cout << x << std::endl;
		};

	f();
	// after calling the func, x will still be set to 8

	std::cin.get();
}