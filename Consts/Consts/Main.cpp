#include <iostream>
#include <string>

class Entity
{
private:
	int m_X, m_Y;
	mutable int var;
public:
	int GetX() const // const function
	{
		return m_X;
		var = 2; // even though we are in a const func as we marked the var mutable we can modify it
	}

	void Set_x(int x)
	{
		m_X = x;
	}
};

void PrintEntity(const Entity& e) // const and pass by reference for not coping(faster appro)
{
	std::cout << e.GetX() << std::endl;
}

int main()
{
	Entity e;


	const int MAX_AGE = 90;
	
	const int* b = new int; // cannot modify the contents of the pointer
	//int const* b = new int; // this is the same
	b = (int*)&MAX_AGE; // reassigning the pointer


	int* const a = new int; // cannot reassign the pointer to point to something else
	*a = 2; // contents at that particular memory address
	

	const int* const c = new int; // cannot do both

	std::cout << *a << " " << *b << std::endl;

	std::cin.get();
}