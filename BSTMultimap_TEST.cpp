#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "BSTMultimap.hpp"

TEST_CASE("TESTS")
{
    SECTION("Initializations")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();

        REQUIRE(x->getSize()==0);
        
        delete x;
    }

    SECTION("getSize")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        REQUIRE(x->getSize()==0);
                delete x;
    }

    SECTION("Insert")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        REQUIRE(x->getSize()==0);
        x->insert(5,10);
        REQUIRE(x->getSize()==1);
        x->insert(5,10);
        REQUIRE(x->getSize()==2);
                delete x;
    }

    SECTION("isEmpty")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        REQUIRE(x->isEmpty());
        x->insert(5,10);
        REQUIRE(!x->isEmpty());
                delete x;
    }

    SECTION("contains")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(3,10);
        x->insert(1,10);
        x->insert(2,10);
        x->insert(5,10);
        x->insert(4,10);
        REQUIRE(x->contains(1));
        REQUIRE(x->contains(2));
        REQUIRE(x->contains(3));
        REQUIRE(x->contains(4));
        REQUIRE(x->contains(5));

        REQUIRE(!x->contains(0));
        REQUIRE(!x->contains(100));
                delete x;
    }

    SECTION("clear")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(3,10);
        x->insert(1,10);
        x->insert(2,10);
        x->insert(5,10);
        x->insert(4,10);

        x->clear();

        REQUIRE(x->getSize()==0);

        delete x;
    }
    SECTION("getMin")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(3,10);
        x->insert(1,10);
        x->insert(2,10);
        x->insert(5,10);
        x->insert(4,10);

        BSTForwardIterator<int,int> whatever=x->getMin();

        REQUIRE(whatever.getKey()==1);
        REQUIRE(whatever.getValue()==10);

        delete x;
    }


    SECTION("getMax")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(3,10);
        x->insert(1,10);
        x->insert(2,10);
        x->insert(5,10);
        x->insert(4,10);

        BSTForwardIterator<int,int> whatever=x->getMax();

        REQUIRE(whatever.getKey()==5);
        REQUIRE(whatever.getValue()==10);

        delete x;
    }

    SECTION("isPastEnd")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(3,10);

        BSTForwardIterator<int,int> whatever=x->getMax();

        REQUIRE(!whatever.isPastEnd());
        whatever.next();
        REQUIRE(whatever.isPastEnd());

        delete x;
    }

    SECTION("getKey")
    {
        BSTNode<int, int>* x=new  BSTNode<int, int>(2,2);

        BSTForwardIterator<int,int> whatever(x,nullptr);
        REQUIRE(whatever.getKey()==2);
        delete x;
    }

    SECTION("getValue")
    {
        BSTNode<int, int>* x=new  BSTNode<int, int>(2,2);

        BSTForwardIterator<int,int> whatever(x,nullptr);
        REQUIRE(whatever.getValue()==2);
        delete x;
    }


    SECTION("setKey")
    {
        BSTNode<int, int>* x=new  BSTNode<int, int>(2,2);

        BSTForwardIterator<int,int> whatever(x,nullptr);
        whatever.setValue(10);
        REQUIRE(whatever.getValue()==10);
        delete x;
    }


    SECTION("next")
    {
        SECTION("1")
        {        //test for a sentinel returned,,an empty tree,, when the value doesnt exist and shit
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(3,1);
            x->insert(1,10);
            x->insert(2,10);
            x->insert(5,10);
            x->insert(4,10);


            BSTForwardIterator<int,int> whatever=x->findLast(1);
            REQUIRE(whatever.getKey()==1);
            whatever.next();
            REQUIRE(whatever.getKey()==2);
            whatever.next();
            REQUIRE(whatever.getKey()==3);
            whatever.next();
            REQUIRE(whatever.getKey()==4);
            whatever.next();
            REQUIRE(whatever.getKey()==5);

            delete x;
        }
    }

    SECTION("findFirst")
    {

        //test for a sentinel returned,,an empty tree,, when the value doesnt exist and shit
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(3,1);
        x->insert(1,10);
        x->insert(2,10);
        x->insert(5,10);
        x->insert(4,10);


        BSTForwardIterator<int,int> whatever=x->findFirst(4);

        REQUIRE(whatever.getValue()==10);
        REQUIRE(whatever.getKey()==4);

        delete x;
    }

    SECTION("findFirst")
    {

        //test for a sentinel returned,,an empty tree,, when the value doesnt exist and shit
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(3,1);
        x->insert(1,10);
        x->insert(2,10);
        x->insert(5,10);
        x->insert(4,10);


        BSTForwardIterator<int,int> whatever=x->findLast(4);

        REQUIRE(whatever.getValue()==10);
        REQUIRE(whatever.getKey()==4);

        delete x;
    }

    SECTION("Insert")
    {
        BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
        x->insert(1,1);
        x->insert(2,1);
        x->insert(3,1);
        x->insert(4,1);
        REQUIRE(x->getSize()==4);
        delete x;
    }

    SECTION("remove")
    {

        SECTION("1,2..remove 1")
        {
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(1,1);
            x->insert(2,1);

            BSTForwardIterator<int,int> whatever=x->findFirst(1);
            BSTForwardIterator<int,int> y=x->remove(whatever);

            REQUIRE(y.getKey()==2);

            delete x;
        }

        SECTION("2,1..remove 2")
        {
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(2,1);
            x->insert(1,1);

            BSTForwardIterator<int,int> whatever=x->findFirst(2);
            BSTForwardIterator<int,int> y=x->remove(whatever);

            REQUIRE(x->getSize()==1);
            REQUIRE(y.isPastEnd());

            delete x;
        }

        SECTION("2,1,4,5,546,3,123..remove 2")
        {
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(2,1);
            x->insert(1,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(546,1);
            x->insert(3,1);
            x->insert(123,1);


            BSTForwardIterator<int,int> whatever=x->findFirst(2);
            BSTForwardIterator<int,int> y=x->remove(whatever);

            REQUIRE(y.getKey()==3);
            y = x->remove(y);
            REQUIRE(y.getKey()==4);
            y = x->remove(y);
            REQUIRE(y.getKey()==5);
            y = x->remove(y);
            REQUIRE(y.getKey()==123);
            y = x->remove(y);
            REQUIRE(y.getKey()==546);
            y = x->remove(y);
            REQUIRE(y.isPastEnd());

            delete x;
        }

        SECTION("10,2,20,15,11...remove 10")
        {
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(10,1);
            x->insert(2,1);
            x->insert(20,1);
            x->insert(15,1);
            x->insert(11,1);

            BSTForwardIterator<int,int> whatever=x->findFirst(10);
            BSTForwardIterator<int,int> y=x->remove(whatever);

            REQUIRE(y.getKey()==11);
            y = x->remove(y);
            REQUIRE(y.getKey()==15);
            y = x->remove(y);
            REQUIRE(y.getKey()==20);
            y = x->remove(y);
            REQUIRE(y.isPastEnd());

            delete x;
        }

        SECTION("10,2,20,15,16...remove 10")
        {
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(10,1);
            x->insert(2,1);
            x->insert(20,1);
            x->insert(15,1);
            x->insert(16,1);

            BSTForwardIterator<int,int> whatever=x->findFirst(10);
            BSTForwardIterator<int,int> y=x->remove(whatever);

            REQUIRE(y.getKey()==15);
            y = x->remove(y);
            REQUIRE(y.getKey()==16);
            y = x->remove(y);
            REQUIRE(y.getKey()==20);
            y = x->remove(y);
            REQUIRE(y.isPastEnd());
            
            delete x;
        }

        SECTION("10,2,20,15,16...remove 15")
        {
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(10,1);
            x->insert(2,1);
            x->insert(20,1);
            x->insert(15,1);
            x->insert(16,1);

            BSTForwardIterator<int,int> whatever=x->findFirst(15);
            BSTForwardIterator<int,int> y=x->remove(whatever);

            REQUIRE(y.getKey()==16);
            y = x->remove(y);
            REQUIRE(y.getKey()==20);
            y = x->remove(y);
            REQUIRE(y.isPastEnd());

            delete x;
        }

        SECTION("10,2,20,15,16...remove 2")
        {
            BSTMultimap<int, int>* x=new BSTMultimap<int, int>();
            x->insert(10,1);
            x->insert(2,1);
            x->insert(20,1);
            x->insert(15,1);
            x->insert(16,1);

            BSTForwardIterator<int,int> whatever=x->findFirst(2);
            BSTForwardIterator<int,int> y=x->remove(whatever);

            REQUIRE(y.getKey()==10);
            y = x->remove(y);
            REQUIRE(y.getKey()==15);
            y = x->remove(y);
            REQUIRE(y.getKey()==16);
            y = x->remove(y);
            REQUIRE(y.getKey()==20);
            y = x->remove(y);
            REQUIRE(y.isPastEnd());

            delete x;
        }
    }
}