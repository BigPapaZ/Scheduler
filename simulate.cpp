#include "simulate.hpp"
#include "chrono"
#include "Process.hpp"
#include "iostream"

using namespace std;

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles)
{
    double total_clicks=0;

    double CPU_Wait_clicks=0;
    double IO_Wait_clicks=0;

    double CPU_CPU_clicks=0;
    double IO_CPU_clicks=0;

    double CPU_Wait_time=0;
    double IO_Wait_time=0;

    double CPU_CPU_time=0;             
    double IO_CPU_time=0;

    for(int i=0;i<numCPUBound;i++)
    {
        sched->addProcess(new CPUBoundProcess(i));
        total_clicks++;
    }


    for(int i=numCPUBound;i<numIOBound+numCPUBound;i++)
    {
       sched->addProcess(new IOBoundProcess(i));
       total_clicks++;
    }

    int i=0;

    auto time_start = chrono::system_clock::now();

    while(i<=numCycles)
    {
        Process* item=sched->popNext(i);total_clicks++;
        if(item==0)//or a zero??
        {
            i+=10;
        }
        else
        {

            if(item->getID()>=numCPUBound)
            {   //IOBoundProcess
                i+=item->useCPU(i,10); //is i the number of simulated cycles?
                IO_CPU_clicks++;IO_Wait_clicks++;
                IO_CPU_time+=item->getCPUTime();
                IO_Wait_time+=item->getWaitTime(i);
            }

            else
            {   //CPUBoundProcess
                i+=item->useCPU(i,10); //is i the number of simulated cycles?
//                cout<<"the problem"<<i<<endl;
                CPU_CPU_clicks++;CPU_Wait_clicks++;
                CPU_CPU_time+=item->getCPUTime();
                CPU_Wait_time+=item->getWaitTime(i);
            }
            
            sched->addProcess(item);total_clicks++;
        }
    }

    auto time_end = chrono::system_clock::now();
    auto dur_total=time_end-time_start;

    auto total_time=chrono::duration_cast<chrono::nanoseconds>(dur_total);

    double* stat_array=new double[5];

    stat_array[0]=total_time.count()/total_clicks;
    stat_array[1]=CPU_CPU_time/CPU_CPU_clicks;
    stat_array[2]=CPU_Wait_time/CPU_Wait_clicks;
    stat_array[3]=IO_CPU_time/IO_CPU_clicks;
    stat_array[4]=IO_Wait_time/IO_Wait_clicks;

    return stat_array;
}