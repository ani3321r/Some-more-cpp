#include <iostream>

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}

//virtual funcs
public:
	virtual std::string GetName() { return "Entity"; } // generate v-table for the func
	//virtual std::string GetName() = 0; // pure virtual func
};

class Player : public Entity
{
public:
	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
	}

//virtual funcs eg
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) { }
	std::string GetName() override { return m_Name; } // as it is an overwritten func
};

int main()
{
	/*
	Player pl;
	pl.X = 3;
	pl.Y = 9;
	pl.Move(2, 5);
	*/
	
	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;

	Player* p = new Player("Raiden");
	std::cout << p->GetName() << std::endl;

	Entity* entity = p;
	std::cout << entity->GetName() << std::endl;

	std::cin.get();
}