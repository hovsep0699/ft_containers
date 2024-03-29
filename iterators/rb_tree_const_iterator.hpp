#pragma once

#include "bits/iterator_traits.hpp"
#include "bits/rb_tree_def.hpp"

namespace ft
{
	template<typename T>
	class rb_tree_const_iterator : public iterator<bidirectional_iterator_tag, T>
	{
		public:

           /* ============================= */
           /*         member types          */
           /* ============================= */ 

			typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, const T>::reference	reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, const T>::pointer		pointer;
			typedef ft::rb_tree_iterator<T>													iterator;
			typedef ft::rb_tree_node_base*													base_ptr;
			typedef rb_tree_node_base														base_type;
			typedef const ft::rb_tree_node_base*											const_base_ptr;
			typedef ft::rb_tree_node<value_type>*											link_type;
			typedef const rb_tree_node<value_type>*											const_link_type;
			typedef ft::bidirectional_iterator_tag											iterator_category;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;


			/* ========================= */
			/*      member functions     */
			/* ========================= */

									rb_tree_const_iterator();
									rb_tree_const_iterator(base_ptr _base);
									rb_tree_const_iterator(iterator const& _it);
									rb_tree_const_iterator(rb_tree_const_iterator const& it);
			virtual					~rb_tree_const_iterator();
			rb_tree_const_iterator&	operator=(rb_tree_const_iterator const& it);

			/* ========================= */
			/*       element access      */
			/* ========================= */

			base_ptr				base();
			const_base_ptr			base() const;
			reference				operator*() const;
			pointer					operator->() const;

			/* =========================== */
			/*    arithmetic  functions    */
			/* =========================== */

			rb_tree_const_iterator&	operator++();
			rb_tree_const_iterator	operator++(int);
			rb_tree_const_iterator&	operator--();
			rb_tree_const_iterator	operator--(int);

			/* =========================== */
			/*      compare  functions     */
			/* =========================== */

			bool					operator==(rb_tree_const_iterator const& it);
			bool					operator!=(rb_tree_const_iterator const& it);

		protected:

			/* =================== */
			/*    member objects   */
			/* =================== */

			base_type	_nil;
			base_ptr	_base;
		private:

			/*
			 * red black tree implementation trait type
			*/
			typedef rb_tree_impl<T, allocator<link_type> > rb_tree_impl_type;
	};
}
#include "iterators/rb_tree_const_iterator_impl.hpp"
