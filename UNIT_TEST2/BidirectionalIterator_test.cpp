/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BiDirectionalIterator_test.cpp                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 16:04:25 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/23 09:53:43 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <list>
#include <string>
#include <iostream>

#include "../Iterator/BidirectionalIterator.hpp"
#include "../List/List.hpp"

TEST_CASE( "BiDirectionalIterator-tests", "[BiDirectionalIterator]") 
{
	ft::list<std::string> own_list_string;
	std::list<std::string> real_list_string;

	own_list_string.push_back("my");
	real_list_string.push_back("my");
	own_list_string.push_back("name");
	real_list_string.push_back("name");
	own_list_string.push_back("is");
	real_list_string.push_back("is");
	own_list_string.push_back("Tim");
	real_list_string.push_back("Tim");

	ft::list<std::string>::iterator own_it = own_list_string.begin();
	ft::list<std::string>::iterator own_it_plus = own_list_string.begin();
	ft::list<std::string>::iterator own_ite = own_list_string.end();

	std::list<std::string>::iterator real_it = real_list_string.begin();
	std::list<std::string>::iterator real_it_plus = real_list_string.begin();
	std::list<std::string>::iterator real_ite = real_list_string.end();

	ft::list<int> 	own_list_int;
	std::list<int>	real_list_int;

	for (int i = 0; i < 10; ++i) own_list_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_list_int.push_back(i);

	ft::list<int>::iterator own_it2 = own_list_int.begin();
	ft::list<int>::iterator own_it2_plus = own_list_int.begin();
	ft::list<int>::iterator own_ite2 = own_list_int.end();
	

	std::list<int>::iterator real_it2 = real_list_int.begin();
	std::list<int>::iterator real_it2_plus = real_list_int.begin();
	std::list<int>::iterator real_ite2 = real_list_int.end();

	SECTION("* overload")
	{
		own_it++;
		own_it2++;

		real_it++;
		real_it2++;
		
		own_ite--;
		own_ite2--;
		real_ite--;
		real_ite2--;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-> overload")
	{
		++own_it;
		++real_it;
		
		--own_ite;
		--real_ite;

		REQUIRE(*own_ite->data() == *real_ite->data());
		REQUIRE(*own_it->data() == *real_it->data());
	}
	
	SECTION("Increment - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_it++;
		real_it++;
		own_it2++;
		real_it2++;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		++own_it;
		++real_it;
		++own_it2;
		++real_it2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}
	
	SECTION("Decrement - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_ite--;
		real_ite--;
		own_ite2--;
		real_ite2--;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		--own_ite;
		--real_ite;
		--own_ite2;
		--real_ite2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
	
	SECTION("== operator") 
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus == *own_it;
		bool real_res = *real_it_plus == *real_it;
		bool own_res2 = *own_it2_plus == *own_it2;
		bool real_res2 = *real_it2_plus == *real_it2;
		bool res3 = *own_it == *real_it;
		bool res4 = *own_it2 == *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == true);
		REQUIRE(res4 == true);
	}
	SECTION("!= operator")
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus != *own_it;
		bool real_res = *real_it_plus != *real_it;
		bool own_res2 = *own_it2_plus != *own_it2;
		bool real_res2 = *real_it2_plus != *real_it2;
		bool res3 = *own_it != *real_it;
		bool res4 = *own_it2 != *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == false);
		REQUIRE(res4 == false);
	}
}

