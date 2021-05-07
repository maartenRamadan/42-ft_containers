#include "catch.hpp"

#include <stack>
#include <list>
#include "../Stack/Stack.hpp"

TEST_CASE( "stack - empty container constructor (default constructor)", "[stack]" ) {
    ft::list<int> mylist (2,200);         // list with 2 elements

    ft::stack<int> first;                      // empty queue
    REQUIRE(first.size() == 0);

    ft::stack<int, ft::list<int> > third;      // empty queue with list as underlying container
    REQUIRE(third.size() == 0);

    ft::stack<int,ft::list<int> > fourth (mylist);
    REQUIRE(fourth.size() == 2);
}

TEST_CASE( "stack - empty", "[stack]" ) {
    ft::stack<int> first;                      // empty queue
    REQUIRE(first.empty() == true);

    first.push(100);
    REQUIRE(first.empty() == false);
}

TEST_CASE( "stack - size", "[stack]" ) {
    ft::stack<int> myints;

    REQUIRE(myints.size() == 0);
    for (int i=0; i<5; i++) myints.push(i);
    REQUIRE(myints.size() == 5);
}

TEST_CASE( "stack - top", "[stack]" ) {
    std::stack<int> mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;
    REQUIRE(mystack.top() == 15);
    mystack.top() -= 10;
    REQUIRE(mystack.top() == 5);
}

TEST_CASE( "stack - push", "[stack]" ) {
    ft::stack<int> myints;

    for (int i=0; i<15; i++)
        myints.push(i);
    REQUIRE(myints.size() == 15);
}

TEST_CASE( "stack - pop", "[stack]" ) {
    ft::stack<int> myints;

    for (int i=0; i<15; i++)
        myints.push(i);
    REQUIRE(myints.size() == 15);

    myints.pop();
    REQUIRE(myints.size() == 14);
    myints.pop();
    REQUIRE(myints.size() == 13);
}

TEST_CASE("stack - relational operator overloads", "[stack]") {
    ft::stack<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    ft::stack<int> b;
    b.push(10);
    b.push(20);
    b.push(30);
    ft::stack<int> c;
    c.push(30);
    c.push(20);
    c.push(10);

    REQUIRE((a == b) == true);
    REQUIRE((b != c) == true);
    REQUIRE((b < c) == true);
    REQUIRE((c > b) == true);
    REQUIRE((a <= b) == true);
    REQUIRE((a >= b) == true);

    REQUIRE((a <= b) == true);
    REQUIRE((a > b) == false);
    REQUIRE((a < b) == false);
    REQUIRE((a != b) == false);
    REQUIRE((b > c) == false);
    REQUIRE((b == c) == false);
    REQUIRE((b != c) == true);
}