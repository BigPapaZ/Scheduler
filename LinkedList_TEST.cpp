#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "iostream"

#include "LinkedList.hpp"
#include "LinkedList.hpp"
#include "LinkedListNode.hpp"

TEST_CASE("TESTS")
{
    SECTION("Initializations")
    {
        SECTION("Empty")
        {
            SECTION("Int")
            {
                LinkedList<int> x=LinkedList<int>();
                REQUIRE(x.getCapacity()==0);
            }
            // SECTION("String")
            // {
            //     LinkedList<std::string> x=LinkedList<std::string>();
            //     REQUIRE(x.getCapacity()==0);
            // }
        }
    }

    SECTION("PushBack")
    {
        SECTION("No resize")
        {
            LinkedList<int> x=LinkedList<int>();
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
            LinkedList<int> x=LinkedList<int>();

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
        LinkedList<int> x=LinkedList<int>();

        x.pushBack(1);
        REQUIRE(x.getBack()==1);
    }

    SECTION("PopBack")
    {
        LinkedList<int> x=LinkedList<int>();

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
        SECTION("Small Length")
        {
            LinkedList<int> x=LinkedList<int>();

            x.pushFront(10);
            REQUIRE(x.getBack()==10);
            REQUIRE(x.getFront()==10);
            REQUIRE(x.getSize()==1);

            x.pushFront(1);
            REQUIRE(x.getBack()==10);
            REQUIRE(x.getFront()==1);
            REQUIRE(x.getSize()==2);
        }

        SECTION("Large Length")
        {
            LinkedList<int> x=LinkedList<int>();

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
        LinkedList<int> x=LinkedList<int>();

        x.pushFront(1);
        REQUIRE(x.getFront()==1);
        
    }

    SECTION("PopFront")
    {
        LinkedList<int> x=LinkedList<int>();

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
        LinkedList<int> x=LinkedList<int>();
        REQUIRE(x.getSize()==0);
        
        x.pushFront(1);
        REQUIRE(x.getSize()==1);
        
        x.pushBack(1);
        REQUIRE(x.getSize()==2);
    }

    SECTION("isEmpty")
    {
        LinkedList<int> x=LinkedList<int>();
        REQUIRE(x.isEmpty());

        x.pushBack(1);
        REQUIRE(!x.isEmpty());

        x.popBack();
        REQUIRE(x.isEmpty());
    }

    SECTION("getCapacity")
    {
        LinkedList<int> x=LinkedList<int>();
        REQUIRE(x.getCapacity()==0);

        for(int i=0;i<11;i++)
        {
            x.pushBack(1);
        }
        

        REQUIRE(x.getCapacity()==x.getSize());
    }

    SECTION("GetItem")
    {
        LinkedList<int> x=LinkedList<int>();

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
        LinkedList<int> x=LinkedList<int>();

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
        LinkedList<int> x=LinkedList<int>();

        for(int i=0;i<10;i++)
        {
            x.pushBack(i);
        }

        x.insert(3,5);
        REQUIRE(x.getItem(3)==5);
        REQUIRE(x.getSize()==11);
    }

    SECTION("Remove")
    {
        LinkedList<int> x=LinkedList<int>();

        for(int i=0;i<10;i++)
        {
            x.pushBack(i);
        }

        x.remove(3);
        REQUIRE(x.getItem(3)==4);
        REQUIRE(x.getSize()==9);
    }
}