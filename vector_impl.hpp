#pragma once

#include "vector.hpp"
// #include <stdexcept>
namespace ft
{

    template<typename T, typename Alloc>
    vector<T, Alloc>::vector(const allocator_type& alloc)
        :	_elems(ft_nullptr),
            _size(0),
            _capacity(0),
            _allocator(alloc),
            _max_size(std::numeric_limits<size_type>::max() / 2)
    {}
    template<typename T, typename Alloc>
    vector<T, Alloc>::vector(size_type n, const allocator_type& alloc)
        :	_size(n), 
            _capacity(n),
            _allocator(alloc),
            _max_size(std::numeric_limits<size_type>::max() / 2)
    {
        _elems = _allocator.allocate(n);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return _allocator;
    }
    template<typename T, typename Alloc>
    bool vector<T, Alloc>::empty() const
    {
        return !_elems;
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::push_back(vector<T, Alloc>::const_reference val )
    {
       this->resize(_size + 1, val);
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::reserve(vector<T, Alloc>::size_type new_capacity)
    {
        if (new_capacity > _max_size)
            throw std::length_error("std::length_error");
        if (new_capacity > _capacity)
		{
			_capacity = new_capacity;
			pointer _elems = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; ++i)
				_allocator.construct(_elems + i, this->_elems[i]);
            for (size_type i = 0; i < _size; ++i)
				_allocator.destroy(this->_elems + i);
			_allocator.deallocate(this->_elems, _capacity);
			this->_elems = _elems;
		}
    }

    // template<typename T, typename Alloc>
    // void vector<T, Alloc>::resize( typename vector<T, Alloc>::size_type count, T value )
    // {
	// 	resize(count, value);
    // }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::resize( typename vector<T, Alloc>::size_type count, T value )
    {
        if (count > _max_size)
            throw std::length_error("std::length_error");
        if (count == _size) return ;
        if (count < _size)
        {
            for (size_type i = count; i < _size; ++i)
                _allocator.destroy(_elems + i);
        }
        else if (count > this->_capacity)
        {
            size_type _capacity;
            if (!this->_capacity) _capacity = 1;
            else if (this->_capacity < _max_size / 2)
                _capacity = this->_capacity * 2;
            else
                _capacity = _max_size;
            if (count > _capacity) _capacity = count;
            reserve(_capacity);
        }
        for (size_type i = _size; i < count; ++i)
            _allocator.construct(_elems + i, value);
        _size = count;
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::resize( typename vector<T, Alloc>::size_type count )
    {
        if (count > _max_size)
            throw std::length_error("std::length_error");
        if (count == _size) return ;
        if (count < _size)
        {
            for (size_type i = count; i < _size; ++i)
                _allocator.destroy(_elems + i);
        }
        else
        {
            size_type _capacity;
            if (!_capacity) _capacity = 1;
            if (this->_capacity < _max_size / 2)
                _capacity = this->_capacity * 2;
            else
                _capacity = _max_size;
            if (count > _capacity) _capacity = count;
            reserve(_capacity);
        }
        _size = count;
    }

    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return iterator(_elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return iterator(_elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return iterator(_elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return iterator(_elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return reverse_iterator(_elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return reverse_iterator(_elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return reverse_iterator(_elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return reverse_iterator(_elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const
    {
        return const_iterator(_elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const
    {
        return const_iterator(_elems + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crbegin() const
    {
        return const_reverse_iterator(_elems);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crend() const
    {
        return const_reverse_iterator(_elems + _size);
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
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
        return _max_size;
    }
    template<typename T, typename Alloc>
    vector<T, Alloc>::~vector()
    {
        for (size_type i = 0; i < _size; ++i)
            _allocator.destroy(_elems + i);
        _allocator.deallocate(_elems, _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
    {
        return _elems[n];
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
    {
        return _elems[n];
    }
}
