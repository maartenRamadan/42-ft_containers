#include "catch.hpp"

#include <string>
#include <iostream>
#include <list>

#include "../List/List.hpp"

TEST_CASE( "list - empty container constructor (default constructor)", "[list]" ) {
    ft::list<int> first;                                // empty list of ints
    REQUIRE(first.size() == 0);
}

TEST_CASE( "list - fill constructor", "[list]" ) {
    ft::list<int> second (4,100);                // four ints with value 100
    REQUIRE(second.size() == 4);
}

TEST_CASE( "list - range constructor", "[list]" ) {
    ft::list<int> second (4,100);
    ft::list<int> third (second.begin(),second.end());  // iterating through second
    REQUIRE(third.size() == 4);
}

TEST_CASE( "list - copy constructor", "[list]" ) {
    ft::list<int> second (4,100);
    ft::list<int> fourth (second);                       // a copy of second
    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "list - assignment operator", "[list]" ) {
    ft::list<int> second (4,100);
    ft::list<int> fourth = second;                      // a copy of second
    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "list - empty", "[list]" ) {
    ft::list<int> my_list;
    REQUIRE(my_list.empty() == true);
    my_list.push_front(1);
    REQUIRE(my_list.empty() == false);
}

TEST_CASE( "list - size", "[list]" ) {
    ft::list<int> my_list;
    my_list.push_front(1);
    REQUIRE(my_list.size() == 1);
    my_list.push_front(1);
    REQUIRE(my_list.size() == 2);
}

TEST_CASE( "list - max_size", "[list]" ) {
    ft::list<int> my_list;
    std::list<int> original_list;
    REQUIRE(my_list.max_size() == original_list.max_size());
}

TEST_CASE( "list - front", "[list]" ) {
    ft::list<int> mylist;

    mylist.push_back(77);
    mylist.push_back(22);

    // now front equals 77, and back 22
    REQUIRE(mylist.front() == 77);
}

TEST_CASE( "list - back", "[list]" ) {
    ft::list<int> mylist;

    mylist.push_back(77);
    mylist.push_back(22);

    // now front equals 77, and back 22
    REQUIRE(mylist.back() == 22);
}

TEST_CASE( "list - assign", "[list]" ) {
    ft::list<int> first;
    ft::list<int> second;

    first.assign (7,100);                      // 7 ints with value 100
    REQUIRE(first.size() == 7);
    REQUIRE(*first.begin() == 100);

    second.assign (first.begin(),first.end());          // a copy of first
    REQUIRE(second.size() == 7);
    REQUIRE(second.front() == 100);
}

TEST_CASE( "list - push_front", "[list]" ) {
    std::list<int> mylist (2,100);         // two ints with a value of 100
    mylist.push_front (200);
    mylist.push_front (300);

    // mylist: 300 200 100 100
    REQUIRE(mylist.size() == 4);
    REQUIRE(*mylist.begin() == 300);
}

TEST_CASE( "list - pop_front", "[list]" ) {
    std::list<int> mylist;
    mylist.push_back (100);
    mylist.push_back (200);
    mylist.push_back (300);

    REQUIRE(mylist.size() == 3);

    while (!mylist.empty())
        mylist.pop_front();

    REQUIRE(mylist.size() == 0);
}

TEST_CASE( "list - push_back", "[list]" ) {
    std::list<int> mylist (2,100);         // two ints with a value of 100
    mylist.push_back(200);
    mylist.push_back(300);

    // mylist: 100 100 200 300
    REQUIRE(mylist.size() == 4);
    REQUIRE(*mylist.begin() == 100);
}

TEST_CASE( "list - pop_back", "[list]" ) {
    std::list<int> mylist;
    mylist.push_back (100);
    mylist.push_back (200);
    mylist.push_back (300);

    REQUIRE(mylist.size() == 3);

    while (!mylist.empty())
        mylist.pop_back();

    REQUIRE(mylist.size() == 0);
}

