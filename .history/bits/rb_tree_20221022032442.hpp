#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include "rb_tree_node.hpp"
#include "rb_tree_iterator.hpp"
#include "../utility.hpp"
#include "../functional.hpp"

namespace ft
{

	template<typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare, 
			typename _Allocator>
	class rb_tree
	{
		
		enum rb_tree_recolor
		{
			rb_right = true,
			rb_left = false
		};
		typedef typename _Allocator::template rebind<rb_tree_node<_V> >::other node_allocator;
		public:

			/* ========================= */
			/*        member types       */
			/* ========================= */

			typedef _K key_type;
			typedef _V value_type;
			typedef _V mapped_type;
			typedef _KOV key_of_value_type;
			typedef _Compare key_compare;
			typedef rb_tree_iterator<_V> iterator;
			typedef rb_tree_iterator<const _V> const_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;
			typedef rb_tree_iterator<const_iterator> const_reverse_iterator;
			typedef _Allocator allocator_type;
			typedef rb_tree_node_base* base_ptr;
			typedef const rb_tree_node_base* const_base_ptr;
			typedef rb_tree_node<value_type>* link_type;
			typedef const rb_tree_node<value_type>* const_link_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef typename _Allocator::difference_type difference_type;
			typedef typename _Allocator::size_type size_type;
		protected:
			class value_compare : public ft::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;
				public:
					value_compare(key_compare comp) : comp(comp) {}
					bool operator()( const value_type& lhs, const value_type& rhs ) const
					{
						return comp(lhs.first, rhs.first);
					}
			};
		private:
			/* ========================= */
			/*           members         */
			/* ========================= */

			rb_tree_impl<value_type, node_allocator> _rb_tree_impl;
			allocator_type		_alloc;
			key_compare			_comp;
			value_compare		_value_comp;
			key_of_value_type	_key_of_value;
		public:
			rb_tree() :  _comp(key_compare()), _value_comp(_comp), _rb_tree_impl(), _alloc(allocator_type())
			{}
			explicit rb_tree( const key_compare& comp,
            			const allocator_type& alloc = allocator_type() ) : _comp(comp), _alloc(alloc), _value_comp(_comp), _rb_tree_impl()
        	{}
            explicit rb_tree( const allocator_type& alloc ) : _comp(key_compare()), _value_comp(_comp), _alloc(alloc), _rb_tree_impl()
        	{}
            rb_tree(const rb_tree& tree) : _alloc(tree._alloc), _comp(tree._comp), _value_comp(tree._value_comp), _rb_tree_impl(tree._rb_tree_impl)
			{
				for (const_iterator it = tree.begin(); it != tree.end(); ++it)
					insert(*it);
			}
			
