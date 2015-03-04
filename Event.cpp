// Event class
#include "Event.hpp"

Event::Event()
{
	execTime = 0;
	relatedTask = nullptr;
	endSession = true;
}

Event::Event(Task* taskToRelate, double newExecTime, bool setEndSession)
{
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

Task* Event::getRelatedTask()
{
	return relatedTask;
}

void Event::operator=(Event evToAssign)
{
	execTime = evToAssign.getTime();
	endSession = evToAssign.willEndSession();
	relatedTask = evToAssign.getRelatedTask();
}

Event::~Event()
{
	delete relatedTask;
}