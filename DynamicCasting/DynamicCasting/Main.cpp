#include <iostream>
#include <string>

class Entity
{
public:
	virtual void PrintName() {}
};

class Player : public Entity
{

};

class Enemy : public Entity
{

};

int main()
{
	Player* p1 = new Player();
	Entity* actuallyPlayer = p1;
	Entity* actuallyEnemy = new Enemy();

	// if the cast is valid then only the dynamic cast allows to cast, otherwise not
	// stores runtime type information(dynamic cast)
	// dynamic cast costs some performance
	Player* p0 = dynamic_cast<Player*>(actuallyEnemy); // here we are casting player to enemy, so its not possible

	Player* p2 = dynamic_cast<Player*>(actuallyPlayer);

	std::cin.get();
}