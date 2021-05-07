#include "catch.hpp"

#include <map>
#include <list>
#include "../Map/Map.hpp"

TEST_CASE( "map - empty container constructor (default constructor)", "[map]" ) {
    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );
    REQUIRE(mymap.size() == 2);

    ft::map<char, int>::iterator it = mymap.begin();
    REQUIRE(it->second == 100);

}

TEST_CASE("map - range constructor", "[map]") {
    ft::map<char,int> map;
    map.insert ( ft::pair<char,int>('a',100) );
    map.insert ( ft::pair<char,int>('z',200) );
    map.insert ( ft::pair<char,int>('c',300) );
    map.insert ( ft::pair<char,int>('q',400) );
    ft::map<char, int>::iterator mapit = map.begin();

    ft::map<char, int> rangemap(map.begin(), map.end());
    REQUIRE(rangemap.size() == map.size());

    ft::map<char, int>::iterator rangeit;
    for (rangeit=rangemap.begin(); rangeit!=rangemap.end(); rangeit++) {
        REQUIRE(rangeit->first == mapit->first);
        mapit++;
    }
}

TEST_CASE("map - copy constructor", "[map]") {
    ft::map<char,int> map;
    map.insert ( ft::pair<char,int>('a',100) );
    map.insert ( ft::pair<char,int>('z',200) );
    map.insert ( ft::pair<char,int>('c',300) );
    map.insert ( ft::pair<char,int>('q',400) );
    ft::map<char, int>::iterator mapit = map.begin();

    ft::map<char, int> rangemap(map);
    REQUIRE(rangemap.size() == map.size());

    ft::map<char, int>::iterator rangeit;
    for (rangeit=rangemap.begin(); rangeit!=rangemap.end(); rangeit++) {
        REQUIRE(rangeit->first == mapit->first);
        mapit++;
    }
}

TEST_CASE("map - begin", "[map]") {
    int i = 1;
    ft::map<char,int> map;
    map.insert ( ft::pair<char,int>('a',1) );
    map.insert ( ft::pair<char,int>('b',2) );
    map.insert ( ft::pair<char,int>('z',3) );
    ft::map<char, int>::iterator it;

    for (it=map.begin(); it!=map.end(); it++) {
        REQUIRE(it->second == i);
        i++;
    }
}

TEST_CASE("map - end", "[map]") {
    std::map<char,int> stdmap;
    stdmap.insert ( std::pair<char,int>('b',100) );
    stdmap.insert ( std::pair<char,int>('a',200) );
    stdmap.insert ( std::pair<char,int>('c',300) );
    std::map<char, int>::iterator stdit = stdmap.end();

    ft::map<char,int> mymap;
    mymap.insert ( ft::pair<char,int>('b',100) );
    mymap.insert ( ft::pair<char,int>('a',200) );
    mymap.insert ( ft::pair<char,int>('c',300) );
    ft::map<char, int>::iterator myit = mymap.end();

    stdit--;
    myit--;
    REQUIRE(stdit->first == myit->first);
}

TEST_CASE("map - rbegin", "[map]") {
    int i = 3;
    ft::map<char,int> map;
    map.insert ( ft::pair<char,int>('a',1) );
    map.insert ( ft::pair<char,int>('b',2) );
    map.insert ( ft::pair<char,int>('z',3) );
    ft::map<char, int>::reverse_iterator it=map.rbegin();

    std::map<char,int> stdmap;
    stdmap.insert ( std::pair<char,int>('a',1) );
    stdmap.insert ( std::pair<char,int>('b',2) );
    stdmap.insert ( std::pair<char,int>('z',3) );
    std::map<char, int>::reverse_iterator stdit=stdmap.rbegin();

    REQUIRE(it->first == stdit->first);

    for (it=map.rbegin(); it!=map.rend(); it++) {
        REQUIRE(it->second == i);
        i--;
    }
}

TEST_CASE("map - rend", "[map]") {
    std::map<char,int> stdmap;
    stdmap.insert ( std::pair<char,int>('b',100) );
    stdmap.insert ( std::pair<char,int>('a',200) );
    stdmap.insert ( std::pair<char,int>('c',300) );
    std::map<char, int>::reverse_iterator stdit = stdmap.rend();

    ft::map<char,int> mymap;
    mymap.insert ( ft::pair<char,int>('b',100) );
    mymap.insert ( ft::pair<char,int>('a',200) );
    mymap.insert ( ft::pair<char,int>('c',300) );
    ft::map<char, int>::reverse_iterator myit = mymap.rend();

    stdit--;
    myit--;
    REQUIRE(stdit->first == myit->first);
}

