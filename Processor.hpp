#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "Scheduler.hpp"
#include "RRQueue.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
// #include <sstream>

class Processor
{
private:
	Scheduler mainScheduler;
	Data sessionResults;
	Data roundResults;
public:
	Processor();
	void startShell();
	void showHelpText();
	std::vector<std::string> parseString(const std::string&);
	void printResults(Data);
};

#endif