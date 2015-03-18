// Event class
#include "Event.hpp"

Event::Event()
{
	// std::cout << "constructing event...\n";
	execTime = 0;
	relatedTask = nullptr;
	endSession = true;
}

Event::Event(std::shared_ptr<Task> taskToRelate, double newExecTime, bool setEndSession)
{
	// std::cout << "constructing event...\n";
	relatedTask = taskToRelate;
	execTime = newExecTime;
	endSession = setEndSession;
}

bool Event::willEndSession()
{
	return endSession;
}

double Event::getTime()
{
	return execTime;
}

std::shared_ptr<Task> Event::getRelatedTask()
{
	return relatedTask;
}

void Event::operator=(Event evToAssign)
{
	execTime = evToAssign.getTime();
	endSession = evToAssign.willEndSession();
	relatedTask = evToAssign.getRelatedTask();
}

bool Event::operator>(Event toCompare) const
{
	// std::cout << "Is " << execTime << " > " << toCompare.getTime() << "?\n";
	if (execTime > toCompare.getTime()) return true;
	return false;
}

bool Event::operator<(Event toCompare) const
{
	// std::cout << "Is " << execTime << " < " << toCompare.getTime() << "?\n";
	if (execTime < toCompare.getTime()) return true;
	return false;
}
// Event::~Event()
// {
// 	delete relatedTask;
// }