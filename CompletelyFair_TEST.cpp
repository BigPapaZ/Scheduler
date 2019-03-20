#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Scheduler.hpp"
#include "Process.hpp"

TEST_CASE("TESTS")
{
    SECTION("CompletelyFair")
    {
        SECTION("Initialization")
        {
            CompletelyFair x=CompletelyFair();
            REQUIRE(true);
        }

        SECTION("addProcess")
        {
            CompletelyFair x=CompletelyFair();

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

        SECTION("popNext")
        {
            SECTION("basic case")
            {
                CompletelyFair x=CompletelyFair();

                x.addProcess(new  CPUBoundProcess(1));
                x.addProcess(new  CPUBoundProcess(2));

                // for (int i=5;i<10;i++)
                // {
                //     g=new IOBoundProcess(i);
                //     x.addProcess(g);
                // }
                Process* item1=x.popNext(1);
                REQUIRE(item1->getID()==1);
                x.addProcess(item1);
                item1=x.popNext(1000);
                REQUIRE(item1->getID()==2);
                x.addProcess(item1);
            }
        }
    }

    SECTION("FastCompletelyFair")
    {
        SECTION("Initialization")
        {
            FastCompletelyFair x=FastCompletelyFair();
            REQUIRE(true);
        }

        SECTION("addProcess")
        {
            FastCompletelyFair x=FastCompletelyFair();

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

        SECTION("popNext")
        {
            SECTION("basic case")
            {
                FastCompletelyFair x=FastCompletelyFair();

                x.addProcess(new  CPUBoundProcess(1));
                x.addProcess(new  CPUBoundProcess(2));

                // for (int i=5;i<10;i++)
                // {
                //     g=new IOBoundProcess(i);
                //     x.addProcess(g);
                // }
                Process* item1=x.popNext(1);
                REQUIRE(item1->getID()==1);
                x.addProcess(item1);
                item1=x.popNext(1000);
                REQUIRE(item1->getID()==2);
                x.addProcess(item1);
            }

            SECTION("Whatever is happening")
            {
                FastCompletelyFair x=FastCompletelyFair();

                CPUBoundProcess* z;
                IOBoundProcess* g;

                for (int i=1;i<5;i++)
                {
                    z=new  CPUBoundProcess(i);
                    x.addProcess(z);
                }

                for (int i=5;i<=10;i++)
                {
                    g=new IOBoundProcess(i);
                    x.addProcess(g);
                }

                for (int i=1;i<1000000;i++)
                {
                    Process* item1=x.popNext(i);
                    
                    if(i%10!=0)
                    {REQUIRE(item1->getID()==i%10);}

                    else{REQUIRE(item1->getID()==10);}

                    x.addProcess(item1);
                }
                delete z;
                delete g;
            }

        }
    }
}