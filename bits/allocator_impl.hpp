#pragma once

#include "bits/allocator.hpp"
#include "bits/utility.hpp"
#include <limits>
#include <new>
#include <memory>

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
		return ft::addressof(x);
	}

	template<typename T>
	typename allocator<T>::const_pointer allocator<T>::address( const_reference x ) const
	{
		return ft::addressof(x);
	}

	template<typename T>
	typename allocator<T>::pointer allocator<T>::allocate( size_type _n, const void* )
	{
		pointer allocate_ptr;
		if (_n > max_size())
			throw std::bad_alloc();
		allocate_ptr = static_cast<pointer>(::operator new(_n * sizeof(value_type) ) );
		return allocate_ptr;
	}
	template<typename T>
	typename allocator<T>::size_type allocator<T>::max_size () const throw()
	{
		return size_t(-1) / sizeof(value_type);
	}

	template<typename T>
	void allocator<T>::deallocate( pointer p, std::size_t )
	{
		::operator delete( ( void* )p );
	}

	template<typename T>
	void allocator<T>::construct( pointer p, const_reference val )
	{
		::new( ( void* )p ) value_type(val);
	}

	template<typename T>
	void allocator<T>::destroy(pointer p)
	{
		p->~T();
	}

	template< typename T1, typename T2 >
	bool operator==( const allocator<T1>& , const allocator<T2>&  )
	{
		return true;
	}

	template< typename T1, typename T2 >
	bool operator!=( const allocator<T1>& , const allocator<T2>& )
	{
		return false;
	}

	template< typename T>
	bool operator==( const allocator<T>& , const allocator<T>& )
	{
		return true;
	}

	template< typename T>
	bool operator!=( const allocator<T>&, const allocator<T>& )
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

