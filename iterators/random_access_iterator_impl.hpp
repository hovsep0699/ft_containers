#pragma once

#include "iterators/random_access_iterator.hpp"


namespace ft
{
	template<typename T>
	random_access_iterator<T>::random_access_iterator()
		: _ptr(ft_nullptr)
	{}
	template<typename T>
	random_access_iterator<T>::random_access_iterator(pointer ptr)
		: _ptr(ptr)
	{}
	template<typename T>
	random_access_iterator<T>::random_access_iterator(const random_access_iterator<T>& it)
		: _ptr(it._ptr)
	{}
	template<typename T>
	random_access_iterator<T>& random_access_iterator<T>::operator=(const random_access_iterator<T>& it)
	{
		if (&it != this)
			_ptr = it._ptr;
		return *this;
	}
	//
	// dereference operators
	//
	template<typename T>
	typename random_access_iterator<T>::reference random_access_iterator<T>::operator*() const
	{
		return *_ptr;
	}

	template<typename T>
	typename random_access_iterator<T>::pointer random_access_iterator<T>::operator->() const
	{
		return _ptr;
	}
	//
	// other operations
	//
	template<typename T>
	random_access_iterator<T>& random_access_iterator<T>::operator++()
	{
		++_ptr;
		return *this;
	}

	template<typename T>
	random_access_iterator<T> random_access_iterator<T>::operator++(int)
	{
		random_access_iterator<T> tmp(*this);
		++_ptr;
		return tmp;
	}

	template<typename T>
	random_access_iterator<T>& random_access_iterator<T>::operator--()
	{
		--_ptr;
		return *this;
	}

	template<typename T>
	random_access_iterator<T> random_access_iterator<T>::operator--(int)
	{
		random_access_iterator<T> tmp(*this);
		--_ptr;
		return tmp;
	}

	template<typename T>
	random_access_iterator<T>& random_access_iterator<T>::operator+=(difference_type offset)
	{
		_ptr += offset;
		return *this;
	}

	template<typename T>
	random_access_iterator<T>& random_access_iterator<T>::operator-=(difference_type offset)
	{
		_ptr -= offset;
		return *this;
	}

	template<typename T>
	random_access_iterator<T> random_access_iterator<T>::operator+(difference_type offset) const
	{
		random_access_iterator<T> tmp(*this);
		tmp += offset;
		return tmp;
	}
	template<typename T>
	random_access_iterator<T> random_access_iterator<T>::operator-(difference_type offset) const
	{
		random_access_iterator<T> tmp(*this);
		tmp -= offset;
		return tmp;
	}

	template<typename T>
	typename random_access_iterator<T>::reference random_access_iterator<T>::operator[](difference_type n)
	{
		return _ptr[n];
	}

	template<typename T>
	typename random_access_iterator<T>::const_reference random_access_iterator<T>::operator[](difference_type n) const
	{
		return _ptr[n];
	}

	template<typename T>
	typename random_access_iterator<T>::pointer random_access_iterator<T>::base()
	{
		return _ptr;
	}

	template<typename T>
	typename random_access_iterator<T>::const_pointer random_access_iterator<T>::base() const
	{
		return _ptr;
	}

	// compare operations
	//
	template<typename T>
	bool operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename T>
	bool operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename T>
	bool operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename T>
	bool operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename T>
	bool operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename T>
	bool operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename T1, typename T2>
	bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename T1, typename T2>
	bool operator>(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename T1, typename T2>
	bool operator<(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<typename T>
	random_access_iterator<T>::operator random_access_iterator<const value_type>() const
	{
		return random_access_iterator<const value_type>(base());
	}

	template<typename T>
	random_access_iterator<T>  operator+(
			typename random_access_iterator<T>::difference_type rhs,
			const random_access_iterator<T>& lhs)
	{
		return lhs.base() + rhs;
	}


	template<typename IType>
	typename random_access_iterator<IType>::difference_type operator-(
			const random_access_iterator<IType>& rhs,
			const random_access_iterator<IType>& lhs)
	{
		return rhs.base() - lhs.base();
	}

	template<typename LIter, typename RIter>
	typename random_access_iterator<LIter>::difference_type operator-(
			const random_access_iterator<LIter>& rhs, 
			const random_access_iterator<RIter>& lhs)
	{
		return rhs.base() - lhs.base();
	}
}

