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
	int waitLocation;
public:
	int getIoLocation();
	void setIfIoStatus(bool);
	Burst(int=-1);
	Burst(double, bool, int=-1);
	bool isIo();
	double getLatency();
	double getEndTime();
	double getBurstTime();
	void endBurst(int);
	void setDevLoc(int);
	void operator=(Burst);
};

class IoBurst:public Burst
{
private:
public:
	// int getIoLocation() override;
	IoBurst(int newWaitLoc=0):Burst(newWaitLoc)
	{
		// waitLocation = newWaitLoc;
		// isIoBurst = true;
		setIfIoStatus(true);
	}
};

#endif