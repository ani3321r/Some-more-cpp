#include <iostream>

class Base
{
public:
	Base() {}
	virtual ~Base();
};

class Derived : public Base
{
public:
	Derived() {}
	~Derived() {}
};

class AnotherClass : public Base
{
public:
	AnotherClass() {}
	~AnotherClass () {}
};

int main()
{
	double val = 5.25;
	double a = (int)val + 5.3; // c style casting

	double s = static_cast<int>(val) + 5.3; // only allow the static cast to a int and cant be casted to unoperable stuff
	//double s = static_cast<AnotherClass*>(&val) + 5.3; // this is an example of the restrictions made by the static cast(invalid type conversion)

	//double s = reinterpret_cast<AnotherClass*>(&val) + 5.5; // with reinterpret cast it is possible

	// example of dynamic cast
	Derived* derived = new Derived();

	Base* base = derived;

	AnotherClass* ac = dynamic_cast<AnotherClass*>(base); // check at runtime if the casting really occurs

	std::cin.get();
}