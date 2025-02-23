#include <iostream>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{ }

	// copy constructor
	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "copied" << std::endl;
	}
};

int main()
{
	std::vector<Vertex> vertices;
	// by this method first the vertex is created in the main stack and then copied to the vector
	vertices.push_back({ 1, 2, 3 }); 
	vertices.push_back(Vertex(7, 8, 9)); // due to this the vector need to resize the capacity to 3
	vertices.push_back({ 4, 5, 6 });
	// for this the vertices are copied 6 times in total

	std::cout << "minor optimization" << "\n";

	// some optimization
	std::vector<Vertex> ver2;
	ver2.reserve(3); // if we know we want to make 3 vertices we just reserve the space
	ver2.push_back(Vertex(1, 2, 3)); // as the vertex is constructed here we are getting the copy
	ver2.push_back(Vertex(4, 5, 6));
	ver2.push_back(Vertex(7, 8, 9));
	// due to this some space is prereserved so multiple copies are not created only 3 are created

	std::cout << "most optimized" << "\n";

	std::vector<Vertex> ver3;
	ver3.reserve(3); // if we know we want to make 3 vertices we just reserve the space
	ver3.emplace_back(1, 2, 3); // used to construct inside the actual vector
	ver3.emplace_back(4, 5, 6);
	ver3.emplace_back(7, 8, 9);


	std::cin.get();
}