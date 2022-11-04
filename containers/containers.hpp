#pragma once

#include <memory>
#include "bits/functional.hpp"

namespace ft
{

	template<typename T1, typename T2>
	struct pair;

    template<typename T>
    struct allocator;

	template<typename T, typename Allocator = allocator<T> >
	class vector;

	template<typename T, typename Container = vector<T> >
	class queue;

	template<typename T, typename Container = vector<T> >
	class stack;

	template<typename _K,
		typename _V,
		typename _Compare = less<_K>,
		typename _Allocator = allocator<pair<const _K, _V> > >
	class map;

	template< typename _K,
			typename _Compare = less<_K>,
			typename _Allocator = allocator<_K> >
	class set;

	template< typename _K,
			typename _Compare = less<_K>,
			typename _Allocator = allocator<_K> >
	class multiset;

	template<typename _K,
		typename _V,
		typename _Compare = less<_K>,
		typename _Allocator = allocator<pair<const _K, _V> > >
	class multimap;


	template< typename T, typename _Alloc >
	bool operator==(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T, typename _Alloc >
	bool operator!=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T, typename _Alloc >
	bool operator>(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T, typename _Alloc >
	bool operator>=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T, typename _Alloc >
	bool operator<(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T, typename _Alloc >
	bool operator<=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

    template<typename T, typename _Alloc>
    void swap(vector<T, _Alloc>& lhs, 
    		vector<T, _Alloc>& rhs);

};

