#include <iostream>
#include "simulate.hpp"
#include "Scheduler.hpp"

using namespace std;

int main(int argc, char** argv)
{
    int CPU=atoi(argv[1]);
    int I_O=atoi(argv[2]);
    int CYCLS=atoi(argv[3]);

    Scheduler* x=new RoundRobin();

    Scheduler* y=new FastRoundRobin();

    Scheduler* stuff[4];

    stuff[0]=new RoundRobin();
    stuff[1]=new FastRoundRobin();
    stuff[2]=new CompletelyFair();
    stuff[3]=new FastCompletelyFair();


    string output[2];

    double* stat_array;

    for(int i=0;i<4;i++)
    {
        stat_array=new double[5];
        
        stat_array=simulate(stuff[i],CPU,I_O,CYCLS);

        if(i==0)
        {
            output[i]="\n RoundRobin \n";
        }

        else if(i==1)
        { 
            output[i]="\nFastRoundRobin \n";            
        }


        else if(i==2)
        {
            output[i]="\n CompletelyFair \n";
        }

        else if(i==3)
        {
            output[i]="\n FastCompletelyFair \n";
        }

        output[i]+="Total Average: "+to_string(stat_array[0])+
                "\n"+" CPU time"+"\n"
                    +"        CPU bound "+to_string(stat_array[1])+"\n"
                    +"        I/O bound "+to_string(stat_array[3])+"\n"
                    +" Wait time"+
        +"\n"    +"        CPU bound "+to_string(stat_array[2])+"\n"
        +         "        I/O bound "+to_string(stat_array[4])+"\n";

        cout<<output[i]<<endl;
    }

    delete stat_array;
    delete x;
    delete y;
}