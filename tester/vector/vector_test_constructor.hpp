#include "tester.hpp"

#define cout_vector_type() \ 
	ORIGINAL_NAMESPACE::cout << NAMESPACE_TYPE << "::vector<" << VALUE_TYPE << ", "; \
#ifdef ALLOCATOR_TYPE \
	ORIGINAL_NAMESPACE::cout << ALLOCATOR_TYPE << ">"; \
#else
	ORIGINAL_NAMESPACE::cout << ">"; \
#endif

void vector_test::constructor()
{
	vector_type	vec;

	cout_vector_type();
	ORIGINAL_NAMESPACE::cout << "::size() = " << vec.size() << ORIGINAL_NAMESPACE::endl;
	cout_vector_type();
	ORIGINAL_NAMESPACE::cout << "::capacity() = " << vec.capacity() << ORIGINAL_NAMESPACE::endl;
	cout_vector_type();
	ORIGINAL_NAMESPACE::cout << "::empty() = " << vec.empty() << ORIGINAL_NAMESPACE::endl;
	ORIGINAL_NAMESPACE::cout << "( ";
	cout_vector_type();
	ORIGINAL_NAMESPACE::cout << "::begin() == ";
	cout_vector_type();
	ORIGINAL_NAMESPACE::cout << "end()";
	ORIGINAL_NAMESPACE::cout << " ) = " << ( vec.begin() == vec.end() ) << ORIGINAL_NAMESPACE::endl;
	cout_vector_type();
	ORIGINAL_NAMESPACE::cout << "front() = " << vec.front() << ORIGINAL_NAMESPACE::endl;
	vec.push_back()
}
