#include "Scheduler.hpp"
#include "Process.hpp"
#include "LinkedList.hpp"

RoundRobin::RoundRobin()
{
    this->procQueue=new ArrayList<Process *>();
}
        

void RoundRobin::addProcess(Process* proc)
{
    procQueue->pushBack(proc);
}

Process* RoundRobin::popNext(int ourCycle)
{
    int size=this->procQueue->getSize();

    for (int i=0;i<size;i++)
    {
        Process* Item=this->procQueue->getFront();//memory leak???
        this->procQueue->popFront();

        if (!Item->isBlocked(ourCycle))     
        {

            return Item;
        }
        this->addProcess(Item);
    }
    return 0;
}


FastRoundRobin::FastRoundRobin() : RoundRobin()
{
    delete this->procQueue;
    this->procQueue=new LinkedList<Process *>();
}

RoundRobin::~RoundRobin()
{
    delete this->procQueue;
}

CompletelyFair::CompletelyFair()
{
    this->procTree=new BSTMultimap<int,Process *>();
}
        

void CompletelyFair::addProcess(Process* proc)
{
    this->procTree->insert(proc->getCPUTime(), proc);
}

Process* CompletelyFair::popNext(int ourCycle)
{

    Process* proc;

    BSTForwardIterator<int,Process *> x=this->procTree->getMin();
    for (int i=0;i<this->procTree->getSize();i++)
    {
        if(!x.isPastEnd())
        {
            proc=x.getValue();

            if (!proc->isBlocked(ourCycle))     
            {
                this->procTree->remove(x);
                return proc;
            }

            x.next();
        }
    }

    return nullptr;

    // while(!x.isPastEnd()&&x.getValue()->isBlocked(ourCycle))//
    // {
    // // while(x.getValue()->isBlocked(ourCycle)&&!x.isPastEnd())//
    // // {
    //     cout<<endl<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    //     x.next();
    // }

    // cout<<"before return"<<endl;

    // if(x.isPastEnd())
    // {
    //     return 0;
    // }

    // Process* proc=x.getValue();

    // cout<<"return successful"<<endl;

    // this->procTree->remove(x);
    // //cout<<"below remove"<<endl;

    // return proc;
}


FastCompletelyFair::FastCompletelyFair() : CompletelyFair()
{
    delete this->procTree;
    this->procTree=new BSTMultimap<int,Process*>();
}

CompletelyFair::~CompletelyFair()
{
    delete this->procTree;
}

Scheduler::~Scheduler(){}