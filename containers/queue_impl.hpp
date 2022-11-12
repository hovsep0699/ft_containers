#pragma once

#include "containers/queue.hpp"

namespace ft
{
    
    template<typename T,
    		typename _Container>
    queue<T, _Container>::queue (const _Container& container)
    	:	c(container)
    {}

    template<typename T,
    		typename _Container>
    typename queue<T, _Container>::size_type queue<T, _Container>::size() const
    {
        return c.size();
    }

    template<typename T, 
    		typename _Container>
    bool queue<T, _Container>::empty() const
    {
        return c.empty();
    }

    template<typename T, 
    		typename _Container>
    typename queue<T, _Container>::reference queue<T, _Container>::front()
    {
        return c.front();
    }

    template<typename T, 
    		typename _Container>
    typename queue<T, _Container>::const_reference queue<T, _Container>::front() const
    {
        return c.front();
    }

    template<typename T,
    		typename _Container>
    typename queue<T, _Container>::value_type& queue<T, _Container>::back()
    {
        return c.back();
    }

    template<typename T,
    		typename _Container>
    typename queue<T, _Container>::const_reference queue<T, _Container>::back() const
    {
        return c.back();
    }

    template<typename T,
    		typename _Container>
    void queue<T, _Container>::push (const_reference val)
    {
        c.push_back(val);
    }

    template<typename T,
    		typename _Container>
    void queue<T, _Container>::pop()
    {
        c.pop_front();
    }

    template<typename T, 
    		typename _Container>
    void queue<T, _Container>::swap (queue& x)
    {
        swap(c, x.c);
    }

    template <typename T, 
    		 typename _Container>
    bool operator== (const queue<T, _Container>& lhs,
    				const queue<T,Container>& rhs)
    {
        return lhs.c == rhs.c;
    }

    template <typename T,
    		 typename _Container>
    bool operator!= (const queue<T, _Container>& lhs, 
    				const queue<T, _Container>& rhs)
    {
        return lhs.c != rhs.c;
    }

    template <typename T, 
    		 typename _Container>
    bool operator<  (const queue<T, _Container>& lhs, 
    				const queue<T, _Container>& rhs)
    {
        return lhs.c < rhs.c;
    }

    template <typename T, 
    		 typename _Container>
    bool operator<= (const queue<T, _Container>& lhs, 
    				const queue<T, _Container>& rhs)
    {
        return lhs.c <= rhs.c;
    }

    template <typename T,
    		 typename _Container>
    bool operator>  (const queue<T, _Container>& lhs, 
    				const queue<T, _Container>& rhs)
    {
        return lhs.c > rhs.c;
    }

    template <typename T, 
    		 typename _Container>
    bool operator>= (const queue<T, _Container>& lhs, 
    				const queue<T, _Container>& rhs)
    {
        return lhs.c >= rhs.c;
    }

    template< typename T, 
    		typename _Container >
    void swap( queue<T, _Container>& lhs,
    			queue<T, _Container>& rhs )
    {
        lhs.swap(rhs);
    }
} // namespace ft
