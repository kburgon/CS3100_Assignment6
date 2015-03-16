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
	std::shared_ptr<Task> initTask = std::make_shared<Task>();
	std::shared_ptr<Task> endTask = std::make_shared<Task>();
	// create new event
	Event firstEvent(initTask, 0);
	Event lastEvent(endTask, 100, true);
	// load events on event queue
	eQueue.addEvent(firstEvent);
	eQueue.addEvent(lastEvent);
	// load schedule end event
	runSession();
}

void Scheduler::execTask(std::shared_ptr<Task> exTask, double curTime)
{
	std::cout << "Executing task...\n";
	exTask->endBurst(curTime);
	double nextEventTime = curTime + cntxtSwitchCost + exTask->getBurstTime();
	Event nextEvent(exTask, nextEventTime);
	// numCpus--;
	eQueue.addEvent(nextEvent);
}

void Scheduler::runSession()
{
	std::cout << "Running session...\n";
	bool endOfSession = false;
	Event curEvent;
	std::shared_ptr<Task> curTask;
	while (!endOfSession && !eQueue.isEmpty())
	{
		curEvent = eQueue.pullEvent();
		if (curEvent.willEndSession())
		{
			endOfSession = true;
			std::cout << "Ending session now with time at " << curEvent.getTime() << "\n";
		}
		else 
		{
			std::cout << "Not ending session yet!  Time: " << curEvent.getTime() << "\n";
			curTask = curEvent.getRelatedTask();
			if (numCpus > 0)
			{
				execTask(curTask, curEvent.getTime());
			}
			else
			{
				rQueue.pushTask(curTask);
			}
		}
	}
	// std::shared_ptr<Task> curTask;
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
