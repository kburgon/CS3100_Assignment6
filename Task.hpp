#ifndef TASK_HPP
#define TASK_HPP

#include "Burst.hpp"
#include <iostream>
#include <vector>

class Task
{
private:
	bool isIo;
	// int randomInt;
	std::vector<Burst> bursts;
	Burst burst;
	int curBurstLoc;
	int numOfBursts;
	bool firstResponse;
	bool isCompleted;
public:
	Task();
	// Task(bool, bool, int=0);
	int getBurstLoc();
	bool isFirstResp();
	Burst getBurst();
	void endBurst(int);
	bool curBurstIo();
	void setTimes();
	int getIoWaitLoc();
	double getBurstTime();
	void operator=(Task);
	bool taskIsCompleted();
	std::vector<Burst> assignBursts();
};

#endif