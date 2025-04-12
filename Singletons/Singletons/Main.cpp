#include <iostream>

class Singleton
{
public:
	Singleton(const Singleton&) = delete; // this ensures no new instance is created which is a copy

	static Singleton& Get() {
		return s_Instance;
	}

	void Func(){}
private:
	Singleton() {}

	static Singleton s_Instance;
};

// example
class Random
{
public:
	Random(const Random&) = delete;

	static Random& Get() {
		static Random instance1; // here we are instantiating in the function itself to reduce code
		return instance1;
	}

	static float Float() { return Get().IFloat(); } // calling it and passing as static to make the code more readable and easier
private:
	// write any no. of non-static methods and access it via get()
	float IFloat(){ return m_RandomGen; } // implementation of the Float func
	
	Random() {}

	float m_RandomGen = 0.5f;
};

Singleton Singleton::s_Instance;

int main()
{
	Singleton::Get().Func(); // we do not need to instantiate it again

	float num = Random::Float(); //here we don't need get then func as we made implementation in the private
	std::cout << num << std::endl;
	std::cin.get();
}