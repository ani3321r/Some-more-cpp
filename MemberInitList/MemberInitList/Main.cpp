#include <iostream>
#include <string>

class Example
{
public:
	Example()
	{
		std::cout << "Created entity" << std::endl;
	}

	Example(int x)
	{
		std::cout << "Created entity with " << x << std::endl;
	}
};

// the member initializer is mainly used as we dont need to clutter the constructor
class Entity
{
private:
	std::string m_Name;
	int m_Score;
	Example m_Example;
public:
	Entity()
		: m_Name("Unknown"), m_Score(0), m_Example(6) // this always follows the order of initializing the members
	{
		//m_Example = Example(5); // with this two entities are created(both of the example)
		//it is another advantage of using the mem initializer list that extra objects are not being created
	}

	Entity(const std::string& name)
		:m_Name(name)
	{}

	const std::string& GetName() const { return m_Name; }
};

int main()
{
	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1("Raiden");
	std::cout << e1.GetName();
	std::cin.get();
}