/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:10:37 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/08 14:19:27 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "predifine.hpp"

static void	example1()
{
	/* Example 1 */
	/* Example for constructor without parametrs */
	/* Example for size and capacity with int */
	/* Example for push_back */

	NAMESPACE::vector<int>	vec;
	std::cout << "Example 1" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(42);
	std::cout << ", push_back[42] value[0]: " << vec[0];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(84);
	std::cout << ", push_back[84] value[1]: " << vec[1];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(168);
	std::cout << ", push_back[168] value[2]: " << vec.at(2);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(336);
	vec.push_back(672);
	std::cout << ", push_back[336],[672] value[3]: " << vec.at(3);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size() << '.';
	std::cout << std::endl;

}

static void	example2()
{
	/* Example 2 */
	/* Example for constructor with 2 parametrs with double */
	/* Example for operator[] */

	NAMESPACE::vector<double> vec(3, double(58));
	std::cout << "Example 2" << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[2]: " << vec[2] << '.';
	std::cout << std::endl;
}

static void	example3()
{
	/* Example 3 */
	/* Example for const operator[] and for function at() with float */

	const NAMESPACE::vector<float> vec(10, float(-60));
	std::cout << "Example 3" << std::endl;
	std::cout << "NAMESPACE::vector -> at(3): " << vec.at(3);
	try
	{
		std::cout << ", at(13): " << vec.at(13) << '.';
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << '.';
	}
	std::cout << std::endl;

}

static void	example4()
{
	/* Example 4 */
	/* Example for front() and back() functions */

	const NAMESPACE::vector<int> vec(3, int(58));
	std::cout << "Example 4" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[0]: " << vec[0];
	std::cout << ", front(): " << vec.front();
	std::cout << ", value[2]: " << vec[0];
	std::cout << ", back(): " << vec.back() << '.';
	std::cout << std::endl;

}

static void	example5()
{
	/* Example 5 */
	/* Example for data() */

	int	*p;

	NAMESPACE::vector<int> vec(5, int(41));
	std::cout << "Example 5" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	p = vec.data();
	std::cout << ", p[0]: " << p[0] << '.';
	std::cout << std::endl;

}

static void	example6()
{
	/* Example 6 */
	/* Example for max_size() and get_allocator() */

	long double	*p;

	NAMESPACE::vector<long double> vec(5, (long double)(41));
	std::cout << "Example 6" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", max_size: " << vec.max_size();

	p = vec.get_allocator().allocate(3);
	for (int i = 0; i < 3; ++i)
		vec.get_allocator().construct(&p[i], i);
	std::cout << ", allocated array:";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << ' ' << p[i];
		vec.get_allocator().destroy(&p[i]);
	}
	vec.get_allocator().deallocate(p, 3);

	std::cout << '.' << std::endl;

}

static void	example7()
{
	/* Example 7 */
	/* Example for push_back() and pop_back() */
	/* Example for clear() function */
	/* Example for empty() function */

	NAMESPACE::vector<int> vec(5, (int)(42));
	std::cout << "Example 7" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	vec.pop_back();
	vec.pop_back();
	std::cout << ", is_empty: " << vec.empty();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.clear();
	std::cout << ", after clear capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", is_empty: " << vec.empty();
	std::cout << '.' << std::endl;

}

static void	example8()
{
	/* Example 8 */
	/* Example for iterators */

	NAMESPACE::vector<int> vec;
	NAMESPACE::vector<int>::iterator	it;
	std::cout << "Example 8" << std::endl;
	std::cout << "NAMESPACE::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.begin();
	std::cout << ", it_begin: " << *it;
	it = vec.begin() + 1;
	std::cout << ", it_begin + 1: " << *it;
	it += 1;
	std::cout << ", it += 1: " << *it;
	std::cout << ", it++: " << *(it++);
	std::cout << ", ++it: " << *(++it);
	it = vec.end() - 1;
	std::cout << ", it_end - 1: " << *it;
	it -= 2;
	std::cout << ", it -= 2: " << *it;
	it += 1;
	std::cout << ", it += 1: " << *it;
	std::cout << ", it[-1]: " << it[-1];
	std::cout << '.' << std::endl;

}

