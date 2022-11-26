#pragma once

#include "containers/stack.hpp"

namespace ft
{

    template<typename T, typename Container>
    stack<T, Container>::stack( const Container& cont )
        : c(cont)
    {}

    template<typename T, typename Container>
	stack<T, Container>::stack( const stack<T, Container>& other )
        : c(other.c)
    {}

    template<typename T, typename Container>
	stack<T, Container>& stack<T, Container>::operator=( const stack<T, Container>& other )
	{
		if (&other != this)
			c = other.c;
		return *this;
	}

    template<typename T, typename Container>
    typename stack<T, Container>::reference stack<T, Container>::top()
    {
        return c.back();
    }

    template<typename T, typename Container>
    typename stack<T, Container>::const_reference stack<T, Container>::top() const
    {
        return c.back();
    }

    template<typename T, typename Container>
    void stack<T, Container>::push( const typename stack<T, Container>::value_type& value )
    {
        c.push_back(value);
    }

    template<typename T, typename Container>
    bool stack<T, Container>::empty() const
    {
        return c.empty();
    }

    template<typename T, typename Container>
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return c.size();
    }

    template<typename T, typename Container>
    void stack<T, Container>::pop()
    {
        c.pop_back();
    }

    template<typename T, typename Container>
    void stack<T, Container>::swap( stack<T, Container>& other )
    {
        ft::swap(c, other.c);
    }

	template< typename Elem_Type, typename Base_Container >
	bool operator==( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 )
	{
		return s1.c == s2.c;
	}
	
	template< typename Elem_Type, typename Base_Container >
	bool operator!=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 )
	{
		return s1.c != s2.c;
	}
	
	template< typename Elem_Type, typename Base_Container >
	bool operator>( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 )
	{
		return s1.c > s2.c;
	}

	template< typename Elem_Type, typename Base_Container >
	bool operator<( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 )
	{
		return s1.c < s2.c;
	}

	template< typename Elem_Type, typename Base_Container >
	bool operator>=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 )
	{
		return s1.c >= s2.c;
	}

	template< typename Elem_Type, typename Base_Container >
	bool operator<=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 )
	{
		return s1.c <= s2.c;
	}

    template< class T, class Container >
    void swap( stack<T,Container>& lhs, stack<T,Container>& rhs )
    {
        lhs.swap(rhs);
    }
}
