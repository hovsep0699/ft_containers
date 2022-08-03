#include "vector.hpp"
#include <vector>
#include <iostream>
#include "allocator.hpp"

int main(int argc, char *argv[])
{
	// ft::allocator<int>  alloc;
	
		// while(1)
		// {
		// 	try
		// 	{	
		// 		int* p = alloc.allocate(10000000);	
		// 		// int *p = new int [1000000000];
		// 	}
		// 	catch(const std::bad_alloc& e)
		// 	{
		// 		std::cerr << e.what() << '\n';
		// 		break;
		// 	}

		// }
		// std::cout << "hello" << std::endl;
	
	ft::vector<int, ft::allocator<int> > v;
	std::vector<int> v1;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "v1.size() = " << v1.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
	v.push_back(5);
	v1.push_back(5);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "v1.size() = " << v1.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
	v.push_back(6);
	v1.push_back(6);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "v1.size() = " << v1.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
	v.push_back(7);
	v1.push_back(7);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "v1.size() = " << v1.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
	v1.push_back(8);
	v.push_back(8);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "v1.size() = " << v1.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
	v1.push_back(9);
	v.push_back(9);
	
	// std::vector<int>::iterator it = v.begin();
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "v1.size() = " << v1.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v1.capacity() = " << v1.capacity() << std::endl;

	for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
