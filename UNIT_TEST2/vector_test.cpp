/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_test.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 13:05:30 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/23 09:40:57 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <vector>

#include "../Vector/Vector.hpp"

/*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("vector-default constructor", "[vector]")
{
	ft::vector<int> 	own;
	std::vector<int> 	real;
	
	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-size and value constructor", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int> 	real(5, 3);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-iterator instanciation", "[vector]")
{
	ft::vector<int>		own(6, 100);
	std::vector<int>	real(6, 100);

	ft::vector<int>		own2(own.begin(), own.end());
	std::vector<int>	real2(real.begin(), real.end());
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.capacity() == real2.capacity());
	REQUIRE(own2[0] ==  real2[0]);
	REQUIRE(own2[1] == real2[1]);

	own.clear();
	real.clear();
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 1;
	}
	own.pop_back();
	real.pop_back();
	ft::vector<int> 	own3(own.begin() + 1, own.end());
	std::vector<int>	real3(real.begin() + 1, real.end());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own3.capacity() == real3.capacity());
	REQUIRE(own3[0] == real3[0]);
	REQUIRE(own3[1] == real3[1]);
}

TEST_CASE("vector-copy constructor", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);

	ft::vector<int> 	own2(own1);
	std::vector<int> 	real2(real1);

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
}

TEST_CASE("operator= function", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);
	
	ft::vector<int> own2;
	std::vector<int> real2;

	own2 = own1;
	real2 = real1;

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
	REQUIRE(own2.capacity() == real2.capacity());
}


/*-----------------ITERATORS-----------------*/
TEST_CASE("vector-begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::iterator own_it = own.begin();
	std::vector<int>::iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-const begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::const_iterator own_it = own.begin();
	std::vector<int>::const_iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::iterator own_ite = own.end();
	std::vector<int>::iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-const end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::const_iterator own_ite = own.end();
	std::vector<int>::const_iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-rbegin function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::reverse_iterator old_own_rit;
	std::vector<int>::reverse_iterator real_rit = real.rbegin();
	std::vector<int>::reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-const rbegin function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::const_reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::const_reverse_iterator old_own_rit;
	std::vector<int>::const_reverse_iterator real_rit = real.rbegin();
	std::vector<int>::const_reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::reverse_iterator own_rite = own.rend();
	ft::vector<int>::reverse_iterator old_own_rite;
	std::vector<int>::reverse_iterator real_rite = real.rend();
	std::vector<int>::reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

TEST_CASE("vector-const rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::const_reverse_iterator own_rite = own.rend();
	ft::vector<int>::const_reverse_iterator old_own_rite;
	std::vector<int>::const_reverse_iterator real_rite = real.rend();
	std::vector<int>::const_reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}


/*-----------------Capcity-----------------*/
TEST_CASE("vector-size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-max_size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	own.clear();
	real.clear();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.max_size() == real.max_size());
}

TEST_CASE("vector-resize function", "[vector]")
{
	ft::vector<int> 	own(8, 5);
	std::vector<int> 	real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[1] == real[1]);
}

TEST_CASE("vector-capacity function", "[vector]")
{
	ft::vector<int> own(8, 5);
	std::vector<int> real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-empty function", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int>	real(5, 3);
	
	ft::vector<int> 	empty_own;
	std::vector<int>	empty_real;

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(empty_own.empty() == empty_real.empty());
}

