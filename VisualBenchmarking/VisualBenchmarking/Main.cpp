#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>

#include <cmath>
#include <thread>

struct ProfileResult
{
	std::string Name;
	long long Start, End;
	uint32_t ThreadID;
};

struct InstrumentationSession
{
	std::string Name;
};

class Instrumentor
{
private:
	InstrumentationSession* m_CurrentSession;
	std::ofstream m_OutputStream;
	int m_ProfileCount;
public:
	Instrumentor()
		: m_CurrentSession(nullptr), m_ProfileCount(0)
	{
	}

	void BeginSession(const std::string& name, const std::string& filepath = "results.json")
	{
		m_OutputStream.open(filepath);
		WriteHeader();
		m_CurrentSession = new InstrumentationSession({ name });
	}

	void EndSession()
	{
		WriteFooter();
		m_OutputStream.close();
		delete m_CurrentSession;
		m_CurrentSession = nullptr;
		m_ProfileCount = 0;
	}

	void WriteProfile(const ProfileResult& result)
	{
		if (m_ProfileCount++ > 0)
			m_OutputStream << ",";
		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		m_OutputStream << "{";
		m_OutputStream << "\"cat\":\"function\",";
		m_OutputStream << "\"dur\":" << (result.End - result.Start) << ",";
		m_OutputStream << "\"name\":\"" << name << "\",";
		m_OutputStream << "\"ph\":\"X\",";
		m_OutputStream << "\"pid\":0,";
		m_OutputStream << "\"tid\":" << result.ThreadID << ",";
		m_OutputStream << "\"ts\":" << result.Start;
		m_OutputStream << "}";

		m_OutputStream.flush();
	}

	void WriteHeader()
	{
		m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
		m_OutputStream.flush();
	}

	void WriteFooter()
	{
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}

	static Instrumentor& Get()
	{
		static Instrumentor instance;
		return instance;
	}
};

class InstrumentationTimer
{
public:
	InstrumentationTimer(const char* name)
		: m_Name(name), m_Stopped(false)
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	
	~InstrumentationTimer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto EndTimePoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

		uint32_t threadID = std::hash<std::thread::id>()(std::this_thread::get_id());
		 Instrumentor::Get().WriteProfile({ m_Name, start, end, threadID });

		m_Stopped = true;
	}

private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
	bool m_Stopped;
};

#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#endif

namespace Benchmarking{
	void Function1()
	{
		PROFILE_FUNCTION();
	
		for (int i = 0; i < 1000; i++)
			std::cout << "Hello raiden #" << i << std::endl;
	}
	
	void Function2()
	{
		PROFILE_FUNCTION();
	
		for (int i = 0; i < 1000; i++)
			std::cout << "Hello raiden #" << sqrt(i) << std::endl;
	}

	void PrintFunction(int val)
	{
		PROFILE_FUNCTION();

		for (int i = 0; i < 1000; i++)
			std::cout << "Hello liu #" << i + val << std::endl;
	}
	
	void PrintFunction()
	{
		PROFILE_FUNCTION();

		for (int i = 0; i < 1000; i++)
			std::cout << "Hello gord #" << i << std::endl;
	}
	
	void RunBenchmark()
	{
		PROFILE_FUNCTION();
	
		std::cout << "Running benchmark..." << std::endl;
		std::thread a([]() {PrintFunction(2);});
		std::thread b([]() {PrintFunction();});

		a.join();
		b.join();

		Function1();
		Function2();
	}
}
int main()
{
	Instrumentor::Get().BeginSession("Test Session");
	Benchmarking::RunBenchmark();
	Instrumentor::Get().EndSession();

	std::cin.get();
}