#pragma once

#include <exception>

namespace ft
{
    template<typename T>
    struct allocator
    {

		/* =================== */
		/*    member types     */
		/* =================== */

        typedef T               value_type;
        typedef T*              pointer;
        typedef const T*        const_pointer;
        typedef T&              reference;
        typedef const T&        const_reference;
        typedef std::size_t     size_type;
        typedef std::ptrdiff_t  difference_type;

		template< typename U >
		struct rebind;

		/* ========================= */
		/*      member functions     */
		/* ========================= */

    					allocator() throw();
        				allocator( const allocator& ) throw();
        template<typename M>
        				allocator(const allocator<M>& ) throw();
        virtual			~allocator();
        pointer			address( reference x ) const;
        const_pointer	address( const_reference x ) const;
        pointer			allocate( size_type _n, const void* = 0 );
        size_type		max_size () const throw();
        void			deallocate( pointer p, std::size_t n );
        void			construct( pointer p, const_reference val );
        void			destroy(pointer p);
    };

	/* ========================= */
	/*    non-member functions   */
	/* ========================= */

    template< typename T1,
    		typename T2 >
    inline bool operator==( const allocator<T1>&,
    						const allocator<T2>& );

    template< typename T1,
    		typename T2 >
    inline bool operator!=( const allocator<T1>&,
    						const allocator<T2>& );

    template< typename T>
    inline bool operator==( const allocator<T>&,
    						const allocator<T>& );

    template< typename T>
    inline bool operator!=( const allocator<T>&,
    						const allocator<T>& );
}

#include "bits/allocator_impl.hpp"
