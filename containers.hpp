#pragma once

#include <memory>
#include "functional.hpp"

namespace ft
{

	template<typename T1, typename T2>
	struct pair;

    template<typename T>
    struct allocator;

	template<typename T, typename Allocator = std::allocator<T> >
	class vector;

	template<typename T, typename Container = vector<T> >
	class queue;

	template<typename T, typename Container = vector<T> >
	class stack;

	template<typename _K,
		typename _V,
		typename _Compare = less<_K>,
		typename _Allocator = std::allocator<ft::pair<const _K, _V> > >
	class map;

	template< typename _K,
			typename _Compare = less<_K>,
			typename _Allocator = std::allocator<_K> >
	class set;
};

