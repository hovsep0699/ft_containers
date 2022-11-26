#pragma once

#include "bits/rb_tree.hpp"

namespace ft
{

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rb_tree(bool multivalues)
		:	_rb_tree_impl(multivalues),
			_alloc(allocator_type()),
			_comp(key_compare()),
			_value_comp(_comp),
			_key_of_value()
	{}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rb_tree( const key_compare& comp,
            			const allocator_type& alloc, bool multivalues )
    	:	_rb_tree_impl(multivalues),
			_alloc(alloc),
    		_comp(comp),
    		_value_comp(_comp),
			_key_of_value()
	{}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rb_tree( const allocator_type& alloc, bool multivalues )
		:	_rb_tree_impl(multivalues),
			_alloc(alloc),
			_comp(key_compare()),
			_value_comp(_comp),
			_key_of_value()
	{}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rb_tree(const rb_tree& tree)
		:	_rb_tree_impl(tree._rb_tree_impl),
			_alloc(tree._alloc),
			_comp(tree._comp),
			_value_comp(tree._value_comp),
			_key_of_value(tree._key_of_value)
	{
		insert(tree.begin(), tree.end());
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	template< typename InputIt >
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rb_tree( InputIt first, InputIt last,
     			const key_compare& comp,
     			const allocator_type& alloc, bool multivalues)
    	:	_rb_tree_impl(multivalues),
    		_alloc(alloc),
    		_comp(comp),
    		_value_comp(_comp),
    		_key_of_value()
    {
     	while (first != last)
     	{
     		insert(*first);
     		++first;
     	}
    }

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>::~rb_tree()
	{
		clear();
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::base_ptr rb_tree<_K, _V, _KOV, _Compare, _Allocator>::root()
	{
		return _rb_tree_impl._root;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_base_ptr rb_tree<_K, _V, _KOV, _Compare, _Allocator>::root() const
	{
		return _rb_tree_impl._root;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::size_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::size() const
	{
		return _rb_tree_impl._size;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::allocator_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::get_allocator() const
	{
		return _alloc;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::size_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::count(const key_type& key) const
	{
		size_type node_count = 0;
		base_ptr node = _rb_tree_impl._root;
		while (!node->_is_nil)
		{
			key_type curr_key = s_key(node);
			if (_comp(key, curr_key))
				node = node->_left;
			else if (_comp(curr_key, key))
				node = node->_right;
			else
			{
				++node_count;
				node = node->_right;
			}
		}
        return node_count;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_const_cast(const_iterator it)
	{
		return iterator(static_cast<link_type>(
						const_cast<base_ptr>(it.base())));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::lower_bound(const key_type& key)
	{
		iterator it = begin();
		iterator it_end = end();
		while (it != it_end)
		{
			if ( !_comp(s_key(it.base()), key) )
				break;
			++it;
		}
		return it;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::lower_bound(const key_type& key) const
	{
		const_iterator it = begin();
		const_iterator it_end = end();
		while (it != it_end)
		{
			if ( !_comp(s_key(it.base()), key) )
				break;
			++it;
		}
		return it;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::upper_bound(const key_type& key) const
	{
		const_iterator it = begin();
		const_iterator it_end = end();
		while (it != it_end)
		{
			if ( _comp( key, s_key(it.base()) ) )
				break;
			++it;
		}
		//base_ptr node_begin = _rb_tree_impl._begin;
		//base_ptr node = _rb_tree_impl._nil;
		//while (!node_begin->_is_nil)
		//{
		//	if ( _comp(s_key(node_begin), key) )
		//	{
		//		node = node_begin;
		//		node_begin = s_left(node_begin);
		//	}
		//	else
		//		node_begin = s_right(node_begin);
		//}
		return it;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::upper_bound(const key_type& key)
	{
		iterator it = begin();
		iterator it_end = end();
		while (it != it_end)
		{
			if ( _comp( key, s_key(it.base()) ) )
				break;
			++it;
		}
		//base_ptr node_begin = _rb_tree_impl._begin;
		//base_ptr node = _rb_tree_impl._nil;
		//while (!node_begin->_is_nil)
		//{
		//	if ( _comp(s_key(node_begin), key) )
		//	{
		//		node = node_begin;
		//		node_begin = s_left(node_begin);
		//	}
		//	else
		//		node_begin = s_right(node_begin);
		//}
		return it;
		//base_ptr node_begin = _rb_tree_impl._begin;
		//base_ptr node = _rb_tree_impl._nil;
		//while (!node_begin->_is_nil)
		//{
		//	if ( _comp(s_key(node_begin), key) )
		//	{
		//		node = node_begin;
		//		node_begin = s_left(node_begin);
		//	}
		//	else
		//		node_begin = s_right(node_begin);
		//}
		//return iterator(node);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	ft::pair<typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator, typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator> rb_tree<_K, _V, _KOV, _Compare, _Allocator>::equal_range(const key_type& key)
	{
		return ft::make_pair(lower_bound(key), upper_bound(key));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	ft::pair<typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator, typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator> rb_tree<_K, _V, _KOV, _Compare, _Allocator>::equal_range(const key_type& key) const
	{
		return ft::make_pair(lower_bound(key), upper_bound(key));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::key_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_key(const_link_type link)
	{
		return key_of_value_type()(link->_value);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::key_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_key(const_base_ptr ptr)
	{
		return key_of_value_type()(static_cast<const_link_type>(ptr)->_value);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_reference rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_value(const_link_type link)
	{
		return link->_value;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_reference rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_value(const_base_ptr ptr)
	{
		return static_cast<const_link_type>(ptr)->_value;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::link_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_left(const_base_ptr ptr)
	{
		return static_cast<link_type>(ptr->_left);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::link_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_right(const_base_ptr ptr)
	{
		return static_cast<link_type>(ptr->_right);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::link_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::s_current(base_ptr ptr)
	{
		return static_cast<link_type>(ptr);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::clear()
	{
		clear_tree(_rb_tree_impl._root);
		_rb_tree_impl = rb_tree_impl_type();
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::clear_tree(base_ptr node)
	{
		if (node->_is_nil)
			return ;
		clear_tree(node->_left);
		_rb_tree_impl._alloc.destroy(s_current(node));
		_rb_tree_impl._alloc.deallocate(s_current(node), 1);
		clear_tree(node->_right);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::begin()
	{
		return iterator(_rb_tree_impl._begin);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::begin() const
	{
		return const_iterator(_rb_tree_impl._begin);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::cbegin() const
	{
		return const_iterator(_rb_tree_impl._begin);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::end()
	{
		return iterator(_rb_tree_impl.increment(_rb_tree_impl._end));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::end() const
	{
		return const_iterator(_rb_tree_impl.increment(_rb_tree_impl._end));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::cend() const
	{
		return const_iterator(_rb_tree_impl.increment(_rb_tree_impl._end));
	}
	
	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::reverse_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rbegin()
	{
		return reverse_iterator(end());
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_reverse_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rbegin() const
	{
		return const_reverse_iterator(end());
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_reverse_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::crbegin() const
	{
		return const_reverse_iterator(end());
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::reverse_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rend()
	{
		return reverse_iterator(begin());
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_reverse_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rend() const
	{
		return const_reverse_iterator(begin());
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_reverse_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::crend() const
	{
		return const_reverse_iterator(begin());
	}


	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_rb_tree_impl_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::get_impl() const
	{
		return _rb_tree_impl;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::rb_tree_impl_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::get_impl()
	{
		return _rb_tree_impl;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	pair<typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator, bool> rb_tree<_K, _V, _KOV, _Compare, _Allocator>::insert(base_ptr& root, const_reference _value)
	{
		base_ptr y = _rb_tree_impl._nil;
		base_ptr x = root;
		while (!x->_is_nil)
		{
			y = x;
			if (_value_comp(_value, s_value(x)))
				x = x->_left;
			else if (_value_comp(s_value(x), _value))
				x = x->_right;
			else
				x = x->_right;
		}
		base_ptr z = _rb_tree_impl.create_node(_value);
		z->_parent = y;
		if (y->_is_nil)
			root = z;
		else if (_value_comp(_value, s_value(y)))
			y->_left = z;
		else
			y->_right = z;
		insert_fixup(z);
		iterator it(z);
		if ( _value_comp(s_value( it.base() ), s_value(_rb_tree_impl._begin) ) )
			_rb_tree_impl._begin = it.base();
		else if ( !_value_comp(s_value( it.base() ), s_value(_rb_tree_impl._begin) ) 
				&& !_value_comp(s_value(_rb_tree_impl._begin), s_value( it.base() ) ) )
			_rb_tree_impl._begin = _rb_tree_impl.min(_rb_tree_impl._begin);
		if ( _value_comp(s_value(_rb_tree_impl._end), s_value( it.base() ) ) )
			_rb_tree_impl._end = it.base();
		else if ( !_value_comp(s_value( it.base() ), s_value(_rb_tree_impl._end) ) 
				&& !_value_comp(s_value(_rb_tree_impl._end), s_value( it.base() ) ) )
			_rb_tree_impl._end = _rb_tree_impl.max(_rb_tree_impl._end);
		_rb_tree_impl._nil->_parent = _rb_tree_impl._root;
		++_rb_tree_impl._size;
		return ft::make_pair(it, true);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::insert_fixup(base_ptr z)
	{
		while (z->_parent->_color == rb_red)
		{
			if (z->_parent->_parent->_left == z->_parent)
				insert_recolor(z, z->_parent->_parent->_right, rb_right);
			else
				insert_recolor(z, z->_parent->_parent->_left, rb_left);
		}
		_rb_tree_impl._root->_color = rb_black;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::insert(iterator pos, const_reference _value)
	{
		if (_rb_tree_impl._root->_is_nil)
		{
			_rb_tree_impl._root = _rb_tree_impl.create_node(_value);
			_rb_tree_impl._root->_color = rb_black;
			_rb_tree_impl._size = 1;
			_rb_tree_impl._begin = _rb_tree_impl._root;
			_rb_tree_impl._end = _rb_tree_impl._root;
			_rb_tree_impl._nil->_parent = _rb_tree_impl._root;
			return iterator(_rb_tree_impl._begin);
		}
		if (!_rb_tree_impl._multivalues)
		{
			base_ptr ptr = find(_key_of_value(_value) ).base();
			if (!ptr->_is_nil)
				return iterator(ptr);
		}
		base_ptr head = pos.base();
		while (!head->_is_nil)
		{
			value_type val = s_value(head->_parent);
			if (!head->_is_nil &&
				head->_parent->_left == head &&
				_value_comp(_value, val))
				break ;
			if (!head->_is_nil &&
				head->_parent->_right == head &&
				_value_comp(val, _value))
				break ;
			head = head->_parent;
		}
		if (head->_is_nil)
			head = _rb_tree_impl._root;
		ft::pair<iterator, bool> p_insert = insert(head, _value);
		return p_insert.first;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	pair<typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator, bool> rb_tree<_K, _V, _KOV, _Compare, _Allocator>::insert(const_reference _value)
	{
		if (_rb_tree_impl._root->_is_nil)
		{
			_rb_tree_impl._root = _rb_tree_impl.create_node(_value);
			_rb_tree_impl._root->_color = rb_black;
			_rb_tree_impl._size = 1;
			_rb_tree_impl._begin = _rb_tree_impl._root;
			_rb_tree_impl._end = _rb_tree_impl._root;
			_rb_tree_impl._nil->_parent = _rb_tree_impl._root;
			return ft::make_pair(iterator(_rb_tree_impl._begin), true);
		}
		if (!_rb_tree_impl._multivalues)
		{
			base_ptr ptr = find(_key_of_value(_value) ).base();
			if (!ptr->_is_nil)
				return ft::make_pair(iterator(ptr), false);
		}
		ft::pair<iterator, bool> p_insert = insert(_rb_tree_impl._root, _value);
		return p_insert;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	template<typename InputIt>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::insert(InputIt first, InputIt last)
	{
		while (first != last)
		{
			insert(*first);
			++first;
		}
	}
	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::insert_recolor(base_ptr& z, base_ptr y, rb_tree_recolor side)
	{
		if (y->_color == rb_red)
		{
			z->_parent->_color = rb_black;
			y->_color = rb_black;
			z->_parent->_parent->_color = rb_red;
			z = z->_parent->_parent;
		}
		else 
		{
			if (side)
			{
				if (z == z->_parent->_right)
				{
					z = z->_parent;
					left_rotate(z);
				}
				z->_parent->_color = rb_black;
				z->_parent->_parent->_color = rb_red;
				right_rotate(z->_parent->_parent);
			}
			else
			{
				if (z == z->_parent->_left)
				{
					z = z->_parent;
					right_rotate(z);
				}
				z->_parent->_color = rb_black;
				z->_parent->_parent->_color = rb_red;
				left_rotate(z->_parent->_parent);
			}
		}
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::left_rotate(base_ptr x)
	{
		base_ptr y = x->_right;
		x->_right = y->_left;
		if (!y->_left->_is_nil)
			y->_left->_parent = x;
		y->_parent = x->_parent;
		if (x->_parent->_is_nil)
			_rb_tree_impl._root = y;
		else if (x == x->_parent->_left)
			x->_parent->_left = y;
		else
			x->_parent->_right = y;
		y->_left = x;
		x->_parent = y;
		
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::right_rotate(base_ptr x)
	{
		base_ptr y = x->_left;
		x->_left = y->_right;
		if (!y->_right->_is_nil)
			y->_right->_parent = x;
		y->_parent = x->_parent;
		if (x->_parent->_is_nil)
			_rb_tree_impl._root = y;
		else if (x == x->_parent->_right)
			x->_parent->_right = y;
		else
			x->_parent->_left = y;
		y->_right = x;
		x->_parent = y;

	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::size_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::erase( const key_type& key )
	{
		base_ptr ptr = find(key).base();
		if (ptr->_is_nil)
			return 0;
		base_ptr z = ptr;
		if ( z == _rb_tree_impl._begin )
			_rb_tree_impl._begin = _rb_tree_impl.increment(_rb_tree_impl._begin);
		if ( z == _rb_tree_impl._end )
			_rb_tree_impl._end = _rb_tree_impl.decrement(_rb_tree_impl._end);
		base_ptr y = z;
		base_ptr x;
		rb_tree_color orig_color = y->_color;
		if (z->_left->_is_nil)
		{
			x = z->_right;
			transplant(z, z->_right);
		}
		else if (z->_right->_is_nil)
		{
			x = z->_left;
			transplant(z, z->_left);
		}
		else
		{
			y = _rb_tree_impl.min(z->_right);
			orig_color = y->_color;
			x = y->_right;
			if (y->_parent == z)
				x->_parent = y;
			else
			{
				transplant(y, y->_right);
				y->_right = z->_right;
				y->_right->_parent = y;
			}
			transplant(z, y);
			y->_left = z->_left;
			y->_left->_parent = y;
			y->_color = z->_color;
		}
		if (orig_color == rb_black)
			erase_fixup(x);
		_rb_tree_impl._nil->_parent = _rb_tree_impl._root;
		_rb_tree_impl._root->_color = rb_black;
		_rb_tree_impl._alloc.destroy(s_current(z));
		_rb_tree_impl._alloc.deallocate(s_current(z), 1);
		--_rb_tree_impl._size;
		return 1;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::erase( iterator pos)
	{
		key_type key = _key_of_value(*pos);
		erase(_key_of_value(*pos));
		return(upper_bound(key));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::erase( iterator first, iterator last)
	{
		value_type value = *first;
		while (first != last)
		{
			key_type key = _key_of_value(*first);
			++first;
			erase(key);
		}
		return upper_bound(_key_of_value(value));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::erase_recolor(base_ptr& x, base_ptr w, rb_tree_recolor side)
	{
		
		if (w->_color == rb_red)
		{
			w->_color = rb_black;
			x->_parent->_color = rb_red;
			if (side == rb_right)
			{
				left_rotate(x->_parent);
				w = x->_parent->_right;
			}
			else
			{
				right_rotate(x->_parent);
				w = x->_parent->_left;
			}
		}
		if (w->_left->_color == rb_black && w->_right->_color == rb_black)
		{
			w->_color = rb_red;
			x = x->_parent;
		}
		else
		{
			if (side == rb_right)
			{
				if (w->_right->_color == rb_black)
				{
					w->_left->_color = rb_black;
					w->_color = rb_red;
					right_rotate(w);
					w = x->_parent->_right;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = rb_black;
				w->_right->_color = rb_black;
				left_rotate(x->_parent);
				x = _rb_tree_impl._root;
			}
			else
			{
				if (w->_left->_color == rb_black)
				{
					w->_right->_color = rb_black;
					w->_color = rb_red;
					left_rotate(w);
					w = x->_parent->_left;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = rb_black;
				w->_left->_color = rb_black;
				right_rotate(x->_parent);
				x = _rb_tree_impl._root;
			}
		}
	}
	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::erase_fixup(base_ptr x)
	{
		while (x != _rb_tree_impl._root && x->_color == rb_black)
		{
			if (x == x->_parent->_left)
				erase_recolor(x, x->_parent->_right, rb_right);
			else
				erase_recolor(x, x->_parent->_left, rb_left);
		}
		x->_color = rb_black;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::transplant(base_ptr u, base_ptr v)
	{
		if (u->_parent->_is_nil)
			_rb_tree_impl._root = v;
		else if (u == u->_parent->_left)
			u->_parent->_left = v;
		else
			u->_parent->_right = v;
		v->_parent = u->_parent;
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::find(const key_type& key)
	{
		base_ptr node = _rb_tree_impl._root;
		while (!node->_is_nil)
		{
			if (!_comp(key, s_key(node)) && !_comp(s_key(node), key))
				break;
			if (_comp(key, s_key(node)))
				node = node->_left;
			else
				node = node->_right;
		}
		return iterator(node);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::const_iterator rb_tree<_K, _V, _KOV, _Compare, _Allocator>::find(const key_type& key) const
	{
		base_ptr node = _rb_tree_impl._root;
		while (!node->_is_nil)
		{
			if (!_comp(key, s_key(node)) && !_comp(s_key(node), key))
				break;
			if (_comp(key, s_key(node)))
				node = node->_left;
			else
				node = node->_right;
		}
		return const_iterator(node);
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	bool rb_tree<_K, _V, _KOV, _Compare, _Allocator>::empty() const
	{
		return begin() == end();
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>::value_compare::value_compare(key_compare comp)
		: comp(comp)
	{}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	bool rb_tree<_K, _V, _KOV, _Compare, _Allocator>::value_compare::operator()(const_reference lhs, const_reference rhs) const
	{
		_KOV key_of_value;
		return comp(key_of_value(lhs), key_of_value(rhs));
	}

	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rb_tree<_K, _V, _KOV, _Compare, _Allocator>::operator=(const rb_tree& other)
	{
		if (this != &other)
		{
			clear();
			_alloc = other._alloc;
			_comp = other._comp;
			_key_of_value = other._key_of_value;
			_value_comp = other._value_comp;
			_rb_tree_impl = other._rb_tree_impl;
			for (const_iterator it = other.begin(); it != other.end(); ++it)
				insert(*it);
		}
		return *this;
	}
	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::key_compare rb_tree<_K, _V, _KOV, _Compare, _Allocator>::key_comp() const
	{
		return _comp;
	}
	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::value_compare rb_tree<_K, _V, _KOV, _Compare, _Allocator>::value_comp() const
	{
		return _value_comp;
	}
	template<typename _K, 
			typename _V,
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::size_type rb_tree<_K, _V, _KOV, _Compare, _Allocator>::max_size() const
	{
		return _rb_tree_impl._alloc.max_size();
	}

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator==( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs )
	{
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template< typename _K,
			typename _V,
			typename _KOV,
			typename _Compare,
			typename _Allocator >
	bool operator!=( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs )
	{
		return !(lhs == rhs);
	}

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator<( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator<=( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs )
	{
		return (lhs < rhs || lhs == rhs);
	}

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator>( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), greater<typename rb_tree<_K, _V, _KOV, _Compare, _Allocator>::value_type>());
	}

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	bool operator>=( const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 const rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs )
	{
		return (lhs > rhs || lhs == rhs);
	}

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	void swap( rb_tree<_K, _V, _KOV, _Compare, _Allocator>& lhs,
                 rb_tree<_K, _V, _KOV, _Compare, _Allocator>& rhs )
	{
		lhs.swap(rhs);
	}

	template< typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator >
	void rb_tree<_K, _V, _KOV, _Compare, _Allocator>::swap(rb_tree& other)
	{
		_rb_tree_impl.swap(other._rb_tree_impl);
		ft::swap(_alloc, other._alloc);
		ft::swap(_comp, other._comp);
		ft::swap(_value_comp, other._value_comp);
		ft::swap(_key_of_value, other._key_of_value);
	}
	template<typename T>
	inline bool operator==(const rb_tree_iterator<T>& lhs,
						const rb_tree_const_iterator<T>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename T>
	inline bool operator!=(const rb_tree_iterator<T>& lhs,
						const rb_tree_const_iterator<T>& rhs)
	{
		return !(lhs == rhs);
	}
}

