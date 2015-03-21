// Task pseudocode
#include "Task.hpp"

Task::Task(int ioDevCnt, double cpuMultiplier, double ioMultiplier)
{
	double ioTimeSet, cpuTimeSet;
	isIo = false;
	Burst newBurst;
	IoBurst newIoBurst;
	numOfBursts = 0;
	for (int n = 0; n < 10; n++)
	{
		if (isIo)
		{
			ioTimeSet = ioMultiplier * getRandomFloat();
			std::cout << "IO BINDING: The multiplier is at " << ioMultiplier << " and the new time is " << ioTimeSet << std::endl;
			newIoBurst = IoBurst(ioMultiplier, getRandomInt(ioDevCnt));
			bursts.push_back(newIoBurst);
			isIo = false;
		}
		else
		{
			cpuTimeSet = cpuMultiplier * getRandomFloat();
			std::cout << "CPU BINDING: The multiplier is at " << ioMultiplier << " and the new time is " << cpuTimeSet << std::endl;
			newBurst = Burst(cpuTimeSet);
			bursts.push_back(newBurst);
			isIo = true;
		}
		numOfBursts++;
	}
	curBurstLoc = 0;
	firstResponse = true;
	isCompleted = false;
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
	std::cout << "WARNING!!	 Using Task's assignment operator.  This should be updated.\n";
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

double Task::getRandomFloat()
{
	std::random_device rdm;
	std::mt19937 mt(rdm());
	std::normal_distribution<> norm(10, 3.5);
	double normalNum = norm(mt);
	return normalNum;
}

int Task::getRandomInt(int upperNum)
{
	std::random_device rdm;
	std::mt19937 mt(rdm());
	std::uniform_int_distribution<> devLocGen(0, upperNum - 1);
	int randNum = devLocGen(mt);
	return randNum;
}