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
			node_allocator		_alloc_node;
			_Allocator			_alloc;
			_Compare			_comp;
			value_compare		_value_comp;
			key_of_value_type	_key_of_value;
			base_ptr			_root;
			base_ptr			_begin;
			size_type			_size;
		public:
			rb_tree() : _root(rb_tree_node_base::nil), _begin(rb_tree_node_base::nil), _comp(key_compare()),
						_value_comp(_comp), _alloc(allocator_type()), _size(0) {}
			explicit rb_tree( const key_compare& comp,
            			const allocator_type& alloc = allocator_type() ) : _root(rb_tree_node_base::nil),
            			_begin(rb_tree_node_base::nil), _comp(comp), _alloc(alloc), _size(0), _value_comp(_comp) {}
            explicit rb_tree( const allocator_type& alloc ) : _root(rb_tree_node_base::nil), _begin(rb_tree_node_base::nil), _comp(key_compare()), _value_comp(_comp), _alloc(alloc), _size(0) {}
            rb_tree(const rb_tree& tree) : _alloc(tree._alloc), _comp(tree._comp), _value_comp(tree._value_comp), _begin(rb_tree_node_base::nil), _root(rb_tree_node_base::nil), _size(tree._size)
			{
				for (const_iterator it = tree.begin(); it != tree.end(); ++it)
					insert(*it);
			}
			
			template< class InputIt >
			rb_tree( InputIt first, InputIt last,
     			const key_compare& comp = key_compare(),
     			const allocator_type& alloc = allocator_type() ) : _root(rb_tree_node_base::nil), _begin(rb_tree_node_base::nil), _size(0), _comp(comp), _value_comp(_comp), _alloc(alloc)
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
				return _root;
			}
			size_type size()
			{
				return _size;
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
				base_ptr node_begin = _begin;
				base_ptr node = rb_tree_node_base::nil;
				while (node_begin != rb_tree_node_base::nil)
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
				base_ptr node_begin = _begin;
				base_ptr node = rb_tree_node_base::nil;
				while (node_begin != rb_tree_node_base::nil)
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
			base_ptr createNode(const_reference _value)
			{
				link_type node =_alloc_node.allocate(1);
				_alloc_node.construct(node, _value);
				return node;
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
				return _root;
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
				while (node != rb_tree_node_base::nil)
				{
					erase(s_key(node));
					node = root();
				}
				_root = rb_tree_node_base::nil;
			}
			iterator  begin()
			{
				return iterator(_begin);
			}
			const_iterator begin() const
			{
				return const_iterator(_begin);
			}
			iterator end()
			{
				return iterator(rb_tree_node_base::nil);
			}
			const_iterator end() const
			{
				return const_iterator(rb_tree_node_base::nil);
			}

			ft::pair<iterator, bool> insert(base_ptr& root, const_reference _value)
			{
				iterator it = find(_key_of_value(_value) );
				if (it != end())
					return ft::make_pair(it, false);
				base_ptr y = rb_tree_node_base::nil;
				base_ptr x = root;
				while (x != rb_tree_node_base::nil)
				{
					y = x;
					if (_value_comp(_value, s_value(x)))	
						x = x->_left;
					else
						x = x->_right;
				}
				base_ptr z = createNode(_value);
				z->_parent = y;
				if (y == rb_tree_node_base::nil)
					root = z;
				else if (_value_comp(_value, s_value(y)))
					y->_left = z;
				else
					y->_right = z;
				insert_fixup(z);
				++_size;
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
				if (y->_left != rb_tree_node_base::nil)
					y->_left->_parent = x;
				y->_parent = x->_parent;
				if (x->_parent == rb_tree_node_base::nil)
					_root = y;
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
				if (y->_right != rb_tree_node_base::nil)
					y->_right->_parent = x;
				y->_parent = x->_parent;
				if (x->_parent == rb_tree_node_base::nil)
					_root = y;
				else if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
				y->_right = x;
				x->_parent = y;

			}

			void erase(const key_type& key)
			{
				iterator it = find(key);
				if (it == end())
					return ;
				base_ptr z = it.base();
				if ( !_value_comp(s_value(_begin), s_value(z)) && !_value_comp(s_value(z), s_value(_begin)))
					_begin = z->_parent;
				base_ptr y = z;
				base_ptr x;
				rb_tree_color orig_color = y->_color;
				if (z->_left == rb_tree_node_base::nil)
				{
					x = z->_right;
					transplant(z, z->_right);
				}
				else if (z->_right == rb_tree_node_base::nil)
				{
					x = z->_left;
					transplant(z, z->_left);
				}
				else
				{
					y = rb_tree_node_base::min(z->_right);
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
				--_size;
			}
			void erase_fixup(base_ptr x)
			{
				base_ptr w;
				while (x != _root && x->_color != rb_black)
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
							x = _root;
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
							x = _root;
						}

					}
				}
				x->_color = rb_black;
			}

			void transplant(base_ptr u, base_ptr v)
			{
				if (u->_parent == rb_tree_node_base::nil)
				{
					_root = v;
					_begin =rb_tree_node_base::min(_root);	
				}
				else if (u == u->_parent->_left)
					u->_parent->_left = v;
				else
					u->_parent->_right = v;
				v->_parent = u->_parent;
			}
			iterator find(const key_type& key)
			{
				base_ptr node = _root;
				while (node != rb_tree_node_base::nil)
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
				if (_root == rb_tree_node_base::nil)
				{
					_root = createNode(_value);
					_root->_color = rb_black;
					_size = 1;
					_begin = _root;
					return iterator(_begin);
				}
				base_ptr head = pos.base();
				while (head != rb_tree_node_base::nil)
				{
					if (head != rb_tree_node_base::nil &&
						head->_parent->_left == head &&
						_value_comp(_value, s_value(head->_parent)))
						break ;
					if (head != rb_tree_node_base::nil &&
						head->_parent->_right == head &&
						_value_comp(_value, s_value(head->_parent)))
						break ;
					head = head->_parent;
				}
				ft::pair<iterator, bool> p_insert = insert(head, _value);
				if ( _value_comp(s_value(p_insert.first.base()), s_value(_begin) ))
					_begin = p_insert.first.base();
				return p_insert.first;
			}
			ft::pair<iterator, bool> insert(const_reference _value)
			{
				if (_root == rb_tree_node_base::nil)
				{
					_root = createNode(_value);
					_root->_color = rb_black;
					_size = 1;
					_begin = _root;
					return ft::make_pair(iterator(_begin), true);
				}
				ft::pair<iterator, bool> p_insert = insert(_root, _value);
				if ( _value_comp(s_value(p_insert.first.base()), s_value(_begin) ))
					_begin = p_insert.first.base();
				return p_insert;
			}
			
	};
}

