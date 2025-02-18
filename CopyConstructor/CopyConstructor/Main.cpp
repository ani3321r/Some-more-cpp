#include <iostream>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	// this one is the shallow copy one
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	// making a copy constructor to make deep copy
	String(const String& other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);

		std::cout << "string copied" << std::endl;
	} // copy the memory of the pointer

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer; // due to making friend we can access a private member
	return stream;
}

void PrintString(const String& string)
{
	std::cout << string << std::endl;
} // we need a const reference here or else the memory will be copied multiple times in the heap

int main()
{
	String string = "Raiden";
	String string2 = string; // we are creating a shallow copy here(with the first func)
	//std::cout << string << std::endl;

	String str3 = string;
	str3[3] = 'g';

	PrintString(string);
	PrintString(str3);

	std::cin.get();
} // so when the program ends the destructor is trying to delete the same buffer twice which leads to crash(only for the shallow copy one)