TEST_CASE( "list - insert", "[list]" ) {
    ft::list<int> mylist;
    ft::list<int>::iterator it;
                                                          // set some initial values:
    for (int i=1; i<=5; ++i) mylist.push_back(i);         // 1 2 3 4 5

    it = mylist.begin();
    ++it;                                                 // it points now to number 2

    mylist.insert (it,10);                           // 1 10 2 3 4 5
    REQUIRE(*it == 2);                                   // "it" still points to number 2

    mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
    REQUIRE(mylist.size() == 8);

    --it;                                                 // it points now to the second 20

    std::vector<int> myvector (2,30);
    mylist.insert (it,myvector.begin(),myvector.end());   // 1 10 20 30 30 20 2 3 4 5
    REQUIRE(mylist.size() == 10);
}

TEST_CASE( "list - erase", "[list]" ) {
    ft::list<int> mylist;
    ft::list<int>::iterator it1,it2;

    for (int i=1; i<10; ++i) mylist.push_back(i*10); // 10 20 30 40 50 60 70 80 90
    it1 = it2 = mylist.begin();
    std::advance (it2,6);
    ++it1;

    it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
    REQUIRE(mylist.size() == 8);
    REQUIRE(*it1 == 30);
    it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
    REQUIRE(mylist.size() == 7);
    REQUIRE(*it2 == 80);

    ++it1;
    --it2;

    mylist.erase (it1,it2);     // 10 30 60 80 90
    REQUIRE(mylist.size() == 5);
    REQUIRE(*it2 == 60);
}

TEST_CASE( "list - swap", "[list]" ) {
    ft::list<int> first (3,100);   // three ints with a value of 100
    ft::list<int> second (5,200);  // five ints with a value of 200

    first.swap(second);
    REQUIRE(first.size() == 5);
    REQUIRE(second.size() == 3);
}

TEST_CASE( "list - resize", "[list]" ) {
    ft::list<int> mylist;

    // set some initial content:
    for (int i=1; i<10; ++i) mylist.push_back(i);

    mylist.resize(5);
    REQUIRE(mylist.size() == 5);

    mylist.resize(8,100);
    REQUIRE(mylist.size() == 8);

    mylist.resize(12);
    REQUIRE(mylist.size() == 12);
}

TEST_CASE( "list - splice", "[list]" ) {
    ft::list<int> mylist1, mylist2;
    ft::list<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=4; ++i)
        mylist1.push_back(i);      // mylist1: 1 2 3 4

    for (int i=1; i<=3; ++i)
        mylist2.push_back(i*10);                     // mylist2: 10 20 30

    it = mylist1.begin();
    ++it;                                               // points to 2

    mylist1.splice (it, mylist2);                    // mylist1: 1 10 20 30 2 3 4
    REQUIRE(mylist1.size() == 7);                       // mylist2 (empty)
    REQUIRE(mylist1.size() == 7);
    REQUIRE(*it == 2);                                  // "it" still points to 2 (the 5th element)

    mylist2.splice (mylist2.begin(),mylist1, it);
    REQUIRE(mylist1.size() == 6);                       // mylist1: 1 10 20 30 3 4
    REQUIRE(mylist2.size() == 1);                       // mylist2: 2
    REQUIRE(*mylist2.begin() == 2);

    it = mylist1.begin();
    std::advance(it,3);                           // "it" points now to 30

    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end()); // mylist1: 30 3 4 1 10 20
    REQUIRE(mylist1.size() == 6);
}

TEST_CASE( "list - remove", "[list]" ) {
    ft::list<int> mylist ;
    mylist.push_back(17);
    mylist.push_back(89);
    mylist.push_back(7);
    mylist.push_back(14);

    ft::list<int>::iterator it = mylist.begin();

    mylist.remove(89);
    REQUIRE(mylist.size() == 3);
    REQUIRE(*it == 17);
    it++;
    REQUIRE(*it == 7);
    it++;
    REQUIRE(*it == 14);
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
    bool operator() (const int& value) { return (value%2)==1; }
};