TEST_CASE( "ConstBiDirectionalIterator-tests", "[ConstBiDirectionalIterator]") 
{
	ft::list<std::string> own_list_string;
	std::list<std::string> real_list_string;

	own_list_string.push_back("my");
	real_list_string.push_back("my");
	own_list_string.push_back("name");
	real_list_string.push_back("name");
	own_list_string.push_back("is");
	real_list_string.push_back("is");
	own_list_string.push_back("Tim");
	real_list_string.push_back("Tim");

	ft::list<std::string>::const_iterator own_it = own_list_string.begin();
	ft::list<std::string>::const_iterator own_it_plus = own_list_string.begin();
	ft::list<std::string>::const_iterator own_ite = own_list_string.end();

	std::list<std::string>::const_iterator real_it = real_list_string.begin();
	std::list<std::string>::const_iterator real_it_plus = real_list_string.begin();
	std::list<std::string>::const_iterator real_ite = real_list_string.end();

	ft::list<int> 	own_list_int;
	std::list<int>	real_list_int;

	for (int i = 0; i < 10; ++i) own_list_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_list_int.push_back(i);

	ft::list<int>::const_iterator own_it2 = own_list_int.begin();
	ft::list<int>::const_iterator own_it2_plus = own_list_int.begin();
	ft::list<int>::const_iterator own_ite2 = own_list_int.end();
	

	std::list<int>::const_iterator real_it2 = real_list_int.begin();
	std::list<int>::const_iterator real_it2_plus = real_list_int.begin();
	std::list<int>::const_iterator real_ite2 = real_list_int.end();

	SECTION("* overload")
	{
		own_it++;
		own_it2++;

		real_it++;
		real_it2++;
		
		own_ite--;
		own_ite2--;
		real_ite--;
		real_ite2--;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-> overload")
	{
		++own_it;
		++real_it;
		
		--own_ite;
		--real_ite;

		REQUIRE(*own_ite->data() == *real_ite->data());
		REQUIRE(*own_it->data() == *real_it->data());
	}
	
	SECTION("Increment - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_it++;
		real_it++;
		own_it2++;
		real_it2++;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		++own_it;
		++real_it;
		++own_it2;
		++real_it2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}
	
	SECTION("Decrement - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_ite--;
		real_ite--;
		own_ite2--;
		real_ite2--;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		--own_ite;
		--real_ite;
		--own_ite2;
		--real_ite2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
	
	SECTION("== operator") 
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus == *own_it;
		bool real_res = *real_it_plus == *real_it;
		bool own_res2 = *own_it2_plus == *own_it2;
		bool real_res2 = *real_it2_plus == *real_it2;
		bool res3 = *own_it == *real_it;
		bool res4 = *own_it2 == *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == true);
		REQUIRE(res4 == true);
	}
	SECTION("!= operator")
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus != *own_it;
		bool real_res = *real_it_plus != *real_it;
		bool own_res2 = *own_it2_plus != *own_it2;
		bool real_res2 = *real_it2_plus != *real_it2;
		bool res3 = *own_it != *real_it;
		bool res4 = *own_it2 != *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == false);
		REQUIRE(res4 == false);
	}
}

