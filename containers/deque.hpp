#pragma once

#include "bits/iterator_traits.hpp"
#include "bits/type_traits.hpp"
#include "iterators/deque_terator_def.hpp"


namespace ft
{

	template<typename T,
			typename _DT>
	struct deque_block_size
	{
		static const _DT value;
	};

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	class deque_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
		public:

			/* ================== */
			/*    member types    */
			/* ================== */

			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
			typedef const reference															const_reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
			typedef const pointer															const_pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef _DT																		difference_type;
			typedef pointer*																map_pointer;
			typedef const pointer*															const_map_pointer;
			typedef deque_iterator<T, const_reference, const_pointer>						const_iterator;

			/* ================== */
			/*    constructors    */
			/* ================== */

			deque_iterator();
			deque_iterator(pointer ptr, map_pointer mp);
			deque_iterator(const deque_iterator& it);

			operator const_iterator() const;

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

			pointer				current();
			const_pointer		current() const;
			pointer				begin();
			const_pointer		begin() const;
			pointer				end();
			const_pointer		end() const;
			map_pointer			node();
			const_map_pointer	node() const;


		protected:
			map_pointer	_node;
			pointer 	_begin;
			pointer 	_end;
			pointer 	_current;

			void set_node(map_pointer _mp);
	};
}



