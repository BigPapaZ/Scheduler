#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "RBTNode.hpp"

TEST_CASE("TESTS")
{
    SECTION("Initializations")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
    }


    SECTION("getKey")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        REQUIRE(x.getKey()==5);
    }


    SECTION("getValue")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        REQUIRE(x.getValue()==6);
    }

    SECTION("setKey")
    {
        RBTNode<int, int> x=RBTNode<int, int>(10,10,0);
        x.setKey(10);
        REQUIRE(x.getKey()==10);
    }

    SECTION("setValue")
    {
        RBTNode<int, int> x=RBTNode<int, int>(10,10,0);
        x.setValue(10);
        REQUIRE(x.getValue()==10);
    }

    SECTION("getParent")
    {//I am not covering here properly
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        REQUIRE(x.getParent()==nullptr);
    }

    SECTION("setParent")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        RBTNode<int, int> y=RBTNode<int, int>(6,5,0);
        x.setParent(&y);
        REQUIRE(x.getParent()->getKey()==6);
    }

    SECTION("getLeftChild")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        REQUIRE(x.getLeftChild()==nullptr);
    }

    SECTION("setLeftChild")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        RBTNode<int, int> y=RBTNode<int, int>(6,5,0);
        x.setLeftChild(&y);
        REQUIRE(x.getLeftChild()->getKey()==6);
    }

    SECTION("getRightChild")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        REQUIRE(x.getRightChild()==nullptr);
    }

    SECTION("setRightChild")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        RBTNode<int, int> y=RBTNode<int, int>(6,5,0);
        x.setRightChild(&y);
        REQUIRE(x.getRightChild()->getKey()==6);
    }

    SECTION("isRed")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        REQUIRE(x.isRed()==0);
    }

    SECTION("setRed")
    {
        RBTNode<int, int> x=RBTNode<int, int>(5,6,0);
        REQUIRE(x.isRed()==0);
        x.setIsRed(1);
        REQUIRE(x.isRed()==1);
    }

}