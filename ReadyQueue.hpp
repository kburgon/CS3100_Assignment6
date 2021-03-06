#ifndef READYQUEUE_HPP
#define READYQUEUE_HPP

#include "Task.hpp"
#include <memory>
#include <vector>
#include <iostream>

class ReadyQueue
{
private:
	std::vector<std::shared_ptr<Task>> readyList;
public:
	ReadyQueue();
	void pushTask(std::shared_ptr<Task> curTask);
	std::shared_ptr<Task> pullTask();
	bool isEmpty();
	void printQueue();
};

#endif