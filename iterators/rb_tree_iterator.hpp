#pragma once

#include "bits/iterator_traits.hpp"
#include "bits/rb_tree_def.hpp"

namespace ft
{
	template<typename T>
	class rb_tree_iterator : public iterator<bidirectional_iterator_tag, T>
	{
		friend class rb_tree_const_iterator<T>;
		public:

           /* ============================= */
           /*         member types          */
           /* ============================= */ 

			typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer			pointer;
			typedef rb_tree_node_base*														base_ptr;
			typedef rb_tree_node_base														base_type;
			typedef const rb_tree_node_base*												const_base_ptr;
			typedef rb_tree_node<value_type>*												link_type;
			typedef const rb_tree_node<value_type>*											const_link_type;
			typedef bidirectional_iterator_tag												iterator_category;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;

           /* ============================= */
           /*         Orthodox form         */
           /* ============================= */ 

			rb_tree_iterator();
			rb_tree_iterator(base_ptr _base);
			rb_tree_iterator(rb_tree_iterator const& it);
			rb_tree_iterator& operator=(rb_tree_iterator const& it);
			virtual ~rb_tree_iterator();


           /* ============================= */
           /*     dereference operators     */
           /* ============================= */ 

			reference operator*() const;
			
			pointer operator->() const;

           /* ============================= */
           /*            increment          */
           /* ============================= */ 

			rb_tree_iterator& operator++();
			rb_tree_iterator operator++(int);

           /* ============================= */
           /*            decrement          */
           /* ============================= */ 
			
			rb_tree_iterator& operator--();

			rb_tree_iterator operator--(int);
			

           /* ============================= */
           /*       	   base             */
           /* ============================= */ 
			

			base_ptr base();

			const_base_ptr base() const;


           /* ============================= */
           /*       compare operators       */
           /* ============================= */ 
			
			bool operator==(rb_tree_iterator const& it);

			bool operator!=(rb_tree_iterator const& it);

		protected:
			base_type	_nil;
			base_ptr	_base;
		private:
			typedef rb_tree_impl<T, allocator<link_type> > rb_tree_impl_type;
	};
}
#include "rb_tree_iterator_impl.hpp"
