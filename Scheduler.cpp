#include "Scheduler.hpp"

Scheduler::Scheduler()
{
	numCpus = 1;
	cpuVsIo = 1;
	taskCreateFreq = 1;
	cntxtSwitchCost = 1;
	numOfIoDevs = 1;
	curTime = 0;
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
	ioDevQueue.createQueues(numOfIoDevs);
	std::shared_ptr<Task> initTask = std::make_shared<Task>();
	std::shared_ptr<Task> endTask = std::make_shared<Task>();
	Event firstEvent(initTask, 0, false);
	Event lastEvent(endTask, 100, false, true);
	eQueue.addEvent(firstEvent);
	eQueue.addEvent(lastEvent);
	runSession();
}

void Scheduler::createTasks(int numOfTasks)
{
	std::shared_ptr<Task> taskToAdd;
	Event eventToAdd;
	double newTaskExecTime;
	for (int n = 0; n < numOfTasks; n++)
	{
		taskToAdd = std::make_shared<Task>();
		newTaskExecTime = curTime + taskToAdd->getBurstTime();
		eventToAdd = Event(taskToAdd, newTaskExecTime, false);
		eQueue.addEvent(eventToAdd);
	}
}

void Scheduler::execTask(std::shared_ptr<Task> exTask)
{
	// std::cout << "Executing task...\n";
	exTask->endBurst(curTime);
	double timeToEvent = cntxtSwitchCost + exTask->getBurstTime();
	if (!exTask->taskIsCompleted())
	{
		// check if io task or not, act accordingly
		double nextEventTime = curTime + timeToEvent;
		Event nextEvent(exTask, nextEventTime, false);
		eQueue.addEvent(nextEvent);
	}
	else
	{
		std::cout << "The task has finished.\n";
	}
	// numCpus--;
	
}

void Scheduler::handleIoEvent(std::shared_ptr<Task> eventTask)
{
	int ioDevLoc = eventTask->getIoWaitLoc();
	ioDevQueue.finishTask(ioDevLoc);
	eventTask->endBurst(curTime);
	if (!ioDevQueue.queueIsEmpty(ioDevLoc))
	{
		std::shared_ptr<Task> newEventTask = ioDevQueue.getNextTask(ioDevLoc);
		double eventTime = curTime + newEventTask->getBurstTime();
		Event newEvent(newEventTask, eventTime, true);
		eQueue.addEvent(newEvent);
	}
}

void Scheduler::execIO(std::shared_ptr<Task> execTask)
{
	int ioDevLoc = execTask->getIoWaitLoc();
	std::cout << "Wait location: " << ioDevLoc << std::endl;
	if (ioDevQueue.queueIsEmpty(ioDevLoc))
	{
		double eventTime = curTime + execTask->getBurstTime();
		Event newEvent(execTask, eventTime, true);
		eQueue.addEvent(newEvent);
	}
	ioDevQueue.pushTask(execTask);
}

void Scheduler::runSession()
{
	// std::cout << "Running session...\n";
	bool endOfSession = false;
	Event curEvent;
	std::shared_ptr<Task> curTask;
	double lastEventTime = 0;
	double timeFromLastE;
	while (!endOfSession)
	{
		// std::cout << "Starting loop again...\n";
		curEvent = eQueue.pullEvent();
		curTime = curEvent.getTime();
		timeFromLastE = curTime - lastEventTime;
		if (curEvent.willEndSession())
		{
			endOfSession = true;
			std::cout << "Ending session now with time at " << curEvent.getTime() << "\n";
		}
		else
		{
			curTask = curEvent.getRelatedTask();
			if (curEvent.isIo())
			{
				handleIoEvent(curTask);
			}
			std::cout << "Not ending session yet!  Time: " << curEvent.getTime() << "\n";
			int tasksToCreate = timeFromLastE / taskCreateFreq;
			std::cout << "Amount of tasks that will be created: " << tasksToCreate << std::endl;
			createTasks(tasksToCreate);
			if (curTask->curBurstIo())
			{
				std::cout << "This has been recognized as an io burst...\n";
				execIO(curTask);
			}
			else
			{
				if (numCpus > 0)
				{
					execTask(curTask);
				}
				else
				{
					rQueue.pushTask(curTask);
				}
			}
			lastEventTime = curTime;
		}
		// std::cout << "How about now?\n";
	}
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
