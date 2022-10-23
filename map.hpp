#pragma once

#include "stl.hpp"
#include "bits/tree_iterator_def.hpp"
#include "bits/reverse_iterator.hpp"
#include "bits/rb_tree.hpp"
#include "utility.hpp"
#include <iostream>
namespace ft
{
	template< typename Key,
		typename T,
		typename Compare,
		typename Allocator >
	class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const Key, T>					value_type;
			typedef typename Allocator::size_type			size_type;
			typedef typename Allocator::difference_type		difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef ft::rb_tree_iterator<value_type>		iterator;
			typedef ft::rb_tree_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			

			iterator begin()
			{
				return iterator(_tree.begin());
			}
			const_iterator begin() const
			{
				return const_iterator(_tree.begin());
			}
			iterator end()
			{
				return iterator(_tree.end());
			}
			const_iterator end() const
			{
				return const_iterator(_tree.end());
			}
			void clear()
			{
				iterator it = begin();
				while (it != end())
				{
					erase(it);
					++it;
				}
			}
			void get_allocator()
			{
				return _alloc;
			}
			virtual ~map()
			{
	//			clear();
			}
			map() : _tree(), _comp(key_compare()), _alloc(allocator_type())
			{}
			explicit map( const Compare& comp,
              const Allocator& alloc = Allocator() )
				: _root(rb_node_base::nil), _comp(comp), _alloc(alloc)
			{}
			explicit map( const Allocator& alloc )
				:  _root(rb_node_base::nil), _alloc(alloc), _comp(Compare())
			{}

			void erase(const key_type& key)
			{
				value_type v(ft::make_pair(key, mapped_type()));
				erase(v);
			}
			void insert(const_reference data)
			{
				if (_root == rb_node_base::nil)
				{
					_root = createNode(data);
					_root->color = rb_black;
					return ;
				}
				rb_node_base* y = rb_node_base::nil;
				rb_node_base* x = _root;
				while (x != rb_node_base::nil)
				{
					y = x;
					rb_node<value_type>* node = static_cast<rb_node<value_type>*>(x);
					if (_comp(data.first, node->data.first))	
						x = x->left;
					else
						x = x->right;
				}
				rb_node_base* z = createNode(data);
				z->parent = y;
				rb_node<value_type>* node = static_cast<rb_node<value_type>*>(y);
				if (y == rb_node_base::nil)
					_root = z;
				else if (_comp(data.first, node->data.first))
					y->left = z;
				else
					y->right = z;
				insert_fixup(z);
			}
		private:
			typedef typename Allocator::template rebind<rb_node<value_type> >::other _node_alloc;
			_node_alloc _alloc_node;
			enum rb_recolor
			{
				rb_right = true,
				rb_left = false
			};
			allocator_type				_alloc;
			key_compare					_comp;
			rb_tree						_tree;
			void insert_fixup(rb_node_base* z)
			{
				while (z->parent->color == rb_red)
				{
					if (z->parent->parent->left == z->parent)
						recolor(z, z->parent->parent->right, rb_right);
					else
						recolor(z, z->parent->parent->left, rb_left);
				}
			}

			void erase(const_reference data)
			{
				rb_node_base* z = search(data);
				if (z == rb_node_base::nil)
					return ;
				rb_node_base* y = z;
				rb_node_base* x;
				rb_color orig_color = y->color;
				if (z->left == rb_node_base::nil)
				{
					x = z->right;
					transplant(z, z->right);
				}
				else if (z->right == rb_node_base::nil)
				{
					x = z->left;
					transplant(z, z->left);
				}
				else
				{
					y = z->right->min();
					orig_color = y->color;
					x = y->right;
					if (y->parent == z
						x->parent = y;
					else
					{
						transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				if (orig_color == rb_black)
					erase_fixup(x);
			}
		protected:
			typedef tree_type::value_compare value_compare
			void erase_fixup(rb_node_base* x)
			{
				rb_node_base* w;
				while (x != _root && x->color != rb_black)
				{
					if (x == x->parent->left)
					{
						w = x->parent->right;
						if (w->color == rb_red)
						{
							w->color = rb_black;
							x->parent->color = rb_black;
							left_rotate(x->parent);
							w = x->parent->right;
						}
						if (w->left->color == rb_black && w->right->color == rb_black)
						{
							w->color = rb_red;
							x = x->parent;
						}
						else
						{
							if (w->right->color == rb_black)
							{
								w->left->color = rb_black;
								w->color = rb_red;
								right_rotate(w);
								w = x->parent->right;
							}
							w->color = x->parent->color;
							x->parent->color = rb_black;
							w->right->color = rb_black;
							left_rotate(x->parent);
							x = _root;
						}
					}
					else
					{
						w = x->parent->left;
						if (w->color == rb_red)
						{
							w->color = rb_black;
							x->parent->color = rb_black;
							right_rotate(x->parent);
							w = x->parent->left;
						}
						if (w->right->color == rb_black && w->left->color == rb_black)
						{
							w->color = rb_red;
							x = x->parent;
						}
						else
						{
							if (w->left->color == rb_black)
							{
								w->right->color = rb_black;
								w->color = rb_red;
								left_rotate(w);
								w = x->parent->left;
							}
							w->color = x->parent->color;
							x->parent->color = rb_black;
							w->left->color = rb_black;
							right_rotate(x->parent);
							x = _root;
						}

					}
				}
				x->color = rb_black;
			}

			void transplant(rb_node_base* u, rb_node_base* v)
			{
				if (u->parent == rb_node_base::nil)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}
			rb_node_base* search(const_reference data)
			{
				rb_node_base* node = _root;
				while (node != rb_node_base::nil)
				{
					rb_node<value_type>* curr = static_cast<rb_node<value_type>* >(node);
					if (!_comp(data.first, curr->data.first) && !_comp(curr->data.first, data.first))
						break;
					if (_comp(data.first, curr->data.first))
						node = node->left;
					else
						node = node->right;
				}
				return node;
			}
			void recolor(rb_node_base* z, rb_node_base* y, rb_recolor side)
			{
				if (y->color == rb_red)
				{
					z->parent->color = rb_black;
					y->color = rb_black;
					z->parent->parent->color = rb_red;
					z = z->parent->parent;
				}
				else 
				{
					if (side)
					{
						if (z == z->parent->right)
						{
							z = z->parent;
							left_rotate(z);
						}
						z->parent->color = rb_black;
						z->parent->parent->color = rb_red;
						right_rotate(z->parent->parent);
					}
					else
					{
						if (z == z->parent->left)
						{
							z = z->parent;
							right_rotate(z);
						}
						z->parent->color = rb_black;
						z->parent->parent->color = rb_red;
						left_rotate(z->parent->parent);
					}
				}
			}

	};
}
