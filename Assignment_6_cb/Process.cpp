#include "Process.h"

void Process::cpuBurstOne()
{
	std::cout << "Running cpu process one...\n";
	sleep(3);
	nextBurstCPU = false;
	nextBurstIO = true;
}

void Process::ioBurstOne()
{
	std::cout << "Running io process one...\n";
	sleep(5);
	nextBurstCPU = true;
	nextBurstIO = false;
}

void Process::cpuBurstTwo()
{
	std::cout << "Running cpu process two...\n";
	sleep(2);
	nextBurstCPU = false;
	nextBurstIO = true;
}

void Process::ioBurstTwo()
{
	std::cout << "Running io process two...\n";
	sleep(4);
	nextBurstCPU = true;
	nextBurstIO = false;
}

void Process::execute()
{
    cpuBurstOne();
    ioBurstOne();
    cpuBurstTwo();
    ioBurstTwo();
}
