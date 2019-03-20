#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

//constructors for Process
Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}

//gets the ID no.
int Process::getID() const
{
   return id;
}

//gets the CPU time cosumed
int Process::getCPUTime() const
{
   return cpuTime;
}

//get the time wasted by a process
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}


//constructor for CPU process 
CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}

//tells if a process is blocked..always false for this class
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}

//makes the process use the CPU 
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;

   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}


//contructor for IO class
IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}

//tells if the IO process is blocked depending on the number of the cycle
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}

//makes the process use the CPU
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = random()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + random()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
