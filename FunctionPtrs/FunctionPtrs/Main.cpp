#include <iostream>
#include <vector>

void HelloRaiden(int a)
{
	std::cout << "Hello Raiden: " << a << std::endl;
}

// funcs for the application
void PrintVal(int val) 
{
	std::cout << "Value: " << val << std::endl;
}

void ForEach(const std::vector<int>& vals, void(*func)(int))
{
	for (int val : vals)
		func(val);
}

int main() {
	auto func = &HelloRaiden; //getting the memory address of the function
	func(2);
	func(4);

	//another way of declaring func ptr
	void(*raiden)(int) = HelloRaiden;
	raiden(7);

	//using typedef
	typedef void(*HelloRaidenFunc)(int);
	HelloRaidenFunc func1 = HelloRaiden;
	func1(9);

	// an actual application of func ptrs
	std::vector<int> vals = { 6, 5, 8, 3, 0 };
	ForEach(vals, PrintVal);

	std::cin.get();
}