TEST_CASE("vector-reserve function", "[vector]")
{
	ft::vector<int>		own(6, 10);
	std::vector<int>	real(6, 10);

	own.reserve(100);
	real.reserve(100);
	
	REQUIRE(own.capacity() == real.capacity());

	// try
	// {
	// 	own.reserve(own.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// try
	// {
	// 	real.reserve(real.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}



/*-----------------Element Access-----------------*/
TEST_CASE("vector-operator[] function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real[i] = sum;
		own[i] = sum;
		sum += 1;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
	REQUIRE(own[3] == real[3]);
}

TEST_CASE("vector-at function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	REQUIRE(own.at(0) == real.at(0));
	REQUIRE(own.at(1) == real.at(1));
	REQUIRE(own.at(2) == real.at(2));
	REQUIRE(own.at(3) == real.at(3));
	// try
	// {
	// 	own.at(6);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// try
	// {
	// 	real.at(6);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

TEST_CASE("vector-front function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	REQUIRE(own.front() == real.front());
}

TEST_CASE("vector-back function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	REQUIRE(own.back() == real.back());
}


/*-----------------Modifiers-----------------*/

TEST_CASE("vector-assign fucntion with itarators", "[vector]")
{
	ft::vector<int>		own1(5, 100);
	ft::vector<int>		own2;
	std::vector<int>	real1(5, 100);
	std::vector<int>	real2;

	own2.assign(own1.begin(), own1.begin() + 3);
	real2.assign(real1.begin(), real1.begin() + 3);

	ft::vector<int>::iterator own_it = own2.begin();
	std::vector<int>::iterator real_it = real2.begin();

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.capacity() == real2.capacity());
	while (own_it != own2.end())
	{
		REQUIRE(*own_it == *real_it);
		++own_it;
		++real_it;
	}
}

TEST_CASE("vector-assign function with n and val", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	own.assign(20, 20);
	real.assign(20 , 20);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
	REQUIRE(own.at(3) == real.at(3));
	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-push_back function", "[vector]")
{
	int sum = 10;
	ft::vector<int>		own;
	std::vector<int>	real;
	
	for(int i = 0; i < 4; ++i)
	{	
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-pop_back function", "[vector]")
{
	int sum = 10;
	ft::vector<int>		own;
	std::vector<int>	real;
	
	for(int i = 0; i < 4; ++i)
	{	
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own.size() == real.size());
	own.pop_back();
	real.pop_back();
	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-insert function", "[vector]")
{
	ft::vector<int>		own(6, 100);
	std::vector<int>	real(6, 100);
	
	ft::vector<int>::iterator	it_own = own.begin();
	std::vector<int>::iterator	it_real = real.begin();

	it_own = own.insert(it_own, 200);
	it_real = real.insert(it_real, 200);
	//  200 100 100 100 100 100 100
	//  ^
	REQUIRE(*it_own == *it_real);
	
	own.insert(it_own, 2, 300);
	real.insert(it_real, 2, 300);
	// 300 300 200 100 100 100 100 100 100
	// ^   ^
	
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);

	ft::vector<int> 	own1(2, 400);
	std::vector<int>	real2(2, 400);

	it_own = own.begin();
	it_real = real.begin();

	own.insert(it_own + 2, own1.begin(), own1.end());
	real.insert(it_real + 2, real2.begin(), real2.end());
	// 300 300 400 400 200 100 100 100 100 100 100
	//         ^   ^
	REQUIRE(own[2] == real[2]);
	REQUIRE(own[3] == real[3]);
	
	int myarray[] = {101, 102, 103};

	it_own = ft::vector<int>::iterator(myarray);

	own.insert(own.begin(), it_own, it_own + 3);
	real.insert(real.begin(), myarray, myarray + 3);
	// 101 102 103 300 300 400 400 200 100 100 100 100 100 100
	// ^   ^   ^
	
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
	REQUIRE(own.size() == real.size());
	
}
TEST_CASE("vector-erase function", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;
	int sum = 0;
	
	ft::vector<int>::iterator	it_own;
	std::vector<int>::iterator	it_real;
	for (int i = 0; i < 10; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 1;
	}
	//  0 1 2 3 4 5 6 7 8 9
	
	it_own = own.erase(own.begin() + 4);
	it_real = real.erase(real.begin() + 4);
	// 0 1 2 3 5 6 7 8 9
	//         ^
	
	REQUIRE(own[4] == real[4]);
	REQUIRE(*it_own == *it_real);
	
	it_own = own.erase(own.begin(), own.end() - 4);
	it_real = real.erase(real.begin(), real.end() - 4);
	// 6 7 8 9
	// ^
	
	REQUIRE(own[0] == real[0]);
	REQUIRE(*it_own == *it_real);
	
}
TEST_CASE("vector-swap function", "[vector]")
{
	ft::vector<int> 	own(4, 100);
	ft::vector<int> 	own2(5, 300);
	std::vector<int> 	real(4, 100);
	std::vector<int>	real2(5, 300);
	
	own.swap(own2);
	real.swap(real2);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.capacity() == real.capacity());
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-clear function", "[vector]")
{
	ft::vector<int>		own(10, 100);
	std::vector<int>	real(10, 100);

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-get_allocator function", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	int *p_own;
	int *p_real;
	bool own_return = false;
	bool real_return = false;
	unsigned int i_own;
	unsigned int i_real;

	// allocate an array with space for 5 elements using vector's allocator:
  	p_own = own.get_allocator().allocate(5);
  	p_real = real.get_allocator().allocate(5);

	if (!p_own)
		own_return = false;
	else
		own_return = true;

	if (!p_real)
		real_return = false;
	else
		real_return = true;
		
	REQUIRE(own_return == real_return);

  	// construct values in-place on the array:
  	for (i_own = 0; i_own < 5; i_own++) own.get_allocator().construct(&p_own[i_own],i_own);
  	for (i_real = 0; i_real < 5; i_real++) real.get_allocator().construct(&p_real[i_real],i_real);

	REQUIRE(p_own[0] == p_real[0]);
	REQUIRE(p_own[1] == p_real[1]);
	REQUIRE(p_own[2] == p_real[2]);
	REQUIRE(p_own[3] == p_real[3]);

  	// destroy and deallocate:
	for (i_own = 0; i_own < 3; i_own++) own.get_allocator().destroy(&p_own[i_own]);
	for (i_real = 0; i_real < 3; i_real++) own.get_allocator().destroy(&p_own[i_real]);
	
	REQUIRE(p_own[0] == p_real[0]);
	REQUIRE(p_own[1] == p_real[1]);
	
	own.get_allocator().deallocate(p_own,5);
	real.get_allocator().deallocate(p_real,5);
	
	if (!p_own)
		own_return = false;
	else
		own_return = true;

	if (!p_real)
		real_return = false;
	else
		real_return = true;
		
	REQUIRE(own_return == real_return);
}

/*-----------------Relational Operators-----------------*/
TEST_CASE("vector-operation overloaders", "[vector]")
{
	ft::vector<int> 	own(4, 200);
	ft::vector<int> 	own2(4, 100);
	ft::vector<int> 	own3(4, 200);
	std::vector<int>	real(4, 200);
	std::vector<int>	real2(4, 100);
	std::vector<int>	real3(4, 200);


	REQUIRE((own == own3) == true);
	REQUIRE((own == own2) == false);
	REQUIRE((real == real3) == true);
	REQUIRE((real == real2) == false);
	
	REQUIRE((own != own3) == false);
	REQUIRE((own != own2) == true);
	REQUIRE((real != real3) == false);
	REQUIRE((real != real2) == true);
	
	REQUIRE((own < own2) == false);
	REQUIRE((own2 < own3) == true);
	REQUIRE((real < real2) == false);
	REQUIRE((real2 < real3) == true);

	REQUIRE((own < own3) == false);
	REQUIRE((own <= own3) == true);
	REQUIRE((real < real3) == false);
	REQUIRE((real <= real3) == true);

	REQUIRE((own > own2) == true);
	REQUIRE((own2 > own3) == false);
	REQUIRE((real > real2) == true);
	REQUIRE((real2 > real3) == false);

	REQUIRE((own > own3) == false);
	REQUIRE((own >= own3) == true);
	REQUIRE((real > real3) == false);
	REQUIRE((real >= real3) == true);
}
