#pragma once

#include <memory>

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
};

