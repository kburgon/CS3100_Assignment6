// Task pseudocode
#include "Task.hpp"

Task::Task()
{
	// create burst vector
	isIo = false;
	Burst newBurst;
	burst = newBurst;
	curBurstLoc = 0;
	firstResponse = true;
	std::cout << "Constructing task...\n";
	// generate random int
	// for (int n = 0; n < randomInt; n++)
	// {
	// 	// if setIo == false create burst()
	// 	// if setIo == true create burst(waitSpot)
	// 	// add to burstVector
	// }
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
	return burst.isIo();
}

int Task::getIoWaitLoc()
{
	// burst.location
}

int Task::getBurstLoc()
{
	return curBurstLoc;
}

bool Task::isFirstResp()
{
	return firstResponse;
}

Burst Task::getBurst()
{
	return burst;
}

double Task::getBurstTime()
{
	return burst.getBurstTime();
}

void Task::operator=(Task toAssign)
{
	isIo = curBurstIo();
	burst = toAssign.getBurst();
	curBurstLoc = toAssign.getBurstLoc();
	firstResponse = toAssign.isFirstResp();
}