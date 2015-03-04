#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "Scheduler.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// #include <sstream>

class Processor
{
private:
	// Scheduler mainScheduler;
public:
	Processor();
	void startShell();
	void showHelpText();
	std::vector<std::string> parseString(const std::string&);
};

#endif