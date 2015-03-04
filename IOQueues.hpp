#ifndef IOQUEUES_HPP
#define IOQUEUES_HPP

class IOQueues
{
private:
public:
	IOQueues(int=1);
	void createQueues(int);
	void pushTask(Task*);
	Task* endTaskGetNext(Task*);
};

#endif