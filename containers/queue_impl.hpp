#pragma once

#include "queue.hpp"

namespace ft
{
    
    template<typename T, typename Container>
    queue<T, Container>::queue (const Container& container) : c(container)
    {}
    template<typename T, typename Container>
    queue<T, Container>::~queue ()
    {}
    template<typename T, typename Container>
    typename queue<T, Container>::size_type queue<T, Container>::size() const
    {
        return c.size();
    }
    template<typename T, typename Container>
    bool queue<T, Container>::empty() const
    {
        return c.empty();
    }
    template<typename T, typename Container>
    typename queue<T, Container>::value_type& queue<T, Container>::front()
    {
        return c.front();
    }
    template<typename T, typename Container>
    const typename queue<T, Container>::value_type& queue<T, Container>::front() const
    {
        return c.front();
    }
    template<typename T, typename Container>
    typename queue<T, Container>::value_type& queue<T, Container>::back()
    {
        return c.back();
    }
    template<typename T, typename Container>
    const typename queue<T, Container>::value_type& queue<T, Container>::back() const
    {
        return c.back();
    }
    template<typename T, typename Container>
    void queue<T, Container>::push (const typename queue<T, Container>::value_type& val)
    {
        c.push_back(val);
    }
    template<typename T, typename Container>
    void queue<T, Container>::pop()
    {
        c.pop_front();
    }
    template<typename T, typename Container>
    void queue<T, Container>::swap (queue<T, Container>& x)
    {
        swap(c, x.c);
    }

    template <class T, class Container>
    bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c == rhs.c;
    }
    template <class T, class Container>
    bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c != rhs.c;
    }
    template <class T, class Container>
    bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c < rhs.c;
    }
    template <class T, class Container>
    bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c <= rhs.c;
    }
    template <class T, class Container>
    bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c > rhs.c;
    }
    template <class T, class Container>
    bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c >= rhs.c;
    }
    template< class T, class Container >
    void swap( queue<T,Container>& lhs, queue<T,Container>& rhs )
    {
        lhs.swap(rhs);
    }
} // namespace ft
