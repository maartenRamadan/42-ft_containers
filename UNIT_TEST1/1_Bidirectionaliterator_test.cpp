#include "catch.hpp"

#include <string>
#include <list>
#include "../List/List.hpp"

TEST_CASE( "BiDirectionalIterator", "[list]" ) {
    ft::list<std::string> ft_basic_list;
    std::list<std::string> std_basic_list;

    ft_basic_list.push_back("Hello world");
    std_basic_list.push_back("Hello world");
    ft_basic_list.push_back("Goodbye world");
    std_basic_list.push_back("Goodbye world");
    ft_basic_list.push_back("Hello again");
    std_basic_list.push_back("Hello again");
    ft_basic_list.push_back("Final goodbye");
    std_basic_list.push_back("Final goodbye");

    ft::list<std::string>::iterator ft_basic_it = ft_basic_list.begin();
    std::list<std::string>::iterator std_basic_it = std_basic_list.begin();

    ft::list<std::string>::iterator ft_basic_end_it = ft_basic_list.end();
    std::list<std::string>::iterator std_basic_end_it = std_basic_list.end();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_basic_it == *std_basic_it);
        ft_basic_it++;
        std_basic_it++;
        REQUIRE(*ft_basic_it->data() == *std_basic_it->data());
        ++ft_basic_it;
        ++std_basic_it;
        REQUIRE(*ft_basic_it == *std_basic_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_basic_end_it--;
        std_basic_end_it--;
        REQUIRE(*ft_basic_end_it->data() == *std_basic_end_it->data());
        --ft_basic_end_it;
        --std_basic_end_it;
        REQUIRE(*ft_basic_end_it == *std_basic_end_it);
    }
    SECTION("* overload") {
        ++ft_basic_it;
        ++std_basic_it;
        REQUIRE(*ft_basic_it == *std_basic_it);
    }
    SECTION("-> overload") {
        ft_basic_it--;
        std_basic_it--;
        REQUIRE(*ft_basic_it->data() == *std_basic_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_basic_it == *std_basic_it);
        REQUIRE(equal == true);
        ++ft_basic_it;
        equal = (*ft_basic_it == *std_basic_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_basic_it != *std_basic_it);
        REQUIRE(unequal == false);
        ++std_basic_it;
        unequal = (*ft_basic_it != *std_basic_it);
        REQUIRE(unequal == true);
    }
}

TEST_CASE( "Const BiDirectionalIterator", "[list]" ) {
    ft::list<std::string> ft_const_list;
    std::list<std::string> std_const_list;

    ft_const_list.push_back("Hello world");
    std_const_list.push_back("Hello world");
    ft_const_list.push_back("Goodbye world");
    std_const_list.push_back("Goodbye world");
    ft_const_list.push_back("Hello again");
    std_const_list.push_back("Hello again");
    ft_const_list.push_back("Final goodbye");
    std_const_list.push_back("Final goodbye");

    ft::list<std::string>::const_iterator ft_const_it = ft_const_list.begin();
    std::list<std::string>::const_iterator std_const_it = std_const_list.begin();

    ft::list<std::string>::const_iterator ft_const_end_it = ft_const_list.end();
    std::list<std::string>::const_iterator std_const_end_it = std_const_list.end();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_const_it == *std_const_it);
        ft_const_it++;
        std_const_it++;
        REQUIRE(*ft_const_it->data() == *std_const_it->data());
        ++ft_const_it;
        ++std_const_it;
        REQUIRE(*ft_const_it == *std_const_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_const_end_it--;
        std_const_end_it--;
        REQUIRE(*ft_const_end_it->data() == *std_const_end_it->data());
        --ft_const_end_it;
        --std_const_end_it;
        REQUIRE(*ft_const_end_it == *std_const_end_it);
    }
    SECTION("* overload") {
        ++ft_const_it;
        ++std_const_it;
        REQUIRE(*ft_const_it == *std_const_it);
    }
    SECTION("-> overload") {
        ft_const_it--;
        std_const_it--;
        REQUIRE(*ft_const_it->data() == *std_const_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_const_it == *std_const_it);
        REQUIRE(equal == true);
        ++ft_const_it;
        equal = (*ft_const_it == *std_const_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_const_it != *std_const_it);
        REQUIRE(unequal == false);
        ++std_const_it;
        unequal = (*ft_const_it != *std_const_it);
        REQUIRE(unequal == true);
    }
}

