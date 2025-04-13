#include <iostream>
#include <memory>

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotaFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotaFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
	s_AllocationMetrics.TotalAllocated += size;

	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	s_AllocationMetrics.TotaFreed += size;

	free(memory);
}

struct Object
{
	int x, y, z;
};

static void PrintMemoryUsaage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main()
{
	PrintMemoryUsaage();
	std::string string = "Raiden";
	PrintMemoryUsaage();
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		PrintMemoryUsaage();
	}
	PrintMemoryUsaage();
	
	std::cin.get();
}