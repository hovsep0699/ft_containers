
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
#include "./bits/type_traits.hpp"
#include "./bits/type_traits_def.hpp"
#include "./iterator.hpp"
#include "./queue.hpp"
#include "./queue_impl.hpp"
#include "./stack.hpp"
#include "./stack_impl.hpp"
#include "./stl.hpp"
#include "./utility.hpp"
#include "./utility_impl.hpp"
#include "./vector.hpp"
#include "./vector_impl.hpp"

template<typename T>
void printVec(T& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	// std::cout << std::endl;
	// std::cout << "v.capacity() = " << v.capacity() << std::endl;
	// std::cout << "v.size() = " << v.size() << std::endl;
}

template<typename T>
void fillVec(T& v, typename T::size_type start, typename T::size_type end)
{
	for (size_t i = start; i < end; i++)
		v.push_back(i);
}

int main(int argc, char *argv[])
{
	ft::vector<int> v;
	ft::vector<int> v2;

	fillVec(v, 56, 60);
	fillVec(v2, 30,56);
	ft::vector<int> v3(v2);
	ft::vector<int> v4(30);
	v4.assign(30, 8);
	ft::vector<int> v5(v4.begin(), v4.end());
	v5 = v2;
	// for (ft::vector<int>::iterator i = v.rbegin(); i != v.rend(); i++)
	// {
	// 	/* code */
	// }
	// std::cout << "rev: " << *v5.rbegin() << std::endl;
	// printVec(v5);
	// v5.insert(v5.cend() - 10 ,v.begin(), v.end());
	printVec(v5);
	v5.erase(v5.cbegin() + 2, v5.cbegin() + 5);
	// v5.erase(v5.cbegin() + 2);
	// v5.erase(v5.cbegin() + 2);
	std::cout << "***************\n";

	//  for (ft::vector<int>::reverse_iterator i = v5.rbegin(); i != v5.rend(); ++i)
    //     {
    //        std::cout << *i << " ";
    //     }
	// std::cout << *(v5.rbegin() + v5.size() - 1) << " ";
//	v5.insert(v5.cbegin(), v.begin(), v.end());
	// v5.resize(10);
	// v4.assign(v2.begin(), v2.begin() + 2);
	// printVec(v);
	// printVec(v2);
	// printVec(v3);
	// printVec(v4);
	printVec(v5);
	// std::cout << "front() = " << v5.front() << std::endl;
	// std::cout << "back() = " << v5.back() << std::endl;
	return 0;
}
