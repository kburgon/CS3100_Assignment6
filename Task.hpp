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
	// Burst burst;
	double createTime;
	double latency;
	int curBurstLoc;
	int numOfBursts;
	bool firstResponse;
	double firstResponseTime;
	bool isCompleted;
	double getRandomFloat();
	int getRandomInt(int);
public:
	Task(int, double, double);
	int getBurstLoc();
	// bool isFirstResp();
	// Burst getBurst();
	void endBurst(int);
	bool curBurstIo();
	void setCreateTime(double);
	int getIoWaitLoc();
	double getBurstTime();
	double getFirstResponseTime();
	bool taskIsCompleted();
	double getLatency();
	// probably not needed
	// void operator=(Task);
	std::vector<Burst> assignBursts();
};

#endif