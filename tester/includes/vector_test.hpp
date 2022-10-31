#pragma once

#include "vector.hpp"
#include <vector>

/*! class vector_test
 *  
 *  Detailed test vector class
 */
class vector_test
{
	public:
		typedef VALUE_TYPE																test_type;
		typedef NAMESPACE_TYPE														namespace_type;
		typedef typename ALLOCATOR_TYPE												allocator_type;
		typedef typename namespace_type::vector<test_type, allocator_type>		vector_type;
		typedef typename vector_type::iterator									iterator_type;
		typedef typename vector_type::const_iterator							const_iterator_type;
		typedef typename vector_type::const_iterator							const_iterator_type;
		typedef typename vector_type::reverse_iterator							const_iterator_type;
		typedef typename vector_type::const_reverse_iterator					const_iterator_type;

		void constructor();	
	
};

#include "vector_test_impl.hpp"
