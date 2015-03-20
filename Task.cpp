// Task pseudocode
#include "Task.hpp"

Task::Task(int ioDevCnt)
{
	// create burst vector - ioDevCnt is for generating random io location
	isIo = false;
	Burst newBurst;
	IoBurst newIoBurst;
	numOfBursts = 0;
	int ioDevNum = 0;
	for (int n = 0; n < 10; n++)
	{
		if (isIo)
		{
			newIoBurst.setDevLoc(newIoBurst.getRandomIoLoc(ioDevCnt));
			// newIoBurst.setDevLoc(ioDevNum);
			bursts.push_back(newIoBurst);
			isIo = false;
			ioDevNum++;
			if (ioDevNum == ioDevCnt)
			{
				ioDevNum = 0;
			}
		}
		else
		{
			bursts.push_back(newBurst);
			isIo = true;
		}
		numOfBursts++;
	}
	// burst = newBurst;
	curBurstLoc = 0;
	firstResponse = true;
	isCompleted = false;
	// std::cout << "Constructing task...\n";
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
	// if (bursts[curBurstLoc].isIo()) std::cout << "EndBurst: This is io\n";
	// else std::cout << "EndBurst: This is cpu\n";
	bursts[curBurstLoc].endBurst(endTime);
	// burst.endBurst(endTime);
	curBurstLoc++;
	// if (bursts[curBurstLoc].isIo()) std::cout << "EndBurst: This is io\n";
	// else std::cout << "EndBurst: This is cpu\n";
	
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
	// std::cout << "The current burst location: " << curBurstLoc << std::endl;
	if (bursts[curBurstLoc].isIo())
	{
		// std::cout << "This is an io burst.  Getting location...\n";
		return bursts[curBurstLoc].getIoLocation();
	}
	return -1;
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

// int Task::getIoBurstWaitLoc()
// {
// 	if (bursts[curBurstLoc].isIo())
// 	{

// 	}
// }