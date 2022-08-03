#pragma once

#include "vector.hpp"
// #include <stdexcept>
namespace ft
{

    template<typename T, typename Alloc>
    vector<T, Alloc>::vector(const allocator_type& alloc)
        :	elems(ft_nullptr),
            _size(0),
            _capacity(0),
            allocator(alloc)
    {}
    template<typename T, typename Alloc>
    vector<T, Alloc>::vector(size_type n, const allocator_type& alloc)
        :	_size(n), 
            _capacity(n),
            allocator(alloc)
    {
        elems = allocator.allocate(n);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return allocator;
    }
    template<typename T, typename Alloc>
    bool vector<T, Alloc>::empty() const
    {
        return !elems;
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::push_back(vector<T, Alloc>::const_reference val )
    {
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::reserve(vector<T, Alloc>::size_type new_capacity)
    {
        if (new_capacity > allocator.max_size())
            throw std::length_error("std::length_error");
        if (new_capacity > _capacity)
		{
			_capacity = new_capacity;
			pointer elems = allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; ++i)
				allocator.construct(elems + i, this->elems[i]);
			allocator.deallocate(this->elems, _capacity);
			this->elems = elems;
		}
    }

    template<typename T, typename Alloc>
    void vector<T, Alloc>::resize( typename vector<T, Alloc>::size_type count, T value )
    {
		resize(count, value);
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::resize( typename vector<T, Alloc>::size_type count, const T& value )
    {
        if (count > allocator.max_size())
            throw std::length_error("std::length_error");
        if (count < _size)
            _size = count;
		if (count > _size)
		{
			reserve(count);
			for (size_type i = count - _size; i < count; ++i)
				allocator.construct(elems + i, value);
		}
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::resize( typename vector<T, Alloc>::size_type count )
    {
        if (count > _size)
        {
            _size = count;
            return ;
        }
        if (count < _size)
    }

    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return iterator(elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return iterator(elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return iterator(elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return iterator(elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return reverse_iterator(elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return reverse_iterator(elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return reverse_iterator(elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return reverse_iterator(elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const
    {
        return const_iterator(elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const
    {
        return const_iterator(elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crbegin() const
    {
        return const_reverse_iterator(elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crend() const
    {
        return const_reverse_iterator(elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {
        return _size;
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return _capacity;
    }
    template<typename T, typename Alloc>
    vector<T, Alloc>::~vector()
    {
        allocator.deallocate(elems, _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
    {
        return elems[n];
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
    {
        return elems[n];
    }
}
