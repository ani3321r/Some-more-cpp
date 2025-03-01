#include <iostream>

// int i = 0; if we initialize here it is accessible everywhere but only has one instance so it doesnt change with every func call

void Func() 
{
	static int i = 0; // we use it so that the var is only initialized once and not accessible out of this class
	// int i = 0; doing this will initialize the i everytime the func is called
	i++;
	std::cout << i << std::endl;
}

// use of the static
class Singleton
{
public:
	static Singleton& Get()
	{
		static Singleton instance; // the instance do not gets destroyed as soon as its lifetime ends
		return instance;
	}

	void Hello(){}
	
};

int main() {
	Func();
	Func();
	Func();
	Func();
	Func();
	Func();

	Singleton::Get().Hello();

	std::cin.get();
}