TEST_CASE( "Rev BiDirectionalIterator", "[list]" ) {
    ft::list<std::string> ft_rev_list;
    std::list<std::string> std_rev_list;

    ft_rev_list.push_back("Hello world");
    std_rev_list.push_back("Hello world");
    ft_rev_list.push_back("Goodbye world");
    std_rev_list.push_back("Goodbye world");
    ft_rev_list.push_back("Hello again");
    std_rev_list.push_back("Hello again");
    ft_rev_list.push_back("Final goodbye");
    std_rev_list.push_back("Final goodbye");

    ft::list<std::string>::reverse_iterator ft_rev_it = ft_rev_list.rbegin();
    std::list<std::string>::reverse_iterator std_rev_it = std_rev_list.rbegin();

    ft::list<std::string>::reverse_iterator ft_rev_end_it = ft_rev_list.rend();
    std::list<std::string>::reverse_iterator std_rev_end_it = std_rev_list.rend();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_rev_it == *std_rev_it);
        ft_rev_it++;
        std_rev_it++;
        REQUIRE(*ft_rev_it->data() == *std_rev_it->data());
        ++ft_rev_it;
        ++std_rev_it;
        REQUIRE(*ft_rev_it == *std_rev_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_rev_end_it--;
        std_rev_end_it--;
        REQUIRE(*ft_rev_end_it->data() == *std_rev_end_it->data());
        --ft_rev_end_it;
        --std_rev_end_it;
        REQUIRE(*ft_rev_end_it == *std_rev_end_it);
    }
    SECTION("* overload") {
        ++ft_rev_it;
        ++std_rev_it;
        REQUIRE(*ft_rev_it == *std_rev_it);
    }
    SECTION("-> overload") {
        ft_rev_it--;
        std_rev_it--;
        REQUIRE(*ft_rev_it->data() == *std_rev_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_rev_it == *std_rev_it);
        REQUIRE(equal == true);
        ++ft_rev_it;
        equal = (*ft_rev_it == *std_rev_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_rev_it != *std_rev_it);
        REQUIRE(unequal == false);
        ++std_rev_it;
        unequal = (*ft_rev_it != *std_rev_it);
        REQUIRE(unequal == true);
    }
}

TEST_CASE( "Const Rev BiDirectionalIterator", "[list]" ) {
    ft::list<std::string> ft_const_rev_list;
    std::list<std::string> std_const_rev_list;

    ft_const_rev_list.push_back("Hello world");
    std_const_rev_list.push_back("Hello world");
    ft_const_rev_list.push_back("Goodbye world");
    std_const_rev_list.push_back("Goodbye world");
    ft_const_rev_list.push_back("Hello again");
    std_const_rev_list.push_back("Hello again");
    ft_const_rev_list.push_back("Final goodbye");
    std_const_rev_list.push_back("Final goodbye");

    ft::list<std::string>::const_reverse_iterator ft_const_rev_it = ft_const_rev_list.rbegin();
    std::list<std::string>::const_reverse_iterator std_const_rev_it = std_const_rev_list.rbegin();

    ft::list<std::string>::const_reverse_iterator ft_const_rev_end_it = ft_const_rev_list.rend();
    std::list<std::string>::const_reverse_iterator std_const_rev_end_it = std_const_rev_list.rend();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
        ft_const_rev_it++;
        std_const_rev_it++;
        REQUIRE(*ft_const_rev_it->data() == *std_const_rev_it->data());
        ++ft_const_rev_it;
        ++std_const_rev_it;
        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_const_rev_end_it--;
        std_const_rev_end_it--;
        REQUIRE(*ft_const_rev_end_it->data() == *std_const_rev_end_it->data());
        --ft_const_rev_end_it;
        --std_const_rev_end_it;
        REQUIRE(*ft_const_rev_end_it == *std_const_rev_end_it);
    }
    SECTION("* overload") {
        ++ft_const_rev_it;
        ++std_const_rev_it;
        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
    }
    SECTION("-> overload") {
        ft_const_rev_it--;
        std_const_rev_it--;
        REQUIRE(*ft_const_rev_it->data() == *std_const_rev_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_const_rev_it == *std_const_rev_it);
        REQUIRE(equal == true);
        ++ft_const_rev_it;
        equal = (*ft_const_rev_it == *std_const_rev_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_const_rev_it != *std_const_rev_it);
        REQUIRE(unequal == false);
        ++std_const_rev_it;
        unequal = (*ft_const_rev_it != *std_const_rev_it);
        REQUIRE(unequal == true);
    }
}