#pragma once

#include "iterators/iterator.hpp"
#include "bits/utility.hpp"

namespace ft
{
	template<typename T, typename Allocator>
	class vector
	{
		public:
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef ft::random_access_iterator<value_type>						iterator;
			typedef ft::random_access_iterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type());
			vector(vector& vec);
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, 
					const allocator_type& alloc = allocator_type(),
					typename enable_if<!is_integral<InputIterator>::value, bool>::type = true);

			vector& operator= (const vector& x);

			void assign( size_type count, const_reference value );

			template< class InputIt >
			void assign( InputIt first, InputIt last,
						typename enable_if<!is_integral<InputIt>::value, bool>::type = true);

			virtual ~vector();

			allocator_type get_allocator() const;

			size_type max_size() const;

			bool empty() const;

			void push_back(const_reference val );

			void reserve(size_type new_capacity);

			// void resize(size_type new_capacity);
			void resize( size_type count, value_type value = value_type() );
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

			reference at (size_type _n);

			void clear();

			const_reference at (size_type _n) const;

			pointer data();

			const_pointer data() const;

			reference back();
			const_reference back() const;

			reference front();
			const_reference front() const;

			void shrink_to_fit();

			//iterator insert( const_iterator pos, const_reference value );
			iterator insert( iterator pos, const_reference value );

			//iterator insert( const_iterator pos, size_type count, const_reference value );

			void insert( iterator pos, size_type count, const_reference value );

			template<typename InputIt>
			iterator insert( const_iterator pos, InputIt first, InputIt last, 
					typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0);

			iterator erase( iterator pos );
			//iterator erase( const_iterator pos );

			iterator erase( iterator first, iterator last );
			//iterator erase( const_iterator first, const_iterator last );

			void swap( vector& other );


		protected:
			allocator_type	_allocator;
			pointer			_data;
			size_type		_size;
			size_type		_capacity;
			size_type		_max_size;

	};

}

#include "vector_impl.hpp"


