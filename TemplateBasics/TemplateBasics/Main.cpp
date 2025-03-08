#include <iostream>
#include <string>

template<typename T>
void Print(T val) //making it a template reduces code duplication
{
	std::cout << val << std::endl;
} // it is only created when the template is called

// class templates
template<typename T, int N>
class Array
{
private:
	T int m_arr[N];
public:
	int GetSize() const { return N; }
};

int main()
{
	Print(10);
	Print<std::string>("Hi"); //we can also explicitely define type like this
	Print(6.9f);

	Array<std::string, 3> arr;
	std::cout << arr.GetSize() << std::endl;

	std::cin.get();
}