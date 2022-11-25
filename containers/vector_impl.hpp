#pragma once

#include "bits/utility.hpp"
#include "containers/vector.hpp"
#include <sstream>

namespace ft
{

	template<typename T,
			typename Alloc>
	void vector<T, Alloc>::range_construct(size_type count, const_reference value, ft::true_type)
	{
		size_type _capacity = update_size(count);
		pointer _data = _alloc.allocate(_capacity);
		try
		{
			ft::uninitialized_fill_n(_data, count, value, _alloc);
		}
		catch (...)
		{
			_alloc.deallocate(_data);
			throw ;
		}
		this->_data = _data;
		this->_size = count;
		this->_capacity = _capacity;
	}

	template<typename T,
			typename Alloc>
	template<typename InputIterator>
	void vector<T, Alloc>::range_construct(InputIterator first, InputIterator last, ft::false_type)
	{
		typedef typename ft::iterator<InputIterator>::iterator_category category;
		range_construct_select(first, last, category());
	}

	template<typename T,
			typename Alloc>
	template<typename InputIterator>
	void vector<T, Alloc>::range_construct_select(InputIterator first, InputIterator last, ft::input_iterator_tag)
	{
		for ( ; first != last; ++first )
			push_back(*first);
	}

	template<typename T,
			typename Alloc>
	template<typename InputIterator>
	void vector<T, Alloc>::range_construct_select(InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		range_construct_select(first, last, ft::input_iterator_tag());
	}

	template<typename T,
			typename Alloc>
	template<typename ForwardIterator>
	void vector<T, Alloc>::range_construct_select(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag)
	{
		size_type range_len = ft::distance(first, last);
		pointer _data = _alloc.allocate(range_len);
		pointer _end = _data;
		try
		{
			_end = ft::uninitialized_copy(first, last, _data, _alloc);
		}
		catch (...)
		{
			_alloc.deallocate(_data);
			throw ;
		}
		_capacity = range_len;
		_size = range_len;
	}

	template<typename T,
			typename Alloc>
	template<typename ForwardIterator>
	void vector<T, Alloc>::range_construct_select(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
	{
		range_construct_select(first, last, ft::forward_iterator_tag());
	}

    template<typename T,
    		typename Alloc>
    vector<T, Alloc>::vector(const allocator_type& alloc)
    	:	_given_alloc(alloc),
    		_alloc(),
			_data(ft_nullptr),
            _size(0),
			_capacity(0),
            _max_size(alloc.max_size())
    {}
    
    template<typename T,
    		typename Alloc>
    vector<T, Alloc>::vector(size_type count, const_reference value, const allocator_type& alloc)
        :	_given_alloc(alloc),
        	_alloc(),
            _data(ft_nullptr),
            _size(0), 
			_capacity(0),
           _max_size(alloc.max_size())
    {
    	range_construct(count, value, ft::true_type());
    }

    template<typename T,
    		typename Alloc>
    vector<T, Alloc>::vector(const vector<T, Alloc>& other)
    	:	_given_alloc(other._alloc),
    		_alloc(other._alloc),
        	_data(ft_nullptr),
            _size(0),
            _capacity(0),
       	   _max_size(other._alloc.max_size())
    {
    	range_construct(other.begin(), other.end(), ft::false_type());
    }


    template<typename T, 
    		typename Alloc>
    template <typename InputIterator>
    vector<T, Alloc>::vector (InputIterator first, InputIterator last, 
                            const allocator_type& alloc)
		:	_given_alloc(alloc),
			_alloc(),
			_data(ft_nullptr),
			_size(0),
			_capacity(0),
			_max_size(alloc.max_size())
    {
		typedef typename is_integral<InputIterator>::type integral;
		range_construct(first, last, integral() );
    }

    template<typename T,
    		typename Alloc>
    vector<T, Alloc>& vector<T, Alloc>::operator= (const vector<T, Alloc>& other)
    {
        if (this != &other)
        {
        	size_type other_size = other.size();
        	if (other_size > capacity())
			{
				pointer _data = _alloc.allocate(other_size);
				try
				{
					ft::uninitialized_copy(other.begin(), other.end(), iterator(_data), _alloc);
					ft::destroy(begin(), end(), _alloc);
					if (this->_data)
						_alloc.deallocate(this->_data, _capacity);
					this->_data = _data;
				}
				catch(...)
				{
					if (_data)
						_alloc.deallocate(_data, other_size);
					throw ;
				}

				_capacity = other_size;
			}
			else if (size() >= other_size)
			{
				iterator it = ft::copy(other.begin(), other.end(), begin());
				ft::destroy(it, end(), _alloc);
			}
			else
			{
				ft::copy(other.begin(), other.end(), begin());
				ft::uninitialized_copy(other.end(), other.end(), end(), _alloc);
			}
			_size = other_size;

        }
        return *this;
    }
   	 
    template<typename T,
    		typename Alloc>
	void vector<T, Alloc>::range_assign(size_type count, const_reference value, ft::true_type)
	{
		if (count > _capacity)
		{
			vector tmp(count, value);
			tmp.swap(*this);
		}
		else if (count > _size)
		{
			ft::fill(begin(), end(), value);
			ft::uninitialized_fill_n(end(), count - _size, value, _alloc);
			_size = count;
		}
		else
		{
			iterator _end = ft::fill_n(begin(), count, value);
			ft::destroy(_end, end(), _alloc);
			_size = ft::distance(begin(), _end);
		}
	}

    template<typename T,
    		typename Alloc>
    template<InputIterator>
	void vector<T, Alloc>::range_assign(InputIterator first, InputIterator last, ft::false_type)
	{
		typedef typename ft::iterator<InputIterator>::iterator_category category;
		range_assign_select(first, last, category());
	}

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return _given_alloc;
    }

