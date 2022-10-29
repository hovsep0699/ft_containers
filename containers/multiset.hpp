#pragma once

#include "containers/containers.hpp"
#include "bits/rb_tree.hpp"
#include "bits/utility.hpp"

namespace ft
{
	template< typename _K,
			typename _Compare,
			typename _Allocator >
	class multiset
	{
		typedef rb_tree<_K, _K, ft::identity<_K>, _Compare, _Allocator> tree_type; 

		tree_type _tree;
		public:
			typedef typename tree_type::key_type				key_type;
			typedef typename tree_type::value_type				value_type;
			typedef typename tree_type::size_type				size_type;
			typedef typename tree_type::difference_type			difference_type;
			typedef typename tree_type::key_compare				key_compare;
			typedef typename tree_type::key_compare				value_compare;
			typedef typename tree_type::allocator_type			allocator_type;
			typedef typename tree_type::reference				reference;
			typedef typename tree_type::const_reference			const_reference;
			typedef typename tree_type::pointer					pointer;
			typedef typename tree_type::const_pointer			const_pointer;
			typedef typename tree_type::const_iterator			iterator;
			typedef typename tree_type::const_iterator			const_iterator;
			typedef typename tree_type::reverse_iterator		reverse_iterator;
			typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;
			

			multiset();

			explicit multiset( const key_compare& comp,
            			const allocator_type& alloc = allocator_type() );

            explicit multiset( const allocator_type& alloc );

            template< typename InputIt >
			multiset( InputIt first, InputIt last,
     	 	 	 const key_compare& comp = key_compare(),
     	 	 	 const allocator_type& alloc = allocator_type() );

			multiset( const multiset& other );


			// multiset is read only and cannot have operator[] and at method
			virtual ~multiset();
			multiset& operator=( const multiset& other );
			allocator_type get_allocator() const;
			iterator begin();
			const_iterator begin() const;
			const_iterator cbegin() const;
			iterator end();
			const_iterator end() const;
			const_iterator cend() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			const_reverse_iterator crbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			const_reverse_iterator crend() const;
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void clear();
			ft::pair<iterator, bool> insert( const value_type& value );
			iterator insert( iterator pos, const value_type& value );
			template< typename InputIt >
			void insert( InputIt first, InputIt last );
			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
			size_type erase( const key_type& key );
			void swap( multiset& other );
			size_type count( const key_type& key ) const;
			iterator find( const key_type& key );
			const_iterator find( const key_type& key ) const;
			ft::pair<iterator, iterator> equal_range( const key_type& key );
			ft::pair<const_iterator, const_iterator> equal_range( const key_type& key ) const;
			iterator lower_bound( const key_type& key );
			const_iterator lower_bound( const key_type& key ) const;
			iterator upper_bound( const key_type& key );
			const_iterator upper_bound( const key_type& key ) const;
			key_compare key_comp() const;
			value_compare value_comp() const;


	};

	template< typename _K,
			typename _Compare, 
			typename _Allocator >
	bool operator==( const multiset<_K, _Compare, _Allocator>& lhs,
                 	 const multiset<_K, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare, 
			typename _Allocator >
	bool operator!=( const multiset<_K, _Compare, _Allocator>& lhs,
                 	 const multiset<_K, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare, 
			typename _Allocator >
	bool operator>( const multiset<_K, _Compare, _Allocator>& lhs,
                 	 const multiset<_K, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare,
			typename _Allocator >
	bool operator<( const multiset<_K, _Compare, _Allocator>& lhs,
                 	 const multiset<_K, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare, 
			typename _Allocator >
	bool operator>=( const multiset<_K, _Compare, _Allocator>& lhs,
                 	 const multiset<_K, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare, 
			typename _Allocator >
	bool operator<=( const multiset<_K, _Compare, _Allocator>& lhs,
                 	 const multiset<_K, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare, 
			typename _Allocator >
	void swap( multiset<_K, _Compare, _Allocator>& lhs, 
           		multiset<_K, _Compare, _Allocator>& rhs );
}

#include "multiset_impl.hpp"