TEST_CASE("map - empty", "[map]") {
    ft::map<char,int> map;
    REQUIRE(map.empty() == true);
    map.insert ( ft::pair<char,int>('b',100) );
    REQUIRE(map.empty() == false);
}

TEST_CASE("map - size", "[map]") {
    ft::map<char,int> map;
    REQUIRE(map.size() == 0);
    map.insert ( ft::pair<char,int>('b',100) );
    REQUIRE(map.size() == 1);
}

TEST_CASE("map - [] operator", "[map]") {
    ft::map<char, std::string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['a'];

    REQUIRE(mymap['a'] == "an element");
    REQUIRE(mymap['b'] == "another element");
    REQUIRE(mymap['c'] == "an element");
}

TEST_CASE("map - insert", "[map]") {
    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );
    REQUIRE(mymap.size() == 2);

    ft::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( ft::pair<char,int>('z',500) );
    REQUIRE(mymap.size() == 2);
    REQUIRE(ret.second == false);

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
    REQUIRE(mymap.size() == 4);

    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.end());
    ft::map<char, int>::iterator secondit = anothermap.begin();

    for (it=mymap.begin(); it!=mymap.end(); it++) {
        REQUIRE(it->first == secondit->first);
        secondit++;
    }
}

TEST_CASE("map - erase", "[map]") {
    ft::map<char,int> mymap;

    // insert some values:
    mymap.insert ( ft::pair<char,int>('g',1) );
    mymap.insert ( ft::pair<char,int>('b',2) );
    mymap.insert ( ft::pair<char,int>('c',3) );
    mymap.insert ( ft::pair<char,int>('a',12) );
    mymap.insert ( ft::pair<char,int>('z',3) );
    mymap.insert ( ft::pair<char,int>('f',22) );
    mymap.insert ( ft::pair<char,int>('z',3) );

    ft::map<char,int>::iterator it = mymap.begin();

    it++;
    mymap.erase(it);                   // erasing by iterator
    REQUIRE(mymap.size() == 5);
    it = mymap.begin();
    it++;
    it++;

    mymap.erase ('c');                  // erasing by key
    REQUIRE(mymap.size() == 4);
    mymap.erase ('c');                  // erasing by key
    REQUIRE(mymap.size() == 4);

    it = mymap.begin();
    it++;
    it++;
    mymap.erase ( it, mymap.end() );    // erasing by range
    it = mymap.begin();
    REQUIRE(mymap.size() == 2);
    REQUIRE(it->second == 12);
    it++;
    REQUIRE(it->second == 22);
}

TEST_CASE("map - swap", "[map]") {
    ft::map<char,int> foo;
    ft::map<char,int> bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    foo.swap(bar);

    REQUIRE(bar.size() == 2);
    REQUIRE(bar.begin()->first == 'x');

    REQUIRE(foo.size() == 3);
    REQUIRE(foo.begin()->first == 'a');
}

TEST_CASE("map - key compare", "[map]") {
    ft::map<char,int> mymap;

    ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    char highest = mymap.rbegin()->first;     // key value of last element

    REQUIRE(mycomp(mymap.begin()->first, highest) == true );
}

TEST_CASE("map - value compare", "[map]") {
    ft::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    ft::pair<char,int> highest = *mymap.rbegin();          // last element

    ft::map<char,int>::iterator it = mymap.begin();

    REQUIRE(mymap.value_comp()(*it, highest) == true);
}

TEST_CASE("map - find", "[map]") {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    REQUIRE(it->second == 100);
    it = mymap.find('z');
    REQUIRE(it->second == mymap.end()->second);
}

TEST_CASE("map - count", "[map]") {
    ft::map<char,int> mymap;
    char a = 'a';
    char b = 'z';

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    REQUIRE(mymap.count(a) == 1);
    REQUIRE(mymap.count(b) == 0);
}

TEST_CASE("map - lower bound", "[map]") {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    REQUIRE(itlow->second == 40);
    mymap.erase(itlow);
    itlow=mymap.lower_bound ('b');  // itlow points to c
    REQUIRE(itlow->second == 60);
}

TEST_CASE("map - uper bound", "[map]") {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itup=mymap.upper_bound('c');  // itup points to d
    REQUIRE(itup->second == 80);
    mymap.erase(itup);
    itup=mymap.upper_bound('d');  // itlow points to e
    REQUIRE(itup->second == 100);
}

TEST_CASE("map - equal range", "[map]") {
    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    REQUIRE(ret.first->first == 'b');
    REQUIRE(ret.second->first == 'c');
}
