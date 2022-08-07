#pragma once

#include "allocator.hpp"
#include <limits>
#include <new>

namespace ft
{
	template<typename T>
	allocator<T>::allocator() throw()
	{}

	template<typename T>
	allocator<T>::allocator(const allocator& ) throw()
	{}

	template<typename T>
	template<typename M>
	allocator<T>::allocator(const allocator<M>& ) throw()
	{}

	template<typename T>
	allocator<T>::~allocator()
	{}

	template<typename T>
	typename allocator<T>::pointer allocator<T>::address( reference x ) const
	{
		return &x;
	}

	template<typename T>
	typename allocator<T>::const_pointer allocator<T>::address( const_reference x ) const
	{
		return &x;
	}

	template<typename T>
	typename allocator<T>::pointer allocator<T>::allocate( size_type _n )
	{
		pointer allocate_ptr;
		size_type size = _n * sizeof(value_type);
		if ( std::numeric_limits<size_type>::max() / sizeof(value_type) < _n)
			throw std::bad_array_new_length();
		if (_n > max_size())
			throw std::bad_alloc();
		allocate_ptr = reinterpret_cast<pointer>(::operator new(size));
		return allocate_ptr;
	}
	template<typename T>
	typename allocator<T>::size_type allocator<T>::max_size () const throw()
	{
		return std::numeric_limits<difference_type>::max() / sizeof(value_type);
	}

	template<typename T>
	void allocator<T>::deallocate( pointer p, std::size_t n )
	{
		(void)n;
		::operator delete((void *)p);
	}

	template<typename T>
	void allocator<T>::construct( pointer p, const_reference val )
	{
		new((pointer)p)value_type(val);
	}

	template<typename T>
	void allocator<T>::destroy(pointer p)
	{
		p->~T();
	}

	template< typename T1, typename T2 >
	bool operator==( const allocator<T1>& lhs, const allocator<T2>& rhs )
	{
		return true;
	}

	template< typename T1, typename T2 >
	bool operator!=( const allocator<T1>& lhs, const allocator<T2>& rhs )
	{
		return false;
	}

	template<typename T>
	template< class U >
	struct allocator<T>::rebind
	{
		typedef allocator<U> other;
	};
}

