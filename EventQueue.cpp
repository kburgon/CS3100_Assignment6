// EventQueue pseudocode

EventQueue::addEvent(Task *curTask, int curTime)
{
	// check if io event
	// if so set time to curTime + curTask.time
	// check if cpu event
	// if cpu then set time to curTime + curTask.time + contextSwitch
	curTask->endBurst(curTime);
	// create event
	// add event to queue
}

Event EventQueue::pullEvent()
{
	// pulls event off of priority queue
	// returns event
}

EventQueue::EventQueue()
{
	// context switch cost = 0.5
	// set priority queue
}

EventQueue::EventQueue(double newSwitchCost)
{
	switchCost = newSwitchCost;
	// set priority queue
}

EventQueue::EventQueue(Task *curTask, int curTime, double newSwitchCost)
{
	switchCost = newSwitchCost
	addEvent(curTask, curTime);
}