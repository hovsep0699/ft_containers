#pragma once

#include <exception>
#include <iostream>
// #include <climits>

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

        allocator() throw() {}
        allocator(const allocator& ) throw() {}

        template<typename M>
        allocator(const allocator<M>& ) throw() {}

        ~allocator() {}

        pointer address( reference x ) const
        {
            return &x;
        }

        const_pointer address( const_reference x ) const
        {
            return &x;
        }

        pointer allocate( size_type n )
        {
            pointer allocate_ptr;
            size_type size = n * sizeof(value_type);
            if ( std::numeric_limits<std::size_t>::max() / sizeof(value_type) < n)
                throw std::bad_array_new_length();
            allocate_ptr = reinterpret_cast<pointer>(::operator new(size));
            return allocate_ptr;
        }
        size_type max_size () const throw() {
           return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
        }

        void deallocate( pointer p, std::size_t n )
        {
            (void)n;
            ::operator delete((void *)p);
        }

        void construct( pointer p, const_reference val )
        {
            new((pointer)p)value_type(val);
        }

        void destroy(pointer p)
        {
            p->~T();
        }
    };
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
    template< class U >
    struct rebind
    {
        typedef allocator<U> other;
    };
    
}



