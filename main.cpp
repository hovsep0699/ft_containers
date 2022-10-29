#include <iostream>
#include <list>
#include <set>
#include "multiset.hpp"

#define TESTED_TYPE int
#define ORIGINAL_NAMESPACE std
#define TESTED_NAMESPACE ft
#define TEST_SET_T(T) TESTED_NAMESPACE::multiset<T>

template<typename T>
void print(T container)
{
	std::cout << "#######################################################\n";
	typename T::const_iterator it = container.begin();
	while (it != container.end() )
	{
		std::cout << *it << " " << " color: " << ((it.base()->_color == ft::rb_red) ? "red" : "black") << "\n";
		++it;
	}
	std::cout << "#######################################################\n";
}

bool test_set()
{
	TEST_SET_T(int) s;
	int arr[] = {1,4,8,6,9,3,6,7,2, 5,9};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; ++i)
		s.insert(arr[i]);
//	s.insert(arr, arr + size);
	//while (it != s.end() )
	//{
	//	std::cout << *it << " " << " color: " << ((it.base()->_color == ft::rb_red) ? "red" : "black") << "\n";
	//	++it;
	//}
	//std::cout << "#######################################################\n";
	//print(s);
//	s.erase(2);
	//TEST_SET_T(int)::iterator it1 = s.end();
//	--it1;
//	std::cout << *it1 << "\n";
	print(s);
	s.clear();
	s.insert(arr, arr + size);
	print(s);
	//TEST_SET_T(int) s1(s);
	//TEST_SET_T(int) s2(s);
	//print(s);
	//TEST_SET_T(int)::const_iterator it = s.begin();
	//while (it != s.end() )
	//{
	//	std::cout << *it << " " << " color: " << ((it.base()->_color == ft::rb_red) ? "red" : "black") << "\n";
	//	++it;
	//}
	//print(s);
	return true;
}


int		main(void)
{
	test_set();
	//++it;
	//std::cout << *it;
//	std::vector<TESTED_TYPE> lst;
//	std::vector<TESTED_TYPE>::iterator lst_it;
//	int arr[] = {1,5,8,9,6,7};
//	size_t size = sizeof(arr)/sizeof(arr[0]);
//	for (int i = 1; i < 5; ++i)
//		lst.push_back(i * 3);
//	TESTED_NAMESPACE::vector<int> v;
//	for (int i = 1; i < 5; ++i)
//		v.push_back(i * 3);
//	for (TESTED_NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//		std::cout << *it << " ";
//	std::cout << "\n";
	//v.insert(v.begin(), arr, arr + size);	
	//std::iterator_traits<std::vector<TESTED_TYPE>::iterator>::difference_type d;
	//size_t size = TESTED_NAMESPACE::distance(lst.begin(), lst.end());
	//size_t size = std::distance(v.begin(), v.end());

//	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
//	printSize(vct);
//
//	lst_it = lst.begin();
//	for (int i = 1; lst_it != lst.end(); ++i)
//		*lst_it++ = i * 5;
//	vct.assign(lst.begin(), lst.end());
//	printSize(vct);
//
//	vct.insert(vct.end(), lst.rbegin(), lst.rend());
//	printSize(vct);
	return (0);
}
