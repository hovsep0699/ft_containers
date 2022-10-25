

#include <iostream>
#include <map>
#include "map.hpp"
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

#include <map>
#include "set.hpp"
int main(int argc, char *argv[])
{
	
	//typedef ft::rb_tree<float, int, ft::select1st<ft::pair<float, int> >, ft::less<float> > tree_type;
	//typedef ft::map<float, int> tree_type;
	typedef ft::map<int, int> set_type;
	set_type s;
	s.insert(ft::make_pair(17, 8));
	s.insert(ft::make_pair(8,88));
	s.insert(ft::make_pair(9,22));
	s.insert(ft::make_pair(14,33));
	s.insert(ft::make_pair(11,11));
	s.insert(ft::make_pair(16,44));
	s.insert(ft::make_pair(13,3));
	s.insert(ft::make_pair(15,4));
	s.insert(ft::make_pair(10,0));
	s.insert(ft::make_pair(12,6));
	s.insert(ft::make_pair(18,7));
	std::cout << "##################  set #####################\n";
   // for (set_type::iterator it = s.begin(); it != s.end(); ++it) {
   //    	std::cout << it->first << "\n";
   // }
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
	return 0;
}
