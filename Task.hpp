#ifndef TASK_HPP
#define TASK_HPP

#include "Burst.hpp"
#include <iostream>

class Task
{
private:
	bool endSession;
	bool isIo;
	int randomInt;
	Burst burst;
	int curBurstLoc;
	bool firstResponse;
public:
	Task();
	// Task(bool, bool, int=0);
	void endBurst(int);
	bool curBurstIo();
	void setTimes();
	int getIoWaitLoc();

};

#endif