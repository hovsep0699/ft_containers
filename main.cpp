

#include <iostream>
#include <map>
#include "bits/rb_tree.hpp"
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


int main(int argc, char *argv[])
{
	ft::rb_tree<int, ft::pair<int, int>, ft::select1st<ft::pair<int, int> >, ft::less<int> > tree;
	tree.insert(ft::make_pair(1,5));
	//tree.insert(ft::make_pair(2,6));
	//tree.insert(ft::make_pair(3,7));
	//tree.insert(ft::make_pair(4,8));
	typename ft::rb_tree<int, ft::pair<int, int>, ft::select1st<ft::pair<int, int> >, ft::less<int> >::iterator it = tree.begin();
//	int p = it->first;
		std::cout << it->first << " " << it->second << std::endl;

	//createNode(ft::make_pair("hello", A(5)));
	//ft::map<std::string, A> f;
	//f.insert(ft::make_pair("hello", A(5)));
	//f.insert(ft::make_pair("he", A(6)));
	//f.insert(ft::make_pair("a", A(9)));
	//f.insert(ft::make_pair("hel", A(8)));
	//ft::map<std::string, A>::iterator it = f.begin();
	//while (it != f.end())
	//{
	//	std::cout << it->first << std::endl;;
	//	++it;
	//}
	return 0;
}
