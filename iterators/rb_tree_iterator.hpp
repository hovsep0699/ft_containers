#pragma once

#include "bits/iterator_traits.hpp"
#include "bits/type_traits.hpp"
#include "bits/rb_tree_def.hpp"
#include "bits/rb_tree_node.hpp"

namespace ft
{
	template<typename T>
	class rb_tree_iterator : public iterator<bidirectional_iterator_tag, T>
	{
		typedef std::allocator<T> allocator_type;
		typedef std::allocator<rb_tree_node<T> > node_allocator_type;
		allocator_type _alloc;
		friend class rb_tree_const_iterator<T>;
		public:

           /* ============================= */
           /*         member types          */
           /* ============================= */ 

			typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer			pointer;
			typedef rb_tree_node_base*														base_ptr;
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
//			template<typename Iter>
//			rb_tree_iterator(const rb_tree_iterator<Iter>& it);

		//	operator const_iterator() const;
			//operator rb_tree_iterator<value_type>();
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

			rb_tree_impl<value_type, node_allocator_type> get_impl() const
			{
				return _rb_tree_impl;
			}
		protected:
			base_ptr _base;
		private:
			rb_tree_impl<value_type, node_allocator_type> _rb_tree_impl;
	};
}
#include "rb_tree_iterator_impl.hpp"
