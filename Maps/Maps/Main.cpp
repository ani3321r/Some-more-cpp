#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Lat, Long;

	// in order to make the custom hash func work we need to overload the "<" operator or else the map will not work
	// the "<" defines the unique key inside the actual map
	bool operator<(const CityRecord& other) const
	{
		return Population < other.Population;
	}
};

// we can take a custom datatype as a key so we need to hash it then use it as a key
namespace std {
	template<>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key)
		{
			return hash<std::string>()(key.Name);
		}
	};
}

int main()
{
	std::unordered_map<std::string, CityRecord> cityMap;

	cityMap["Tokyo"] = CityRecord{ "Tokyo", 14000000, 3.4, 5.4 };
	cityMap["Kyoto"] = CityRecord{ "Kyoto", 1500000, 7.4, 4.8 };
	cityMap["Osaka"] = CityRecord{ "Osaka", 2800000, 2.4, 1.2 };
	cityMap["Yokohama"] = CityRecord{ "Yokohama", 3800000, 6.5, 7.2 };
	cityMap["Sendai"] = CityRecord{ "Sendai", 1100000, 4.6, 3.7 };

	std::map<CityRecord, uint32_t> foundedMap; // hashed key
	foundedMap[CityRecord{ "Tokyo", 14000000, 3.4, 5.4 }];
	foundedMap[CityRecord{ "Kyoto", 1500000, 7.4, 4.8 }];
	foundedMap[CityRecord{ "Osaka", 2800000, 2.4, 1.2 }];

	// the [] operator always inserts data inside the map if its not present in the map
	CityRecord& KobeData = cityMap["Kobe"];
	// this is a preferred way of inserting data in map which ensures no copy
	KobeData.Name = "Kobe";
	KobeData.Population = 1500000;

	if(cityMap.find("Kobe") != cityMap.end()) // check if the key exists
		CityRecord& kobeData2 = cityMap.at("Kobe"); // also retrieve from a non-const map

	// in order to avoid inserting we can make the map const
	const auto& cities = cityMap;
	//CityRecord& KobeData = cities["Kobe"]; // this will not work
	// to retrieve data from the map we use "at"
	const CityRecord& kobeData1 = cities.at("Kobe"); // has to be a const


	//iterating through the map
	for (auto& [name,city] : cityMap)
	{
		std::cout << name << " Population: " << city.Population << std::endl;
		foundedMap[city] = 0; // initializing all the years with 0
	}

	std::cout << "-------------------------------------------\n";
	
	for (auto& [city, founded] : foundedMap)
	{
		std::cout << city.Name << " Population: " << city.Population << std::endl;
	}

	std::cin.get();
}