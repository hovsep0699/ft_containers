#pragma once

#include "../iterator.hpp"
#include "../utility.hpp"
#include "../functional.hpp"

namespace ft
{

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	class rb_tree
	{
		public:

			/* ========================= */
			/*        member types       */
			/* ========================= */

			typedef _K										key_type;
//			typedef _V										mapped_type;
			typedef _V										value_type;
			typedef _KOV									key_of_value_type;
			typedef _Compare								key_compare;
			typedef rb_tree_iterator<value_type>			iterator;
			typedef rb_tree_iterator<const value_type>		const_iterator;
			typedef reverse_iterator<iterator>				reverse_iterator;
			typedef rb_tree_iterator<const_iterator>		const_reverse_iterator;
			typedef _Allocator								allocator_type;
			typedef rb_tree_node_base*						base_ptr;
			typedef const rb_tree_node_base*				const_base_ptr;
			typedef rb_tree_node<value_type>*				link_type;
			typedef const rb_tree_node<value_type>*			const_link_type;
			typedef typename _Allocator::pointer			pointer;
			typedef typename _Allocator::const_pointer		const_pointer;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename _Allocator::difference_type	difference_type;
			typedef typename _Allocator::size_type			size_type;

		private:
			enum rb_tree_recolor
			{
				rb_right = true,
				rb_left = false
			};
			typedef typename _Allocator::template rebind<rb_tree_node<value_type> >::other node_allocator;
			typedef rb_tree_impl<value_type, node_allocator> rb_tree_impl_type;
			typedef const rb_tree_impl<value_type, node_allocator> const_rb_tree_impl_type;
		public:
			class value_compare : public ft::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;
					value_compare(key_compare comp);
				public:
					bool operator()( const_reference lhs, const_reference rhs ) const;
					friend class rb_tree<key_type, value_type, key_of_value_type, key_compare, allocator_type>;
			};
		private:
			/* ========================= */
			/*           members         */
			/* ========================= */

			rb_tree_impl_type _rb_tree_impl;
			allocator_type		_alloc;
			key_compare			_comp;
			value_compare		_value_comp;
			key_of_value_type	_key_of_value;
		public:

			/* ========================= */
			/*        constructors       */
			/* ========================= */

			rb_tree();
			explicit rb_tree( const key_compare& comp,
            			const allocator_type& alloc = allocator_type() );
            explicit rb_tree( const allocator_type& alloc );
            rb_tree(const rb_tree& tree);
			
			template< typename InputIt >
			rb_tree( InputIt first, InputIt last,
     			const key_compare& comp = key_compare(),
     			const allocator_type& alloc = allocator_type() );

			virtual ~rb_tree();
			rb_tree& operator=(const rb_tree& other ); 
			size_type size() const;
			allocator_type get_allocator() const;
			size_type count(const key_type& key) const;
			const_iterator lower_bound(const key_type& key) const;
			iterator lower_bound(const key_type& key);
			const_iterator upper_bound(const key_type& key) const;
			iterator upper_bound(const key_type& key);
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const;
			ft::pair<iterator, iterator> equal_range(const key_type& key);
			base_ptr root();
			const_base_ptr root() const;

			/* ========================= */
			/*       static methods      */
			/* ========================= */

			static key_type s_key(const_link_type link);
			static key_type s_key(const_base_ptr ptr);
			static const_reference s_value(const_base_ptr ptr);
			static const_reference s_value(const_link_type link);
			static link_type s_left(const_base_ptr ptr);
			static link_type s_right(const_base_ptr ptr);

			void clear();

			/* ========================= */
			/*    access  iterators      */
			/* ========================= */

			iterator  begin();
			const_iterator begin() const;
			const_iterator cbegin() const;
			iterator end();
			const_iterator end() const;
			const_iterator  cend() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			const_reverse_iterator crbegin() const;
			reverse_iterator rend();
			//mapped_type& at( const key_type& key );
			//const mapped_type& at( const key_type& key ) const;
			const_reverse_iterator rend() const;
			const_reverse_iterator crend() const;
			//mapped_type& operator[](const key_type& _key);
			const_rb_tree_impl_type get_impl() const;
			rb_tree_impl_type get_impl();

			ft::pair<iterator, bool> insert(base_ptr& root, const_reference _value);

			void insert_fixup(base_ptr z);

			void recolor(base_ptr z, base_ptr y, rb_tree_recolor side);
			void left_rotate(base_ptr x);
			void right_rotate(base_ptr x);
			iterator find(const key_type& key);
			const_iterator find(const key_type& key) const;
			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
			size_type erase(const key_type& key);
			void erase_fixup(base_ptr x);

			void transplant(base_ptr u, base_ptr v);
			bool empty() const;
			iterator insert(iterator pos, const_reference _value);
			template< typename InputIt >
			void insert( InputIt first, InputIt last );
			ft::pair<iterator, bool> insert(const_reference _value);
			key_compare key_comp() const;
			value_compare value_comp() const;
			size_type max_size() const;
			void swap( rb_tree& other );
	};

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator==( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator!=( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator>( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator>=( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator<( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator<=( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	void swap( rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs );
}
#include "rb_tree_impl.hpp"

