// has a vector of queues (of vectors)
#include "IOQueues.hpp"

IOQueues::IOQueues(int numOfQueues)
{
	createQueues(numOfQueues);
}

void IOQueues::createQueues(int numOfQueues)
{
	std::vector<Task*> newQueue;
	for (int n = 0; n < numOfQueues; n++)
	{
		queueList.push_back(newQueue);
	}
}

void IOQueues::pushTask(Task* ioTask)
{
	// get burst io location
	if (queueList[burstIoLoc].empty())
	{
		// add end io event to ioTask
	}
	queueList[burstIoLoc].push_back(ioTask);
}

Task* IOQueues::endTaskGetNext(Task* endingIoTask)
{
	// get burst io location
	queueList[burstIoLoc].erase(queueList[burstIoLoc].begin());
	return queueList[burstIoLoc][0];
}

