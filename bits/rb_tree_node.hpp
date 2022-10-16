#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include <iostream>
#include "rb_tree_def.hpp"
#include "../utility.hpp"
namespace ft
{
	class rb_tree_node_base
	{
		//
		// NIL node of tree
		// 
		static rb_tree_node_base _nil_node;
		public:
			static rb_tree_node_base* nil;
			typedef rb_tree_node_base* 			base_ptr;
			typedef const rb_tree_node_base*	const_base_ptr;			

			base_ptr							_left;
			base_ptr							_right;
			base_ptr							_parent;
			rb_tree_color						_color;

			rb_tree_node_base(rb_tree_color _color = rb_red) : _left(rb_tree_node_base::nil), _right(rb_tree_node_base::nil), _parent(rb_tree_node_base::nil), _color(_color) {}


			/*!
			 * @function	increment
			 * @abstract	Get next node of red-black tree
			 * @discussion	This function take a poiner of red-black tree
			 * 				and returns a pointer to next node 
			 * 				of tree
			 *
			 * @param		node pointer to node of red-black tree
			 *
			 *
			 * @result		A poiner to next node of tree
			 *
			*/
			static base_ptr increment(base_ptr node)
			{
				base_ptr _base = node;
				if (_base->_right != rb_tree_node_base::nil)
					_base = rb_tree_node_base::min(_base->_right);
				else
				{
					base_ptr node = _base->_parent;
					while (_base == node->_right)
					{
						_base = node;
						node = node->_parent;
					}
					if (_base->_right != node)
						_base = node;
				}
				return _base;
			}


			/*!
			 * @function	decrement
			 * @abstract	Get previous node of red-black tree
			 * @discussion	This function take a poiner of red-black tree
			 * 				and returns a pointer to previous node 
			 * 				of tree
			 *
			 * @param		node pointer to node of red-black tree
			 *
			 *
			 * @result		A poiner to previous node of tree
			 *
			*/
			static base_ptr decrement(base_ptr node)
			{
				base_ptr _base = node;

				if (_base->_parent->_parent == _base && _base->_color == rb_red)
					_base = _base->_left;
				else if (_base->_left != rb_tree_node_base::nil)
				{
					_base = _base->_left;
            		while (_base->_right != rb_tree_node_base::nil)
            			_base = _base->_right;
				}
				else
				{
					if (_base == _base->_parent->_right)
						_base = _base->_parent;
					else
					{
						while (_base == _base->_parent->_left)
							_base = _base->_parent;
						_base = _base->_parent;
					}
				}
				return _base;
			}
			/*!
			 * @function	min
			 * @abstract	find a leftmost node of red-black tree node
			 * @discussion	This function take a node of red-black tree
			 * 				and returns a pointer to leftmost node 
			 * 				of argument subtree
			 *
			 * @param		base node of red-black tree
			 *
			 *
			 * @result		A poiner to leftmost node of subtree
			 *
			*/
			static base_ptr min(base_ptr base)
			{
				base_ptr node = base;
				if (node == nil)
					return node;
				while (node->_left != nil)
					node = node->_left;
				return node;
			}
			/*!
			 * @function	max
			 * @abstract	find a rightmost node of red-black tree node
			 * @discussion	This function take a node of red-black tree
			 * 				and returns a pointer to rightmost node 
			 * 				of argument subtree
			 *
			 * @param		base node of red-black tree
			 *
			 *
			 * @result		A poiner to rightmost node of subtree
			 *
			*/
			static base_ptr max(base_ptr base)
			{
				base_ptr node = base;
				if (node == nil)
					return node;
				while (node->_right != nil)
					node = node->_right;
				return node;
			}

	};
	rb_tree_node_base rb_tree_node_base::_nil_node = rb_tree_node_base(rb_black);
	rb_tree_node_base* rb_tree_node_base::nil = &rb_tree_node_base::_nil_node;
	template<typename T>
	class rb_tree_node : public rb_tree_node_base
	{
		public:
			T _value;
			typedef rb_tree_node_base::base_ptr base_ptr;
			rb_tree_node(T _value, rb_tree_color _color = rb_red) : rb_tree_node_base(_color), _value(_value)
		{
			_parent = nil;
			_left = nil;
			_right = nil;
		}

	};
}
