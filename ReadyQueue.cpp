// ready queue pseudocode
#include "ReadyQueue.hpp"

ReadyQueue::ReadyQueue()
{
	std::cout << "Started ready queue...\n";
}

void ReadyQueue::pushTask(std::shared_ptr<Task> curTask)
{
	readyList.push_back(curTask);
}

std::shared_ptr<Task> ReadyQueue::pullTask()
{
	std::shared_ptr<Task> toPull = readyList.back();
	readyList.pop_back();
	return toPull;
}