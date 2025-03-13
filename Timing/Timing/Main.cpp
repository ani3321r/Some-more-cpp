#include <iostream>
#include <chrono>
#include <thread>

// struct for timing a func or a program
struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};

void Func()
{
	Timer timer;

	for (int i = 0; i < 100; i++)
		std::cout << "Hello\n"; // takes less time
}

void Func2()
{
	Timer timer;

	for (int i = 0; i < 100; i++)
		std::cout << "Hello" << std::endl;
}

int main()
{
	using namespace std::literals::chrono_literals;

	auto start = std::chrono::high_resolution_clock::now(); // gives the current time
	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << std::endl;

	Func();

	Func2();

	std::cin.get();
}