			template< class InputIt >
			rb_tree( InputIt first, InputIt last,
     			const key_compare& comp = key_compare(),
     			const allocator_type& alloc = allocator_type() ) : _comp(comp), _value_comp(_comp), _alloc(alloc), _rb_tree_impl()
     		{
     			while (first != last)
     			{
     				insert(*first);
     				++first;
     			}
     		}
			~rb_tree()
			{
				clear();
			}
			base_ptr root()
			{
				return _rb_tree_impl._root;
			}
			size_type size()
			{
				return _rb_tree_impl._size;
			}
			allocator_type get_allocator()
			{
				return _alloc;
			}
			size_type count(const key_type& key)
			{
                return (find(key) != end()) ? 1 : 0;
			}
			iterator lower_bound(const key_type& key)
			{
				base_ptr node_begin = _rb_tree_impl._begin;
				base_ptr node = _rb_tree_impl._nil_left;
				while (!node_begin->_is_nil)
				{
					if ( !_comp(s_key(node_begin), key) )
					{
						node = node_begin;
						node_begin = s_left(node_begin);
					}
					else
						node_begin = s_right(node_begin);
				}
				return iterator(node);
			}
			iterator upper_bound(const key_type& key)
			{
				base_ptr node_begin = _rb_tree_impl._begin;
				base_ptr node = _rb_tree_impl._nil_left;
				while (!node_begin->_is_nil)
				{
					if ( _comp(s_key(node_begin), key) )
					{
						node = node_begin;
						node_begin = s_left(node_begin);
					}
					else
						node_begin = s_right(node_begin);
				}
				return iterator(node);
			}
			ft::pair<iterator, iterator> equal_range(const key_type& key)
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}
			static key_type s_key(const_link_type link)
			{
				return key_of_value_type()(link->_value);
			}
			static key_type s_key(const_base_ptr ptr)
			{
				return key_of_value_type()(static_cast<const_link_type>(ptr)->_value);
			}
			const_base_ptr root() const
			{
				return _rb_tree_impl._root;
			}
			static const_reference s_value(const_base_ptr ptr)
			{
				return static_cast<const_link_type>(ptr)->_value;
			}
			static const_reference s_value(const_link_type link)
			{
				return link->_value;
			}
			static link_type s_left(const_base_ptr ptr)
			{
				return static_cast<link_type>(ptr->_left);
			}
			static link_type s_right(const_base_ptr ptr)
			{
				return static_cast<link_type>(ptr->_right);
			}
			void clear()
			{
				base_ptr node = root();
				while (node->_is_nil)
				{
					erase(s_key(node));
					node = root();
				}
				_rb_tree_impl._root = _rb_tree_impl._nil_left;
				_rb_tree_impl._begin = _rb_tree_impl._nil_left;
				_rb_tree_impl._end = _rb_tree_impl._nil_left;
			}
			iterator  begin()
			{
				return iterator(_rb_tree_impl._begin);
			}
			const_iterator  cbegin() 
			{
				return const_iterator(_rb_tree_impl._begin);
			}
			const_iterator  cbegin() const
			{
				return const_iterator(_rb_tree_impl._begin);
			}
			reverse_iterator rbegin()
			{
				return reverse_iterator(_rb_tree_impl._nil_right);
			}
			const_reverse_iterator rbegin() const
			{
				return reverse_iterator(_rb_tree_impl._begin);
			}
			const_reverse_iterator crbegin() const
			{
				return const_reverse_iterator(_rb_tree_impl._begin);
			}
			reverse_iterator rend()
			{
				return reverse_iterator(_rb_tree_impl._begin);

			}
			rb_tree_impl<value_type, node_allocator> get_impl() const
			{
				return _rb_tree_impl;
			}
			const_iterator begin() const
			{
				return const_iterator(_rb_tree_impl._begin);
			}
			iterator end()
			{
				return iterator(_rb_tree_impl._end->_left);
			}
			const_iterator end() const
			{
				return const_iterator(_rb_tree_impl._end);
			}
			const_iterator  cend() const
			{
				return const_iterator(_rb_tree_impl._end);
			}

			ft::pair<iterator, bool> insert(base_ptr& root, const_reference _value)
			{
				base_ptr ptr = find(_key_of_value(_value) ).base();
				if (!ptr->_is_nil)
					return ft::make_pair(iterator(ptr), false);
				base_ptr y = ((!root->_is_nil && _value_comp(s_value(_rb_tree_impl._root), s_value(root))) || root == _rb_tree_impl._root) ? _rb_tree_impl._nil_right : _rb_tree_impl._nil_left;
				base_ptr x = root;
				while (!x->_is_nil)
				{
					y = x;
					if (_value_comp(_value, s_value(x)))	
						x = x->_left;
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
				++_rb_tree_impl._size;
				return ft::make_pair(iterator(z), true);
			}

			void insert_fixup(base_ptr z)
			{
				while (z->_parent->_color == rb_red)
				{
					if (z->_parent->_parent->_left == z->_parent)
						recolor(z, z->_parent->_parent->_right, rb_right);
					else
						recolor(z, z->_parent->_parent->_left, rb_left);
				}
			}

			void recolor(base_ptr z, base_ptr y, rb_tree_recolor side)
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
			void left_rotate(base_ptr x)
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
			void right_rotate(base_ptr x)
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

			void erase(const key_type& key)
			{
				base_ptr ptr = find(key).base();
				if (ptr->_is_nil)
					return ;
				base_ptr z = ptr;
				if ( !_value_comp(s_value(_rb_tree_impl._begin), s_value(z)) && !_value_comp(s_value(z), s_value(_rb_tree_impl._begin)))
					_rb_tree_impl._begin = z->_parent;
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
				--_rb_tree_impl._size;
			}
			void erase_fixup(base_ptr x)
			{
				base_ptr w;
				while (x != _rb_tree_impl._root && x->_color != rb_black)
				{
					if (x == x->_parent->_left)
					{
						w = x->_parent->_right;
						if (w->_color == rb_red)
						{
							w->_color = rb_black;
							x->_parent->_color = rb_black;
							left_rotate(x->_parent);
							w = x->_parent->_right;
						}
						if (w->_left->_color == rb_black && w->_right->_color == rb_black)
						{
							w->_color = rb_red;
							x = x->_parent;
						}
						else
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
					}
					else
					{
						w = x->_parent->_left;
						if (w->_color == rb_red)
						{
							w->_color = rb_black;
							x->_parent->_color = rb_black;
							right_rotate(x->_parent);
							w = x->_parent->_left;
						}
						if (w->_right->_color == rb_black && w->_left->_color == rb_black)
						{
							w->_color = rb_red;
							x = x->_parent;
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
				x->_color = rb_black;
			}

			void transplant(base_ptr u, base_ptr v)
			{
				if (u->_parent->_is_nil)
				{
					_rb_tree_impl._root = v;
					_rb_tree_impl._begin = _rb_tree_impl.min(_rb_tree_impl._root);	
				}
				else if (u == u->_parent->_left)
					u->_parent->_left = v;
				else
					u->_parent->_right = v;
				v->_parent = u->_parent;
			}
			iterator find(const key_type& key)
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
			bool empty() const
			{
				return begin() == end();
			}
			iterator insert(iterator pos, const_reference _value)
			{
				if (_rb_tree_impl._root->_is_nil)
				{
					_rb_tree_impl._root = _rb_tree_impl.create_node(_value);
					_rb_tree_impl._root->_color = rb_black;
					_rb_tree_impl._size = 1;
					_rb_tree_impl._begin = _rb_tree_impl._root;
					_rb_tree_impl._nil_left->_parent = _rb_tree_impl._root;
					_rb_tree_impl._nil_right->_parent = _rb_tree_impl._root;
					_rb_tree_impl._end = _rb_tree_impl._root;
					return iterator(_rb_tree_impl._begin);
				}
				base_ptr head = pos.base();
				while (!head->_is_nil)
				{
					if (!head->_is_nil &&
						head->_parent->_left == head &&
						_value_comp(_value, s_value(head->_parent)))
						break ;
					if (!head->_is_nil &&
						head->_parent->_right == head &&
						_value_comp(_value, s_value(head->_parent)))
						break ;
					head = head->_parent;
				}
				ft::pair<iterator, bool> p_insert = insert(head, _value);
				if ( _value_comp(s_value(p_insert.first.base()), s_value(_rb_tree_impl._begin) ))
					_rb_tree_impl._begin = p_insert.first.base();
				return p_insert.first;
			}
			ft::pair<iterator, bool> insert(const_reference _value)
			{
				if (_rb_tree_impl._root->_is_nil)
				{
					_rb_tree_impl._root = _rb_tree_impl.create_node(_value);
					_rb_tree_impl._root->_color = rb_black;
					_rb_tree_impl._size = 1;
					_rb_tree_impl._begin = _rb_tree_impl._root;
					_rb_tree_impl._end = _rb_tree_impl._root;
//					_rb_tree_impl._root->_right = _rb_tree_impl._nil_right;
//					_rb_tree_impl._root->_left = _rb_tree_impl._nil_left;
//					_rb_tree_impl._nil_left->_parent = _rb_tree_impl._root;
//					_rb_tree_impl._nil_right->_parent = _rb_tree_impl._root;
//					base_ptr p = _rb_tree_impl.increment(_rb_tree_impl._end);
//					std::cout << "end: " << (p == _rb_tree_impl._nil_right) << "\n";
					return ft::make_pair(iterator(_rb_tree_impl._begin), true);
				}
				ft::pair<iterator, bool> p_insert = insert(_rb_tree_impl._root, _value);
				if ( _value_comp(s_value(p_insert.first.base()), s_value(_rb_tree_impl._begin) ))
					_rb_tree_impl._begin = p_insert.first.base();
				if ( _value_comp(s_value(_rb_tree_impl._end), s_value(p_insert.first.base()) ))
					_rb_tree_impl._end = p_insert.first.base();
				//std::cout << "end: " << iterator(_rb_tree_impl.increment(_rb_tree_impl._end))->first << "\n";
				//_rb_tree_impl._begin->_left = _rb_tree_impl._nil_left;
				//_rb_tree_impl._begin->_right = _rb_tree_impl._nil_left;
				//_rb_tree_impl._nil_left->_parent = _rb_tree_impl._begin;
//				_rb_tree_impl._end->_left = _rb_tree_impl._nil_right;
//				_rb_tree_impl._end->_right = _rb_tree_impl._nil_right;
				//std::cout << "endleft: " << (_rb_tree_impl._end->_left == _rb_tree_impl._nil_left) << "\n";
				//std::cout << "endright: " << (_rb_tree_impl._end->_right == _rb_tree_impl._nil_left) << "\n";
//				_rb_tree_impl._nil_right->_parent = _rb_tree_impl._end;
//				base_ptr p = _rb_tree_impl.increment(_rb_tree_impl._end);
//				std::cout << "end: " << (p == _rb_tree_impl._nil_right) << "\n";
				
				return p_insert;
			}
			
	};
}

