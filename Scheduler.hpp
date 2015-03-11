#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include "Event.hpp"
#include "EventQueue.hpp"
#include "Task.hpp"

class Scheduler
{
private:
	// std::vector<Task*> tasks;
	int numCpus;
	double cpuVsIo;
	double taskCreateFreq;
	double cntxtSwitchCost;
	int numOfIoDevs;
	EventQueue eQueue;
public:
	Scheduler();
	void setNumCpus(int numToSet);
	void setPercentCpuIo(double setPercent);
	void setTaskCreateFreq(double setFreq);
	void setCntxtSwitchCost(double setCost);
	void setNumIoDevices(int numDevices);
	void init();
	void runSession();
	void getDats();
	void calcLatency();
	void calcRespTime();
	void calcPercentUtilized();
	void calcThroughput();
};

#endif