#pragma once

#include "rb_tree_iterator.hpp"

namespace ft
{
		template<typename T>	
		rb_tree_iterator<T>::rb_tree_iterator()
			: _base(rb_tree_node_base::nil)
		{}
		template<typename T>	
		rb_tree_iterator<T>::rb_tree_iterator(rb_tree_node_base* _base)
			: _base(_base)
		{}
		template<typename T>	
		rb_tree_iterator<T>::rb_tree_iterator(rb_tree_iterator<T> const& it)
			: _base(it._ptr)
		{}
		template<typename T>	
		rb_tree_iterator<T>& rb_tree_iterator<T>::operator=(rb_tree_iterator<T> const& it)
		{
			if (this != &it)
				_base = it._base;
			return *this;
		}
		template<typename T>	
		rb_tree_iterator<T>::~rb_tree_iterator() {}


	   /* ============================= */
	   /*     dereference operators     */
	   /* ============================= */ 

		template<typename T>	
		typename rb_tree_iterator<T>::reference rb_tree_iterator<T>::operator*() const
		{
			return static_cast<rb_tree_node<value_type>* >(_base)->data;
		}
		
		template<typename T>	
		typename rb_tree_iterator<T>::pointer rb_tree_iterator<T>::operator->() const
		{
			return _alloc.address(static_cast<rb_tree_node<value_type>* >(_base)->data);
		}

	   /* ============================= */
	   /*            increment          */
	   /* ============================= */ 

		template<typename T>	
		void rb_tree_iterator<T>::increment()
		{
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
		}
		template<typename T>	
		rb_tree_iterator<T>& rb_tree_iterator<T>::operator++()
		{
			increment();
			return *this;
		}
		template<typename T>	
		rb_tree_iterator<T> rb_tree_iterator<T>::operator++(int)
		{
			rb_tree_iterator<T> tmp(*this);
			increment();
			return tmp;
		}

	   /* ============================= */
	   /*            decrement          */
	   /* ============================= */ 
		
		template<typename T>	
		void rb_tree_iterator<T>::decrement()
		{
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
		}
		template<typename T>	
		rb_tree_iterator<T>& rb_tree_iterator<T>::operator--()
		{
			decrement();
			return *this;
		}

		template<typename T>	
		rb_tree_iterator<T> rb_tree_iterator<T>::operator--(int)
		{
			rb_tree_iterator<T> tmp(*this);
			decrement();
			return tmp;
		}
		

	   /* ============================= */
	   /*       	   base             */
	   /* ============================= */ 
		
		template<typename T>	
		rb_tree_node_base* rb_tree_iterator<T>::base()
		{
			return _base;
		}



	   /* ============================= */
	   /*       compare operators       */
	   /* ============================= */ 
		
		template<typename T>	
		bool rb_tree_iterator<T>::operator==(rb_tree_iterator<T> const& it)
		{
			return _base == it._base;
		}

		template<typename T>	
		bool rb_tree_iterator<T>::operator!=(rb_tree_iterator<T> const& it)
		{
			return _base != it._base;
		}
}
