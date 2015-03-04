// Scheduler class 
#include "Scheduler.hpp"

Scheduler::Scheduler()
{
	numCpus = 1;
	cpuVsIo = 0.5;
	taskCreateFreq = 0.5;
	cntxtSwitchCost = 0.2;
	numOfIoDevs = 1;
}

void Scheduler::setNumCpus(int numToSet)
{
	numCpus = numToSet;
}

void Scheduler::setPercentCpuIo(double setPercent)
{
	cpuVsIo = setPercent;
}

void Scheduler::setTaskCreateFreq(double setFreq)
{
	taskCreateFreq = setFreq;
}

void Scheduler::setCntxtSwitchCost(double setCost)
{
	cntxtSwitchCost = setCost;
}

void Scheduler::setNumIoDevices(int numDevices)
{
	numOfIoDevs = numDevices;
}

void Scheduler::init()
{
	std::cout << "Started init phase..\n";
	// IOQueues waitQueue(numOfIoDevs);
	// ReadyQueue readyQ;
	// create task
	// load task on event queue
	// EventQueue processEvent(cntxtSwitchCost);
	// create new task and event
	// processEvent.addEvent(newTask);
	// load schedule end event
	runSession();
}

void Scheduler::runSession()
{
	std::cout << "Running session...\n";
	bool endOfSession = false;
	Event curEvent;
	// Task* curTask;
	// while (!endOfSession)
	// {
	// 	curEvent = processEvent.pullEvent();
	// 	processTime = processEvent.getTime();
	// 	if (!processEvent.willEndSession())
	// 	{
	// 		curTask = processEvent.getRelatedTask();
	// 		if (curTask->curBurstIo())
	// 		{
	// 			processEvent.addEvent(waitQueue.endTaskGetNext(curTask));
	// 			curTask->endBurst(processTime);
	// 		}
	// 	}
	// }
}

void Scheduler::getDats()
{
	// need to fill in
}

void Scheduler::calcLatency()
{
	// need to fill in
}

void Scheduler::calcRespTime()
{
	// need to fill in
}

void Scheduler::calcPercentUtilized()
{
	// need to fill in
}

void Scheduler::calcThroughput()
{
	// need to fill in
}
