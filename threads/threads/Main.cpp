#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	while (!s_Finished)
	{
		std::cout << "Working...\n";
		// this_thread is used to give commands to the current thread
		std::this_thread::sleep_for(1s); // we are sleeping for a sec to not overload the single thread
	}
}

int main()
{
	std::thread worker(DoWork);

	std::cin.get(); // until the user gives input the while loop will keep running
	s_Finished = true;

	worker.join(); // after the thread gets executed then the rest of the code after this will start executing
	std::cout << "Finished..." << std::endl;

	std::cin.get();
}