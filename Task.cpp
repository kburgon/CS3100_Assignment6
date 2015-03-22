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
	burstInterrupted = false;
	interruptTimeRemaining = -1;
}

void Task::setCreateTime(double timeSet)
{
	createTime = timeSet;
}

void Task::endBurst(int endTime)
{
	if (bursts[curBurstLoc].isIo() && firstResponse == true)
	{
		firstResponse = false;
		firstResponseTime = endTime - createTime;
	}
	if (!isInterrupted())
	{	
		bursts[curBurstLoc].endBurst(endTime);
		curBurstLoc++;
	}
	if (curBurstLoc == numOfBursts)
	{
		std::cout << "Shutting down task...\n";
		curBurstLoc = -1;
	}
	latency = endTime - createTime;
}

bool Task::curBurstIo()
{
	return bursts[curBurstLoc].isIo();
}

int Task::getIoWaitLoc()
{
	if (bursts[curBurstLoc].isIo())
	{
		return bursts[curBurstLoc].getIoLocation();
	}
	return -1;
}

int Task::getBurstLoc()
{
	return curBurstLoc;
}

double Task::getBurstTime()
{
	if (isInterrupted())
	{
		return interruptRunTime;
	}
	else if (interruptTimeRemaining == -1)
	{
		return bursts[curBurstLoc].getBurstTime();	
	}
	return interruptTimeRemaining;
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
	std::normal_distribution<> norm(2, 0.75);
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

double Task::getLatency()
{
	return latency;
}

double Task::getFirstResponseTime()
{
	return firstResponseTime;
}

bool Task::isInterrupted()
{
	return burstInterrupted;
}

void Task::setInterrupted(bool setIsInterrupted)
{
	burstInterrupted = setIsInterrupted;
}

void Task::setInterruptRunTime(double setTime)
{
	interruptRunTime = setTime;
}

void Task::setRemainingInterruptTime(double setTime)
{
	interruptTimeRemaining = setTime;
}

double Task::getRemainingInterruptTime()
{
	return interruptTimeRemaining;
}