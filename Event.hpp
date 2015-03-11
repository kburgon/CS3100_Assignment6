#ifndef EVENT_HPP
#define EVENT_HPP

#include "Task.hpp"
#include <memory>
#include <iostream>

class Event
{
private:
	double execTime;
	std::shared_ptr<Task> relatedTask;
	bool endSession;
public:
	Event();
	Event(std::shared_ptr<Task>, double, bool=false);
	bool willEndSession();
	double getTime();
	std::shared_ptr<Task> getRelatedTask();
	void operator=(Event);
	bool operator>(Event) const;
	bool operator<(Event) const;
	// ~Event();
};

#endif