#include <iostream>
#include <memory>

#include <chrono>
#include <array>

class Timer
{
public:
	Timer()
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto EndTimePoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << duration << "us (" << ms << "ms)\n";
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};

int main()
{
	int val = 0;
	{
		Timer timer;
		for (int i = 0; i < 1000000; i++)
			val += 2;
	}
	std::cout << val << std::endl;

	// another example
	struct Vec2
	{
		float x, y;
	};
	
	std::cout << "Make shared\n";
	{
		std::array<std::shared_ptr<Vec2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vec2>();
	}
	
	std::cout << "Shared ptr\n";
	{
		std::array<std::shared_ptr<Vec2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vec2>(new Vec2());
	}
	
	std::cout << "Make unique\n";
	{
		std::array<std::unique_ptr<Vec2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_unique<Vec2>();
	}
	__debugbreak();
}