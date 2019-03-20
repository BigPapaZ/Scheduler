#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "RBTMultimap.hpp"

TEST_CASE("TESTS")
{
    SECTION("Initializations")
    {
        RBTMultimap<int, int>* x=new RBTMultimap<int, int>();
        REQUIRE(x->getSize()==0);
        delete x;
    }

    SECTION("Insert")
    {
        RBTMultimap<int, int>* x=new RBTMultimap<int, int>();


        x->insert(8,1);
        x->insert(9,1);

        x->insert(15,1);
        x->insert(10,1);
        x->insert(11,1);

        x->insert(13,1);
        x->insert(14,1);

        x->insert(12,1);

        x->insert(4,1);
        x->insert(5,1);
        x->insert(6,1);
        x->insert(16,1);
        x->insert(1,2);
        x->insert(2,1);
        x->insert(3,1);

        x->insert(7,1);        
        x->insert(13,1);
        x->insert(14,1);
        x->insert(15,1);
        x->insert(16,1);

        REQUIRE(x->getSize()==20);

        delete x;
    }
    SECTION("FindFirst")
    {
        RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

        x->insert(8,1);
        x->insert(9,1);

        x->insert(15,1);
        x->insert(10,1);
        x->insert(11,1);
        x->insert(13,1);
        x->insert(14,1);
        x->insert(12,1);
        x->insert(4,1);
        x->insert(5,1);
        x->insert(6,1);
        x->insert(16,1);
        x->insert(1,2);
        x->insert(2,1);
        x->insert(3,1);
        x->insert(7,1);        
        x->insert(13,1);
        x->insert(14,1);
        x->insert(15,2);
        x->insert(16,1);

        BSTForwardIterator<int,int> z=x->findFirst(15);
        BSTForwardIterator<int,int> y=x->findLast(15);

        REQUIRE(z.getValue()==1);
        REQUIRE(y.getValue()==2);

        delete x;
    }

    SECTION("Delete")
    {
        SECTION("11")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(11);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==12);
   
            delete x;
        }

        SECTION("7")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(7);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==8);
   
            delete x;
        }

        SECTION("13")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(13);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==13);
   
            delete x;
        }

        SECTION("1")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(1);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==2);
   
            delete x;
        }

        SECTION("4")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(4);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==5);
   
            delete x;
        }

        SECTION("5")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(5);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==6);
   
            delete x;
        }

        SECTION("10")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(10);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==11);
   
            delete x;
        }
        SECTION("14f")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(14);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==14);
   
            delete x;
        }
        SECTION("14l")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findLast(14);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==15);
   
            delete x;
        }


        SECTION("16f")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(16);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==16);
   
            delete x;
        }

        SECTION("16l")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findLast(16);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.isPastEnd());
   
            delete x;
        }

        SECTION("3")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(3);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==4);
   
            delete x;
        }

                SECTION("6")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(6);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==7);
   
            delete x;
        }
        SECTION("8")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(8);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==9);
   
            delete x;
        }

        SECTION("12")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(12);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==13);
   
            delete x;
        }

        SECTION("13l")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findLast(13);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==14);
   
            delete x;
        }

        SECTION("15l")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findLast(15);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==16);
   
            delete x;
        }


        SECTION("2")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(2);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==3);
   
            delete x;
        }

        SECTION("9")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(9);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==10);
   
            delete x;
        }

        SECTION("15")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(1,2);
            x->insert(2,1);
            x->insert(3,1);
            x->insert(7,1);        
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,2);
            x->insert(16,1);

            BSTForwardIterator<int,int> z=x->findFirst(15);
            BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==15);
   
            delete x;
        }
        SECTION("10 new")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(9,1);

            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(6,1);
            x->insert(16,1);

             BSTForwardIterator<int,int> z=x->findFirst(10);
             BSTForwardIterator<int,int> y=x->remove(z);

            REQUIRE(y.getKey()==11);
   
            delete x;
        }

        SECTION("10 new")
        {

            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(10,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(16,1);
            x->insert(9,1);
            x->insert(13,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(16,1);
            x->insert(9,1);
            x->insert(5,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(10,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(4,1);

            BSTForwardIterator<int,int> z=x->findFirst(4);

            int i=0;
            while(!z.isPastEnd())
            {
                z=x->remove(z);
                i++;
            }
   
            delete x;
        }
        SECTION("10 final")
        {
            RBTMultimap<int, int>* x=new RBTMultimap<int, int>();

            x->insert(8,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(16,1);
            x->insert(9,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(16,1);
            x->insert(9,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(10,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(6,1);
            x->insert(16,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(12,1);
            x->insert(4,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(16,1);
            x->insert(9,1);
            x->insert(5,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(10,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(10,1);
            x->insert(5,1);
            x->insert(13,1);
            x->insert(13,1);
            x->insert(14,1);
            x->insert(15,1);
            x->insert(10,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(15,1);
            x->insert(11,1);
            x->insert(4,1);
            x->insert(16,1);
            x->insert(9,1);

            BSTForwardIterator<int,int> z=x->findFirst(4);

            int i=0;
            while(!z.isPastEnd())
            {
                z=x->remove(z);
                i++;
            }
   
            delete x;
        }

    }
}