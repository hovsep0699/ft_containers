#pragma once

#include <exception>

namespace ft
{
    template<typename T>
    struct allocator
    {
        typedef T               value_type;
        typedef T*              pointer;
        typedef const T*        const_pointer;
        typedef T&              reference;
        typedef const T&        const_reference;
        typedef std::size_t     size_type;
        typedef std::ptrdiff_t  difference_type;

        allocator() throw();
        allocator(const allocator& ) throw();

        template<typename M>
        allocator(const allocator<M>& ) throw();

        ~allocator();

        pointer address( reference x ) const;

        const_pointer address( const_reference x ) const;

        pointer allocate( size_type _n, const void* = 0 );

        size_type max_size () const throw();

        void deallocate( pointer p, std::size_t n );

        void construct( pointer p, const_reference val );

        void destroy(pointer p);

		template< class U >
		struct rebind;
    };
    template< typename T1, typename T2 >
    inline bool operator==( const allocator<T1>&, const allocator<T2>& );

    template< typename T1, typename T2 >
    inline bool operator!=( const allocator<T1>& , const allocator<T2>& );

    template< typename T>
    inline bool operator==( const allocator<T>&, const allocator<T>& );

    template< typename T>
    inline bool operator!=( const allocator<T>&, const allocator<T>& );
}

#include "allocator_impl.hpp"