static void	example9()
{
	/* Example 9 */
	/* Example for iterators comparison */

	NAMESPACE::vector<int> vec;
	NAMESPACE::vector<int>::iterator	it1;
	NAMESPACE::vector<int>::iterator	it2;
	std::cout << "Example 9" << std::endl;
	std::cout << "NAMESPACE::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it1 = vec.begin();
	it2 = vec.begin() + 2;
	std::cout << ", it2 - it1: " << (it2 - it1);
	std::cout << ", it2 > it1: " << (it2 > it1);
	std::cout << ", it2 < it1: " << (it2 < it1);
	std::cout << ", it2 >= it1: " << (it2 >= it1);
	std::cout << ", it2 <= it1: " << (it2 <= it1);
	std::cout << ", it2 == it1: " << (it2 == it1);
	std::cout << ", it2 != it1: " << (it2 != it1);
	it1 = it2;
	std::cout << ", it2 >= it1: " << (it2 >= it1);
	std::cout << ", it2 <= it1: " << (it2 <= it1);
	std::cout << ", it2 == it1: " << (it2 == it1);
	std::cout << ", it2 != it1: " << (it2 != it1);
	std::cout << '.' << std::endl;

}

static void	example10()
{
	/* Example 10 */
	/* Example for const iterators comparison */

	NAMESPACE::vector< int> vec;
	std::cout << "Example 10" << std::endl;
	std::cout << "NAMESPACE::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<int>::const_iterator	it1 = vec.begin();
	NAMESPACE::vector<int>::const_iterator	it2 = vec.begin() + 2;
	std::cout << ", it2 - it1: " << (it2 - it1);
	std::cout << ", it2 > it1: " << (it2 > it1);
	std::cout << ", it2 < it1: " << (it2 < it1);
	std::cout << ", it2 >= it1: " << (it2 >= it1);
	std::cout << ", it2 <= it1: " << (it2 <= it1);
	std::cout << ", it2 == it1: " << (it2 == it1);
	std::cout << ", it2 != it1: " << (it2 != it1);
	NAMESPACE::vector<int>::const_iterator	it3 = vec.begin() + 2;
	NAMESPACE::vector<int>::const_iterator	it4 = vec.begin() + 2;
	std::cout << ", it2 >= it1: " << (it4 >= it3);
	std::cout << ", it2 <= it1: " << (it4 <= it3);
	std::cout << ", it2 == it1: " << (it4 == it3);
	std::cout << ", it2 != it1: " << (it4 != it3);
	std::cout << '.' << std::endl;

}

static void	example11()
{
	/* Example 11 */
	/* Example for const and non-const iterators comparison */

	NAMESPACE::vector<int> vec;
	std::cout << "Example 11" << std::endl;
	std::cout << "NAMESPACE::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<const int>::iterator	it1 = vec.begin();
	NAMESPACE::vector<int>::iterator	it2 = vec.begin() + 2;
	std::cout << ", it2 - it1: " << (it2 - it1);
	std::cout << ", it2 > it1: " << (it2 > it1);
	std::cout << ", it2 < it1: " << (it2 < it1);
	std::cout << ", it2 >= it1: " << (it2 >= it1);
	std::cout << ", it2 <= it1: " << (it2 <= it1);
	std::cout << ", it2 == it1: " << (it2 == it1);
	std::cout << ", it2 != it1: " << (it2 != it1);
	NAMESPACE::vector<const int>::iterator	it3 = vec.begin() + 2;
	NAMESPACE::vector<int>::iterator	it4 = vec.begin() + 2;
	std::cout << ", it2 >= it1: " << (it4 >= it3);
	std::cout << ", it2 <= it1: " << (it4 <= it3);
	std::cout << ", it2 == it1: " << (it4 == it3);
	std::cout << ", it2 != it1: " << (it4 != it3);
	std::cout << '.' << std::endl;

}

static void	example12()
{
	/* Example 12 */
	/* Example for copy constructors */

	NAMESPACE::vector<double> vec(2, double(58));
	std::cout << "Example 12" << std::endl;
	std::cout << std::fixed << std::setprecision(2) ;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", copy-constructor:";
	NAMESPACE::vector<double> vec2(vec);
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	vec.push_back(42);
	vec2 = vec;
	std::cout << ", copy-assignement:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	std::cout << '.' << std::endl;

}

static void	example13()
{
	/* Example 13 */
	/* Example for insert */

	NAMESPACE::vector<int> vec(5, int(58));
	std::cout << "Example 13" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	NAMESPACE::vector<int>::iterator it = vec.begin() + 2;
	vec.insert(it, 3, 50);
	vec.insert(vec.begin(), 1, 1);
	vec.insert(vec.begin(), 0, 2);
	vec.insert(vec.end(), 3, 2);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.reserve(30);
	it = vec.begin() + 2;
	vec.insert(it, 3, -50);
	vec.insert(vec.begin(), 0, -2);
	vec.insert(vec.end(), 3, -2);
	vec.insert(vec.begin(), 1, -1);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << '.' << std::endl;

}

