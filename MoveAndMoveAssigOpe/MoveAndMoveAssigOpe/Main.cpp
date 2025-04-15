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

	String(String&& other) noexcept
	{
		printf("Moved\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	// the move assignment operator
	// changing the assignment operator for moving the casted(with std::move) value
	String& operator=(String&& other) noexcept
	{
		printf("Moved\n");

		if (this != &other) {
			delete[] m_Data; // to avoid memory leak

			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
		}

		return *this; // when the variable moved to itself
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
		: m_Name((String&&)name)
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
	String string = "Hi";
	String dest;

	std::cout << "String: ";
	string.Print();
	std::cout << "Dest: ";
	dest.Print();

	dest = std::move(string); // in order to make the string a temporary val(acting as a rvalue)

	std::cout << "String: ";
	string.Print();
	std::cout << "Dest: ";
	dest.Print();

	// moved without any coping of data
	std::cin.get();
}