TEST_CASE( "ReverseBiDirectionalIterator-tests", "[ReverseBiDirectionalIterator]") 
{
	ft::list<std::string> own_list_string;
	std::list<std::string> real_list_string;

	own_list_string.push_back("my");
	real_list_string.push_back("my");
	own_list_string.push_back("name");
	real_list_string.push_back("name");
	own_list_string.push_back("is");
	real_list_string.push_back("is");
	own_list_string.push_back("Tim");
	real_list_string.push_back("Tim");

	ft::list<std::string>::reverse_iterator own_it = own_list_string.rbegin();
	ft::list<std::string>::reverse_iterator own_it_plus = own_list_string.rbegin();
	ft::list<std::string>::reverse_iterator own_ite = own_list_string.rend();

	std::list<std::string>::reverse_iterator real_it = real_list_string.rbegin();
	std::list<std::string>::reverse_iterator real_it_plus = real_list_string.rbegin();
	std::list<std::string>::reverse_iterator real_ite = real_list_string.rend();

	ft::list<int> 	own_list_int;
	std::list<int>	real_list_int;

	for (int i = 0; i < 10; ++i) own_list_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_list_int.push_back(i);

	ft::list<int>::reverse_iterator own_it2 = own_list_int.rbegin();
	ft::list<int>::reverse_iterator own_it2_plus = own_list_int.rbegin();
	ft::list<int>::reverse_iterator own_ite2 = own_list_int.rend();
	

	std::list<int>::reverse_iterator real_it2 = real_list_int.rbegin();
	std::list<int>::reverse_iterator real_it2_plus = real_list_int.rbegin();
	std::list<int>::reverse_iterator real_ite2 = real_list_int.rend();

	SECTION("* overload")
	{
		own_it++;
		own_it2++;

		real_it++;
		real_it2++;
		
		own_ite--;
		own_ite2--;
		real_ite--;
		real_ite2--;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-> overload")
	{
		++own_it;
		++real_it;
		
		--own_ite;
		--real_ite;

		REQUIRE(*own_ite->data() == *real_ite->data());
		REQUIRE(*own_it->data() == *real_it->data());
	}
	
	SECTION("Increment - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_it++;
		real_it++;
		own_it2++;
		real_it2++;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		++own_it;
		++real_it;
		++own_it2;
		++real_it2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}
	
	SECTION("Decrement - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_ite--;
		real_ite--;
		own_ite2--;
		real_ite2--;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		--own_ite;
		--real_ite;
		--own_ite2;
		--real_ite2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
	
	SECTION("== operator") 
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus == *own_it;
		bool real_res = *real_it_plus == *real_it;
		bool own_res2 = *own_it2_plus == *own_it2;
		bool real_res2 = *real_it2_plus == *real_it2;
		bool res3 = *own_it == *real_it;
		bool res4 = *own_it2 == *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == true);
		REQUIRE(res4 == true);
	}
	SECTION("!= operator")
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus != *own_it;
		bool real_res = *real_it_plus != *real_it;
		bool own_res2 = *own_it2_plus != *own_it2;
		bool real_res2 = *real_it2_plus != *real_it2;
		bool res3 = *own_it != *real_it;
		bool res4 = *own_it2 != *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == false);
		REQUIRE(res4 == false);
	}
}

TEST_CASE( "ConstReverseBiDirectionalIterator-tests", "[ConstReverseBiDirectionalIterator]") 
{
	ft::list<std::string> own_list_string;
	std::list<std::string> real_list_string;

	own_list_string.push_back("my");
	real_list_string.push_back("my");
	own_list_string.push_back("name");
	real_list_string.push_back("name");
	own_list_string.push_back("is");
	real_list_string.push_back("is");
	own_list_string.push_back("Tim");
	real_list_string.push_back("Tim");

	ft::list<std::string>::const_reverse_iterator own_it = own_list_string.rbegin();
	ft::list<std::string>::const_reverse_iterator own_it_plus = own_list_string.rbegin();
	ft::list<std::string>::const_reverse_iterator own_ite = own_list_string.rend();

	std::list<std::string>::const_reverse_iterator real_it = real_list_string.rbegin();
	std::list<std::string>::const_reverse_iterator real_it_plus = real_list_string.rbegin();
	std::list<std::string>::const_reverse_iterator real_ite = real_list_string.rend();

	ft::list<int> 	own_list_int;
	std::list<int>	real_list_int;

	for (int i = 0; i < 10; ++i) own_list_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_list_int.push_back(i);

	ft::list<int>::const_reverse_iterator own_it2 = own_list_int.rbegin();
	ft::list<int>::const_reverse_iterator own_it2_plus = own_list_int.rbegin();
	ft::list<int>::const_reverse_iterator own_ite2 = own_list_int.rend();
	

	std::list<int>::const_reverse_iterator real_it2 = real_list_int.rbegin();
	std::list<int>::const_reverse_iterator real_it2_plus = real_list_int.rbegin();
	std::list<int>::const_reverse_iterator real_ite2 = real_list_int.rend();

	SECTION("* overload")
	{
		own_it++;
		own_it2++;

		real_it++;
		real_it2++;
		
		own_ite--;
		own_ite2--;
		real_ite--;
		real_ite2--;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-> overload")
	{
		++own_it;
		++real_it;
		
		--own_ite;
		--real_ite;

		REQUIRE(*own_ite->data() == *real_ite->data());
		REQUIRE(*own_it->data() == *real_it->data());
	}
	
	SECTION("Increment - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_it++;
		real_it++;
		own_it2++;
		real_it2++;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		++own_it;
		++real_it;
		++own_it2;
		++real_it2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}
	
	SECTION("Decrement - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_ite--;
		real_ite--;
		own_ite2--;
		real_ite2--;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		--own_ite;
		--real_ite;
		--own_ite2;
		--real_ite2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
	
	SECTION("== operator") 
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus == *own_it;
		bool real_res = *real_it_plus == *real_it;
		bool own_res2 = *own_it2_plus == *own_it2;
		bool real_res2 = *real_it2_plus == *real_it2;
		bool res3 = *own_it == *real_it;
		bool res4 = *own_it2 == *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == true);
		REQUIRE(res4 == true);
	}
	SECTION("!= operator")
	{
		++own_it_plus;
		++real_it_plus;
		++own_it2_plus;
		++real_it2_plus;
		bool own_res = *own_it_plus != *own_it;
		bool real_res = *real_it_plus != *real_it;
		bool own_res2 = *own_it2_plus != *own_it2;
		bool real_res2 = *real_it2_plus != *real_it2;
		bool res3 = *own_it != *real_it;
		bool res4 = *own_it2 != *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
		REQUIRE(res3 == false);
		REQUIRE(res4 == false);
	}
}

