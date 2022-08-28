#pragma once

#include <memory>
#include "functional.hpp"

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

	template<typename Key,
		typename T,
		typename Compare = less<Key>,
		typename Allocator = allocator<pair<const Key, T> > >
	class map;
};

