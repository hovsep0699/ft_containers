#pragma once

#include "bits/utility.hpp"
#include "containers/vector.hpp"
#include <sstream>

namespace ft
{

    template<typename T, typename Alloc>
    vector<T, Alloc>::vector(const allocator_type& alloc)
    	:	_allocator(alloc),
			_data(ft_nullptr),
            _size(0),
			_capacity(0),
            _max_size(alloc.max_size())
    {}
    template<typename T, typename Alloc>
    vector<T, Alloc>::vector(size_type n, const_reference val, const allocator_type& alloc)
        :	_allocator(alloc),
            _data(ft_nullptr),
            _size(0), 
			_capacity(0),
           _max_size(alloc.max_size())
    {
        resize(n, val);
    }

    template<typename T, typename Alloc>
    vector<T, Alloc>::vector(const vector<T, Alloc>& other)
    	:	_allocator(other._allocator),
        	_data(ft_nullptr),
            _size(0),
            _capacity(0),
       	   _max_size(other._allocator.max_size())
    {
        for (size_type i = 0; i < other._size; ++i)
           push_back(other._data[i]);
    }
    template<typename T, typename Alloc>
    template <typename InputIterator>
    vector<T, Alloc>::vector (InputIterator first, InputIterator last, 
                            const allocator_type& alloc,
                            typename enable_if<!is_integral<InputIterator>::value, bool>::type)
		:	_allocator(alloc),
			_data(ft_nullptr),
			_size(0),
			_capacity(0),
			_max_size(alloc.max_size())
    {
        size_type i = 0;
        for (InputIterator it = first; it != last; ++it, ++i)
            push_back(*it);
    }

