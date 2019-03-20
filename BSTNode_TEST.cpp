#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "BSTNode.hpp"

TEST_CASE("TESTS")
{
    SECTION("Initializations")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
    }


    SECTION("getKey")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        REQUIRE(x.getKey()==5);
    }


    SECTION("getValue")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        REQUIRE(x.getValue()==6);
    }

    SECTION("setKey")
    {
        BSTNode<int, int> x=BSTNode<int, int>(10,10);
        x.setKey(10);
        REQUIRE(x.getKey()==10);
    }

    SECTION("setValue")
    {
        BSTNode<int, int> x=BSTNode<int, int>(10,10);
        x.setValue(10);
        REQUIRE(x.getValue()==10);
    }

    SECTION("getParent")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        REQUIRE(x.getParent()==nullptr);
    }

    SECTION("setParent")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        BSTNode<int, int> y=BSTNode<int, int>(6,5);
        x.setParent(&y);
        REQUIRE(x.getParent()->getKey()==6);
    }

    SECTION("getLeftChild")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        REQUIRE(x.getLeftChild()==nullptr);
    }

    SECTION("setLeftChild")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        BSTNode<int, int> y=BSTNode<int, int>(6,5);
        x.setLeftChild(&y);
        REQUIRE(x.getLeftChild()->getKey()==6);
    }

    SECTION("getRightChild")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        REQUIRE(x.getRightChild()==nullptr);
    }

    SECTION("setRightChild")
    {
        BSTNode<int, int> x=BSTNode<int, int>(5,6);
        BSTNode<int, int> y=BSTNode<int, int>(6,5);
        x.setRightChild(&y);
        REQUIRE(x.getRightChild()->getKey()==6);
    }
}