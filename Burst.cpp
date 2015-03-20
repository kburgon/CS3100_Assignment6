// two classes: Burst and IoBurst
#include "Burst.hpp"

Burst::Burst(int newWaitLoc)
{
	bTime = getRandomTime();
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

void Burst::setDevLoc(int newLoc)
{
	waitLocation = newLoc;
}

void Burst::operator=(Burst toAssign)
{
	latency = toAssign.getLatency();
	endTime = toAssign.getEndTime();
	bTime = toAssign.getBurstTime();
}

double Burst::getRandomTime()
{
	std::random_device rdm;
	std::mt19937 mt(rdm());
	std::normal_distribution<> norm(10, 3.5);
	double normalNum = norm(mt);
	return normalNum;
}

int Burst::getRandomIoLoc(int numOfDevs)
{
	std::random_device rdm;
	std::mt19937 mt(rdm());
	std::uniform_int_distribution<> devLocGen(0, numOfDevs - 1);
	int randDevLoc = devLocGen(mt);
	return randDevLoc;
}

// child class IoBurst

// int IoBurst::getIoLocation()
// {
// 	return waitLocation;
// }