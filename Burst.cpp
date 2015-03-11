// two classes: Burst and IoBurst
#include "Burst.hpp"

Burst::Burst()
{
	bTime = 1;
	endTime = 0;
	isIoBurst = false;
	latency = 0;
}

Burst::Burst(double newBTime, bool setIo)
{
	endTime = 0;
	isIoBurst = setIo;
	bTime = newBTime;
}

bool Burst::isIo()
{
	if (isIoBurst == false) 
		return false;
	else 
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

int IoBurst::getIoLocation()
{
	return waitLocation;
}
