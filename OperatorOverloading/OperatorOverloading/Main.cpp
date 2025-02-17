#include <iostream>
#include <string>

struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) { }

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	// op overloading is basically making a basic operator more useful
	Vector2 operator+(const Vector2& other) const //here we are doing operator overloading
	{
		return Add(other);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	//another example of overloading
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}
};

// we can also overload the "<<" operator using ostream to show a certain kind of struct
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	Vector2 pos(4.0f, 3.0f);
	Vector2 speed(0.5f, 2.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 res1 = pos.Add(speed.Multiply(powerup)); //without overloading the ops, its a bit long
	//std::cout << res1.x << " " << res1.y << std::endl;
	std::cout << res1 << std::endl; // using the ope overloaded "<<"

	Vector2 res2 = pos + speed * powerup; // this is much easier using the operator overloading
	std::cout << res2.x << " " << res2.y << std::endl;

	std::string fun = (res1 != res2) ? "yay" : "nah";

	std::cout << fun;

	std::cin.get();
}