#include <iostream>

struct Vec2
{
	float x, y;
};

// unions are basically used to address the same data in different ways

struct Vec4
{
	// using this we can access the elements in two differnet ways
	union {
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vec2 a, b;
		};
	};
};

void PrintVec2(const Vec2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	Vec4 vec = { 1.0f, 2.0f, 3.0f, 4.0f };
	PrintVec2(vec.a); // accessing via the 2nd struct
	PrintVec2(vec.b);
	vec.z = 200.0f; // accessing via the 1st struct
	std::cout << "------------------------------------------\n";
	PrintVec2(vec.a);
	PrintVec2(vec.b);

	std::cin.get();
}