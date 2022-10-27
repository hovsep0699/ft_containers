

#include <iostream>
#include "vector.hpp"
struct A
{
	int x;
	A(int x) : x(x)
	{
//		std::cout << "A()\n";
	}
	~A()
	{

//		std::cout << "~A()\n";
	}
	bool operator<(const A& b)
	{
		return x < b.x;
	}
	bool operator>(const A& b)
	{
		return x > b.x;
	}
	bool operator==(const A& b)
	{
		return x == b.x;
	}
	bool operator!=(const A& b)
	{
		return x != b.x;
	}
	bool operator<=(const A& b)
	{
		return x <= b.x;
	}
	bool operator>=(const A& b)
	{
		return x >= b.x;
	}

	template<typename T>
	operator T()
	{
		return T(x);
	}
	
	friend bool operator<(const A& b, const A& a);
	friend bool operator>(const A& b, const A& a);
	friend bool operator<=(const A& b, const A& a);
	friend bool operator<=(const A& b, const A& a);
	friend bool operator!=(const A& b, const A& a);
	friend bool operator==(const A& b, const A& a);
};

	bool operator<(const A& b, const A& a)
	{
		return a.x < b.x;
	}
	bool operator>(const A& b, const A& a)
	{
		return a.x > b.x;
	}
	bool operator<=(const A& b, const A& a)
	{
		return a.x <= b.x;
	}
	bool operator>=(const A& b, const A& a)
	{
		return a.x >= b.x;
	}
	bool operator!=(const A& b, const A& a)
	{
		return a.x != b.x;
	}
	bool operator==(const A& b, const A& a)
	{
		return a.x == b.x;
	}

#include "set.hpp"
#include "map.hpp"
#include <list>
//int main(int argc, char *argv[])
//{
//	std::list<int> lst;
//	for (int i = 1; i < 5; ++i)
//		lst.push_back(i * 3);
//	typedef ft::vector<int> vector_type;
//	vector_type v(lst.begin(), lst.end());
	//v.push_back(6);
	//v.push_back(7);
	//v.push_back(8);
	//v.push_back(9);
	//v.push_back(10);
	//v.push_back(11);
	//v.push_back(12);
	//v.push_back(13);
	//v.push_back(14);
	//v.push_back(15);
	//v.push_back(16);
	//vector_type::reverse_iterator it = v.crbegin();
	//std::cout << "it: " << *it;
	//vector_type::const_reverse_iterator it1 = it;
	//vector_type::iterator it = v.begin();
	//for (int i = 0; i < v.size(); ++i) {
	//	std::cout << v[i] << " ";
	//}
	//std::cout << "\n";
	//try
	//{
	//	v.at(50);
	//}
	//catch(...)
	//{
	//	std::cout << "vector_except\n";
	//}
	//typedef ft::rb_tree<float, int, ft::select1st<ft::pair<float, int> >, ft::less<float> > tree_type;
//	typedef ft::set<float> set_type;
	//typedef ft::map<int, int> map_type;
	//map_type m;
//	set_type s;
//	float arr[] = {1.2, 8.6, 39.2, 17.2, 147.2};
//	int size = sizeof(arr)/sizeof(arr[0]);
//	s.insert(arr, arr + size);
//	set_type::const_iterator it = s.cbegin();
	//std::cout << (it == s.begin()) << "\n";
	//m.insert(ft::make_pair(17, 8));
	//m.insert(ft::make_pair(8,88));
	//m.insert(ft::make_pair(9,22));
	//m.insert(ft::make_pair(14,33));
	//m.insert(ft::make_pair(11,11));
	//m.insert(ft::make_pair(16,44));
	//m.insert(ft::make_pair(13,3));
	//m.insert(ft::make_pair(15,4));
	//m.insert(ft::make_pair(10,0));
	//m.insert(ft::make_pair(12,6));
	//m.insert(ft::make_pair(18,7));
	//map_type::const_iterator it = m.cbegin();
//	std::cout << "##################  map #####################\n";
//    for (map_type::iterator it = m.begin(); it != m.end(); ++it) {
//       	std::cout << it->first << " : "  << it->second <<  "\n";
//    }
//
//	set_type::iterator iter = s.cbegin();
	//std::cout << "##################  set #####################\n";
	//for (set_type::reverse_iterator it = s.rbegin(); it != s.crend(); ++it) {
    //	std::cout << *it <<  "\n";
	//}

	//tree_type tree;
	//tree.insert(ft::make_pair(1.8,5));
	//tree.insert(ft::make_pair(2.2,6));
	//tree.insert(ft::make_pair(-3.5,7));
	//tree.insert(ft::make_pair(-7.2,8));
	//tree.insert(ft::make_pair(1.9,14));
	//tree.insert(ft::make_pair(2.5,3));
	//tree.insert(ft::make_pair(-3.10,22));
	// tree.insert(ft::make_pair(-7.8,0));
	//
	//tree_type m, m1;
    //m.insert(ft::make_pair(1.8,5));
    //m.insert(ft::make_pair(2.2,6));
    //m.insert(ft::make_pair(-3.5,7));
    //m.insert(ft::make_pair(-7.2,8));

	//std::cout << "########  M  #########\n";
    //for (tree_type::iterator it = m.begin(); it != m.end(); ++it) {
    //   	std::cout << it->first << ": " << it->second << "\n";
    //}
    //m1.insert(ft::make_pair(-7.2,8));
    //m1.insert(ft::make_pair(1.8,5));
    //m1.insert(ft::make_pair(2.1,6));
    //m1.insert(ft::make_pair(-3.5,7));
	//std::cout << "########  M1  #########\n";
    //for (auto i : m1) {
    //   std::cout << i.first << ": " << i.second << "\n";
    //}

   	//m1 = m;
	//std::cout << "M1_size: "<< m1.size() << std::endl;
	////m1 = m;
    //m1.clear();
	//std::cout << "M1_size: "<< m1.size() << std::endl;
//std::cout << "########  M1  #########\n";
//  for (auto i : m1) {
//     std::cout << i.first << ": " << i.second << "\n";
//  }
//std::cout << "###########  M1 == M  ################\n";
//std::cout << "(m == m1) : " << (m <= m1) << "\n";
//	return 0;
//}

#include "vector"
#include <list>

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

int		main(void)
{
	ft::vector<TESTED_TYPE> lst;
	ft::vector<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);
	//std::iterator_traits<std::vector<TESTED_TYPE>::iterator>::difference_type d;
	//size_t size = std::distance(lst.begin(), lst.end());

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
