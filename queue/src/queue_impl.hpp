#pragma once

#include <deque>
#include "queue.hpp"
#include <iostream>
namespace ft
{
    
    template<typename T, typename Container>
    queue<T, Container>::queue (const Container& container) : _cont(container)
    {}
    template<typename T, typename Container>
    queue<T, Container>::~queue ()
    {}
    template<typename T, typename Container>
    typename queue<T, Container>::size_type queue<T, Container>::size() const
    {
        return _cont.size();
    }
    template<typename T, typename Container>
    bool queue<T, Container>::empty() const
    {
        return _cont.empty();
    }
    template<typename T, typename Container>
    typename queue<T, Container>::value_type& queue<T, Container>::front()
    {
        return _cont.front();
    }
    template<typename T, typename Container>
    const typename queue<T, Container>::value_type& queue<T, Container>::front() const
    {
        return _cont.front();
    }
    template<typename T, typename Container>
    typename queue<T, Container>::value_type& queue<T, Container>::back()
    {
        return _cont.back();
    }
    template<typename T, typename Container>
    const typename queue<T, Container>::value_type& queue<T, Container>::back() const
    {
        return _cont.back();
    }
    template<typename T, typename Container>
    void queue<T, Container>::push (const typename queue<T, Container>::value_type& val)
    {
        _cont.push_back(val);
    }
    template<typename T, typename Container>
    void queue<T, Container>::pop()
    {
        _cont.pop_front();
    }
    template<typename T, typename Container>
    void queue<T, Container>::swap (queue<T, Container>& x)
    {
        Container tmp = this->_cont;
        this->_cont = x._cont;
        x._cont = tmp;

    }

    template <class T, class Container>
    bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs._cont == rhs._cont;
    }
    template <class T, class Container>
    bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs._cont != rhs._cont;
    }
    template <class T, class Container>
    bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs._cont < rhs._cont;
    }
    template <class T, class Container>
    bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs._cont <= rhs._cont;
    }
    template <class T, class Container>
    bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs._cont > rhs._cont;
    }
    template <class T, class Container>
    bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs._cont >= rhs._cont;
    }
} // namespace ft