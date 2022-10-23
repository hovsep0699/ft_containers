

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

#include <map>
int main(int argc, char *argv[])
{
	
	typedef ft::rb_tree<float, ft::pair<float, int>, ft::select1st<ft::pair<float, int> >, ft::less<float> > tree_type;
	tree_type tree;
	tree.insert(ft::make_pair(1.8,5));
	tree.insert(ft::make_pair(2.2,6));
	tree.insert(ft::make_pair(-3.5,7));
	tree.insert(ft::make_pair(-7.2,8));
	tree.insert(ft::make_pair(1.9,14));
	tree.insert(ft::make_pair(2.5,3));
	tree.insert(ft::make_pair(-3.10,22));
	 tree.insert(ft::make_pair(-7.8,0));
	
	//ft::rb_tree<float, ft::pair<float, int>, ft::select1st<ft::pair<float, int> >, ft::less<float> > tree1(tree);
	//tree_type::iterator it = tree.begin();
	
	//
	//for (; it != tree.end() ; ++it) {
	//	std::cout << it->first << ": " << it->second << "\n";
	//}
	
	//std::cout << (it.get_impl()._begin == tree.get_impl()._nil) << " : " << (it.get_impl()._begin == it.get_impl()._nil) << " : " << (it.get_impl()._nil == tree.get_impl()._nil)  << " : " << (it.base() == it.get_impl()._nil) << " : " <<  (tree.get_impl()._root == tree.get_impl()._nil)<< "\n";
	////--it;
	//std::cout << it->second;
//	auto it = tree.end();
	
//	std::map<float, int> m;
//	
//	m.insert(std::make_pair(1.8,5));
//	m.insert(std::make_pair(2.2,6));
//	m.insert(std::make_pair(-3.5,7));
//	m.insert(std::make_pair(-7.2,8));
//	std::cout << it1->first;
	//typename ft::rb_tree<int, ft::pair<int, int>, ft::select1st<ft::pair<int, int> >, ft::less<int> >::iterator it = tree.begin();
	//auto it1 = tree.end();
	//--it1;
	//std::cout << "here: " << it1->first << "\n";
	//auto it = tree.rbegin();
	//++it;
	//++it;
	//std::cout << it->first << ": " << it->second << "\n";
	tree_type m;
    m.insert(ft::make_pair(1.8,5));
    m.insert(ft::make_pair(2.2,6));
    m.insert(ft::make_pair(-3.5,7));
    m.insert(ft::make_pair(-7.2,8));

    for (auto i : m) {
       std::cout << i.first << ": " << i.second << "\n";
    }
	std::cout << "#################\n";
	m[ft::make_pair(1.6, 3)] = ft::make_pair(1.6, 3);
    //auto it = m.end();
    //m.erase(it);
    for (auto i : m) {
       std::cout << i.first << ": " << i.second << "\n";
    }
	 //for (auto it = tree.begin(); it != tree.end(); ++it)
	 //{
	 //	std::cout << it->first << ": " << it->second << "\n";	
	 //}
	 //tree.erase(-7.8);
	 //tree.erase(2.5);
	 //std::cout << "####################\n";
	 //for (auto it = tree.begin(); it != tree.end(); ++it)
	 //{
	 //	std::cout << it->first << ": " << it->second << "\n";	
	 //}
	//std::cout << tree.empty();
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
