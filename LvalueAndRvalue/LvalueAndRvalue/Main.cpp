#include <iostream>

int& GetValue() // using it as a lvalue reference
{
	static int val = 10; // in order to pass the value as a reference we need to first store it
	return val;
}

void SetValue(int val)
{

}

void SetValue2(int& val) // only supports lvalue 
{

}

void SetValue3(const int& val) // in order to support both lvalue and rvalue
{

}

// an example with strings
void PrintName(std::string& name)
{
	std::cout << "[lvalue]" << name << std::endl;
}

// this is useful as it is just temporary, and can be used for optimization purposes
void PrintName(std::string&& name) // overloaded the func to take only rvalue
{
	std::cout << "[rvalue]" << name << std::endl;
}

int main()
{
	int i = GetValue();
	GetValue() = 4; // in order to make the function a modifiable lvalue we need to have reference

	int j = 20;
	SetValue(j); // passing a lvalue
	SetValue(20); // passing a rvalue

	// when take a value as reference we can't pass rvalue
	// SetValue2(10); // not possible

	// a string exception
	std::string s1 = "Raiden";
	std::string s2 = " is God";

	std::string s3 = s1 + s2;
	PrintName(s3);
	PrintName(s1 + s2);

	std::cin.get();
}