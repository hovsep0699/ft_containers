
#include "./algorithm.hpp"
#include "./algorithm_impl.hpp"
#include "./allocator.hpp"
#include "./allocator_impl.hpp"
#include "./bits/back_insert_iterator.hpp"
#include "./bits/back_insert_iterator_impl.hpp"
#include "./bits/front_insert_iterator.hpp"
#include "./bits/front_insert_iterator_impl.hpp"
#include "./bits/insert_iterator.hpp"
#include "./bits/insert_iterator_def.hpp"
#include "./bits/insert_iterator_impl.hpp"
#include "./bits/iterator_def.hpp"
#include "./bits/iterator_impl.hpp"
#include "./bits/iterator_traits.hpp"
#include "./bits/iterator_traits_def.hpp"
#include "./bits/iterator_traits_impl.hpp"
#include "./bits/random_access_iterator.hpp"
#include "./bits/random_access_iterator_def.hpp"
#include "./bits/random_access_iterator_impl.hpp"
#include "./bits/reverse_iterator.hpp"
#include "./bits/reverse_iterator_def.hpp"
#include "./bits/reverse_iterator_impl.hpp"
#include "./bits/tree_iterator_def.hpp"
#include "./bits/type_traits.hpp"
#include "./bits/type_traits_def.hpp"
#include "./functional.hpp"
#include "./functional_def.hpp"
#include "./functional_impl.hpp"
#include "./iterator.hpp"
#include "./map.hpp"
#include "./queue.hpp"
#include "./queue_impl.hpp"
#include "./stack.hpp"
#include "./stack_impl.hpp"
#include "./stl.hpp"
#include "./utility.hpp"
#include "./utility_impl.hpp"
#include "./vector.hpp"
#include "./vector_impl.hpp"

#include <iostream>
#include <map>
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


#include <vector>
int main(int argc, char *argv[])
{
	ft::vector<const int> v;
	v.push_back(5);

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
