#include "catch.hpp"

#include <vector>
#include "../Vector/Vector.hpp"


TEST_CASE( "vector - empty container constructor (default constructor)", "[vector]" ) {
    ft::vector<int> first;                                // empty list of ints
    REQUIRE(first.size() == 0);
}

TEST_CASE( "vector - fill constructor", "[vector]" ) {
    ft::vector<int> second (4,100);                // four ints with value 100
    REQUIRE(second.size() == 4);
}

TEST_CASE( "vector - range constructor", "[vector]" ) {
    ft::vector<int> second (5,100);
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    REQUIRE(third.size() == 5);
    REQUIRE(third.capacity() == 5);
}

TEST_CASE( "vector - copy constructor", "[vector]" ) {
    ft::vector<int> second (5,100);
    ft::vector<int> fourth (second);                       // a copy of second
    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "vector - assignment operator", "[vector]" ) {
    ft::vector<int> second (5,100);

    ft::vector<int> fourth;
    fourth = second;                      // a copy of second

    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "vector - begin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(*ft_vector.begin() == *std_vector.begin());
}

TEST_CASE( "vector - rbegin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(*ft_vector.rbegin() == *std_vector.rbegin());
}

TEST_CASE( "vector - size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.size() == std_vector.size());
}

TEST_CASE( "vector - max_size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    REQUIRE(ft_vector.max_size() == std_vector.max_size());
}

TEST_CASE( "vector - resize", "[vector]" ) {
    ft::vector<int> ft_vector;
    for (int i=1; i<=10; i++) ft_vector.push_back(i);

    ft_vector.resize(10);
    REQUIRE(ft_vector.size() == 10);

    ft_vector.resize(5);
    REQUIRE(ft_vector.size() == 5);

    ft_vector.resize(15);
    REQUIRE(ft_vector.size() == 15);
}

TEST_CASE( "vector - capacity", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.capacity() == std_vector.capacity());
}

TEST_CASE( "vector - empty", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    REQUIRE(ft_vector.empty() == std_vector.empty());

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.empty() == std_vector.empty());
}

TEST_CASE( "vector - reserve", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    ft_vector.reserve(25);
    std_vector.reserve(25);

    REQUIRE(ft_vector.capacity() == std_vector.capacity());
}

TEST_CASE( "vector - operator []", "[vector]" ) {
    ft::vector<int> ft_vector;

    for (int i=0; i<=5; i++) ft_vector.push_back(i);

    REQUIRE(ft_vector[0] == 0);
    REQUIRE(ft_vector[3] == 3);
}

TEST_CASE( "vector - at", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.at(3) == 3);
    REQUIRE(myvector.at(6) == 6);
}

TEST_CASE( "vector - front", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.front() == 0);
}

TEST_CASE( "vector - back", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.back() == 9);
}

TEST_CASE( "vector - assign", "[vector]" ) {
    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100
    REQUIRE(first.size() == 7);
    REQUIRE(*first.begin() == 100);

    ft::vector<int>::iterator it;
    it=first.begin()+1;
    REQUIRE(*it == 100);

    ft::vector<int>::iterator it_end;
    it_end=first.end()-1;
    REQUIRE(*it_end == 100);

    second.assign (it,it_end); // the 5 central values of first
    REQUIRE(second.size() == 5);
    REQUIRE(*second.begin() == 100);
}

TEST_CASE( "vector - insert", "[vector]" ) {
    ft::vector<int> myvector (3,100);
    ft::vector<int>::iterator it;

    std::vector<int> realvector (3,100);
    std::vector<int>::iterator std_it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    std_it = realvector.begin();
    std_it = realvector.insert(std_it, 200);

    REQUIRE(myvector.size() == realvector.size());
    REQUIRE(*it == *std_it);

    myvector.insert (it,2,300);
    realvector.insert(std_it, 2, 300);
    REQUIRE(myvector.size() == realvector.size());
    REQUIRE(*myvector.begin()+3 == *realvector.begin()+3);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    ft::vector<int> anothervector (3,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());
    it = myvector.begin();
    std::advance(it, 3);
    REQUIRE(myvector.size() == 9);
    REQUIRE(*it == 400);
}

TEST_CASE( "vector - erase", "[vector]" ) {
    ft::vector<int> myvector;
    std::vector<int> realvector;

    // initialize iterators
    ft::vector<int>::iterator it;
    std::vector<int>::iterator std_it;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) myvector.push_back(i);
    for (int i=1; i<=10; i++) realvector.push_back(i);

    REQUIRE(10 == realvector.size());

    // erase the 6th element
    it = myvector.erase (myvector.begin()+5);
    std_it = realvector.erase (realvector.begin()+5);

    REQUIRE(*it == *std_it);
    REQUIRE(*realvector.begin() == *myvector.begin());
    REQUIRE(*realvector.end()-1 == *myvector.end()-1);
    REQUIRE(realvector.size() == myvector.size());

    // erase the first 3 elements:
    it = myvector.erase (myvector.begin(),myvector.begin()+3);
    std_it = realvector.erase (realvector.begin(),realvector.begin()+3);

    REQUIRE(myvector.size() == realvector.size());
    REQUIRE(myvector.at(0) == realvector.at(0));
    REQUIRE(*it == *std_it);
    REQUIRE(*myvector.begin()+3 == *realvector.begin()+3);
}

TEST_CASE( "vector - swap", "[vector]" ) {
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);
    REQUIRE(foo.size() == 5);
    REQUIRE(*foo.begin() == 200);
    REQUIRE(bar.size() == 3);
    REQUIRE(*bar.begin() == 100);
}

TEST_CASE(" vector - relational operator overloads", "[vector]") {
    ft::vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    ft::vector<int> b;
    b.push_back(10);
    b.push_back(20);
    b.push_back(30);
    ft::vector<int> c;
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

TEST_CASE(" vector - subtracting two iterators", "[vector]") {
    ft::vector<int> myvector (3,100);
    ft::vector<int>::iterator it;
    ft::vector<int>::iterator it2;

    it = myvector.begin();
    it2 = myvector.end();
    REQUIRE(it2 - it == 3);
}