static void	example14()
{
	/* Example 14 */
	/* Example for insert part 2 */

	NAMESPACE::vector<int> vec(5, int(58));
	std::cout << "Example 14" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	NAMESPACE::vector<int>::iterator it = vec.begin() + 2;
	vec.insert(it, 1);
	it = vec.insert(vec.begin(), 1);
	vec.insert(vec.end(), 1);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", it: " << *it;
	vec.reserve(30);
	it = vec.begin() + 2;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	NAMESPACE::vector<int> vec5;
	vec5.insert(vec5.begin(), 9);
	vec5.insert(vec5.end() - 1, 3, 10);
	std::cout << ", values:";
	for (size_t i = 0; i < vec5.size(); ++i)
		std::cout << ' ' << vec5[i];
	std::cout << ", capacity: " << vec5.capacity();
	std::cout << ", size: " << vec5.size();
	std::cout << '.' << std::endl;

}

static void	example15()
{
	/* Example 15 */
	/* Example for insert */

	NAMESPACE::vector<int> vec(5, int(58));
	std::cout << "Example 15" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	NAMESPACE::vector<int> vec1(2, int(42));
	vec.insert(vec.begin() + 2, vec1.begin(), vec1.end());
	vec.insert(vec.begin(), vec1.begin(), vec1.end());
	vec.insert(vec.end(), vec1.begin(), vec1.end());
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.reserve(30);
	NAMESPACE::vector<int> vec2(2, int(21));
	vec.insert(vec.begin() + 2, vec2.begin(), vec2.end());
	vec.insert(vec.begin(), vec2.begin(), vec2.end());
	vec.insert(vec.end(), vec2.begin(), vec2.end());
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << '.' << std::endl;

}

static void	example16()
{
	/* Example 16 */
	/* Example for erase */

	NAMESPACE::vector<int> vec;
	std::cout << "Example 16" << std::endl;
	for (size_t i = 0; i < 9; ++i)
		vec.push_back(i);
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<int>::iterator it;
	it = vec.erase(vec.begin() + 1);
	std::cout << ", it: " << *it;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.erase(vec.begin() + 2, vec.end() - 2);
	std::cout << ", it: " << *it;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.erase(vec.begin(), vec.begin() + 1);
	std::cout << ", it: " << *it;
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.erase(vec.begin(), vec.begin());
	std::cout << ", it: " << *it;
	it = vec.erase(vec.end() - 2, vec.end() - 1);
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", it: " << *it;
	it = vec.erase(vec.begin(), vec.end());
	std::cout << ", it: " << *it;
	std::cout << ", NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << std::endl;

}

static void	example17()
{
	/* Example 17 */
	/* Example for resize */

	NAMESPACE::vector<int> vec(5, int(42));
	std::cout << "Example 17" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.resize(7);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.resize(11, 21);
	vec.resize(11);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.resize(6);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << std::endl;

}

static void	example18()
{
	/* Example 18 */
	/* Example for assign */

	NAMESPACE::vector<int> vec(5, int(42));
	std::cout << "Example 18" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(11, 48);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(3, 21);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(0, 2);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << std::endl;

}

static void	example19()
{
	/* Example 19 */
	/* Example for assign part 2 */

	NAMESPACE::vector<int> vec(5, int(42));
	std::cout << "Example 19" << std::endl;
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<int> vec2(2, int(21));
	vec.assign(vec2.begin(), vec2.end());
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec2.assign(11, 42);
	vec.assign(vec2.begin(), vec2.end());
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.assign(vec2.begin(), vec2.begin());
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '.' << std::endl;

}

static void	example20()
{
	/* Example 20 */
	/* Example for swaps */

	NAMESPACE::vector<int> vec(3, int(42));
	std::cout << "Example 20" << std::endl;
	std::cout << "std::vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<int> vec2(9, int(21));
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	vec.swap(vec2);
	std::cout << ", vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	std::cout << '.' << std::endl;

}

