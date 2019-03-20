#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Scheduler.hpp"
#include "Process.hpp"

TEST_CASE("TESTS")
{
    SECTION("RoundRobin")
    {
        SECTION("Initialization")
        {
            RoundRobin x=RoundRobin();
            REQUIRE(true);
        }

        SECTION("addProcess")
        {
            RoundRobin x=RoundRobin();

            CPUBoundProcess* z;
            IOBoundProcess* g;

            for (int i=1;i<5;i++)
            {
                z=new  CPUBoundProcess(i);
                x.addProcess(z);
                REQUIRE(true);
            }
            for (int i=5;i<10;i++)
            {
                g=new IOBoundProcess(i);
                x.addProcess(g);
                REQUIRE(true);
            }

            delete z;
            delete g;
        }

        SECTION("addProcess")
        {
            RoundRobin x=RoundRobin();

            CPUBoundProcess* z;
            IOBoundProcess* g;

            for (int i=1;i<5;i++)
            {
                z=new  CPUBoundProcess(i);
                x.addProcess(z);
            }
            for (int i=5;i<10;i++)
            {
                g=new IOBoundProcess(i);
                x.addProcess(g);
            }
            for (int i=0;i<1000;i++)
            {
                Process* item1=x.popNext(i);
                REQUIRE(item1->getID()>0);
                x.addProcess(item1);
            }
            delete z;
            delete g;
        }
    }

    SECTION("FastRoundRobin")
    {
        SECTION("Initialization")
        {
            FastRoundRobin x=FastRoundRobin();
            REQUIRE(true);
        }

        SECTION("addProcess")
        {
            FastRoundRobin x=FastRoundRobin();

            CPUBoundProcess* z;
            IOBoundProcess* g;

            for (int i=1;i<5;i++)
            {
                z=new  CPUBoundProcess(i);
                x.addProcess(z);
                REQUIRE(true);
            }
            for (int i=5;i<10;i++)
            {
                g=new IOBoundProcess(i);
                x.addProcess(g);
                REQUIRE(true);
            }

            delete z;
            delete g;
        }

        SECTION("addProcess")
        {
            FastRoundRobin x=FastRoundRobin();

            CPUBoundProcess* z;
            IOBoundProcess* g;

            for (int i=1;i<5;i++)
            {
                z=new  CPUBoundProcess(i);
                x.addProcess(z);
            }
            for (int i=5;i<10;i++)
            {
                g=new IOBoundProcess(i);
                x.addProcess(g);
            }
            for (int i=0;i<1000;i++)
            {
                Process* item1=x.popNext(i);
                REQUIRE(item1->getID()>0);
                x.addProcess(item1);
            }
            delete z;
            delete g;
        }
    }
}