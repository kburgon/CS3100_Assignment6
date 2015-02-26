#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <vector>
#include <string>
#include <random>
#include <iostream>

class Burst
{
public:
    bool isCpuBurst;
    double latency;
    double timeCost;
};

class Task
{
public:
    std::vector<Burst> bursts;
    int curBurst;
    double initTime;
    void generateTask(bool IOBound);
    double getBurstTime();
    double latency;
    double firstResponseTime;
    bool isIOBound;
    void testBursts();
};

#endif // TASK_H_INCLUDED
