#include <iostream>
#include <vector>

#include <unordered_map>

int main()
{
	std::vector<int> vals = { 1, 3, 5, 7, 9 };
	/*
	for (int i = 0; i < vals.size(); i++)
	{
		std::cout << vals[i] << std::endl;
	}

	// range based iterator
	for (int val : vals)
		std::cout << val << std::endl;

	// custom iterator
	for (std::vector<int>::iterator it = vals.begin();
		it != vals.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	*/

	// custom iterator for unordered map
	using ScoreMap = std::unordered_map<std::string, int>;
	ScoreMap map;
	map["raiden"] = 5;
	map["og"] = 1;

	for (ScoreMap::const_iterator it = map.begin();
		it != map.end(); it++)
	{
		auto& key = it->first;
		auto& value = it->second;

		std::cout << key << " = " << value << std::endl;
	}

	std::cout << "----------------------------------\n";

	// easier way ti iterate by mapping
	for (auto kv : map)
	{
		auto& key = kv.first;
		auto& value = kv.second;

		std::cout << key << " = " << value << std::endl;
	}

	std::cout << "----------------------------------\n";

	// using structured bindings
	for(auto [key, val] : map)
		std::cout << key << " = " << val << std::endl;

	std::cin.get();
}