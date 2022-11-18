#pragma once

#include "containers/containers.hpp"
#include "iterators/deque_terator.hpp"


namespace ft
{
	template<typename T,
    		typename _Allocator> 
	class deque
	{
		public:
			typedef T value_type;
			typedef _Allocator allocator_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef ft::deque_iterator<value_type>::iterator					iterator;
			typedef ft::deque_iterator<value_type>::const_iterator				const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

			
			

	};
}