    template<typename T, typename Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator= (const vector<T, Alloc>& other)
    {
        if (this != &other)
        {
            clear();
            for (size_type i = 0; i < other._size; i++)
                push_back(other._data[i]);
        }
        return *this;
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return _allocator;
    }
    template<typename T, typename Alloc>
    bool vector<T, Alloc>::empty() const
    {
        return !_size;
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::push_back(vector<T, Alloc>::const_reference val )
    {
       resize(_size + 1, val);
    }

    template<typename T, typename Alloc>
    void vector<T, Alloc>::pop_back()
    {
       resize(_size - 1);
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::reserve(vector<T, Alloc>::size_type new_capacity)
    {
        if (new_capacity > _max_size)
            throw std::length_error("ft::vector::reserve");
        if (new_capacity > _capacity)
		{
			_capacity = new_capacity;
            size_type _size = this->_size;
			pointer _data = _allocator.allocate(_capacity);
			size_type except_size;
			try
			{
				for (except_size = 0; except_size < this->_size; ++except_size)
					_allocator.construct(_data + except_size, this->_data[except_size]);
				clear();
				this->_size = _size;
				_allocator.deallocate(this->_data, _capacity);
				this->_data = _data;

			}
			catch(...)
			{
				for (size_type i = 0; i < except_size; ++i)
					_allocator.destroy(_data + i);
				_allocator.deallocate(_data, _capacity);
			}
		}
            // assert(_data == ft_nullptr);
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::resize( size_type count, value_type value )
    {
    	if (count < 0) return;
        if (count > _max_size)
            throw std::length_error("ft::vector::resize");
        if (count == _size) return ;
        if (count < _size)
        {
            for (size_type i = count; i < _size; ++i)
                _allocator.destroy(_data + i);
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
        if (count > _size)
        {
            for (size_type i = _size; i < count; ++i)
                _allocator.construct(_data + i, value);

        }
        _size = count;
    }

    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return iterator(_data);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return const_iterator(_data);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return iterator(_data + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return const_iterator(_data + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return reverse_iterator(end());
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return const_reverse_iterator(end());
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return reverse_iterator(begin());
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return const_reverse_iterator(begin());
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const
    {
        return const_iterator(_data);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const
    {
        return const_iterator(_data + _size);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crbegin() const
    {
        return const_reverse_iterator(cend());
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crend() const
    {
        return const_reverse_iterator(cbegin());
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
        clear();
        _allocator.deallocate(_data, _size);
        _data = ft_nullptr;
    }

    template<typename T, typename Alloc>
    void vector<T, Alloc>::clear()
    {
        for (size_type i = 0; i < _size; ++i)
            _allocator.destroy(_data + i);
        _size = 0;
    }

    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
    {
        return _data[n];
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
    {
        return _data[n];
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at (size_type _n) const
    {
        if (_n >= _size)
        {
            std::stringstream ss("ft::vector::at: __n (which is ");
            ss << _n << ") >= this->size() (which is " << this->_size << ")";
            throw std::out_of_range(ss.str());
        }
        return _data[_n];
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type _n)
    {
        if (_n >= _size)
        {
            std::stringstream ss("ft::vector::at: __n (which is ");
            ss << _n << ") >= this->size() (which is " << this->_size << ")";
            throw std::out_of_range(ss.str());
        }
        return _data[_n];
    }

    template<typename T, typename Alloc>
    template< class InputIt >
	void vector<T, Alloc>::assign( InputIt first, InputIt last,
        typename enable_if<!is_integral<InputIt>::value, bool>::type)
    { 
        clear();
        size_type i = 0;
        for (InputIt it = first; it != last; ++it, ++i)
            push_back(*it);
        
    }
    template<typename T, typename Alloc>
    void vector<T, Alloc>::assign( size_type count, const_reference value )
    {
        clear();
        for (size_type i = 0; i < count; ++i)
             push_back(value);
    }

    template<typename T, typename Alloc>
    typename vector<T, Alloc>::pointer vector<T, Alloc>::data()
    {
        return _data;
    }

    template<typename T, typename Alloc>
	typename vector<T, Alloc>::const_pointer vector<T, Alloc>::data() const
    {
        return _data;
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {
        return *_data;
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {
        return *_data;
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {
        return *(_data + _size - 1);
    }
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {
        return *(_data + _size - 1);
    }

    template<typename T, typename Alloc>
    void vector<T, Alloc>::shrink_to_fit()
    {
        size_type _size = this->_size;
		pointer _data;
		size_type except_size;
		try
		{
			_data = _allocator.allocate(_size);
			for (except_size = 0; except_size < this->_size; ++except_size)
				_allocator.construct(_data + except_size, this->_data[except_size]);
			clear();
			this->_size = _size;
			_allocator.deallocate(this->_data, _capacity);
			this->_data = _data;
			_capacity = _size;
		}
		catch(...)
		{
			for (size_type i = 0; i < except_size; ++i)
				_allocator.destroy(_data + i);
			_allocator.deallocate(_data, _size);
			throw ;
		}
    }
    //template<typename T, typename Alloc>
    //typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( const_iterator pos, const_reference value )
    //{
    //    size_type position = distance(cbegin(), pos);
    //    size_type old_size = _size;
    //    resize(_size + 1);

    //    size_type i = _size;
    //    while ( i >= position && i)
    //    {
    //        *(_data + i) = *(_data + old_size);
    //        --old_size;
    //        --i;
    //    }
    //    *(_data + position) = value;
    //    return iterator(begin() + position - 1);
    //}

    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( iterator pos, const_reference value )
    {
        size_type position = distance(begin(), pos);
        size_type old_size = _size;
        resize(_size + 1);

        size_type i = _size;
        while ( i >= position && i)
        {
            *(_data + i) = *(_data + old_size);
            --old_size;
            --i;
        }
        *(_data + position) = value;
        return iterator(begin() + position);
    }
    //template<typename T, typename Alloc>
    //typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( const_iterator pos, size_type count, const_reference value )
    //{
    //    size_type position = distance(cbegin(), pos);
    //    size_type old_size = _size;
    //    resize(_size + count);
    //
    //    size_type i = _size;
    //    while ( i >= position && i)
    //    {
    //        *(_data + i) = *(_data + old_size);
    //        --old_size;
    //        --i;
    //    }
    //    i = position;
    //    while (count)
    //    {
    //        _data[i] = value;
    //        ++i;
    //        --count;
    //    }
    //    return iterator(begin() + position);
    //}
    template<typename T, typename Alloc>
    void vector<T, Alloc>::insert( iterator pos, size_type count, const_reference value )
    {
        size_type position = distance(begin(), pos);
        size_type old_size = _size;
        resize(_size + count);
    
        size_type i = _size;
        while ( i >= position && i)
        {
            *(_data + i) = *(_data + old_size);
            --old_size;
            --i;
        }
        i = position;
        while (count)
        {
            _data[i] = value;
            ++i;
            --count;
        }
    }

    template<typename T, typename Alloc>
    template<typename InputIt>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( const_iterator pos, InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*)
    {
		size_type position = distance(cbegin(), pos);
		size_type i = 0;
		while (first != last)
		{
			iterator it = begin() + position + i;
			insert(it, *first);
			++i;
			++first;
		}

        return iterator(begin() + position);
    }

    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator pos )
    {
        if (pos == end()) return end();
        value_type tmp = *pos;
        size_type position = distance(begin(), pos);
        for (size_type i = position; i < _size - 1; ++i)
            *(_data + i) = *(_data + i + 1);
        *(_data + _size - 1) = tmp;
        --_size;
        _allocator.destroy(_data + _size);
        return iterator(pos);
    }
    //template<typename T, typename Alloc>
    //typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( const_iterator pos )
    //{
    //    if (pos == cend()) return end();
    //    value_type tmp = *pos;
    //    size_type position = distance(cbegin(), pos);
    //    for (size_type i = position; i < _size - 1; ++i)
    //        *(_data + i) = *(_data + i + 1);
    //    *(_data + _size - 1) = tmp;
    //    resize(_size - 1);
    //    return iterator(begin() + position);
    //}
    template<typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator first, iterator last )
    {
        bool isEnd = (last == end());
        size_type position = distance(first, last);
        size_type pos = distance(begin(), first);

        if (first == last) return last;
        while (first != last)
        {
        	for (size_type i = distance(begin(), first); i < _size - position; ++i)
            	*(_data + i) = *(_data + i + position);
            ++first;
        }
        resize(_size - position);
        return isEnd ? end() : begin() + pos;

    }
    //template<typename T, typename Alloc>
    //typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( const_iterator first, const_iterator last )
    //{
    //    bool isEnd = (last == cend());
    //    size_type position = distance(first, last);

    //    if (position <= 0) return iterator(begin() + distance(cbegin(), last));

    //    size_type len = position;
    //    while (len)
    //    {
    //        erase(first);
    //        --len;
    //    }
    //    resize(_size - position);
    //    if (isEnd) return end(); 
    //    return iterator(begin() + distance(cbegin(), last));
    //}

    template<typename T, typename Alloc>
    void vector<T, Alloc>::swap( vector& other )
    {
		ft::swap(_allocator, other._allocator);
		ft::swap(_data, other._data);
		ft::swap(_size, other._size);
		ft::swap(_capacity, other._capacity);
		ft::swap(_max_size, other._max_size);
    }

	template< typename T, typename _Alloc >
	bool operator==(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	if (lhs.size() != rhs.size())
    		return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

	template< typename T, typename _Alloc >
	bool operator!=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(lhs == rhs);
    }

	template< typename T, typename _Alloc >
	bool operator>(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(lhs <= rhs); 
    }

	template< typename T, typename _Alloc >
	bool operator>=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(lhs < rhs);
    }

	template< typename T, typename _Alloc >
	bool operator<(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

	template< typename T, typename _Alloc >
	bool operator<=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(rhs < lhs);
    }

    template< typename T, typename _Alloc >
	void swap( vector<T, _Alloc>& lhs, 
           vector<T, _Alloc>& rhs )
    {
    	lhs.swap(rhs);
    }
}