    template<typename T,
    		typename Alloc>
    bool vector<T, Alloc>::empty() const
    {
        return !_size;
    }
    
    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::push_back(const_reference value)
    {
       insert(end(), value);
    }

    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::pop_back()
    {
    	_alloc.destroy(_data + _size - 1);
    	--_size;
    }


    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::reserve(vector<T, Alloc>::size_type new_capacity)
    {
        if (new_capacity > _max_size)
            throw std::length_error("ft::vector::reserve");
        if (new_capacity > _capacity)
		{
			pointer _data = _alloc.allocate(new_capacity);
			try
			{
				ft::uninitialized_copy(begin(), end(), iterator(_data), _alloc);
				if (this->_data)
				{
					ft::destroy(begin(), end(), _alloc);
					_alloc.deallocate(this->_data, _capacity);
				}
				this->_data = _data;
			}
			catch(...)
			{
				if (_data)
				{
					ft::destroy(begin(), end(), _alloc);
					_alloc.deallocate(_data, new_capacity);
				}
				throw;
			}
			_capacity = new_capacity;
		}
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::update_size(size_type _new_size)
    {
        if (_new_size > _max_size)
            throw std::length_error("ft::vector::update_size");
        if (_new_size == _size) return this->_capacity;
        if (_new_size < _size)
			ft::destroy(begin() + _new_size, end(), _alloc);
        else if (_new_size > this->_capacity)
        {
            size_type _capacity;
            if (!this->_capacity) _capacity = 1;
            else if (this->_capacity < _max_size / 2)
                _capacity = this->_capacity * 2;
            else
                _capacity = _max_size;
            if (_new_size > _capacity) _capacity = _new_size;
			return _capacity;
        }
        return this->_capacity;
    }

    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::resize( size_type count, value_type value )
    {
    	size_type _new_capacity = update_size(count);
    	reserve(_new_capacity);
        if (count > _size)
        {
            for (size_type i = _size; i < count; ++i)
                _alloc.construct(_data + i, value);
        }
        _size = count;
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return iterator(_data);
    }
    
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return const_iterator(_data);
    }
    
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return iterator(_data + _size);
    }
    
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return const_iterator(_data + _size);
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return reverse_iterator(end());
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return const_reverse_iterator(end());
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return reverse_iterator(begin());
    }
    
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return const_reverse_iterator(begin());
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin() const
    {
        return const_iterator(_data);
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend() const
    {
        return const_iterator(_data + _size);
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crbegin() const
    {
        return const_reverse_iterator(cend());
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crend() const
    {
        return const_reverse_iterator(cbegin());
    }
    
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {
        return _size;
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return _capacity;
    }
    
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
    	//return std::numeric_limits<difference_type>::max();
        return _max_size;
    }

    template<typename T,
    		typename Alloc>
    vector<T, Alloc>::~vector()
    {
        clear();
        if (_data)
        	_alloc.deallocate(_data, _capacity);
        _data = ft_nullptr;
    }

    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::clear()
    {
		ft::destroy(begin(), end(), _alloc);
        _size = 0;
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
    {
        return _data[n];
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
    {
        return _data[n];
    }

    template<typename T,
    		typename Alloc>
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
    template<typename T,
    		typename Alloc>
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

    template<typename T,
    		typename Alloc>
    template< typename InputIt >
	void vector<T, Alloc>::assign( InputIt first, InputIt last)
    { 
        clear();
        typedef typename is_integral<InputIt>::type integral;
        range_assign(first, last, integral());
    }

    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::assign( size_type count, const_reference value )
    {
        clear();
        for (size_type i = 0; i < count; ++i)
             push_back(value);
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::pointer vector<T, Alloc>::data()
    {
        return _data;
    }

    template<typename T,
    		typename Alloc>
	typename vector<T, Alloc>::const_pointer vector<T, Alloc>::data() const
    {
        return _data;
    }
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {
        return *_data;
    }
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {
        return *_data;
    }
    
    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {
        return *(_data + _size - 1);
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {
        return *(_data + _size - 1);
    }

    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::shrink_to_fit()
    {
        size_type _size = this->_size;
		pointer _data;
		size_type except_size;
		try
		{
			_data = _alloc.allocate(_size);
			for (except_size = 0; except_size < this->_size; ++except_size)
				_alloc.construct(_data + except_size, this->_data[except_size]);
			clear();
			this->_size = _size;
			if (this->_data)
				_alloc.deallocate(this->_data, _capacity);
			this->_data = _data;
			_capacity = _size;
		}
		catch(...)
		{
			for (size_type i = 0; i < except_size; ++i)
				_alloc.destroy(_data + i);
			if (_data)
				_alloc.deallocate(_data, _size);
			throw ;
		}
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( const_iterator pos, const_reference value )
    {
        size_type position = distance(cbegin(), pos);
    	if (begin() + capacity() != end() && pos == cend())
    	{
    		_alloc.construct(_data + position, value);
			++_size;
    		return begin() + position;
    	}
    	if (begin() + capacity() != end())
    	{
			_alloc.construct(_alloc.address(*end()), back());
			ft::copy_backward(pos, cend() - 1, end());
			*(_data + position) = value;
			++_size;
    		return begin() + position;
    	}
    	size_type _capacity = update_size(_size + 1);
    	pointer _data = _alloc.allocate(_capacity);
		if (pos == cend())
		{
			try
			{
				ft::uninitialized_copy(cbegin(), pos, _data, _alloc);
				_alloc.construct(_data + position, value);
				if (this->_data)
				{
					ft::destroy(begin(), end(), _alloc);
					_alloc.deallocate(this->_data, this->_capacity);
				}
				this->_data = _data;
			}
			catch(...)
			{
				if (_data)
				{
					_alloc.destroy(_data + position);
					_alloc.deallocate(_data, _capacity);
				}
			}
			++_size;
			this->_capacity = _capacity;
			return begin() + position;
		}
		try
		{
			ft::uninitialized_copy(cbegin(), pos, _data, _alloc);
			_alloc.construct(_data + position, value);
			ft::uninitialized_copy(pos, cend(), _data + position + 1, _alloc);
			if (this->_data)
			{
				ft::destroy(begin(), end(), _alloc);
				_alloc.deallocate(this->_data, this->_capacity);
			}
			this->_data = _data;
		}
		catch(...)
		{
			if (_data)
			{
				_alloc.destroy(_data + position);
				_alloc.deallocate(_data, _capacity);
			}
		}
		this->_capacity = _capacity;
		++_size;
        return begin() + position;
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( const_iterator pos, size_type count, const_reference value )
    {
    	return range_insert(pos, count, value, ft::true_type());
    }

	template<typename T,
			typename _Alloc>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert(const_iterator pos, size_type count, const_reference value, ft::true_type)
	{
        size_type position = distance(cbegin(), pos);
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
        return begin() + position;
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert(const_iterator pos, InputIterator first, InputIterator last, ft::false_type)
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

        return begin() + position;
	}
	
    template<typename T,
    		typename Alloc>
    template<typename InputIt>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( const_iterator pos, InputIt first, InputIt last)
    {
    	typedef typename is_integral<InputIt>::type integral;
    	return range_insert(pos, first, last, integral());
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator pos )
    {
        if (pos == end()) return end();
        value_type tmp = *pos;
        size_type position = distance(begin(), pos);
        for (size_type i = position; i < _size - 1; ++i)
            *(_data + i) = *(_data + i + 1);
        *(_data + _size - 1) = tmp;
        --_size;
        _alloc.destroy(_data + _size);
        return iterator(pos);
    }

    template<typename T,
    		typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator first, iterator last )
    {
        bool isEnd = (last == end());
        size_type range_len = distance(first, last);
        size_type pos = distance(begin(), first);

        if (first == last) return last;
		size_type i = 0;
        while (i < range_len)
        {
        	first = erase(first);
        	++i;
        }
        return isEnd ? end() : begin() + pos;

    }

    template<typename T,
    		typename Alloc>
    void vector<T, Alloc>::swap( vector& other )
    {
		ft::swap(_alloc, other._alloc);
		ft::swap(_given_alloc, other._given_alloc);
		ft::swap(_data, other._data);
		ft::swap(_size, other._size);
		ft::swap(_capacity, other._capacity);
		ft::swap(_max_size, other._max_size);
    }

	template< typename T,
			typename _Alloc >
	bool operator==(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	if (lhs.size() != rhs.size())
    		return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

	template< typename T,
			typename _Alloc >
	bool operator!=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(lhs == rhs);
    }

	template< typename T,
			typename _Alloc >
	bool operator>(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(lhs <= rhs); 
    }

	template< typename T,
			typename _Alloc >
	bool operator>=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(lhs < rhs);
    }

	template< typename T,
			typename _Alloc >
	bool operator<(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

	template< typename T,
			typename _Alloc >
	bool operator<=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs )
    {
    	return !(rhs < lhs);
    }

    template< typename T,
    		typename _Alloc >
	void swap( vector<T, _Alloc>& lhs, 
           vector<T, _Alloc>& rhs )
    {
    	lhs.swap(rhs);
    }
}

