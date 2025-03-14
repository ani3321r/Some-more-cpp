#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor\n"; }
	virtual ~Base() { std::cout << "Base Destructor\n"; } // we have to use virtual here as after the destruction of the base class the derived will not be destructed if we dont use it
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived Constructor\n"; }
	~Derived() { delete[] m_Arr; std::cout << "Derived Destructor\n"; }

private:
	int* m_Arr;
};

int main()
{
	Base* base = new Base();
	delete base;
	std::cout << "-----------------------------\n";
	Derived* derived = new Derived();
	delete derived;
	std::cout << "-----------------------------\n";
	Base* poly = new Derived();
	delete poly;

	std::cin.get();
}