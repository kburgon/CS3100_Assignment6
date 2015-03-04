// two classes: Burst and IoBurst
#include "Burst.hpp"

Burst::Burst()
{
	// bTime = randomNum;
	endTime = 0;
	isIoBurst = false;
	latency = 0;
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

// child class IoBurst

int IoBurst::getIoLocation()
{
	return waitLocation;
}