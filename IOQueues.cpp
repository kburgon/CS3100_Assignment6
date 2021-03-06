#include "IOQueues.hpp"

IOQueues::IOQueues(int numOfQueues)
{
	createQueues(numOfQueues);
}

void IOQueues::createQueues(int numOfQueues)
{
	std::vector<std::shared_ptr<Task>> newQueue;
	for (int n = 0; n < numOfQueues; n++)
	{
		std::cout << "IO utilization: Creating queue " << n << " of " << numOfQueues << std::endl;
		queueList.push_back(newQueue);
	}
}

void IOQueues::pushTask(std::shared_ptr<Task> ioTask)
{
	int burstIoLoc = ioTask->getIoWaitLoc();
	if (burstIoLoc >= 0)
	{
		queueList[burstIoLoc].push_back(ioTask);
	}
	else
	{
		std::cerr << "ERROR!!  Current burst is not IO burst!!\n";
	}
}

std::shared_ptr<Task> IOQueues::getNextTask(int burstIoLoc)
{
	// int burstIoLoc = endingIoTask->getIoWaitLoc();
	if (!queueList[burstIoLoc].empty())
	{
		// queueList[burstIoLoc].erase(queueList[burstIoLoc].begin());
		return queueList[burstIoLoc][0];	
	}
	return nullptr;
}

void IOQueues::finishTask(int burstIoLoc)
{
	queueList[burstIoLoc].erase(queueList[burstIoLoc].begin());
}

bool IOQueues::queueIsEmpty(int ioDevLoc)
{
	return queueList[ioDevLoc].empty();
}

double IOQueues::getIoUtilization()
{
	double numOfDevs = 0;
	int numOfUsedDevs = 0;
	std::cout << "IO utilization (the number of devices): " << queueList.size() << std::endl;
	for(auto&& queue:queueList)
	{
		if (!queue.empty())
		{
			numOfUsedDevs++;
		}
		numOfDevs += 1;
	}
	std::cout << "IO utilization: " << numOfUsedDevs << " used of " << numOfDevs << " or " << numOfUsedDevs / numOfDevs << std::endl;
	return numOfUsedDevs / numOfDevs;
}