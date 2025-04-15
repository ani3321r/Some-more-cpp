#include <iostream>

template<typename T, size_t S>
class Array
{
public:
	constexpr int Size() const { return S; } // by adding the constexpr this func can be evaluated at compile time

	// we need to return a reference of the type in order to make it modifiable
	T& operator[](size_t index) 
	{
		if (!(index < S)) // check overflow
		{
			__debugbreak();
		}
		return m_Data[index]; 
	}

	// in order to access the data of a const array
	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }
private:
	T m_Data[S];
};

int main()
{
	int size = 5;
	Array<int, 5> data;

	memset(&data[0], 0, data.Size() * sizeof(int));

	data[2] = 6;
	data[4] = 9;

	const auto& arrayRef = data;

	static_assert(data.Size() < 10, "Size is too small");

	for (size_t i = 0; i < data.Size(); i++)
	{
		std::cout << data[i] << std::endl;
	}
	
	for (size_t i = 0; i < arrayRef.Size(); i++)
	{
		std::cout << arrayRef[i] << std::endl;
	}

	std::cin.get();
}