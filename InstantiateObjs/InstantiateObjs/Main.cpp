#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

void Func()
{
	int a = 10;
	// at the end of the func the lifetime of the object ends in the stackframe
	// so it is not in the memory anymore if required anywhere else
	Entity e = Entity("Raiden"); 

}

int main()
{
	// initializing in the stack
	// fastest and most managed way to instantiate an object in cpp
	Entity entity;
	std::cout << entity.GetName() << std::endl;

	//a heap operation example
	Entity* e;
	{
		Entity* entity1 = new Entity("Raiden"); // here the entity is being created in the heap
		e = entity1; // assigning the heap allocated obj to the obj outside scope
		std::cout << entity1->GetName() << std::endl;
	}

	std::cin.get();
	delete e; // as the obj is heap allocated we need to free it in the end
}