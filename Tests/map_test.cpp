/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:41:32 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/08 14:21:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "predifine.hpp"
#ifndef	MYCOLORS_HPP
# define MYCOLORS_HPP

# define COLOR_YELLOW_B "\033[1;33m"
# define COLOR_PURPLE_B "\033[1;35m"
# define COLOR_BLUE_B "\033[1;34m"
# define COLOR_GREEN_B "\033[1;32m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_RED_B "\033[1;31m"
# define COLOR_END "\033[0m"

static void	example1()
{
	/* Example 1 */
	/* Example for pair and make_pair */

	NAMESPACE::pair<int, std::string>	pair1;
	std::cout << COLOR_PURPLE_B << "Example 1" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::pair -> first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	pair1 = std::make_pair(1, "Nenie_Iri");
	std::cout << ", first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	NAMESPACE::pair<int, std::string>	pair2(2, "HI");
	std::cout << ", first: " << pair2.first;
	std::cout << ", second: " << pair2.second;
	NAMESPACE::pair<int, std::string>	pair3(pair1);
	std::cout << ", first: " << pair3.first;
	std::cout << ", second: " << pair3.second;
	std::cout << ", first: " << std::make_pair(4, 5).first;
	std::cout << ", second: " << std::make_pair(4, 5).second;
	NAMESPACE::pair<int, int>	pair4(1, 5);
	NAMESPACE::pair<int, int>	pair5(1, 4);
	std::cout << ", ==: " << (pair1 == pair2);
	std::cout << ", ==: " << (pair1 == pair3);
	std::cout << ", ==: " << (pair4 == pair5);
	std::cout << ", !=: " << (pair1 != pair2);
	std::cout << ", !=: " << (pair1 != pair3);
	std::cout << ", !=: " << (pair4 != pair5);
	std::cout << ", <: " << (pair1 < pair2);
	std::cout << ", <: " << (pair1 < pair3);
	std::cout << ", <: " << (pair4 < pair5);
	std::cout << ", <=: " << (pair1 <= pair2);
	std::cout << ", <=: " << (pair1 <= pair3);
	std::cout << ", <=: " << (pair4 <= pair5);
	std::cout << ", >: " << (pair1 > pair2);
	std::cout << ", >: " << (pair1 > pair3);
	std::cout << ", >: " << (pair4 > pair5);
	std::cout << ", >=: " << (pair1 >= pair2);
	std::cout << ", >=: " << (pair1 >= pair3);
	std::cout << ", >=: " << (pair4 >= pair5);
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example2()
{
	/* Example 2 */
	/* Example for map constructors, size, empty, max_size */
	/* Example for iterators */

	NAMESPACE::pair<int, std::string>	pair1;
	pair1.first = 0; 
	pair1.second = "A"; 
	NAMESPACE::map<int, std::string> A;
	NAMESPACE::map<int, std::string>::iterator it1;
	std::cout << COLOR_PURPLE_B << "Example 2" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::pair -> ";
	std::cout << "size: " << A.size();
	std::cout << ", empty: " << A.empty();
	std::cout << ", size: " << A.max_size();
	A.insert(pair1);
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(-1, "B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(1, "C"));
	std::cout << ", pair -> first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	std::cout << ", size: " << A.size();
	std::cout << ", size: " << A.max_size();
	std::cout << ", empty: " << A.empty();
	it1 = A.begin();
	std::cout << ", it: " << (*it1).first;
	std::cout << ", " << it1->first;
	std::cout << ", " << it1->second;
	std::cout << ", " << (it1++)->first;
	std::cout << ", " << (++it1)->first;
	std::cout << ", " << (--it1)->second;
	std::cout << ", " << (it1--)->second;
	std::cout << ", " << it1->second;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example3()
{
	/* Example 3 */
	/* Example for iterators */

	NAMESPACE::map<int, std::string> A;
	NAMESPACE::map<int, std::string>::iterator it1;
	NAMESPACE::map<int, std::string>::iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << COLOR_PURPLE_B << "Example 3" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example4()
{
	/* Example 4 */
	/* Example for const iterators */

	NAMESPACE::map<int, std::string> A;
	NAMESPACE::map<int, std::string>::const_iterator it1;
	NAMESPACE::map<int, std::string>::const_iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << COLOR_PURPLE_B << "Example 4" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	it1 = A.begin();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (--it2)->second;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example5()
{
	/* Example 5 */
	/* Example for iterators comparison */

	NAMESPACE::map<int, std::string>				tree;
	NAMESPACE::map<int, std::string>::iterator	it1;
	NAMESPACE::map<int, std::string>::iterator	it2;
	std::cout << COLOR_PURPLE_B << "Example 5" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	it1 = it2;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example6()
{
	/* Example 6 */
	/* Example for const iterators comparison */

	NAMESPACE::map<int, std::string>					tree;
	NAMESPACE::map<int, std::string>::const_iterator	it1;
	NAMESPACE::map<int, std::string>::const_iterator	it2;
	std::cout << COLOR_PURPLE_B << "Example 6" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	it1 = it2;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example7()
{
	/* Example 7 */
	/* Example for const and non-const iterators comparison */

	NAMESPACE::map<int, std::string>					tree;
	NAMESPACE::map<int, std::string>::iterator		it1;
	NAMESPACE::map<int, std::string>::const_iterator	it2;
	std::cout << COLOR_PURPLE_B << "Example 7" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example8()
{
	/* Example 8 */
	/* Example for other compare function */

	NAMESPACE::map<int, std::string, std::greater<int> > A;
	NAMESPACE::map<int, std::string, std::greater<int> >::iterator it1;
	NAMESPACE::map<int, std::string, std::greater<int> >::iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << COLOR_PURPLE_B << "Example 8" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << " size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example9()
{
	/* Example 9 */
	/* Example for reverse iterator */

	NAMESPACE::map<int, std::string>						A;
	NAMESPACE::map<int, std::string>::reverse_iterator	it1;
	NAMESPACE::map<int, std::string>::reverse_iterator	it2;
	it1 = A.rbegin();
	it2 = A.rend();
	std::cout << COLOR_PURPLE_B << "Example 9" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	it1 = A.rbegin();
	it2 = A.rend();
	std::cout << " it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.rend();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example10()
{
	/* Example 10 */
	/* Example for key and value compare */

	std::cout << COLOR_PURPLE_B << "Example 10" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<char, int>	A;
	A.insert(std::make_pair('x', 1001));
	A.insert(std::make_pair('y', 2002));
	A.insert(std::make_pair('z', 3003));
	NAMESPACE::pair<char, int> highest = *(A.rbegin());
	NAMESPACE::map<char, int>::iterator	it = A.begin();
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map ->";
	do
	{
		std::cout << " " << it->first << " => " << it->second;
	} while (A.value_comp()(*it++, highest));
	NAMESPACE::map<char, int>::value_compare	cmp = A.value_comp();
	std::cout << " " << cmp(*A.begin(), *A.begin());
	std::cout << " " << cmp(*A.begin(), *(++A.begin()));
	NAMESPACE::map<char, int>::key_compare	key_cmp = A.key_comp();
	std::cout << " " << key_cmp('a', 'b');
	std::cout << " " << key_cmp('a', 'a');
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example11()
{
	/* Example 11 */
	/* Example for get_allocator */

	std::cout << COLOR_PURPLE_B << "Example 11" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<char, int>			A;
	NAMESPACE::pair<const char, int>	*p;
	p = A.get_allocator().allocate(42);
	A.get_allocator().deallocate(p, 42);
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example12()
{
	/* Example 12 */
	/* Example for find */

	std::cout << COLOR_PURPLE_B << "Example 12" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<char, int>	A;
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('b', -2));
	A.insert(std::make_pair('f', 2));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('e', 1));
	A.insert(std::make_pair('a', -3));
	A.insert(std::make_pair('j', 3));
	std::cout << "NAMESPACE::map -> ";
	std::cout << "find: " << A.find('e')->first;
	NAMESPACE::map<char, int>::const_iterator	it1 = A.find('a');
	NAMESPACE::map<char, int>::const_iterator	it2 = A.find('o');
	while (it1 != it2)
		std::cout << " " << (it1++)->first;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example13()
{
	/* Example 13 */
	/* Example for count */

	std::cout << COLOR_PURPLE_B << "Example 13" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<char, int>	A;
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('b', -2));
	A.insert(std::make_pair('f', 2));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('e', 1));
	A.insert(std::make_pair('g', 3));
	std::cout << "NAMESPACE::map -> ";
	std::cout << "count:";
	for (char c = 'a'; c < 'k'; ++c)
		std::cout << " " << A.count(c);
	A.clear();
	std::cout << ", size " << A.size();
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example14()
{
	/* Example 14 */
	/* Example for bounds */

	std::cout << COLOR_PURPLE_B << "Example 14" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<char, int>	A;
	A.insert(std::make_pair('d', 0));
	A.insert(std::make_pair('b', -2));
	A.insert(std::make_pair('f', 2));
	A.insert(std::make_pair('c', -1));
	A.insert(std::make_pair('e', 1));
	A.insert(std::make_pair('a', -3));
	A.insert(std::make_pair('g', 3));
	std::cout << "NAMESPACE::map -> ";
	NAMESPACE::map<char, int>::iterator	itlow;
	NAMESPACE::map<char, int>::iterator	itup;
	itlow = A.lower_bound('c');
	itup = A.lower_bound('e');
	std::cout << "bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.lower_bound('0');
	itup = A.lower_bound('e');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.lower_bound('c');
	itup = A.lower_bound('x');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.upper_bound('c');
	itup = A.upper_bound('e');
	std::cout << ", upper_bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.upper_bound('0');
	itup = A.upper_bound('e');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.upper_bound('c');
	itup = A.upper_bound('x');
	std::cout << ", bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	itlow = A.lower_bound('b');
	itup = A.upper_bound('d');
	std::cout << ", up_low_bound:";
	for (; itlow != itup; ++itlow)
		std::cout << " " << itlow->first;
	A.clear();
	std::cout << ", size " << A.size();
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example15()
{
	/* Example 15 */
	/* Example for inserts */

	std::cout << COLOR_PURPLE_B << "Example 15" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<int, int>	A;
	A.insert(std::make_pair(4, 0));
	A.insert(std::make_pair(2, -2));
	A.insert(std::make_pair(6, 2));
	A.insert(std::make_pair(3, -1));
	A.insert(std::make_pair(5, 1));
	A.insert(std::make_pair(1, -3));
	std::cout << "NAMESPACE::map -> ";
	std::cout << " size " << A.size();
	NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, bool>	res;
	res = A.insert(std::make_pair(7, 3));
	std::cout << ", bool " << res.second;
	std::cout << ", val " << res.first->second;
	std::cout << ", size " << A.size();
	res = A.insert(NAMESPACE::pair<int, int>(6, 8));
	std::cout << ", bool " << res.second;
	std::cout << ", val " << res.first->second;
	std::cout << ", size " << A.size();
	NAMESPACE::map<int, int>	B;
	B.insert(NAMESPACE::pair<int, int>(1, 100));
	B.insert(NAMESPACE::pair<int, int>(-1, -100));
	B.insert(NAMESPACE::pair<int, int>(2, 200));
	NAMESPACE::map<int, int>::iterator	it5;
	it5 = B.insert(B.begin(), NAMESPACE::pair<int, int>(3, 300));
	std::cout << ", res " << it5->first;
	it5 = B.insert(B.begin(), NAMESPACE::pair<int, int>(3, 300));
	std::cout << ", res " << it5->first;
	it5 = B.insert(B.end(), NAMESPACE::pair<int, int>(-30, -3000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(B.end(), NAMESPACE::pair<int, int>(-30, -3000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--B.end(), NAMESPACE::pair<int, int>(-2, -200));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--B.end(), NAMESPACE::pair<int, int>(-2, -200));
	std::cout << ", res " << it5->first;
	it5 = B.insert(++(++B.begin()), NAMESPACE::pair<int, int>(-8, -800));
	std::cout << ", res " << it5->first;
	it5 = B.insert(++(++B.begin()), NAMESPACE::pair<int, int>(-8, -800));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--(--(--B.end())), NAMESPACE::pair<int, int>(1000, 100000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--(--(--B.end())), NAMESPACE::pair<int, int>(1000, 100000));
	std::cout << ", res " << it5->first;
	it5 = B.insert(--(--(--B.end())), NAMESPACE::pair<int, int>(1000, 100000));
	std::cout << ", res " << it5->first << ",";
	for (NAMESPACE::map<int, int>::iterator it = B.begin(); it != B.end(); ++it)
		std::cout << " " << it->second;
	std::cout << ", size " << B.size();
	NAMESPACE::map<int, int>::iterator it10 = A.begin();
	NAMESPACE::map<int, int>::iterator it11 = A.end();
	B.insert(it10, it11);
	std::cout << ", insert_iters";
	for (NAMESPACE::map<int, int>::iterator it = B.begin(); it != B.end(); ++it)
		std::cout << " " << it->second;
	std::cout << ", size " << B.size();
	B.clear();
	std::cout << ", size " << B.size();
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example16()
{
	/* Example 16 */
	/* Example for erase */

	std::cout << COLOR_PURPLE_B << "Example 16" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	A.insert(std::make_pair(-1, -1));
	A.insert(std::make_pair(1, 1));
	A.insert(std::make_pair(-3, -3));
	A.insert(std::make_pair(3, 3));
	A.insert(std::make_pair(-4, -4));
	A.insert(std::make_pair(4, 4));
	std::cout << "NAMESPACE::map -> ";
	std::cout << "size: " << A.size() << ", before_erase:";
	for (NAMESPACE::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	NAMESPACE::map<int, int>::iterator	it1;
	NAMESPACE::map<int, int>::iterator	it2;
	it1 = A.find(-1);
	it2 = A.find(1);
	A.erase(it1, it2);
	std::cout << ", after_erase:";
	for (NAMESPACE::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << A.size() << ", after_erase:";
	A.erase(A.find(-2));
	A.erase(A.find(2));
	for (NAMESPACE::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << A.size() << ", after_erase:";
	A.erase(A.find(-3));
	A.erase(A.find(4));
	for (NAMESPACE::map<int, int>::iterator first = A.begin(); first != A.end(); ++first)
		std::cout << " " << first->second;
	std::cout << ", size: " << A.size();
	A.clear();
	std::cout << ", size: " << A.size();
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example17()
{
	/* Example 17 */
	/* Example for equal_range and constructors*/

	std::cout << COLOR_PURPLE_B << "Example 17" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	A.insert(std::make_pair(-1, -1));
	A.insert(std::make_pair(1, 1));
	A.insert(std::make_pair(-3, -3));
	A.insert(std::make_pair(3, 3));
	A.insert(std::make_pair(-4, -4));
	A.insert(std::make_pair(4, 4));
	NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, NAMESPACE::map<int, int>::iterator>	p;
	p = A.equal_range(-1);
	std::cout << "NAMESPACE::map -> ";
	std::cout << "lower " << p.first->first;
	std::cout << ", upper " << p.second->first;
	p = A.equal_range(-4);
	std::cout << ", lower " << p.first->first;
	std::cout << ", upper " << p.second->first;
	NAMESPACE::map<int, int>	B;
	B.insert(NAMESPACE::pair<int, int>(100, 10000));
	B.insert(NAMESPACE::pair<int, int>(-100, -10000));
	B.insert(NAMESPACE::pair<int, int>(200, 20000));
	NAMESPACE::map<int, int>::iterator	it5;
	it5 = B.insert(B.begin(), NAMESPACE::pair<int, int>(30, 3000));
	it5 = B.insert(B.end(), NAMESPACE::pair<int, int>(-300, -30000));
	std::cout << ", A:";
	for (NAMESPACE::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B:";
	for (NAMESPACE::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	A = B;
	std::cout << ", A_after=:";
	for (NAMESPACE::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	NAMESPACE::map<int, int>	C;
	C.insert(std::make_pair(0, 0));
	C.insert(std::make_pair(-2, -2));
	A = C;
	std::cout << ", A_after=:";
	for (NAMESPACE::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	NAMESPACE::map<int, int>	D(B.begin(), B.end());
	std::cout << ", D:";
	for (NAMESPACE::map<int, int>::iterator f = D.begin(); f != D.end(); ++f)
		std::cout << " " << f->second;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example18()
{
	/* Example 18 */
	/* Example for swap */

	std::cout << COLOR_PURPLE_B << "Example 18" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	A.insert(std::make_pair(-1, -1));
	A.insert(std::make_pair(1, 1));
	A.insert(std::make_pair(-3, -3));
	A.insert(std::make_pair(3, 3));
	NAMESPACE::map<int, int>	B;
	B.insert(NAMESPACE::pair<int, int>(100, 10000));
	B.insert(NAMESPACE::pair<int, int>(-100, -10000));
	B.insert(NAMESPACE::pair<int, int>(200, 20000));
	NAMESPACE::map<int, int>::iterator	it5;
	it5 = B.insert(B.begin(), NAMESPACE::pair<int, int>(30, 3000));
	it5 = B.insert(B.end(), NAMESPACE::pair<int, int>(-300, -30000));
	NAMESPACE::map<int, int>::iterator	it11 = A.begin();
	NAMESPACE::map<int, int>::iterator	it22 = B.begin();
	std::cout << "NAMESPACE::map -> ";
	std::cout << "A:";
	for (NAMESPACE::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << A.size();
	std::cout << ", B:";
	for (NAMESPACE::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << B.size();
	A.swap(B);
	std::cout << ", A_after=:";
	for (NAMESPACE::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << A.size();
	std::cout << ", B_after=:";
	for (NAMESPACE::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << B.size();
	std::cout << ", iter: " << (it11 == B.begin());
	std::cout << ", " << (it22 == A.begin());
	swap(A, B);
	std::cout << ", A_after=:";
	for (NAMESPACE::map<int, int>::iterator f = A.begin(); f != A.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", A_size: " << A.size();
	std::cout << ", B_after=:";
	for (NAMESPACE::map<int, int>::iterator f = B.begin(); f != B.end(); ++f)
		std::cout << " " << f->second;
	std::cout << ", B_size: " << B.size();
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example19()
{
	/* Example 19 */
	/* Example for comparison functions */

	std::cout << COLOR_PURPLE_B << "Example 19" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<int, int>	A;
	A.insert(std::make_pair(0, 0));
	A.insert(std::make_pair(-2, -2));
	A.insert(std::make_pair(2, 2));
	NAMESPACE::map<int, int>	B;
	B.insert(NAMESPACE::pair<int, int>(0, 0));
	B.insert(NAMESPACE::pair<int, int>(-100, -10000));
	B.insert(NAMESPACE::pair<int, int>(200, 20000));
	NAMESPACE::map<int, int>	C;
	C.insert(std::make_pair(0, 0));
	C.insert(std::make_pair(-2, -2));
	C.insert(std::make_pair(2, 2));
	NAMESPACE::map<int, int>	D;
	D.insert(NAMESPACE::pair<int, int>(0, 0));
	D.insert(NAMESPACE::pair<int, int>(-1, 1));
	D.insert(NAMESPACE::pair<int, int>(200, -20000));
	std::cout << "NAMESPACE::map -> ";
	std::cout << "==: " << (A == B);
	std::cout << ", ==: " << (A == C);
	std::cout << ", ==: " << (A == D);
	std::cout << ", !=: " << (A != B);
	std::cout << ", !=: " << (A != C);
	std::cout << ", !=: " << (A != D);
	std::cout << ", <: " << (A < B);
	std::cout << ", <: " << (A < C);
	std::cout << ", <: " << (A < D);
	std::cout << ", <=: " << (A <= B);
	std::cout << ", <=: " << (A <= C);
	std::cout << ", <=: " << (A <= D);
	std::cout << ", >: " << (A > B);
	std::cout << ", >: " << (A > C);
	std::cout << ", >: " << (A > D);
	std::cout << ", >=: " << (A >= B);
	std::cout << ", >=: " << (A >= C);
	std::cout << ", >=: " << (A >= D);
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example20()
{
	/* Example 20 */
	/* Example for operator[] and at() */

	std::cout << COLOR_PURPLE_B << "Example 20" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	NAMESPACE::map<char, char>	A;
	A['a'] = 'A';
	A['b'] = 'B';
	A['c'] = A['b'];
	std::cout << "NAMESPACE::map -> ";
	std::cout << "[a]=" << A['a'];
	std::cout << ", [b]=" << A['b'];
	std::cout << ", [c]=" << A['c'];
	std::cout << ", [d]=" << A['d'];
	A.at('a') = 'a';
	A.at('b') = 'b';
	A.at('c') = 'c';
	std::cout << ", at(a)=" << A.at('a');
	std::cout << ", at(b)=" << A.at('b');
	std::cout << ", at(c)=" << A.at('c');
	try
	{
		A.at('t');
	}
	catch (const std::exception &e)
	{
		std::cout << " " << e.what();
	}
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example21()
{
	/* Example 21 */
	/* Example from mli-tester about erase */

	unsigned int lst_size = 6;

	std::cout << COLOR_PURPLE_B << "Example 21" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::list<NAMESPACE::pair<const int, std::string> > lst;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::make_pair(i, std::string((lst_size - i), i + 65)));
	NAMESPACE::map<const int, std::string> mp(lst.begin(), lst.end());
	std::cout << "NAMESPACE::map -> ";
	std::cout << "size: " << mp.size();
	std::cout << ", value:";
	for (NAMESPACE::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	for (int i = 2; i < 4; ++i)
		mp.erase(i);
	std::cout << ", value:";
	for (NAMESPACE::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	mp.erase(mp.begin()->first);
	mp.erase((--mp.end())->first);
	std::cout << ", value:";
	for (NAMESPACE::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	mp[-1] = "Hello";
	mp[10] = "Hi there";
	mp[10] = "Hi there";
	std::cout << ", size: " << mp.size();
	mp.erase(0);
	mp.erase(1);
	std::cout << ", value:";
	for (NAMESPACE::map<const int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << " " << it->first;
	std::cout << '.' << COLOR_END << std::endl;

}

static void	example22()
{
	/* Example 22 */
	/* Example from bounds */

	std::cout << COLOR_PURPLE_B << "Example 22" << COLOR_END << std::endl;
	std::cout << COLOR_YELLOW_B;
	std::cout << "NAMESPACE::map -> ";
    std::vector<int> v;
	NAMESPACE::map<int, int, std::greater<int> > mp2;
    mp2.insert(std::make_pair(20, 20));
    mp2.insert(std::make_pair(30, 30));
    mp2.insert(std::make_pair(40, 40));
    mp2.insert(std::make_pair(50, 50));
    mp2.insert(std::make_pair(60, 60));
	NAMESPACE::map<int, int>::iterator it;
    for (int i = 11; i < 70; i += 10) {
        it = mp2.upper_bound(i);
        v.push_back(it->first);
    }
	std::cout << "value:";
	for (std::vector<int>::iterator it1 = v.begin(); it1 != v.end(); ++it1)
		std::cout << " " << *it1;
	std::cout << '.' << COLOR_END << std::endl;

}

void	map_test()
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
}

#endif
