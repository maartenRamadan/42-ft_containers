#include "catch.hpp"

#include <queue>
#include <list>
#include "../Queue/Queue.hpp"

TEST_CASE( "queue - empty container constructor (default constructor)", "[queue]" ) {
    ft::list<int> mylist (2,200);         // list with 2 elements

    ft::queue<int> first;                      // empty queue
    REQUIRE(first.size() == 0);

    ft::queue<int, ft::list<int> > third;      // empty queue with list as underlying container
    REQUIRE(third.size() == 0);

    ft::queue<int,ft::list<int> > fourth (mylist);
    REQUIRE(fourth.size() == 2);
}

TEST_CASE( "queue - empty", "[queue]" ) {
    ft::queue<int> first;                      // empty queue
    REQUIRE(first.empty() == true);

    first.push(100);
    REQUIRE(first.empty() == false);
}

TEST_CASE( "queue - size", "[queue]" ) {
    ft::queue<int> myints;

    REQUIRE(myints.size() == 0);
    for (int i=0; i<5; i++) myints.push(i);
    REQUIRE(myints.size() == 5);
}

TEST_CASE( "queue - front", "[queue]" ) {
    ft::queue<int> myqueue;

    myqueue.push(77);
    myqueue.push(16);

    REQUIRE(myqueue.front() == 77);
    myqueue.front() -= myqueue.back();    // 77-16=61
    REQUIRE(myqueue.front() == 61);
}

TEST_CASE( "queue - back", "[queue]" ) {
    ft::queue<int> myqueue;

    myqueue.push(12);
    myqueue.push(75);   // this is now the back

    REQUIRE(myqueue.back() == 75);
    myqueue.back() -= myqueue.front();  // 75-12=63
    REQUIRE(myqueue.back() == 63);
}

TEST_CASE( "queue - push", "[queue]" ) {
    ft::queue<int> myints;

    for (int i=0; i<15; i++)
        myints.push(i);
    REQUIRE(myints.size() == 15);
}

TEST_CASE( "queue - pop", "[queue]" ) {
    ft::queue<int> myints;

    for (int i=0; i<15; i++)
        myints.push(i);
    REQUIRE(myints.size() == 15);

    myints.pop();
    REQUIRE(myints.size() == 14);
    myints.pop();
    REQUIRE(myints.size() == 13);
}

TEST_CASE("queue - relational operator overloads", "[queue]") {
    ft::queue<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    ft::queue<int> b;
    b.push(10);
    b.push(20);
    b.push(30);
    ft::queue<int> c;
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