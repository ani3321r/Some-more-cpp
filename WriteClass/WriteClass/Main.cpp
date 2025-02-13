#include <iostream>

class Log
{
// public variables and methods goes in different sections for easier readability
public:
	enum Level
	{
		LevelError, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo; //the m_ indicates class member variable, this is a conevntion
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[Error]: " << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[Info]: " << message << std::endl;
	}
};

int main() {
	Log log;
	log.SetLevel(Log::LevelError); // due to the setLevel all the logs will not be printed
	log.Warn("Hello!");
	log.Error("Hello!");
	log.Info("Hello!");
	std::cin.get();
}