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
			: _base(it._base)
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
			return static_cast<rb_tree_node<value_type>* >(_base)->_value;
		}
		
		template<typename T>	
		typename rb_tree_iterator<T>::pointer rb_tree_iterator<T>::operator->() const
		{
			return  _alloc.address(static_cast<rb_tree_node<value_type>* >(_base)->_value);
		}

	   /* ============================= */
	   /*            increment          */
	   /* ============================= */ 

		template<typename T>	
		rb_tree_iterator<T>& rb_tree_iterator<T>::operator++()
		{
			_base = rb_tree_node_base::increment(_base);
			return *this;
		}
		template<typename T>	
		rb_tree_iterator<T> rb_tree_iterator<T>::operator++(int)
		{
			rb_tree_iterator<T> tmp(*this);
			_base = rb_tree_node_base::increment(_base);
			return tmp;
		}

	   /* ============================= */
	   /*            decrement          */
	   /* ============================= */ 
		
		template<typename T>	
		rb_tree_iterator<T>& rb_tree_iterator<T>::operator--()
		{
			_base = rb_tree_node_base::decrement(_base);
			return *this;
		}

		template<typename T>	
		rb_tree_iterator<T> rb_tree_iterator<T>::operator--(int)
		{
			rb_tree_iterator<T> tmp(*this);
			_base = rb_tree_node_base::decrement(_base);
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
