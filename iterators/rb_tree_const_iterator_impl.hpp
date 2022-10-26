#pragma once

#include "rb_tree_const_iterator.hpp"

namespace ft
{
		template<typename T>	
		rb_tree_const_iterator<T>::rb_tree_const_iterator()
			: _base(_rb_tree_impl._nil), _rb_tree_impl()
		{}
		template<typename T>	
		rb_tree_const_iterator<T>::rb_tree_const_iterator(base_ptr _base)
			: _base(_base)
		{}
		template<typename T>	
		rb_tree_const_iterator<T>::rb_tree_const_iterator(rb_tree_const_iterator<T> const& it)
			: _base(it._base)
		{}

		template<typename T>	
		rb_tree_const_iterator<T>::rb_tree_const_iterator(iterator const& it)
			: _base(it._base)
		{}
		template<typename T>	
		rb_tree_const_iterator<T>& rb_tree_const_iterator<T>::operator=(rb_tree_const_iterator<T> const& it)
		{
			if (this != &it)
				_base = it._base;
			return *this;
		}
		template<typename T>	
		rb_tree_const_iterator<T>::~rb_tree_const_iterator() {}

//		template<typename T>
//		rb_tree_const_iterator<T>::operator iterator() const
//		{
//			return iterator(_base);
//		}


	   /* ============================= */
	   /*     dereference operators     */
	   /* ============================= */ 

		template<typename T>	
		typename rb_tree_const_iterator<T>::reference rb_tree_const_iterator<T>::operator*() const
		{
			return static_cast<rb_tree_node<value_type>* >(_base)->_value;
		}
		
		template<typename T>	
		typename rb_tree_const_iterator<T>::pointer rb_tree_const_iterator<T>::operator->() const
		{
			return  _alloc.address(static_cast<link_type>(_base)->_value);
		}

	   /* ============================= */
	   /*            increment          */
	   /* ============================= */ 

		template<typename T>	
		rb_tree_const_iterator<T>& rb_tree_const_iterator<T>::operator++()
		{
			_base = _rb_tree_impl.increment(_base);
			return *this;
		}
		template<typename T>	
		rb_tree_const_iterator<T> rb_tree_const_iterator<T>::operator++(int)
		{
			rb_tree_const_iterator<T> tmp(*this);
			_base = _rb_tree_impl.increment(_base);
			return tmp;
		}

	   /* ============================= */
	   /*            decrement          */
	   /* ============================= */ 
		
		template<typename T>	
		rb_tree_const_iterator<T>& rb_tree_const_iterator<T>::operator--()
		{
			_base = _rb_tree_impl.decrement(_base);
			return *this;
		}

		template<typename T>	
		rb_tree_const_iterator<T> rb_tree_const_iterator<T>::operator--(int)
		{
			rb_tree_const_iterator<T> tmp(*this);
			_base = _rb_tree_impl.decrement(_base);
			return tmp;
		}
		

	   /* ============================= */
	   /*       	   base             */
	   /* ============================= */ 
		
		template<typename T>	
		typename rb_tree_const_iterator<T>::base_ptr rb_tree_const_iterator<T>::base()
		{
			return _base;
		}

		template<typename T>	
		typename rb_tree_const_iterator<T>::const_base_ptr rb_tree_const_iterator<T>::base() const
		{
			return _base;
		}


	   /* ============================= */
	   /*       compare operators       */
	   /* ============================= */ 
		
		template<typename T>	
		bool rb_tree_const_iterator<T>::operator==(rb_tree_const_iterator<T> const& it)
		{
			return _base == it._base;
		}

		template<typename T>	
		bool rb_tree_const_iterator<T>::operator!=(rb_tree_const_iterator<T> const& it)
		{
			return _base != it._base;
		}
}
