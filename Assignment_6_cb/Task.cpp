#include "task.h"

void Task::generateTask(bool IOBound)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::normal_distribution<> norm(10, 5);

    // set iobound , generate burstList
    isIOBound = IOBound;
    bool setIO = false;
    Burst setterBurst;

	int numOfBursts = norm(mt);
    initTime = norm(mt);

	for (int n = 0; n < numOfBursts; n++)
	{
        if (setIO == false)
        {
            setterBurst.isCpuBurst = true;
            setIO = true;
        }
        else
        {
            setterBurst.isCpuBurst = false;
            setIO = false;
        }
        setterBurst.timeCost = norm(mt);
        setterBurst.latency = 0;
        bursts.push_back(setterBurst);
	}
}

/*double Task::getBurstTime()
{

}*/

void Task::testBursts()
{
    for(auto&& singleBurst:bursts)
    {
        std::cout << "This is the burst type: ";
        if (singleBurst.isCpuBurst)
        {
            std::cout << "CPU\n";
        }
        else
        {
            std::cout << "IO\n";
        }
        std::cout << "Burst time cost:  " << singleBurst.timeCost << std::endl << std::endl << std::endl;
    }
}
