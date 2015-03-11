#ifndef READYQUEUE_HPP
#define READYQUEUE_HPP

#include "Task.hpp"
#include <memory>
#include <iostream>

class ReadyQueue
{
private:
public:
	ReadyQueue();
	void pushTask(Task* curTask);
	Task* pullTask();
};

#endif