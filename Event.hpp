#ifndef EVENT_HPP
#define EVENT_HPP

#include "Task.hpp"

class Event
{
private:
	double execTime;
	Task* relatedTask;
	bool endSession;
public:
	Event();
	Event(Task*, double, bool=false);
	bool willEndSession();
	double getTime();
	Task* getRelatedTask();
	void operator=(Event);
	~Event();
};

#endif