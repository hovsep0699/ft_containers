#pragma once
// #include <memory>

namespace ft
{
    template<class T> struct allocator;
    template<class T, class Allocator = ft::allocator<T> >
		class vector;
    template<class T, class Container = ft::vector<T> >
		class stack;

};

