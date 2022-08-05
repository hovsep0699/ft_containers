#include "vector.hpp"
#include <vector>
#include <iostream>
#include "allocator.hpp"


template<typename T>
void printVec(T& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
}

template<typename T>
void fillVec(T& v, typename T::size_type size)
{
	for (size_t i = 0; i < size; i++)
		v.push_back(i);
}

int main(int argc, char *argv[])
{
	ft::vector<int> v;
	ft::vector<int> v2;

	fillVec(v, 10);
	fillVec(v2, 20);
	ft::vector<int> v3(v2);
	ft::vector<int> v4(30);
	v4.assign(30, 8);
	ft::vector<int> v5;
	// v5.resize(10);
	v5.assign(v2.begin(), v2.end());
	// printVec(v);
	// printVec(v2);
	// printVec(v3);
	// printVec(v4);
	printVec(v5);
	return 0;
}
