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
	template<typename _K, typename _V, typename _KOV, typename _Compare, typename _Allocator>
	class rb_tree
	{
		
		enum rb_tree_recolor
		{
			rb_right = true,
			rb_left = false
		};
		typedef typename _Allocator::template rebind<_V>::other node_allocator;
		protected:
			typedef _K key_type;
			typedef _V value_type;
			typedef _KOV key_of_value_type;
			typedef _Compare key_compare;
			typedef _Allocator allocator_type;
			typedef rb_tree_node_base* base_ptr;
			typedef const rb_tree_node_base* const_base_ptr;
			typedef rb_tree_node<value_type>* link_type;
			typedef const rb_tree_node<value_type>* const_link_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef bidirectional_iterator_tag iterator_category;
			typedef typename _Allocator::difference_type difference_type;
			typedef typename _Allocator::size_type size_type;
		private:
			_Allocator		_alloc;
			node_allocator	_node_alloc;
			_Compare		_comp;
			base_ptr		_root;
			size_type		_size;
		public:
			rb_tree(const _Allocator& alloc = _Allocator(), const _Compare comp = _Compare()) : _root(rb_tree_node_base::nil), _comp(comp), _alloc(alloc), _size(0) {}
			base_ptr root();
			const_base_ptr root() const;
			link_type begin();
			const_link_type begin() const;
			link_type end();
			const_link_type end() const;

			rb_tree_node_base* createNode(const_reference data)
			{
				rb_tree_node<value_type>* node = _node_alloc.allocate(1);
				_node_alloc.construct(node, data);
				return node;
			}
			void insert(const_reference data)
			{
				if (_root == rb_tree_node_base::nil)
				{
					_root = createNode(data);
					_root->color = rb_black;
					_size = 1;
					return ;
				}
				rb_tree_node_base* y = rb_tree_node_base::nil;
				rb_tree_node_base* x = _root;
				while (x != rb_tree_node_base::nil)
				{
					y = x;
					rb_tree_node<value_type>* node = static_cast<rb_tree_node<value_type>*>(x);
					if (_comp(data.first, node->data.first))	
						x = x->left;
					else
						x = x->right;
				}
				rb_tree_node_base* z = createNode(data);
				z->parent = y;
				rb_tree_node<value_type>* node = static_cast<rb_tree_node<value_type>*>(y);
				if (y == rb_tree_node_base::nil)
					_root = z;
				else if (_comp(data.first, node->data.first))
					y->left = z;
				else
					y->right = z;
				insert_fixup(z);
				++_size;
			}

			void insert_fixup(rb_tree_node_base* z)
			{
				while (z->parent->color == rb_red)
				{
					if (z->parent->parent->left == z->parent)
						recolor(z, z->parent->parent->right, rb_right);
					else
						recolor(z, z->parent->parent->left, rb_left);
				}
			}

			void recolor(rb_tree_node_base* z, rb_tree_node_base* y, rb_tree_recolor side)
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
			void left_rotate(rb_tree_node_base* x)
			{
				rb_tree_node_base*  y = x->right;
				x->right = y->left;
				if (y->left != rb_tree_node_base::nil)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == rb_tree_node_base::nil)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
				
			}
			void right_rotate(rb_tree_node_base* x)
			{
				rb_tree_node_base*  y = x->left;
				x->left = y->right;
				if (y->right != rb_tree_node_base::nil)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == rb_tree_node_base::nil)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;

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
				: _ptr(rb_tree_node_base::nil)
			{}
			rb_tree_iterator(rb_tree_node_base* ptr)
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
				return static_cast<rb_tree_node<value_type>* >(_ptr)->data;
			}
			
			pointer operator->() const
			{
				return &static_cast<rb_tree_node<value_type>* >(_ptr)->data;
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
				if (_ptr->right != rb_tree_node_base::nil)
					_ptr = _ptr->right->min();
				else
				{
					rb_tree_node_base* node = _ptr->parent;
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
				else if (_ptr->left != rb_tree_node_base::nil)
					_ptr = _ptr->max();
				else
				{
					rb_tree_node_base* node = _ptr->parent;
					while (node->left == _ptr)
					{
						_ptr = node;
						node = node->parent;
					}
					_ptr = node;
				}
			}

			rb_tree_node_base* base()
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
			rb_tree_node_base* _ptr;
	};
}
