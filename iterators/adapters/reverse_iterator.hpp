#pragma once

#include "bits/iterator_traits.hpp"
#include "iterators/adapters/reverse_iterator_def.hpp"

namespace ft
{

	template<typename Iter>
	class reverse_iterator
	{
		protected:
			Iter current;
		public:

			/* ================= */
			/*    member types   */
			/* ================= */

			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;

			/* ================= */
			/*    constructors   */
			/* ================= */

			reverse_iterator();

			reverse_iterator(iterator_type base);

			template<typename U>
			reverse_iterator(const reverse_iterator<U>& rev);

			template<typename U>
			reverse_iterator& operator=(const reverse_iterator<U>& rev);

			/* ======================== */
			/*   base iterator getter   */
			/* ======================== */
			
			iterator_type base() const;

			/* ======================== */
			/*     access operators     */
			/* ======================== */
			
			reference operator*() const;

			pointer operator->() const;

			reference operator[](difference_type n) const;

			/* ========================= */
			/*    arithmetic operators   */
			/* ========================= */

			reverse_iterator<Iter>& operator++();
			reverse_iterator<Iter> operator++(int);
			reverse_iterator<Iter>& operator--();
			reverse_iterator<Iter> operator--(int);
			reverse_iterator<Iter>& operator+=(difference_type offset);
			reverse_iterator<Iter>& operator-=(difference_type offset);
			reverse_iterator operator+( difference_type offset ) const;
			reverse_iterator operator-( difference_type offset ) const;

		}; // class reverse_iterator
} // namespace ft


#include "reverse_iterator_impl.hpp"

