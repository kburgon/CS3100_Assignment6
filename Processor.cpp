#include "Processor.hpp"

Processor::Processor()
{
	std::cout << "Initializing processor..." << std::endl;
}

void Processor::showHelpText()
{
	std::cout << "  List of commands and explanation:" << std::endl
		<< "	exit - exit the application" << std::endl
		<< "	setvars - set the user-defined variables\n"
		<< "	run - run the scheduler\n";
}

void Processor::startShell()
{
	std::string cmd;
	std::vector<std::string> parsedCmd;
	double setFloat;
	int setInt;
	bool willExit = false;
	while (!willExit)
	{
		std::cout << "[main]:";
		// getline(std::cin, cmd);
		std::cin >> cmd;
		// parsedCmd = parseString(cmd);
		if (cmd == "help")
		{
			showHelpText();
		}
		else if (cmd == "exit")
		{
			willExit = true;
		}
		else if (cmd == "setvars")
		{
			std::cout << "Setting the variables.\nNumber of CPUs: ";
			std::cin >> setInt;
			std::cout << "Setting CPUs to " << setInt << std::endl;
			mainScheduler.setNumCpus(setInt);
			// run setter for scheduler
			std::cout << "Number of IO devices: ";
			std::cin >> setInt;
			std::cout << "Setting IO devices to " << setInt << std::endl;
			mainScheduler.setNumIoDevices(setInt);
			// run setter for IO devices
			std::cout << "Cost of context switch: ";
			std::cin >> setFloat;
			std::cout << "Setting context switch to " << setFloat << std::endl;
			mainScheduler.setCntxtSwitchCost(setFloat);
			// run setter for context switch cost
			std::cout << "Percent CPU vs. IO bound: %";
			std::cin >> setFloat;
			std::cout << "Setting percentage to %" << setFloat << std::endl;
			mainScheduler.setPercentCpuIo(setFloat);
			// run setter for CPU vs. IO percentage
			std::cout << "Task creation frequency (every _ units of time): ";
			std::cin >> setFloat;
			std::cout << "Setting creation frequency to " << setFloat << std::endl;
			mainScheduler.setTaskCreateFreq(setFloat);
			// run setter for task create frequency
			std::cout << "Variables set.\n";
		}
		else if (cmd == "run")
		{
			// Scheduler mainScheduler;
			mainScheduler.init();
		}
		else
		{
			std::cout << "Unrecognized command: " << cmd << std::endl;
		}
		parsedCmd.clear();
	}
}

std::vector<std::string> Processor::parseString(const std::string& toParse)
{
        std::string temp;
        std::vector<std::string> parsedList;
        bool newWord = true;
        for (auto&& inChar:toParse)
    {
        if (inChar == ' ')
        {
                newWord = true;
        }
        else
        {
            if (newWord)
            {
                    temp = inChar;
                    parsedList.push_back(temp);
                    newWord = false;
            }
            else
            {
                    temp = inChar;
                    parsedList[parsedList.size() - 1] += temp;
            }
        }
    }
    return parsedList;
}