#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
	Entity()
	{
		std::cout << "Creates Entity" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroys entity" << std::endl;
	}

	void Print() {}
};

int main()
{
	// weak_ptr example
	{
		// proper way to make a unique ptr in order to handel exceptions
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();

		entity->Print();
	} // at the end of the scope the unique ptr gets destroyed


	// shared_ptr example
	{
		std::shared_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;
		} // the sharedEntity do not dies here as e0 is out if the scope and they are sharing the same ptr
	}// it finally dies here after both goes out of scope

	// weak_ptr example
	{
		std::weak_ptr<Entity> e0; // reference the object without owning it
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;
		} // this is why the sharedEntity gets destroyed here
	}

	std::cin.get();
}