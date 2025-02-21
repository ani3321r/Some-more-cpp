#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

int main()
{
	std::vector<Vertex> vertices;
	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 7,8,9 });

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;
	
	vertices.erase(vertices.begin() + 1); // we cant just write the index directly, we have to iterate to it

	for (Vertex& v : vertices) // call by reference so less memory is consumed
		std::cout << v << std::endl;

	//vertices.clear(); // to clear the whole vector


	std::cin.get();
}