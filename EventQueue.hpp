#ifndef EVENTQUEUE_HPP
#define EVENTQUEUE_HPP

#include "Task.hpp"
#include "Event.hpp"

class EventQueue
{
private:
	std::vector<Event> events;
	double switchCost;
public:
	EventQueue();
	EventQueue(double);
	EventQueue(Task*, int, double);
	void addEvent(Task*, int);
	Event pullEvent();

};



#endif