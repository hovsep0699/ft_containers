#pragma once

#include "containers/containers.hpp"
#include "bits/rb_tree.hpp"
#include "bits/utility.hpp"

namespace ft
{
	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	class map
	{
		private:

			/*
		 	 * adapter tree type
			*/
			typedef rb_tree<_K, ft::pair<_K, _V>, ft::select1st<ft::pair<_K, _V> >, _Compare, _Allocator> tree_type; 

			/* =================== */
			/*    member objects   */
			/* =================== */

			tree_type _tree;

		public:

			/* ===================== */
			/*      member types     */
			/* ===================== */

			typedef typename tree_type::key_type				key_type;
			typedef typename tree_type::value_type				value_type;
			typedef _V											mapped_type;
			typedef typename tree_type::size_type				size_type;
			typedef typename tree_type::difference_type			difference_type;
			typedef typename tree_type::key_compare				key_compare;
			typedef typename tree_type::value_compare			value_compare;
			typedef typename tree_type::allocator_type			allocator_type;
			typedef typename tree_type::reference				reference;
			typedef typename tree_type::const_reference 		const_reference;
			typedef typename tree_type::pointer					pointer;
			typedef typename tree_type::const_pointer			const_pointer;
			typedef typename tree_type::iterator				iterator;
			typedef typename tree_type::const_iterator			const_iterator;
			typedef typename tree_type::reverse_iterator		reverse_iterator;
			typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;
			
			
			/* ========================= */
			/*      member functions     */
			/* ========================= */

            template< typename InputIt >
							map( InputIt first, InputIt last,
     	 	 	 				const key_compare& comp = key_compare(),
     	 	 	 				const allocator_type& alloc = allocator_type() );
							map();
							map( const map& other );
			explicit		map( const key_compare& comp,
            					const allocator_type& alloc = allocator_type() );
            explicit		map( const allocator_type& alloc );
			virtual			~map();
			map&			operator=( const map& other );
			allocator_type	get_allocator() const;

			/* ===================== */
			/*       iterators       */
			/* ===================== */

			iterator				begin();
			const_iterator			begin() const;
			const_iterator			cbegin() const;
			iterator				end();
			const_iterator			end() const;
			const_iterator			cend() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			const_reverse_iterator	crbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			const_reverse_iterator	crend() const;

			/* ===================== */
			/*       capacity       */
			/* ===================== */

			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;

			/* ===================== */
			/*       modifiers       */
			/* ===================== */

			void						clear();
			template< typename InputIt >
			void						insert( InputIt first, InputIt last );
			ft::pair<iterator, bool>	insert( const value_type& value );
			iterator					insert( iterator pos, const value_type& value );
			iterator					erase( iterator pos );
			iterator					erase( iterator first, iterator last );
			size_type					erase( const key_type& key );
			void						swap( map& other );

			/* ===================== */
			/*         lookup        */
			/* ===================== */

			size_type									count( const key_type& key ) const;
			iterator									find( const key_type& key );
			const_iterator								find( const key_type& key ) const;
			ft::pair<iterator, iterator>				equal_range( const key_type& key );
			ft::pair<const_iterator, const_iterator>	equal_range( const key_type& key ) const;
			iterator									lower_bound( const key_type& key );
			const_iterator								lower_bound( const key_type& key ) const;
			iterator									upper_bound( const key_type& key );
			const_iterator								upper_bound( const key_type& key ) const;

			/* ===================== */
			/*     element access    */
			/* ===================== */

			mapped_type&		at( const key_type& key );
			const mapped_type&	at( const key_type& key ) const;
			mapped_type&		operator[]( const key_type& key );

			/* ===================== */
			/*       observers       */
			/* ===================== */

			key_compare		key_comp() const;
			value_compare	value_comp() const;

	};

	/* ============================== */
	/*     non-member functions       */
	/* ============================== */

	template< typename _K,
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	bool operator==( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V,
			typename _Compare, 
			typename _Allocator >
	bool operator!=( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	bool operator>( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _Compare,
			typename _Allocator >
	bool operator<( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	bool operator>=( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _V,
			typename _Compare, 
			typename _Allocator >
	bool operator<=( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs );

}

#include "containers/map_impl.hpp"

