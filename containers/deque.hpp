#pragma once

#include "containers/containers.hpp"
#include "iterators/deque_terator.hpp"


namespace ft
{
	template<typename T,
    		typename _Allocator> 
	class deque
	{
		typedef T**	map_pointer;
		typedef typename _Allocator::template rebind<T*>::other map_alloc;
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

		private:
			typedef deque_block_size<T, difference_type> block_type;

			map_pointer 	_map;
			size_type		_map_size;
			iterator		_begin;
			iterator		_end;
			map_alloc		_map_alloc;
			allocator_type	_alloc;
			difference_type	_block_size;	
			
			deque()
				:	_map(ft_nullptr),
					_map_size(0),
					_begin(),
					_end(),
					_map_alloc(),
					_alloc(),
					_block_size(block_type::value)
			{}

			pointer allocate_node()
			{
				return _alloc.allocate(_block_size);
			}

			void deallocate_node(pointer p)
			{
				_alloc.deallocate(p, _block_size);
			}

			map_pointer allocate_map(size_type n)
			{
				return _map_alloc.allocate(n);
			}

			void deallocate_map(map_pointer p, size_type n)
			{
				_map_alloc.deallocate(p, n);
			}
			

	};
}



