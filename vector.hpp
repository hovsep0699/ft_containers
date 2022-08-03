#pragma once

#include "iterator.hpp"
//#include "allocator.hpp"
#include <memory>
#include <iostream>
namespace ft
{

	template<typename T, typename Allocator = std::allocator<T> >
		class vector
		{
			public:
				typedef T value_type;
				typedef Allocator allocator_type;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef typename allocator_type::size_type size_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef ft::random_access_iterator<value_type> iterator;
				typedef ft::random_access_iterator<const value_type> const_iterator;
				typedef ft::reverse_iterator<iterator> const_reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> reverse_iterator;
				typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

				explicit vector(const allocator_type& alloc = allocator_type());
				explicit vector(size_type n, const allocator_type& alloc = allocator_type());

				virtual ~vector();

				allocator_type get_allocator() const;

				size_type max_size() const;

				bool empty() const;

				void push_back(const_reference val );

				void reserve(size_type new_capacity);

				// void resize(size_type new_capacity);
				void resize( size_type count, value_type value = value_type() );
				void resize( size_type count );
				// void resize( size_type count, const value_type& value = value_type() );

				iterator begin();

				const_iterator begin() const;

				iterator end();

				const_iterator end() const;

				reverse_iterator rbegin();

				const_reverse_iterator rbegin() const;

				reverse_iterator rend();

				const_reverse_iterator rend() const;

				const_iterator cbegin() const;

				const_iterator cend() const;

				const_reverse_iterator crbegin() const;

				const_reverse_iterator crend() const;

				size_type size() const;

				size_type capacity() const;

				reference operator[] (size_type n);

				const_reference operator[] (size_type n) const;

			protected:
				allocator_type _allocator;
				pointer	_elems;
				size_type _size;
				size_type _capacity;
				size_type _max_size;

		};

}

#include "vector_impl.hpp"


