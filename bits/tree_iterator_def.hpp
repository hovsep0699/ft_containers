#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include <iostream>
namespace ft
{
	enum rb_color
	{
		rb_red = true,
		rb_black = false
	};
	class rb_node_base
	{
		static rb_node_base _nil_node;
		public:
			static rb_node_base* nil;
			rb_node_base*	left;
			rb_node_base*	right;
			rb_node_base*	parent;
			rb_color		color;
			rb_node_base(rb_color color = rb_red) : left(nullptr), right(nullptr), parent(nullptr), color(color) {}
			rb_node_base* min()
			{
				rb_node_base* node = this;
				if (node == nil)
					return node;
				while (node->left != nil)
					node = node->left;
				return node;
			}
			rb_node_base* max()
			{
				rb_node_base* node = this;
				if (node == nil)
					return node;
				while (node->right != nil)
					node = node->right;
				return node;
			}

	};
	rb_node_base rb_node_base::_nil_node = rb_node_base(rb_black);
	rb_node_base* rb_node_base::nil = &rb_node_base::_nil_node;
	template<typename T>
	class rb_node : public rb_node_base
	{
		public:
			T data;
			rb_node(T data, rb_color color = rb_red) : rb_node_base(color), data(data)
		{
			parent = nil;
			left = nil;
			right = nil;
		}

	};
	template<typename T>
	class rb_tree_iterator : public iterator<bidirectional_iterator_tag, T>
	{

		public:
			//
			// member types
			//
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
			rb_tree_iterator()
				: _ptr(rb_node_base::nil)
			{}
			rb_tree_iterator(rb_node_base* ptr)
				: _ptr(ptr)
			{}
			rb_tree_iterator(rb_tree_iterator const& it)
				: _ptr(it._ptr)
			{}
			rb_tree_iterator& operator=(rb_tree_iterator const& it)
			{
				if (this != &it)
					_ptr = it._ptr;
				return *this;
			}
			//
			// dereference operators
			//
			reference operator*() const
			{
				return static_cast<rb_node<value_type>* >(_ptr)->data;
			}
			
			pointer operator->() const
			{
				return &static_cast<rb_node<value_type>* >(_ptr)->data;
			}

			//
			// other operations
			//
			rb_tree_iterator& operator++()
			{
				increment();
				return *this;
			}
			void increment()
			{
				if (_ptr->right != rb_node_base::nil)
					_ptr = _ptr->right->min();
				else
				{
					rb_node_base* node = _ptr->parent;
					while (_ptr == node->right)
					{
						_ptr = node;
						node = node->parent;
					}
					if (_ptr->right != node)
						_ptr = node;
				}
			}
			void decrement()
			{
				if (_ptr->parent->parent == _ptr && _ptr->color == rb_red)
					_ptr = _ptr->left;
				else if (_ptr->left != rb_node_base::nil)
					_ptr = _ptr->max();
				else
				{
					rb_node_base* node = _ptr->parent;
					while (node->left == _ptr)
					{
						_ptr = node;
						node = node->parent;
					}
					_ptr = node;
				}
			}

			rb_node_base* base()
			{
				return _ptr;
			}

			rb_tree_iterator operator++(int)
			{
				rb_tree_iterator tmp(*this);
				increment();
				return tmp;
			}

			rb_tree_iterator& operator--()
			{
				decrement();
				return *this;
			}

			rb_tree_iterator operator--(int)
			{
				rb_tree_iterator tmp(*this);
				decrement();
				return tmp;
			}

			//
			// compare operations
			//
			bool operator==(rb_tree_iterator const& it)
			{
				return _ptr == it._ptr;
			}

			bool operator!=(rb_tree_iterator const& it)
			{
				return _ptr != it._ptr;
			}


		protected:
			rb_node_base* _ptr;
	};
}
