#include <iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	
	// Deep coping
	String(const String& other)
	{
		printf("Copied\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	// copy constructor taking a rvalue reference to save space by not coping the data
	String(String&& other) noexcept
	{
		printf("Moved\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	~String()
	{
		printf("Destroyed\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		
		printf("\n");
	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	Entity(const String& name)
		: m_Name(name)
	{

	}
	
	Entity(String&& name)
		: m_Name((String&&)name) // cast it properly to take only reference and not copy
	{

	}

	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};

int main()
{
	// usually when we pass a string the value is copied inside the class to do all the operation
	// in order to avoid coping of temporary data we use move semantics
	Entity e1(String("Raiden"));
	e1.PrintName();
	std::cin.get();
}