TEST_CASE("ConstructorBiDirectionalIterator-tests", "[ConstructorBiDirectionalIterator]") 
{
	ft::list<std::string> own_list_string;
	std::list<std::string> real_list_string;

	real_list_string.push_back("my");
	real_list_string.push_back("name");
	real_list_string.push_back("is");
	real_list_string.push_back("Tim");

	own_list_string.push_back("my");
	own_list_string.push_back("name");
	own_list_string.push_back("is");
	own_list_string.push_back("Tim");

	ft::list<std::string>::iterator 				own_it = own_list_string.begin();
	ft::list<std::string>::const_iterator 			own_it_const(own_it);
	ft::list<std::string>::const_iterator			own_it_const2;

	own_it_const2 = own_it_const;

	ft::list<std::string>::reverse_iterator 		own_it_reverse = own_list_string.rbegin();
	ft::list<std::string>::const_reverse_iterator own_it_reverse_const(own_it_reverse);
	ft::list<std::string>::const_reverse_iterator own_it_reverse_const2;

	own_it_reverse_const2 = own_it_reverse_const;
	

	std::list<std::string>::iterator 				real_it = real_list_string.begin();
	std::list<std::string>::const_iterator 			real_it_const(real_it);
	std::list<std::string>::const_iterator			real_it_const2;

	real_it_const2 = real_it_const;

	REQUIRE(*real_it_const == *real_it_const2);
	REQUIRE(*real_it == *real_it_const2);

	std::list<std::string>::reverse_iterator 		real_it_reverse = real_list_string.rbegin();
	std::list<std::string>::const_reverse_iterator real_it_reverse_const(real_it_reverse);
	std::list<std::string>::const_reverse_iterator real_it_reverse_const2;

	real_it_reverse_const2 = real_it_reverse_const;
	
	REQUIRE(*real_it == *own_it);
	REQUIRE(*own_it_const == *real_it_const);
	REQUIRE(*own_it_const2 == *real_it_const2);
	
	REQUIRE(*real_it_reverse == *own_it_reverse);
	REQUIRE(*own_it_reverse_const == *real_it_reverse_const);
	REQUIRE(*own_it_reverse_const2 == *real_it_reverse_const2);

}