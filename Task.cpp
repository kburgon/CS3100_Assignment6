// Task pseudocode
#include "Task.hpp"

Task::Task()
{
	// create burst vector
	endSession = false;
	isIo = false;
	Burst newBurst;
	burst = newBurst;
	curBurstLoc = 0;
	firstResponse = true;
	// generate random int
	for (int n = 0; n < randomInt; n++)
	{
		// if setIo == false create burst()
		// if setIo == true create burst(waitSpot)
		// add to burstVector
	}
}

// Task::Task(bool isEndSession, bool setIsIo, int waitSpot);

void Task::setTimes()
{
	// generate random number
	// int taskTime = randomNum;
}

// double Task::timeToComplete();

// double Task::firstResponseTime();

void Task::endBurst(int endTime)
{
	if (burst.isIo() && firstResponse == true)
	{
		firstResponse = false;
		// set firstResponse time to curTime
	}
	burst.endBurst(endTime);
	curBurstLoc++;
}

bool Task::curBurstIo()
{
	// return burst[curBurstLoc].isIo();
}

int Task::getIoWaitLoc()
{
	// burst.location
}