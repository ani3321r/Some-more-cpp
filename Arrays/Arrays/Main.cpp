#include <iostream>
#include <string>

int main()
{
	int example[5]; // this is created in the stack
	int* ptr = example; // an array is just a integer pointer
	for (int i = 0; i < 5; i++)
		example[i] = 2;

	example[2] = 5;
	*(ptr + 2) = 6; // updating the value using a pointer
	// *(int*)((char*)ptr + 8) = 6; // a more complex way of writing that

	int* another = new int[5]; // this is created in heap
	for (int i = 0; i < 5; i++)
		another[i] = 2;

	delete[] another; // once its created on heap, its need to be deleted

	// string concatination
	std::string con = std::string("hello ") + " Raiden";
	std::cout << con << std::endl;

	// finding strs in a str
	bool contains = con.find("lo") != std::string::npos;

	// different types to initialize string literals
	const char* name = u8"Raiden";
	const wchar_t* name2 = L"Raiden";

	const char16_t* name3 = u"Raiden";
	const char32_t* name4 = U"Raiden";

	using namespace std::string_literals;

	std::string name5 = "Raiden"s + " hello"; // another way to concatinate strs

	// in order to ignore escape chars
	const char* esc = R"(Line1
Line2
Line3
Line4
...)";

	std::cin.get();
}