#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ArrayList.hpp"

TEST_CASE("TESTS")
{
    SECTION("Initializations")
    {
        SECTION("Empty")
        {
            SECTION("Int")
            {
                ArrayList<int> x=ArrayList<int>();
                REQUIRE(x.getCapacity()==10);
            }
            SECTION("No resize")
            {
                ArrayList<std::string> x=ArrayList<std::string>();
                REQUIRE(x.getCapacity()==10);
            }
        }

        SECTION("Particular Length")
        {
            SECTION("No resize")
            {
                ArrayList<int> x=ArrayList<int>(0);
                REQUIRE(x.getCapacity()==0);
            }
            SECTION("No resize")
            {
                ArrayList<int> x=ArrayList<int>(1);
                REQUIRE(x.getCapacity()==1);
            }
            SECTION("No resize")
            {
                ArrayList<int> x=ArrayList<int>(10);
                REQUIRE(x.getCapacity()==10);
            }
        }
    }

    SECTION("PushBack")
    {
        SECTION("No resize")
        {
            ArrayList<int> x=ArrayList<int>();
            x.pushBack(10);
            REQUIRE(x.getBack()==10);
            REQUIRE(x.getFront()==10);
            REQUIRE(x.getSize()==1);

            x.pushBack(1);
            REQUIRE(x.getBack()==1);
            REQUIRE(x.getFront()==10);
            REQUIRE(x.getSize()==2);
        }
        SECTION("Resize")
        {
            ArrayList<int> x=ArrayList<int>();

            for(int i=0;i<11;i++)
            {
                x.pushBack(i);
            }
            for(int i=0;i<11;i++)
            {
                REQUIRE(x.getItem(i)==i);
            }
        }
    }

    SECTION("GetBack")
    {
        ArrayList<int> x=ArrayList<int>();

        x.pushBack(1);
        REQUIRE(x.getBack()==1);
    }

    SECTION("PopBack")
    {
        ArrayList<int> x=ArrayList<int>();

        x.pushBack(10);
        x.pushBack(1);

        x.popBack();

        REQUIRE(x.getBack()==10);
        REQUIRE(x.getFront()==10);
        REQUIRE(x.getSize()==1);

        x.popBack();
        REQUIRE(x.getSize()==0);
    }

    SECTION("PushFront")
    {
        SECTION("No resize")
        {
            ArrayList<int> x=ArrayList<int>();

            x.pushFront(10);
            REQUIRE(x.getBack()==10);
            REQUIRE(x.getFront()==10);
            REQUIRE(x.getSize()==1);

            x.pushFront(1);
            REQUIRE(x.getBack()==10);
            REQUIRE(x.getFront()==1);
            REQUIRE(x.getSize()==2);
        }

        SECTION("No resize")
        {
            ArrayList<int> x=ArrayList<int>();

            for(int i=0;i<10;i++)
            {
                x.pushFront(i);
            }
            for(int i=0;i<10;i++)
            {
                REQUIRE(x.getItem(i)==9-i);
            }
        }
    }

    SECTION("GetFront")
    {
        ArrayList<int> x=ArrayList<int>();

        x.pushFront(1);
        REQUIRE(x.getFront()==1);
        
    }

    SECTION("PopFront")
    {
        ArrayList<int> x=ArrayList<int>();

        x.pushFront(10);
        x.pushFront(1);

        x.popFront();

        REQUIRE(x.getBack()==10);
        REQUIRE(x.getFront()==10);
        REQUIRE(x.getSize()==1);

        x.popFront();
        REQUIRE(x.getSize()==0);
    }


    SECTION("getSize")
    {
        ArrayList<int> x=ArrayList<int>();
        REQUIRE(x.getSize()==0);
        
        x.pushFront(1);
        REQUIRE(x.getSize()==1);
        
        x.pushBack(1);
        REQUIRE(x.getSize()==2);
    }

    SECTION("isEmpty")
    {
        ArrayList<int> x=ArrayList<int>();
        REQUIRE(x.isEmpty());

        x.pushBack(1);
        REQUIRE(!x.isEmpty());

        x.popBack();
        REQUIRE(x.isEmpty());
    }

    SECTION("getCapacity")
    {
        ArrayList<int> x=ArrayList<int>();
        REQUIRE(x.getCapacity()==10);

        for(int i=0;i<11;i++)
        {
            x.pushBack(1);
        }
        

        REQUIRE(x.getCapacity()==20);
    }

    SECTION("GetItem")
    {
        ArrayList<int> x=ArrayList<int>();

        for(int i=0;i<10;i++)
        {
            x.pushBack(i);
        }
        for(int i=0;i<10;i++)
        {
            REQUIRE(x.getItem(i)==i);
        }
    }

    SECTION("SetItem")
    {
        ArrayList<int> x=ArrayList<int>();

        for(int i=0;i<10;i++)
        {
            x.pushBack(i);
        
        }
        for(int i=0;i<10;i++)
        {
            x.setItem(i,10+i);
        }

        for(int i=0;i<10;i++)
        {
            REQUIRE(x.getItem(i)==i+10);
        }
    }

    SECTION("insert")
    {
        ArrayList<int> x=ArrayList<int>();

        for(int i=0;i<10;i++)
        {
            x.pushBack(i);
        }

        x.insert(3,5);
        REQUIRE(x.getItem(3)==5);
        REQUIRE(x.getSize()==11);
        REQUIRE(x.getCapacity()==20);
    }

    SECTION("Remove")
    {
        ArrayList<int> x=ArrayList<int>();

        for(int i=0;i<10;i++)
        {
            x.pushBack(i);
        }

        x.remove(3);
        REQUIRE(x.getItem(3)==4);
        REQUIRE(x.getSize()==9);
    }
}