#ifndef SCHEDULER
#define SCHEDULER

#include "Process.hpp"
#include "List.hpp"
#include "ArrayList.hpp"
#include "BSTMultimap.hpp"
#include "RBTMultimap.hpp"


class Scheduler 
{
    public:
        virtual void addProcess(Process* proc)=0;
        virtual Process* popNext(int ourCycle)=0;
        virtual ~Scheduler();      
};

class RoundRobin: public Scheduler
{
    protected:
        List<Process*>* procQueue;

    public:
        RoundRobin();

        virtual void addProcess(Process* proc);
        virtual Process* popNext(int ourCycle);

        virtual ~RoundRobin();
};

class FastRoundRobin: public RoundRobin
{
    public:
        FastRoundRobin();
};

class CompletelyFair: public Scheduler
{
    protected:
        BSTMultimap<int,Process*>* procTree;

    public:
        CompletelyFair();

        virtual void addProcess(Process* proc);
        virtual Process* popNext(int ourCycle);

        virtual ~CompletelyFair();
};

class FastCompletelyFair: public CompletelyFair
{
    public:
        FastCompletelyFair();
};

#endif