static void	example21()
{
	/* Example 21 */
	/* Example for swaps part 2 */

	NAMESPACE::vector<int> vec(3, int(42));
	std::cout << "Example 21" << std::endl;
	std::cout << "std::vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<int> vec2(9, int(21));
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	swap(vec, vec2);
	std::cout << ", vector1 -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << ", vector2 capacity: " << vec2.capacity();
	std::cout << ", size: " << vec2.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << ' ' << vec2[i];
	std::cout << '.' << std::endl;

}

static void	example22()
{
	/* Example 22 */
	/* Example for relational operators */

	NAMESPACE::vector<char> vec1;
	NAMESPACE::vector<char> vec2;
	std::cout << "Example 22" << std::endl;
	vec1.push_back('h');
	vec1.push_back('e');
	vec1.push_back('l');
	vec1.push_back('l');
	vec1.push_back('o');
	vec2.push_back('h');
	vec2.push_back('e');
	vec2.push_back('l');
	vec2.push_back('l');
	vec2.push_back('o');
	std::cout << "NAMESPACE::vector -> ";
	std::cout << "values1: ";
	for (size_t i = 0; i < vec1.size(); ++i)
		std::cout << vec1[i];
	std::cout << ", values2: ";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << vec2[i];
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	vec2.push_back('o');
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	vec1.push_back('o');
	vec1.push_back('o');
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	vec1.pop_back();
	vec1.erase(vec1.begin() + 1);
	vec1.insert(vec1.begin() + 1, 'E');
	std::cout << ", values1: ";
	for (size_t i = 0; i < vec1.size(); ++i)
		std::cout << vec1[i];
	std::cout << ", values2: ";
	for (size_t i = 0; i < vec2.size(); ++i)
		std::cout << vec2[i];
	std::cout << ", == " << (vec1 == vec2);
	std::cout << ", != " << (vec1 != vec2);
	std::cout << ", < " << (vec1 < vec2);
	std::cout << ", <= " << (vec1 <= vec2);
	std::cout << ", > " << (vec1 > vec2);
	std::cout << ", >= " << (vec1 >= vec2);
	std::cout << '.' << std::endl;

}

static void	example23()
{
	/* Example 23 */
	/* Example for reverse iterator */

	NAMESPACE::vector<int> vec;
	std::cout << "Example 23" << std::endl;
	for (size_t i = 0; i < 5; ++i)
		vec.push_back(i);
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<int>::reverse_iterator	rit(vec.end());
	std::cout << ", it: " << *rit;
	std::cout << ", it: " << *(rit++);
	std::cout << ", it: " << *(++rit);
	std::cout << ", it: " << *(rit--);
	std::cout << ", it: " << *(--rit);
	NAMESPACE::vector<int>::reverse_iterator	rit2(vec.begin() + 1);
	std::cout << ", it: " << *rit2;
	std::cout << ", it: " << *(rit2 - 1);
	rit2 -= 2;
	std::cout << ", it: " << *rit2;
	std::cout << ", it: " << *(rit2 + 1);
	rit2 += 1;
	std::cout << ", it: " << *rit2;
	NAMESPACE::vector<int>::reverse_iterator	rit3;
	rit3 = rit2;
	std::cout << ", it: " << *rit3;
	rit3 = rit3 - 2;
	std::cout << ", it: " << *(rit3.base());
	std::cout << ", it: " << rit3[1];
	std::cout << ", it: " << rit3[3];
	NAMESPACE::vector<int>::reverse_iterator	rit4(rit3);
	std::cout << ", it: " << *rit4;
	std::cout << '.' << std::endl;

}

static void	example24()
{
	/* Example 24 */
	/* Example for rbegin, rend */

	NAMESPACE::vector<int> vec;
	std::cout << "Example 24" << std::endl;
	for (size_t i = 0; i < 5; ++i)
		vec.push_back(i);
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	NAMESPACE::vector<int>::reverse_iterator	rit1;
	rit1 = vec.rbegin();
	std::cout << ", it: " << *rit1;
	rit1 = vec.rend() - 1;
	std::cout << ", it: " << *rit1;
	NAMESPACE::vector<int>::reverse_iterator	rit2(rit1);
	std::cout << ", it: " << *(rit2 - 1);
	NAMESPACE::vector<int>::const_reverse_iterator	rit3 = rit2;
	std::cout << ", it: " << *rit3;
	std::cout << ", == " << (rit3 == rit2);
	std::cout << ", != " << (rit3 != rit2);
	std::cout << ", < " << (rit3 < rit2);
	std::cout << ", <= " << (rit3 <= rit2);
	std::cout << ", > " << (rit3 > rit2);
	std::cout << ", >= " << (rit3 >= rit2);
	rit3 = rit2 - 1;
	std::cout << ", == " << (rit3 == rit2);
	std::cout << ", != " << (rit3 != rit2);
	std::cout << ", < " << (rit3 < rit2);
	std::cout << ", <= " << (rit3 <= rit2);
	std::cout << ", > " << (rit3 > rit2);
	std::cout << ", >= " << (rit3 >= rit2);
	std::cout << ", + " << *(1 + rit3);
	rit2 += 3;
	rit3 += 3;
	std::cout << ", - " << (rit2 - rit1);
	std::cout << ", - " << (rit3 - rit2);
	std::cout << '.' << std::endl;

}

