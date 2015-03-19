#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include "Event.hpp"
#include "EventQueue.hpp"
#include "Task.hpp"
#include "ReadyQueue.hpp"
#include "IOQueues.hpp"

class Scheduler
{
private:
	// std::vector<Task*> tasks;
	double curTime;
	int numCpus;
	double cpuVsIo;
	double taskCreateFreq;
	double cntxtSwitchCost;
	int numOfIoDevs;
	EventQueue eQueue;
	ReadyQueue rQueue;
	IOQueues ioDevQueue;
	void createTasks(int);
	void execIO(std::shared_ptr<Task>);
	void handleIoEvent(std::shared_ptr<Task>);
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
	void execTask(std::shared_ptr<Task>);
};

#endif