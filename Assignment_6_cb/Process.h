#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include <chrono>
#include <iostream>
#include <unistd.h>

class Process
{
private:
	//timeToTake
	void cpuBurstOne();
	void ioBurstOne();
	void cpuBurstTwo();
	void ioBurstTwo();



	bool nextBurstIO;
	bool nextBurstCPU;
public:
	void execute();
	void getTime();
};

#endif