struct	A
{
	A* operator &() const
	{
		std::cout << "error ";
		return (0);
	}
};

static void	example25()
{
	/* Example 25 */
	/* Example for & and address */

	NAMESPACE::vector<A> vec;
	std::cout << "Example 25" << std::endl;
	for (size_t i = 0; i < 5; ++i)
		vec.push_back(A());
	vec.reserve(20);
	std::cout << "NAMESPACE::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", values:";
	std::cout << '.' << std::endl;

}

static void	example26()
{
	/* Example 26 */
	/* Example tests for insert2 */

	const int cut = 3;
	std::cout << "Example 26" << std::endl;
	NAMESPACE::vector<int> vct(5);
	NAMESPACE::vector<int> vct2;
	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	std::cout << "NAMESPACE::vector ->";
	std::cout << " values:";
	for (unsigned long int i = 0; i < vct.size(); ++i)
		std::cout << " " << vct[i];

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	std::cout << ", " << *vct2.insert(vct2.end(), 42) << ", ";
	std::cout << *vct2.insert(vct2.begin() + 5, 84);
	std::cout << ", values:";
	for (unsigned long int i = 0; i < vct2.size(); ++i)
		std::cout << " " << vct2[i];
	std::cout << '.' << std::endl;

}

static void	example27()
{
	/* Example 27 */
	/* Example tests for copy-constructor */

	std::cout << "Example 27" << std::endl;
	std::cout << "NAMESPACE::vector ->";
	NAMESPACE::vector<int> vct(5);
	NAMESPACE::vector<int>::iterator	it = vct.begin();
	NAMESPACE::vector<int>::iterator	ite = vct.end();
	std::cout << " len: " << (ite - it);
	for (; it != ite; ++it)
		*it = (ite - it);
	it = vct.begin();
	NAMESPACE::vector<int> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;
	it = vct.begin();
	NAMESPACE::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);
	std::cout << ", vct_size: " << vct.size();
	std::cout << ", vct_range_size: " << vct_range.size();
	std::cout << ", vct_copy_size: " << vct_copy.size();
	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();
	it = vct.begin();
	std::cout << ", vct_values:";
	for (; it != vct.end(); ++it)
		std::cout << " " << *it;
	it = vct_range.begin();
	std::cout << ", vct_range_values:";
	for (; it != vct_range.end(); ++it)
		std::cout << " " << *it;
	it = vct_copy.begin();
	std::cout << ", vct_copy_values:";
	for (; it != vct_copy.end(); ++it)
		std::cout << " " << *it;
	std::cout << ", vct_size: " << vct.size();
	std::cout << ", vct_range_size: " << vct_range.size();
	std::cout << ", vct_copy_size: " << vct_copy.size();
	std::cout << '.' << std::endl;

}

static void	example28()
{
	/* Example 28 */
	/* Example tests insert(fill) */

	std::cout << "Example 28" << std::endl;
	std::cout << "NAMESPACE::vector ->";
	NAMESPACE::vector<int> vct;
	NAMESPACE::vector<int> v;
	vct.assign(1000, 1);
	vct.insert(vct.end() - 50, 42000000, 2);
	v.push_back(vct.size());
	v.push_back(vct.capacity());
	std::cout << " value:";
	for (NAMESPACE::vector<int>::iterator first = v.begin(); first != v.end(); ++first)
		std::cout << " " << *first;
	std::cout << '.' << std::endl;

}

void	vector_test()
{
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();
	example8();
	example9();
	example10();
	example11();
	example12();
	example13();
	example14();
	example15();
	example16();
	example17();
	example18();
	example19();
	example20();
	example21();
	example22();
	example23();
	example24();
	example25();
	example26();
	example27();
	example28();
}
