#ifndef BURST_HPP
#define BURST_HPP

#include <iostream>

class Burst
{
private:
	double bTime;
	double endTime;
	double latency;
	bool isIoBurst;
public:
	void setIfIoStatus(bool);
	Burst();
	Burst(double, bool);
	bool isIo();
	double getLatency();
	double getEndTime();
	double getBurstTime();
	void endBurst(int);
	void operator=(Burst);
};

class IoBurst:public Burst
{
private:
	int waitLocation;
public:
	IoBurst(int newWaitLoc=0):Burst()
	{
		waitLocation = newWaitLoc;
		// isIoBurst = true;
		setIfIoStatus(true);
	}

	int getIoLocation();
};

#endif