TEST_CASE( "list - remove if", "[list]" ) {
    ft::list<int> mylist;
    mylist.push_back(15);
    mylist.push_back(36);
    mylist.push_back(7);
    mylist.push_back(17);
    mylist.push_back(20);
    mylist.push_back(39);
    mylist.push_back(4);
    mylist.push_back(1);

    mylist.remove_if (single_digit);           // 15 36 17 20 39
    REQUIRE(mylist.size() == 5);

    mylist.remove_if (is_odd());               // 36 20
    REQUIRE(mylist.size() == 2);
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
    bool operator() (double first, double second)
    { return (fabs(first-second)<5.0); }
};

TEST_CASE( "list - unique", "[list]" ) {
    ft::list<double> mylist;
    mylist.push_back(12.15);
    mylist.push_back(2.72);
    mylist.push_back(73.0);
    mylist.push_back(12.77);
    mylist.push_back(3.14);
    mylist.push_back(12.77);
    mylist.push_back(73.35);
    mylist.push_back(72.25);
    mylist.push_back(15.3);
    mylist.push_back(72.25);

    mylist.sort();              //  2.72, 3.14, 12.15, 12.77, 12.77, 15.3, 72.25, 72.25, 73.0, 73.35
    REQUIRE(mylist.size() == 10);

    mylist.unique();           //  2.72, 3.14, 12.15, 12.77, 15.3, 72.25, 73.0, 73.35
    REQUIRE(mylist.size() == 8);

    mylist.unique (same_integral_part);  //  2.72, 3.14, 12.15, 15.3, 72.25, 73.0
    REQUIRE(mylist.size() == 6);

    mylist.unique (is_near());           //  2.72, 12.15, 72.25
    REQUIRE(mylist.size() == 3);
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

TEST_CASE( "list - merge", "[list]" ) {
    ft::list<double> first, second;
    ft::list<double>::iterator it;

    first.push_back (3.1);
    first.push_back (2.2);
    first.push_back (2.9);

    second.push_back (3.7);
    second.push_back (7.1);
    second.push_back (1.4);

    first.sort();
    REQUIRE(*first.begin() == 2.2);
    second.sort();
    REQUIRE(*second.begin() == 1.4);

    first.merge(second);
    it = first.begin();
    REQUIRE(first.size() == 6);
    REQUIRE(second.size() == 0);
    REQUIRE(*it == 1.4);

    // (second is now empty)
    second.push_back (2.1);
    first.merge(second,mycomparison);
    it = first.begin();
    std::advance(it, 3);
    REQUIRE(*it == 2.1);
}

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
    unsigned int i=0;
    while ( (i<first.length()) && (i<second.length()) )
    {
        if (tolower(first[i])<tolower(second[i])) return true;
        else if (tolower(first[i])>tolower(second[i])) return false;
        ++i;
    }
    return ( first.length() < second.length() );
}

TEST_CASE( "list - sort", "[list]" ) {
    ft::list<std::string> mylist;
    ft::list<std::string>::iterator it;
    mylist.push_back ("Three");
    mylist.push_back ("one");
    mylist.push_back ("two");
    mylist.push_back ("Three");

    mylist.sort();
//	mylist contains: Three Three one two
    it = mylist.begin();
    REQUIRE(*it == "Three");
    std::advance(it, 2);
    REQUIRE(*it == "one");
    std::advance(it, 1);
    REQUIRE(*it == "two");

    mylist.sort(compare_nocase); // one Three Three two
    it = mylist.begin();
    REQUIRE(*it == "one");
    std::advance(it, 2);
    REQUIRE(*it == "Three");
    std::advance(it, 1);
    REQUIRE(*it == "two");
}

TEST_CASE( "list - reverse", "[list]" ) {
    ft::list<int> mylist;
    ft::list<int>::iterator it;
    for (int i=1; i<10; ++i) mylist.push_back(i);

    mylist.reverse();
    it = mylist.begin();
    REQUIRE(*it== 9);
    it++;
    REQUIRE(*it == 8);
    it++;
    REQUIRE(*it == 7);
    it++;
    REQUIRE(*it == 6);
    it++;
    REQUIRE(*it == 5);
}

TEST_CASE("list - relational operator overloads", "[List]") {
    ft::list<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    ft::list<int> b;
    b.push_back(10);
    b.push_back(20);
    b.push_back(30);
    ft::list<int> c;
    c.push_back(30);
    c.push_back(20);
    c.push_back(10);

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