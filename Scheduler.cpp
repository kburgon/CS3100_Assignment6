#include "Scheduler.hpp"

Scheduler::Scheduler()
{
	numCpus = 4;
	cpuVsIo = 1;
	taskCreateFreq = 5;
	cntxtSwitchCost = 1;
	numOfIoDevs = 3;
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
	// std::cout << "Started init phase..\n";
	ioDevQueue.createQueues(numOfIoDevs);
	std::shared_ptr<Task> initTask = std::make_shared<Task>(numOfIoDevs);
	std::shared_ptr<Task> endTask = std::make_shared<Task>(numOfIoDevs);
	Event firstEvent(initTask, 0, false);
	Event lastEvent(endTask, 1000, false, true);
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
		taskToAdd = std::make_shared<Task>(numOfIoDevs);
		execTask(taskToAdd);
		// newTaskExecTime = curTime + taskToAdd->getBurstTime();
		// eventToAdd = Event(taskToAdd, newTaskExecTime, false);
		// eQueue.addEvent(eventToAdd);
	}
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
	else std::cout << "<<<<<<<<<<<<The queue is empty!>>>>>>>>>>>>\n";
}

void Scheduler::handleCpuEvent(std::shared_ptr<Task> eventTask)
{
	eventTask->endBurst(curTime);
	std::shared_ptr<Task> toEx;
	Event eToEx;
	numCpus++;
	double newEventTime;
	std::cout << "----------------about to fill remaining resources-----------------\n";
	// if (rQueue.isEmpty()) std::cout << "	rQueue is empty\n";
	// else std::cout << "	rQueue as items in it\n";
	while (!rQueue.isEmpty() && numCpus > 0)
	{
		std::cout << "Number of cpus avaiable: " << numCpus << std::endl;
		std::cout << "\n\nFilling cpus...\n\n";
		toEx = rQueue.pullTask();
		newEventTime = curTime + cntxtSwitchCost + eventTask->getBurstTime();
		eToEx = Event(toEx, newEventTime, false);
		eQueue.addEvent(eToEx);
		numCpus--;
		// std::cout << "There are now " << numCpus << " CPUs\n";
	}
	// std::cout << "Number of cpus avaiable: " << numCpus << std::endl;
}

void Scheduler::execIO(std::shared_ptr<Task> execTask)
{
	if (!execTask->taskIsCompleted())
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
	else
	{
		std::cout << "Task was finished.\n";
	}
}

void Scheduler::execTask(std::shared_ptr<Task> exTask)
{
	// std::cout << "Executing task...\n";
	// exTask->endBurst(curTime);
	if (!exTask->taskIsCompleted())
	{
		std::cout << "Number of cpus avaiable: " << numCpus << std::endl;
		rQueue.pushTask(exTask);
		if (numCpus > 0)
		{
			std::cout << "There are " << numCpus << " cpus left. Filling...\n";
			std::shared_ptr<Task> toExec = rQueue.pullTask();
			double timeToEvent = cntxtSwitchCost + toExec->getBurstTime();
			double nextEventTime = curTime + timeToEvent;
			Event nextEvent(exTask, nextEventTime, false);
			eQueue.addEvent(nextEvent);
			numCpus--;
		}
	}
	else
	{
		std::cout << "The task has finished.\n";
	}
	// numCpus--;
	
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
		std::cout << "\n\n************************************NEW EVENT*******************************\n";
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
			if (curTask->curBurstIo()) std::cout << "This is an IO task\n";
			else std::cout << "This is a CPU task\n";
			if (curEvent.isIo())
			{
				std::cout << "This is an IO event\n";
				handleIoEvent(curTask);
			}
			else
			{
				std::cout << "This is a CPU event\n";
				handleCpuEvent(curTask);
			}
			std::cout << "Not ending session yet!  Time: " << curEvent.getTime() << "\n";
			int tasksToCreate = timeFromLastE / taskCreateFreq;
			// std::cout << "Amount of tasks that will be created: " << tasksToCreate << std::endl;
			createTasks(tasksToCreate);
			if (curTask->curBurstIo())
			{
				std::cout << "This has been recognized as an io burst...\n";
				execIO(curTask);
			}
			else
			{
				std::cout << "This has been recognized as a cpu burst...\n";
				execTask(curTask);
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
