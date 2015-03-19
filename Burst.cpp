// two classes: Burst and IoBurst
#include "Burst.hpp"

Burst::Burst(int newWaitLoc)
{
	bTime = 5;
	endTime = 0;
	isIoBurst = false;
	latency = 0;
	waitLocation = newWaitLoc;
}

int Burst::getIoLocation()
{
	return waitLocation;
}

Burst::Burst(double newBTime, bool setIo, int newWaitLoc)
{
	endTime = 0;
	isIoBurst = setIo;
	bTime = newBTime;
	latency = 0;
	waitLocation = newWaitLoc;
}

bool Burst::isIo()
{
	if (!isIoBurst) 
	{
		// std::cout << "This is a cpu burst\n";
		return false;
	}
	// std::cout << "This is an io burst\n";
	return true;
}

void Burst::endBurst(int endTime)
{
	latency = endTime;
}

void Burst::setIfIoStatus(bool setStatus)
{
	isIoBurst = setStatus;
}

double Burst::getLatency()
{
	return latency;
}

double Burst::getEndTime()
{
	return endTime;
}

double Burst::getBurstTime()
{
	return bTime;
}

void Burst::operator=(Burst toAssign)
{
	latency = toAssign.getLatency();
	endTime = toAssign.getEndTime();
	bTime = toAssign.getBurstTime();
}

// child class IoBurst

// int IoBurst::getIoLocation()
// {
// 	return waitLocation;
// }
