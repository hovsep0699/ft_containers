#pragma once

#include <memory>
#include "bits/functional.hpp"
#include <deque>

namespace ft
{
	/* ==================== */
	/*      containers      */
	/* ==================== */

	template<typename T1,
			typename T2>
	struct pair;

    template<typename T>
    struct allocator;

    template<typename T,
    		typename _Allocator = ft::allocator<T> >
    class deque;

	template<typename T,
			typename _Allocator = ft::allocator<T> >
	class vector;

	template<typename T,
			typename _Container = std::deque<T> >
	class queue;

	template<typename T,
			typename _Container = ft::vector<T> >
	class stack;

	template<typename _K,
			typename _V,
			typename _Compare = ft::less<_K>,
			typename _Allocator = ft::allocator<ft::pair<const _K, _V> > >
	class map;

	template< typename _K,
			typename _Compare = ft::less<_K>,
			typename _Allocator = ft::allocator<_K> >
	class set;

	template< typename _K,
			typename _Compare = ft::less<_K>,
			typename _Allocator = ft::allocator<_K> >
	class multiset;

	template<typename _K,
		typename _V,
		typename _Compare = ft::less<_K>,
		typename _Allocator = ft::allocator<ft::pair<const _K, _V> > >
	class multimap;

	/* ================================================ */
	/*      swap specialization for each container      */
	/* ================================================ */
	
    template<typename T,
    		typename U>
    void swap(pair<T, U>& lhs, 
    		pair<T, U>& rhs);

    template<typename T,
    		typename _Alloc>
    void swap(vector<T, _Alloc>& lhs, 
    		vector<T, _Alloc>& rhs);

    template<typename T,
    		typename _Container>
    void swap(queue<T, _Container>& lhs, 
    		queue<T, _Container>& rhs);

    template<typename T,
    		typename _Container>
    void swap(stack<T, _Container>& lhs, 
    		stack<T, _Container>& rhs);

	template< typename _K, 
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	void swap( map<_K, _V, _Compare, _Allocator>& lhs, 
           		map<_K, _V, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare, 
			typename _Allocator >
	void swap( set<_K, _Compare, _Allocator>& lhs, 
           		set<_K, _Compare, _Allocator>& rhs );

	template< typename T, 
			typename _Allocator >
	void swap( deque<T, _Allocator>& lhs, 
           		deque<T, _Allocator>& rhs );

	template< typename _K, 
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	void swap( multimap<_K, _V, _Compare, _Allocator>& lhs, 
           		multimap<_K, _V, _Compare, _Allocator>& rhs );

	template< typename _K, 
			typename _Compare, 
			typename _Allocator >
	void swap( multiset<_K, _Compare, _Allocator>& lhs, 
           		multiset<_K, _Compare, _Allocator>& rhs );

}

