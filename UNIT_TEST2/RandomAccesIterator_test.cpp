/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccesIterator_test.cpp                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 11:03:00 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/23 09:40:35 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <vector>
#include <string>
#include <iostream>

#include "../Iterator/RandomAccessIterator.hpp"
#include "../Vector/Vector.hpp"

TEST_CASE( "RandomAccesIterator-tests", "[RandomAccesIterator]") 
{
	ft::vector<std::string> own_vector_string;
	std::vector<std::string> real_vector_string;

	own_vector_string.push_back("my");
	real_vector_string.push_back("my");
	own_vector_string.push_back("name");
	real_vector_string.push_back("name");
	own_vector_string.push_back("is");
	real_vector_string.push_back("is");
	own_vector_string.push_back("Tim");
	real_vector_string.push_back("Tim");

	ft::vector<std::string>::iterator own_it = own_vector_string.begin();
	ft::vector<std::string>::iterator own_it_plus = own_vector_string.begin() + 2;
	ft::vector<std::string>::iterator own_ite = own_vector_string.end();

	std::vector<std::string>::iterator real_it = real_vector_string.begin();
	std::vector<std::string>::iterator real_it_plus = real_vector_string.begin() + 2;
	std::vector<std::string>::iterator real_ite = real_vector_string.end();

	ft::vector<int> 	own_vector_int;
	std::vector<int>	real_vector_int;

	for (int i = 0; i < 10; ++i) own_vector_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_vector_int.push_back(i);

	ft::vector<int>::iterator own_it2 = own_vector_int.begin();
	ft::vector<int>::iterator own_it2_plus = own_vector_int.begin() + 2;
	ft::vector<int>::iterator own_ite2 = own_vector_int.end();
	

	std::vector<int>::iterator real_it2 = real_vector_int.begin();
	std::vector<int>::iterator real_it2_plus = real_vector_int.begin() +2;
	std::vector<int>::iterator real_ite2 = real_vector_int.end();

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
	
	SECTION("[] overload")
	{
		REQUIRE(own_it[2] == real_it[2]);
		REQUIRE(own_it2[2] == real_it2[2]);
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

	SECTION("+ overload") 
	{
		own_it = own_it + 2;
		real_it = real_it + 2;
		own_it2 = own_it2 + 3;
		real_it2 = real_it2 + 3;
		
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);

		int own_res = *own_it2 + *own_it2;
		int real_res = *real_it2 + *real_it2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("- overload") 
	{
		own_ite = own_ite - 2;
		real_ite = real_ite - 2;
		own_ite2 = own_ite2 - 3;
		real_ite2 = real_ite2 - 3;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);

		int own_res = *own_ite2 - *own_ite2;
		int real_res = *real_ite2 - *real_ite2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("+= overload") 
	{
		own_it += 2;
		real_it += 2;
		own_it2 += 2;
		real_it2 += 2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-= overload") 
	{
		own_ite -= 2;
		real_ite -= 2;
		own_ite2 -= 2;
		real_ite2 -= 2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
    SECTION("< overload") 
	{
		bool own_res = *own_it_plus < *own_it;
		bool real_res = *real_it_plus < *real_it;
		bool own_res2 = *own_it2_plus < *own_it2;
		bool real_res2 = *real_it2_plus < *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}
	SECTION("> overload")
	{
		bool own_res = *own_it_plus > *own_it;
		bool real_res = *real_it_plus > *real_it;
		bool own_res2 = *own_it2_plus > *own_it2;
		bool real_res2 = *real_it2_plus > *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);;
	}
	SECTION("<= overload") 
	{
		bool own_res = *own_it_plus <= *own_it;
		bool real_res = *real_it_plus <= *real_it;
		bool own_res2 = *own_it2_plus <= *own_it2;
		bool real_res2 = *real_it2_plus <= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
 	}
	SECTION(">= overload") 
	{
		bool own_res = *own_it_plus >= *own_it;
		bool real_res = *real_it_plus >= *real_it;
		bool own_res2 = *own_it2_plus >= *own_it2;
		bool real_res2 = *real_it2_plus >= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}
	SECTION("== operator") 
	{
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

TEST_CASE( "ConstRandomAccesIterator-tests", "[ConstRandomAccesIterator]") 
{
	ft::vector<std::string> own_vector_string;
	std::vector<std::string> real_vector_string;

	own_vector_string.push_back("my");
	real_vector_string.push_back("my");
	own_vector_string.push_back("name");
	real_vector_string.push_back("name");
	own_vector_string.push_back("is");
	real_vector_string.push_back("is");
	own_vector_string.push_back("Tim");
	real_vector_string.push_back("Tim");

	ft::vector<std::string>::const_iterator own_it = own_vector_string.begin();
	ft::vector<std::string>::const_iterator own_it_plus = own_vector_string.begin() + 2;
	ft::vector<std::string>::const_iterator own_ite = own_vector_string.end();

	std::vector<std::string>::const_iterator real_it = real_vector_string.begin();
	std::vector<std::string>::const_iterator real_it_plus = real_vector_string.begin() + 2;
	std::vector<std::string>::const_iterator real_ite = real_vector_string.end();

	ft::vector<int> 	own_vector_int;
	std::vector<int>	real_vector_int;

	for (int i = 0; i < 10; ++i) own_vector_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_vector_int.push_back(i);

	ft::vector<int>::const_iterator own_it2 = own_vector_int.begin();
	ft::vector<int>::const_iterator own_it2_plus = own_vector_int.begin() + 2;
	ft::vector<int>::const_iterator own_ite2 = own_vector_int.end();
	

	std::vector<int>::const_iterator real_it2 = real_vector_int.begin();
	std::vector<int>::const_iterator real_it2_plus = real_vector_int.begin() +2;
	std::vector<int>::const_iterator real_ite2 = real_vector_int.end();

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
	
	SECTION("[] overload")
	{
		REQUIRE(own_it[2] == real_it[2]);
		REQUIRE(own_it2[2] == real_it2[2]);
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

	SECTION("+ overload") 
	{
		own_it = own_it + 2;
		real_it = real_it + 2;
		own_it2 = own_it2 + 3;
		real_it2 = real_it2 + 3;
		
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);

		int own_res = *own_it2 + *own_it2;
		int real_res = *real_it2 + *real_it2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("- overload") 
	{
		own_ite = own_ite - 2;
		real_ite = real_ite - 2;
		own_ite2 = own_ite2 - 3;
		real_ite2 = real_ite2 - 3;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);

		int own_res = *own_ite2 - *own_ite2;
		int real_res = *real_ite2 - *real_ite2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("+= overload") 
	{
		own_it += 2;
		real_it += 2;
		own_it2 += 2;
		real_it2 += 2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-= overload") 
	{
		own_ite -= 2;
		real_ite -= 2;
		own_ite2 -= 2;
		real_ite2 -= 2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
    SECTION("< overload") 
	{
		bool own_res = *own_it_plus < *own_it;
		bool real_res = *real_it_plus < *real_it;
		bool own_res2 = *own_it2_plus < *own_it2;
		bool real_res2 = *real_it2_plus < *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}
	SECTION("> overload")
	{
		bool own_res = *own_it_plus > *own_it;
		bool real_res = *real_it_plus > *real_it;
		bool own_res2 = *own_it2_plus > *own_it2;
		bool real_res2 = *real_it2_plus > *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);;
	}
	SECTION("<= overload") 
	{
		bool own_res = *own_it_plus <= *own_it;
		bool real_res = *real_it_plus <= *real_it;
		bool own_res2 = *own_it2_plus <= *own_it2;
		bool real_res2 = *real_it2_plus <= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
 	}
	SECTION(">= overload") 
	{
		bool own_res = *own_it_plus >= *own_it;
		bool real_res = *real_it_plus >= *real_it;
		bool own_res2 = *own_it2_plus >= *own_it2;
		bool real_res2 = *real_it2_plus >= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}
	SECTION("== operator") 
	{
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

TEST_CASE( "ReverseRandomAccesIterator-tests", "[ReverseRandomAccesIterator]") 
{
	ft::vector<std::string> own_vector_string;
	std::vector<std::string> real_vector_string;

	own_vector_string.push_back("my");
	own_vector_string.push_back("name");
	own_vector_string.push_back("is");
	own_vector_string.push_back("Tim");
	
	real_vector_string.push_back("my");
	real_vector_string.push_back("name");
	real_vector_string.push_back("is");
	real_vector_string.push_back("Tim");

	ft::vector<std::string>::reverse_iterator own_it = own_vector_string.rbegin();
	ft::vector<std::string>::reverse_iterator own_it_plus = own_vector_string.rbegin() + 2;
	ft::vector<std::string>::reverse_iterator own_ite = own_vector_string.rend();

	std::vector<std::string>::reverse_iterator real_it = real_vector_string.rbegin();
	std::vector<std::string>::reverse_iterator real_it_plus = real_vector_string.rbegin() + 2;
	std::vector<std::string>::reverse_iterator real_ite = real_vector_string.rend();

	ft::vector<int> 	own_vector_int;
	std::vector<int>	real_vector_int;

	for (int i = 0; i < 10; ++i) own_vector_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_vector_int.push_back(i);

	ft::vector<int>::reverse_iterator own_it2 = own_vector_int.rbegin();
	ft::vector<int>::reverse_iterator own_it2_plus = own_vector_int.rbegin() + 2;
	ft::vector<int>::reverse_iterator own_ite2 = own_vector_int.rend();
	

	std::vector<int>::reverse_iterator real_it2 = real_vector_int.rbegin();
	std::vector<int>::reverse_iterator real_it2_plus = real_vector_int.rbegin() +2;
	std::vector<int>::reverse_iterator real_ite2 = real_vector_int.rend();

	SECTION("* overload")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		
		own_it++;
		own_it2++;
		real_it++;
		real_it2++;
		
		own_ite--;
		real_ite--;
		own_ite2--;
		real_ite2--;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-> overload")
	{
		own_it++;
		real_it++;
		
		own_ite--;
		real_ite--;

		REQUIRE(*own_ite->data() == *real_ite->data());
		REQUIRE(*own_it->data() == *real_it->data());
	}
	
	SECTION("[] overload")
	{
		REQUIRE(own_it[2] == real_it[2]);
		REQUIRE(own_it2[2] == real_it2[2]);
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

	SECTION("+ overload") 
	{
		own_it = own_it + 2;
		real_it = real_it + 2;
		own_it2 = own_it2 + 3;
		real_it2 = real_it2 + 3;
		
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);

		int own_res = *own_it2 + *own_it2;
		int real_res = *real_it2 + *real_it2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("- overload") 
	{
		own_ite = own_ite - 2;
		real_ite = real_ite - 2;
		own_ite2 = own_ite2 - 3;
		real_ite2 = real_ite2 - 3;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);

		int own_res = *own_ite2 - *own_ite2;
		int real_res = *real_ite2 - *real_ite2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("+= overload") 
	{
		own_it += 2;
		real_it += 2;
		own_it2 += 2;
		real_it2 += 2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-= overload") 
	{
		own_ite -= 2;
		real_ite -= 2;
		own_ite2 -= 2;
		real_ite2 -= 2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
	
    SECTION("< overload") 
	{
		bool own_res = *own_it_plus < *own_it;
		bool real_res = *real_it_plus < *real_it;
		bool own_res2 = *own_it2_plus < *own_it2;
		bool real_res2 = *real_it2_plus < *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}

	SECTION("> overload")
	{
		bool own_res = *own_it_plus > *own_it;
		bool real_res = *real_it_plus > *real_it;
		bool own_res2 = *own_it2_plus > *own_it2;
		bool real_res2 = *real_it2_plus > *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);;
	}
	
	SECTION("<= overload") 
	{
		bool own_res = *own_it_plus <= *own_it;
		bool real_res = *real_it_plus <= *real_it;
		bool own_res2 = *own_it2_plus <= *own_it2;
		bool real_res2 = *real_it2_plus <= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
 	}
	 
	SECTION(">= overload") 
	{
		bool own_res = *own_it_plus >= *own_it;
		bool real_res = *real_it_plus >= *real_it;
		bool own_res2 = *own_it2_plus >= *own_it2;
		bool real_res2 = *real_it2_plus >= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}
	
	SECTION("== operator") 
	{
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

TEST_CASE( "ConstReverseRandomAccesIterator-tests", "[ConstReverseRandomAccesIterator]") 
{
	ft::vector<std::string> own_vector_string;
	std::vector<std::string> real_vector_string;

	own_vector_string.push_back("my");
	own_vector_string.push_back("name");
	own_vector_string.push_back("is");
	own_vector_string.push_back("Tim");
	
	real_vector_string.push_back("my");
	real_vector_string.push_back("name");
	real_vector_string.push_back("is");
	real_vector_string.push_back("Tim");

	ft::vector<std::string>::const_reverse_iterator own_it = own_vector_string.rbegin();
	ft::vector<std::string>::const_reverse_iterator own_it_plus = own_vector_string.rbegin() + 2;
	ft::vector<std::string>::const_reverse_iterator own_ite = own_vector_string.rend();

	std::vector<std::string>::const_reverse_iterator real_it = real_vector_string.rbegin();
	std::vector<std::string>::const_reverse_iterator real_it_plus = real_vector_string.rbegin() + 2;
	std::vector<std::string>::const_reverse_iterator real_ite = real_vector_string.rend();

	ft::vector<int> 	own_vector_int;
	std::vector<int>	real_vector_int;

	for (int i = 0; i < 10; ++i) own_vector_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_vector_int.push_back(i);

	ft::vector<int>::const_reverse_iterator own_it2 = own_vector_int.rbegin();
	ft::vector<int>::const_reverse_iterator own_it2_plus = own_vector_int.rbegin() + 2;
	ft::vector<int>::const_reverse_iterator own_ite2 = own_vector_int.rend();
	

	std::vector<int>::const_reverse_iterator real_it2 = real_vector_int.rbegin();
	std::vector<int>::const_reverse_iterator real_it2_plus = real_vector_int.rbegin() +2;
	std::vector<int>::const_reverse_iterator real_ite2 = real_vector_int.rend();

	SECTION("* overload")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		
		own_it++;
		own_it2++;
		real_it++;
		real_it2++;
		
		own_ite--;
		real_ite--;
		own_ite2--;
		real_ite2--;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-> overload")
	{
		own_it++;
		real_it++;
		
		own_ite--;
		real_ite--;

		REQUIRE(*own_ite->data() == *real_ite->data());
		REQUIRE(*own_it->data() == *real_it->data());
	}
	
	SECTION("[] overload")
	{
		REQUIRE(own_it[2] == real_it[2]);
		REQUIRE(own_it2[2] == real_it2[2]);
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

	SECTION("+ overload") 
	{
		own_it = own_it + 2;
		real_it = real_it + 2;
		own_it2 = own_it2 + 3;
		real_it2 = real_it2 + 3;
		
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);

		int own_res = *own_it2 + *own_it2;
		int real_res = *real_it2 + *real_it2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("- overload") 
	{
		own_ite = own_ite - 2;
		real_ite = real_ite - 2;
		own_ite2 = own_ite2 - 3;
		real_ite2 = real_ite2 - 3;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);

		int own_res = *own_ite2 - *own_ite2;
		int real_res = *real_ite2 - *real_ite2;
		
		REQUIRE(own_res == real_res);
	}

	SECTION("+= overload") 
	{
		own_it += 2;
		real_it += 2;
		own_it2 += 2;
		real_it2 += 2;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-= overload") 
	{
		own_ite -= 2;
		real_ite -= 2;
		own_ite2 -= 2;
		real_ite2 -= 2;
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
	}
	
    SECTION("< overload") 
	{
		bool own_res = *own_it_plus < *own_it;
		bool real_res = *real_it_plus < *real_it;
		bool own_res2 = *own_it2_plus < *own_it2;
		bool real_res2 = *real_it2_plus < *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}

	SECTION("> overload")
	{
		bool own_res = *own_it_plus > *own_it;
		bool real_res = *real_it_plus > *real_it;
		bool own_res2 = *own_it2_plus > *own_it2;
		bool real_res2 = *real_it2_plus > *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);;
	}
	
	SECTION("<= overload") 
	{
		bool own_res = *own_it_plus <= *own_it;
		bool real_res = *real_it_plus <= *real_it;
		bool own_res2 = *own_it2_plus <= *own_it2;
		bool real_res2 = *real_it2_plus <= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
 	}
	 
	SECTION(">= overload") 
	{
		bool own_res = *own_it_plus >= *own_it;
		bool real_res = *real_it_plus >= *real_it;
		bool own_res2 = *own_it2_plus >= *own_it2;
		bool real_res2 = *real_it2_plus >= *real_it2;

		REQUIRE(own_res == real_res);
		REQUIRE(own_res2 == real_res2);
	}
	
	SECTION("== operator") 
	{
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

TEST_CASE( "ConstructorRandomAccesIterator-tests", "[ConstructorRandomAccesIterator]") 
{
	ft::vector<std::string> own_vector_string;
	std::vector<std::string> real_vector_string;

	real_vector_string.push_back("my");
	real_vector_string.push_back("name");
	real_vector_string.push_back("is");
	real_vector_string.push_back("Tim");

	own_vector_string.push_back("my");
	own_vector_string.push_back("name");
	own_vector_string.push_back("is");
	own_vector_string.push_back("Tim");

	ft::vector<std::string>::iterator 				own_it = own_vector_string.begin();
	ft::vector<std::string>::const_iterator 			own_it_const(own_it);
	ft::vector<std::string>::const_iterator			own_it_const2;

	own_it_const2 = own_it_const;

	ft::vector<std::string>::reverse_iterator 		own_it_reverse = own_vector_string.rbegin();
	ft::vector<std::string>::const_reverse_iterator own_it_reverse_const(own_it_reverse);
	ft::vector<std::string>::const_reverse_iterator own_it_reverse_const2;

	own_it_reverse_const2 = own_it_reverse_const;
	

	std::vector<std::string>::iterator 				real_it = real_vector_string.begin();
	std::vector<std::string>::const_iterator 			real_it_const(real_it);
	std::vector<std::string>::const_iterator			real_it_const2;

	real_it_const2 = real_it_const;

	REQUIRE(*real_it_const == *real_it_const2);
	REQUIRE(*real_it == *real_it_const2);

	std::vector<std::string>::reverse_iterator 		real_it_reverse = real_vector_string.rbegin();
	std::vector<std::string>::const_reverse_iterator real_it_reverse_const(real_it_reverse);
	std::vector<std::string>::const_reverse_iterator real_it_reverse_const2;

	real_it_reverse_const2 = real_it_reverse_const;
	
	REQUIRE(*real_it == *own_it);
	REQUIRE(*own_it_const == *real_it_const);
	REQUIRE(*own_it_const2 == *real_it_const2);
	
	REQUIRE(*real_it_reverse == *own_it_reverse);
	REQUIRE(*own_it_reverse_const == *real_it_reverse_const);
	REQUIRE(*own_it_reverse_const2 == *real_it_reverse_const2);
}