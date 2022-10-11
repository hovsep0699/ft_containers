#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include <iostream>
namespace ft
{
	enum rb_tree_color
	{
		rb_red = true,
		rb_black = false
	};
	class rb_tree_node_base
	{
		static rb_tree_node_base _nil_node;
		public:
			static rb_tree_node_base* nil;
			rb_tree_node_base*	left;
			rb_tree_node_base*	right;
			rb_tree_node_base*	parent;
			rb_tree_color		color;
			rb_tree_node_base(rb_tree_color color = rb_red) : left(nullptr), right(nullptr), parent(nullptr), color(color) {}

	   	   /* ============================= */
	   	   /*            increment          */
	   	   /* ============================= */ 

			static rb_tree_node_base* increment(rb_tree_node_base* node)
			{
				rb_tree_node_base* _base = node;
				if (_base->right != rb_tree_node_base::nil)
					_base = _base->right->min();
				else
				{
					rb_tree_node_base* node = _base->parent;
					while (_base == node->right)
					{
						_base = node;
						node = node->parent;
					}
					if (_base->right != node)
						_base = node;
				}
				return _base;
			}

	   	   /* ============================= */
	   	   /*            decrement          */
	   	   /* ============================= */ 

			static rb_tree_node_base* decrement(rb_tree_node_base* node)
			{
				rb_tree_node_base* _base = node;
				if (_base->parent->parent == _base && _base->color == rb_red)
					_base = _base->left;
				else if (_base->left != rb_tree_node_base::nil)
					_base = _base->max();
				else
				{
					rb_tree_node_base* node = _base->parent;
					while (node->left == _base)
					{
						_base = node;
						node = node->parent;
					}
					_base = node;
				}
				return _base;
			}
			rb_tree_node_base* min()
			{
				rb_tree_node_base* node = this;
				if (node == nil)
					return node;
				while (node->left != nil)
					node = node->left;
				return node;
			}
			rb_tree_node_base* max()
			{
				rb_tree_node_base* node = this;
				if (node == nil)
					return node;
				while (node->right != nil)
					node = node->right;
				return node;
			}

	};
	rb_tree_node_base rb_tree_node_base::_nil_node = rb_tree_node_base(rb_black);
	rb_tree_node_base* rb_tree_node_base::nil = &rb_tree_node_base::_nil_node;
	template<typename T>
	class rb_tree_node : public rb_tree_node_base
	{
		public:
			T data;
			typedef rb_tree_node_base* base_ptr;
			rb_tree_node(T data, rb_tree_color color = rb_red) : rb_tree_node_base(color), data(data)
		{
			parent = nil;
			left = nil;
			right = nil;
		}

	};
	template<typename T>
	class rb_tree_iterator;
}
