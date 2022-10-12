#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include "rb_tree_node.hpp"

namespace ft
{
	template<typename T>
	class rb_tree_iterator : public iterator<bidirectional_iterator_tag, T>
	{
		typedef std::allocator<T> _allocator_type;
		_allocator_type _alloc;
		public:

           /* ============================= */
           /*         member types          */
           /* ============================= */ 

			typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
			typedef bidirectional_iterator_tag iterator_category;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;

           /* ============================= */
           /*         Orthodox form         */
           /* ============================= */ 

			rb_tree_iterator();
			rb_tree_iterator(rb_tree_node_base* _base);
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
			
			rb_tree_node_base* base();



           /* ============================= */
           /*       compare operators       */
           /* ============================= */ 
			
			bool operator==(rb_tree_iterator const& it);

			bool operator!=(rb_tree_iterator const& it);


		protected:
			rb_tree_node_base* _base;
	};
}
#include "rb_tree_iterator_impl.hpp"
