#include "Processor.hpp"

Processor::Processor()
{
	std::cout << "Initializing processor..." << std::endl;
}

void Processor::showHelpText()
{
	std::cout << "  List of commands and explanation:" << std::endl
		<< "	exit - exit the application" << std::endl
		<< "	set cpunum [value] - sets the number of CPUs" << std::endl
		<< "	set iobinding [value] - sets percentage of IO bound vs. CPU bound\n"
		<< "	set taskcreatefreq [value] - sets the frequency of task creations (in time)\n"
		<< "	set cswitchtime [value] - sets the context switch time of the simulator\n"
		<< "	set iodevicenum [value] - sets the number of io devices in the simulator\n"
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
		else if (cmd == "set")
		{
			std::cin >> cmd;
			
			if (cmd == "cpunum")
			{
				std::cin >> setFloat;
				std::cout << "Setting number of CPUs to " << setInt << std::endl;
			}
			else if (cmd == "iobinding")
			{
				std::cin >> setFloat;
				std::cout << "Setting tasks to " << setInt << "\% IO bound." << std::endl;
			}
			else if (cmd == "taskcreatefreq")
			{
				std::cin >> setFloat;
				std::cout << "Task create frequency set to " << setFloat << ".\n";
			}
			else if (cmd == "cswitchtime")
			{
				std::cin >> setFloat;
				std::cout << "Context switch time set to " << setFloat << ".\n";
			}
			else
			{
				std::cin >> setFloat;
				std::cout << "Number of IO devices set to " << setInt << ",\n";
			}
		}
		else if (cmd == "run")
		{
			Scheduler mainScheduler;
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