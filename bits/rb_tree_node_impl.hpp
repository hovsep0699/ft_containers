#pragma once

#include "bits/rb_tree_node.hpp"
namespace ft
{
	/* ============================ */
	/*	    base node structure		*/
	/* ============================ */

	rb_tree_node_base::rb_tree_node_base(rb_tree_color _color)
		:	_left(ft_nullptr),
			_right(ft_nullptr),
			_parent(ft_nullptr),
			_is_nil(true),
			_color(_color)
	{}
	rb_tree_node_base::rb_tree_node_base(const rb_tree_node_base& node)
		:	_left(node._left),
			_right(node._right),
			_parent(node._parent),
			_is_nil(node._is_nil),
			_color(node._color)
	{}
	rb_tree_node_base& rb_tree_node_base::operator=(const rb_tree_node_base& node)
	{
		if (this != &node)
		{
			_left = node._left;
			_right = node._right;
			_parent = node._parent;
			_color = node._color;
			_is_nil = node._is_nil;
		}
		return *this;
	}

	template<typename T>
	rb_tree_node<T>::rb_tree_node(const rb_tree_node& node)
		:	rb_tree_node_base(node),
			_value(node._value)
	{}

	template<typename T>
	rb_tree_node<T>::rb_tree_node(T _value, rb_tree_color _color)
		:	rb_tree_node_base(_color),
			_value(_value)
	{}

	template<typename T>
	rb_tree_node<T>& rb_tree_node<T>::operator=(const rb_tree_node& node)
	{
		if (this != node)
		{
			rb_tree_node_base::operator=(node);
			_value = node._value;
		}
		return *this;
	}

	/* ============================ */
	/*	      node structure		*/
	/* ============================ */

	template<typename T, typename _Allocator>
	rb_tree_impl<T, _Allocator>::rb_tree_impl(const allocator_type alloc)
		:	_alloc(alloc),
			_size(0)
	{
		initialize();
	}
	
	template<typename T, typename _Allocator>
	void rb_tree_impl<T, _Allocator>::initialize()
	{
		_sentinel = base_type(rb_black);
		_nil = &_sentinel;
		_root = _nil;
		_begin = _nil;
		_end = _nil;
	}

	/*!
	 * @function	create_node
	 * @abstract	Creates new red-black tree node
	 * @discussion	This function take a value
	 * 				and creates new node for red-black tree
	 *
	 * @param		value of node
	 *
	 *
	 * @result		A poiner to new node
	 *
	*/
	template<typename T, typename _Allocator>
	typename rb_tree_impl<T, _Allocator>::base_ptr rb_tree_impl<T, _Allocator>::create_node(const_reference _value)
	{
		link_type node = _alloc.allocate(1);
		try
		{
			_alloc.construct(node, _value);
			node->_parent = _nil;
			node->_left = _nil;
			node->_right = _nil;
			node->_is_nil = false;
		}
		catch (...)
		{
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			throw ;
		}
		return node;
	}

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
	template<typename T, typename _Allocator>
	typename rb_tree_impl<T, _Allocator>::base_ptr rb_tree_impl<T, _Allocator>::increment(base_ptr node)
	{
		base_ptr _base = node;
		/*
		 * get max element for nil node  
		*/
		if (_base->_is_nil)
		{
			_base = _base->_parent;
			_base = max(_base);
		}
		else if (_base->_right && !_base->_right->_is_nil)
			_base = min(_base->_right);
		else
		{
			base_ptr node = _base->_parent;
			while (!_base->_is_nil && _base == node->_right)
			{
				_base = node;
				node = node->_parent;
			}
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
	template<typename T, typename _Allocator>
	typename rb_tree_impl<T, _Allocator>::base_ptr rb_tree_impl<T, _Allocator>::decrement(base_ptr node)
	{
		base_ptr _base = node;
		
		/*
		 * get max element for nil node  
		*/
		if (_base->_is_nil)
		{
			_base = _base->_parent;
			_base = max(_base);
		}
		else if (_base->_left && !_base->_left->_is_nil)
			_base = max(_base->_left);
		else
		{
			base_ptr node = _base->_parent;
			while (!_base->_is_nil && _base == node->_left)
			{
				_base = node;
				node = node->_parent;
			}
			_base = node;
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
	template<typename T, typename _Allocator>
	typename rb_tree_impl<T, _Allocator>::base_ptr rb_tree_impl<T, _Allocator>::min(base_ptr base)
	{
		base_ptr node = base;
		if (node->_is_nil)
			return node;
		while (!node->_left->_is_nil)
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
	template<typename T, typename _Allocator>
	typename rb_tree_impl<T, _Allocator>::base_ptr rb_tree_impl<T, _Allocator>::max(base_ptr base)
	{
		base_ptr node = base;
		if (node->_is_nil)
			return node;
		while (!node->_right->_is_nil)
			node = node->_right;
		return node;
	}
}

