#pragma once

#include "bits/iterator_traits.hpp"
#include "bits/type_traits.hpp"
#include "iterators/deque_iterator_def.hpp"


namespace ft
{

	template<typename T,
			typename _DT>
	struct deque_block_size
	{
		const _DT value;	
	};

	template<typename T,
			typename _Ref,
			typename _Ptr>
	class deque_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
		public:

			/* ================== */
			/*    member types    */
			/* ================== */
			
			typedef deque_iterator<T, const _Ref, const _Ptr>									const_iterator;
			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference				reference;
			typedef const reference																const_reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer				pointer;
			typedef pointer*																	map_pointer;
			typedef const pointer*																map_pointer;
			typedef const pointer																const_pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type		difference_type;

			/* ================== */
			/*    constructors    */
			/* ================== */

			deque_iterator();
			deque_iterator(pointer ptr, map_pointer mp);
			deque_iterator(const deque_iterator& it);

			operator deque_iterator<const value_type>() const;

			deque_iterator& operator=(const deque_iterator& it);

			/* ======================= */
			/*    access  operators    */
			/* ======================= */

			reference operator*() const;

			pointer operator->() const;

			reference operator[](difference_type n);

			const_reference operator[](difference_type n) const;

			/* =========================== */
			/*    arithmetic  operators    */
			/* =========================== */

			deque_iterator& operator++();

			deque_iterator operator++(int);

			deque_iterator& operator--();

			deque_iterator operator--(int);

			deque_iterator& operator+=(difference_type offset);

			deque_iterator& operator-=(difference_type offset);

			deque_iterator operator+(difference_type offset) const;

			deque_iterator operator-(difference_type offset) const;

			/* ======================== */
			/*    compare  operators    */
			/* ======================== */

			bool operator<(const deque_iterator& it) const;

			bool operator>(const deque_iterator& it) const;

			bool operator<=(const deque_iterator& it) const;

			bool operator>=(const deque_iterator& it) const;

			bool operator==(const deque_iterator& it) const;

			bool operator!=(const deque_iterator& it) const;

			/* ================ */
			/*    base access   */
			/* ================ */

			pointer			begin();
			const_pointer	begin() const;
			pointer			end();
			const_pointer	end() const;
			pointer			current();
			const_pointer	current() const;
			map_pointer			node();
			const_map_pointer	node() const;


		protected:
			map_pointer _node;
			pointer 	_begin;
			pointer 	_end;
			pointer 	_current;
	};

}

#include "random_access_iterator_impl.hpp"

