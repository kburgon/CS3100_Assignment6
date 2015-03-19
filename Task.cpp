// Task pseudocode
#include "Task.hpp"

Task::Task()
{
	// create burst vector
	isIo = false;
	Burst newBurst;
	numOfBursts = 0;
	for (int n = 0; n < 5; n++)
	{
		bursts.push_back(newBurst);
		numOfBursts++;
	}
	// burst = newBurst;
	curBurstLoc = 0;
	firstResponse = true;
	isCompleted = false;
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
	// if (burst.isIo() && firstResponse == true)
	if (bursts[curBurstLoc].isIo() && firstResponse == true)
	{
		firstResponse = false;
		// set firstResponse time to curTime
	}
	// bursts[curBurstLoc].endBurst(endTime);
	burst.endBurst(endTime);
	curBurstLoc++;
	if (curBurstLoc == numOfBursts)
	{
		std::cout << "Shutting down task...\n";
		curBurstLoc = numOfBursts - 1;
	}
}

bool Task::curBurstIo()
{
	return bursts[curBurstLoc].isIo();
	// return burst.isIo();
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
	return bursts[curBurstLoc].getBurstTime();
	// return burst.getBurstTime();
}

void Task::operator=(Task toAssign)
{
	isIo = curBurstIo();
	// burst = toAssign.getBurst();
	bursts = toAssign.assignBursts();
	curBurstLoc = toAssign.getBurstLoc();
	firstResponse = toAssign.isFirstResp();
}

std::vector<Burst> Task::assignBursts()
{
	return bursts;
}

bool Task::taskIsCompleted()
{
	return isCompleted;
}