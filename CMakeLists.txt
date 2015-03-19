project(SchedulerSimulator)

set(Sources
	main.cpp
	Processor.hpp
	Processor.cpp
	Scheduler.hpp
	Scheduler.cpp
	EventQueue.hpp
	EventQueue.cpp
	Event.hpp
	Event.cpp
	Task.hpp
	Task.cpp
	Burst.hpp
	Burst.cpp
	ReadyQueue.hpp
	ReadyQueue.cpp
	IOQueues.hpp
	IOQueues.cpp
)

set(CMAKE_CXX_FLAGS --std=c++11)

add_executable(SchedulerSimulator ${Sources})
