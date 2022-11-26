#pragma once

#include "bits/utility.hpp"
#include "containers/vector.hpp"
#include <sstream>
#include <iostream>

namespace ft
{

	template<typename T,
			typename _Alloc>
	void vector<T, _Alloc>::range_construct(size_type count,
											const_reference value,
											ft::true_type)
	{
		size_type _capacity = update_size(count);
		pointer _data = _alloc.allocate(_capacity);
		try
		{
			ft::uninitialized_fill_n(_data, count, value, _alloc);
		}
		catch (...)
		{
			_alloc.deallocate(_data, _capacity);
			throw ;
		}
		this->_data = _data;
		this->_size = count;
		this->_capacity = _capacity;
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	void vector<T, _Alloc>::range_construct(InputIterator first,
											InputIterator last,
											ft::false_type)
	{
		typedef typename ft::iterator_traits<InputIterator>::iterator_category category;
		range_construct_select(first, last, category());
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	void vector<T, _Alloc>::range_construct_select(	InputIterator first,
													InputIterator last,
													ft::input_iterator_tag)
	{
		for ( ; first != last; ++first )
			push_back(*first);
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	void vector<T, _Alloc>::range_construct_select(	InputIterator first,
													InputIterator last,
													std::input_iterator_tag)
	{
		range_construct_select(first, last, ft::input_iterator_tag());
	}

	template<typename T,
			typename _Alloc>
	template<typename ForwardIterator>
	void vector<T, _Alloc>::range_construct_select(	ForwardIterator first,
													ForwardIterator last,
													ft::forward_iterator_tag)
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
			_alloc.deallocate(_data, range_len);
			throw ;
		}
		this->_data = _data;
		_capacity = range_len;
		_size = range_len;
	}

	template<typename T,
			typename _Alloc>
	template<typename ForwardIterator>
	void vector<T, _Alloc>::range_construct_select(	ForwardIterator first,
													ForwardIterator last,
													std::forward_iterator_tag)
	{
		range_construct_select(first, last, ft::forward_iterator_tag());
	}

    template<typename T,
    		typename _Alloc>
    vector<T, _Alloc>::vector(const allocator_type& alloc)
    	:	_given_alloc(alloc),
    		_alloc(),
			_data(ft_nullptr),
            _size(0),
			_capacity(0),
            _max_size(alloc.max_size())
    {}
    
    template<typename T,
    		typename _Alloc>
    vector<T, _Alloc>::vector(size_type count, const_reference value, const allocator_type& alloc)
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
    		typename _Alloc>
    vector<T, _Alloc>::vector(const vector<T, _Alloc>& other)
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
    		typename _Alloc>
    template <typename InputIterator>
    vector<T, _Alloc>::vector (InputIterator first, InputIterator last, 
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
    		typename _Alloc>
    vector<T, _Alloc>& vector<T, _Alloc>::operator= (const vector<T, _Alloc>& other)
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
				}
				catch(...)
				{
					if (_data)
						_alloc.deallocate(_data, other_size);
					throw ;
				}
				ft::destroy(begin(), end(), _alloc);
				if (this->_data)
					_alloc.deallocate(this->_data, _capacity);
				this->_data = _data;
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
    		typename _Alloc>
	void vector<T, _Alloc>::range_assign(size_type count,
										const_reference value,
										ft::true_type)
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
    		typename _Alloc>
    template<typename InputIterator>
	void vector<T, _Alloc>::range_assign(InputIterator first,
										InputIterator last,
										ft::false_type)
	{
		typedef typename ft::iterator_traits<InputIterator>::iterator_category category;
		range_assign_select(first, last, category());
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	void vector<T, _Alloc>::range_assign_select(InputIterator first,
												InputIterator last,
												ft::input_iterator_tag)
	{
		size_type i = 0;
		for ( ; first != last && i < _size; ++i, ++first)
			*(_data + i) = *first;
		if (first == last)
		{
			ft::destroy(_data + i, _data + i + _size, _alloc);
			_size = i;
		}
		else
			insert(end(), first, last);
	}

	template<typename T,
			typename _Alloc>
	template<typename ForwardIterator>
	void vector<T, _Alloc>::range_assign_select(ForwardIterator first,
												ForwardIterator last,
												ft::forward_iterator_tag)
	{
		size_type range_len = ft::distance(first, last);
		if (range_len > _capacity)
		{
			pointer _data = _alloc.allocate(range_len);
			try
			{
				uninitialized_copy(first, last, _data, _alloc);
			}
			catch (...)
			{
				_alloc.deallocate(_data, range_len);
				throw ;
			}
			ft::destroy(begin(), end(), _alloc);
			if (this->_data)
				_alloc.deallocate(this->_data, _capacity);
			this->_data = _data;
			_capacity = range_len;
			_size = range_len;
		}
		else if (_size >= range_len)
		{
			iterator _end = ft::copy(first, last, begin());
			ft::destroy(_end, end(), _alloc);
			_size = ft::distance(begin(), _end);
		}
		else
		{
			ForwardIterator it = first;
			ft::advance(it, _size);
			ft::copy(first, it, begin());
			iterator _end = ft::uninitialized_copy(it, last, end(), _alloc);
			_size = ft::distance(begin(), _end);
		}
	}

	template<typename T,
			typename _Alloc>
	template<typename ForwardIterator>
	void vector<T, _Alloc>::range_assign_select(ForwardIterator first,
												ForwardIterator last,
												std::input_iterator_tag)
	{
		range_assign_select(first, last, ft::input_iterator_tag());
	}

	template<typename T,
			typename _Alloc>
	template<typename ForwardIterator>
	void vector<T, _Alloc>::range_assign_select(ForwardIterator first,
												ForwardIterator last,
												std::forward_iterator_tag)
	{
		range_assign_select(first, last, ft::forward_iterator_tag());
	}

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::allocator_type vector<T, _Alloc>::get_allocator() const
    {
        return _given_alloc;
    }

    template<typename T,
    		typename _Alloc>
    bool vector<T, _Alloc>::empty() const
    {
        return !_size;
    }
    
    template<typename T,
    		typename _Alloc>
    void vector<T, _Alloc>::push_back(const_reference value)
    {
       insert(end(), value);
    }

    template<typename T,
    		typename _Alloc>
    void vector<T, _Alloc>::pop_back()
    {
    	if (!empty())
    	{
    		_alloc.destroy(_data + _size - 1);
    		--_size;
    	}
    }


    template<typename T,
    		typename _Alloc>
    void vector<T, _Alloc>::reserve(vector<T, _Alloc>::size_type new_capacity)
    {
        if (new_capacity > _max_size)
            throw std::length_error("ft::vector::reserve");
        if (new_capacity > _capacity)
		{
			pointer _data = _alloc.allocate(new_capacity);
			try
			{
				ft::uninitialized_copy(begin(), end(), iterator(_data), _alloc);
			}
			catch(...)
			{
				ft::destroy(begin(), end(), _alloc);
				if (_data)
					_alloc.deallocate(_data, new_capacity);
				throw;
			}
			ft::destroy(begin(), end(), _alloc);
			if (this->_data)
				_alloc.deallocate(this->_data, _capacity);
			this->_data = _data;
			_capacity = new_capacity;
		}
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::size_type vector<T, _Alloc>::update_size(size_type _new_size)
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
    		typename _Alloc>
    void vector<T, _Alloc>::resize( size_type count, value_type value )
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
    		typename _Alloc>
    typename vector<T, _Alloc>::iterator vector<T, _Alloc>::begin()
    {
        return iterator(_data);
    }
    
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_iterator vector<T, _Alloc>::begin() const
    {
        return const_iterator(_data);
    }
    
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::iterator vector<T, _Alloc>::end()
    {
        return iterator(_data + _size);
    }
    
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_iterator vector<T, _Alloc>::end() const
    {
        return const_iterator(_data + _size);
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::reverse_iterator vector<T, _Alloc>::rbegin()
    {
        return reverse_iterator(end());
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reverse_iterator vector<T, _Alloc>::rbegin() const
    {
        return const_reverse_iterator(end());
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::reverse_iterator vector<T, _Alloc>::rend()
    {
        return reverse_iterator(begin());
    }
    
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reverse_iterator vector<T, _Alloc>::rend() const
    {
        return const_reverse_iterator(begin());
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_iterator vector<T, _Alloc>::cbegin() const
    {
        return const_iterator(_data);
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_iterator vector<T, _Alloc>::cend() const
    {
        return const_iterator(_data + _size);
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reverse_iterator vector<T, _Alloc>::crbegin() const
    {
        return const_reverse_iterator(cend());
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reverse_iterator vector<T, _Alloc>::crend() const
    {
        return const_reverse_iterator(cbegin());
    }
    
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::size_type vector<T, _Alloc>::size() const
    {
        return _size;
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::size_type vector<T, _Alloc>::capacity() const
    {
        return _capacity;
    }
    
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::size_type vector<T, _Alloc>::max_size() const
    {
    	//return std::numeric_limits<difference_type>::max();
        return _max_size;
    }

    template<typename T,
    		typename _Alloc>
    vector<T, _Alloc>::~vector()
    {
        clear();
        if (_data)
        	_alloc.deallocate(_data, _capacity);
        _data = ft_nullptr;
    }

    template<typename T,
    		typename _Alloc>
    void vector<T, _Alloc>::clear()
    {
		ft::destroy(begin(), end(), _alloc);
        _size = 0;
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::reference vector<T, _Alloc>::operator[] (size_type n)
    {
        return _data[n];
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reference vector<T, _Alloc>::operator[] (size_type n) const
    {
        return _data[n];
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reference vector<T, _Alloc>::at (size_type _n) const
    {
        if (_n >= _size)
        {
            std::stringstream ss;

            ss << "ft::vector::at: index (which is ";
            ss << _n << ") >= this->size() (which is " << this->_size << ")";
            throw std::out_of_range(ss.str());
        }
        return _data[_n];
    }
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::reference vector<T, _Alloc>::at(size_type _n)
    {
        if (_n >= _size)
        {
            std::stringstream ss;

            ss << "ft::vector::at: index (which is ";
            ss << _n << ") >= this->size() (which is " << this->_size << ")";
            throw std::out_of_range(ss.str());
        }
        return _data[_n];
    }

    template<typename T,
    		typename _Alloc>
    template< typename InputIt >
	void vector<T, _Alloc>::assign( InputIt first, InputIt last)
    { 
        typedef typename is_integral<InputIt>::type integral;
        range_assign(first, last, integral());
    }

    template<typename T,
    		typename _Alloc>
    void vector<T, _Alloc>::assign( size_type count, const_reference value )
    {
    	range_assign(count, value, ft::true_type());
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::pointer vector<T, _Alloc>::data()
    {
        return _data;
    }

    template<typename T,
    		typename _Alloc>
	typename vector<T, _Alloc>::const_pointer vector<T, _Alloc>::data() const
    {
        return _data;
    }
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::reference vector<T, _Alloc>::front()
    {
        return *_data;
    }
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reference vector<T, _Alloc>::front() const
    {
        return *_data;
    }
    
    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::reference vector<T, _Alloc>::back()
    {
        return *(_data + _size - 1);
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::const_reference vector<T, _Alloc>::back() const
    {
        return *(_data + _size - 1);
    }

    template<typename T,
    		typename _Alloc>
    void vector<T, _Alloc>::shrink_to_fit()
    {
		pointer _data = _alloc.allocate(_size);
		try
		{
			ft::uninitialized_copy(begin(), end(), _data, _alloc);
		}
		catch(...)
		{
			
			if (_data)
				_alloc.deallocate(_data, _size);
			throw ;
		}
		ft::destroy(begin(), end(), _alloc);
		if (this->_data)
			_alloc.deallocate(this->_data, _capacity);
		this->_data = _data;
		_capacity = _size;
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::iterator vector<T, _Alloc>::insert( const_iterator pos, const_reference value )
    {
    	return insert(pos, 1, value);
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::iterator vector<T, _Alloc>::insert( const_iterator pos, size_type count, const_reference value )
    {
    	return range_insert(pos, count, value, ft::true_type());
    }

	template<typename T,
			typename _Alloc>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert(const_iterator pos,
																		size_type count,
																		const_reference value,
																		ft::true_type)
	{
		size_type position = ft::distance(cbegin(), pos);
		if ( count )
		{
			if (_size + count < _capacity && pos == cend())
			{
				ft::uninitialized_fill_n(end(), count, value, _alloc);
				_size += count;
			}
			else if (_size + count < _capacity)
			{
				ft::uninitialized_copy(end() - count, end(), end(), _alloc);
				ft::copy_backward(pos, cend() - count, end());
				ft::fill_n(_data + position, count, value);
				_size += count;
			}
			else
			{
				size_type _capacity = update_size(_size + count);
				pointer _data = _alloc.allocate(_capacity);
				if (pos == cend())
				{
					try
					{
						ft::uninitialized_copy(cbegin(), pos, _data, _alloc);
						ft::uninitialized_fill_n(_data + position, count, value, _alloc);
					}
					catch(...)
					{
						if (_data)
							_alloc.deallocate(_data, _capacity);
						throw ;
					}
					ft::destroy(begin(), end(), _alloc);
					if (this->_data)
						_alloc.deallocate(this->_data, this->_capacity);
					this->_data = _data;
					_size += count;
					this->_capacity = _capacity;
					return begin() + position;
				}
				else
				{
					try
					{
						ft::uninitialized_copy(cbegin(), pos, _data, _alloc);
						ft::uninitialized_fill_n(_data + position, count, value, _alloc);
						ft::uninitialized_copy(pos, cend(), _data + position + count, _alloc);
					}
					catch(...)
					{
						_alloc.destroy(_data + position);
						if (_data)
							_alloc.deallocate(_data, _capacity);
						throw ;
					}
					ft::destroy(begin(), end(), _alloc);
					if (this->_data)
						_alloc.deallocate(this->_data, this->_capacity);
					this->_data = _data;
					this->_capacity = _capacity;
					_size += count;
				}
			}
		}
        return begin() + position;
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert(const_iterator pos,
																		InputIterator first,
																		InputIterator last,
																		ft::false_type)
	{
		typedef typename ft::iterator_traits<InputIterator>::iterator_category category;
		return range_insert_select(pos, first, last, category());
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert_select(const_iterator pos,
																				InputIterator first,
																				InputIterator last,
																				ft::input_iterator_tag)
	{
		size_type position = ft::distance(cbegin(), pos);
		iterator it_pos = begin() + position;
		for ( ; first != last; ++first)
		{
			it_pos = insert(it_pos, *first);
			++it_pos;
		}
		return begin() + position;
	}

	template<typename T,
			typename _Alloc>
	template<typename ForwardIterator>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert_select(const_iterator pos,
																				ForwardIterator first,
																				ForwardIterator last,
																				ft::forward_iterator_tag)
	{
		size_type position = ft::distance(cbegin(), pos);
		if (first != last)
		{
			size_type range_len = ft::distance(first, last);

			if (_size + range_len < _capacity && pos == cend())
			{
				ft::uninitialized_copy(first, last, end(), _alloc);
				_size += range_len;
			}
			else if (_size + range_len < _capacity)
			{
				ft::uninitialized_copy(end() - range_len, end(), end(), _alloc);
				ft::copy_backward(pos, cend() - range_len, end());
				ft::copy(first, last, _data + position);
				_size += range_len;
			}
			else
			{
				size_type _capacity = update_size(_size + range_len);
				pointer _data = _alloc.allocate(_capacity);
				if (pos == cend())
				{
					try
					{
						ft::uninitialized_copy(cbegin(), pos, _data, _alloc);
						ft::uninitialized_copy(first, last, _data + position, _alloc);
					}
					catch(...)
					{
						if (_data)
							_alloc.deallocate(_data, _capacity);
						throw ;
					}
					ft::destroy(begin(), end(), _alloc);
					if (this->_data)
						_alloc.deallocate(this->_data, this->_capacity);
					this->_data = _data;
					_size += range_len;
					this->_capacity = _capacity;
					return begin() + position;
				}
				else
				{
					try
					{
						ft::uninitialized_copy(cbegin(), pos, _data, _alloc);
						ft::uninitialized_copy(first, last, _data + position, _alloc);
						ft::uninitialized_copy(pos, cend(), _data + position + range_len, _alloc);
					}
					catch(...)
					{
						_alloc.destroy(_data + position);
						if (_data)
							_alloc.deallocate(_data, _capacity);
						throw ;
					}
					ft::destroy(begin(), end(), _alloc);
					if (this->_data)
						_alloc.deallocate(this->_data, this->_capacity);
					this->_data = _data;
					this->_capacity = _capacity;
					_size += range_len;
				}
			}
		}
		return begin() + position;
	}

	template<typename T,
			typename _Alloc>
	template<typename InputIterator>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert_select(const_iterator pos,
																				InputIterator first,
																				InputIterator last,
																				std::input_iterator_tag)
	{
		return range_insert_select(pos, first, last, ft::input_iterator_tag());
	}

	template<typename T,
			typename _Alloc>
	template<typename ForwardIterator>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::range_insert_select(const_iterator pos,
																				ForwardIterator first,
																				ForwardIterator last,
																				std::forward_iterator_tag)
	{
		return range_insert_select(pos, first, last, ft::forward_iterator_tag());
	}
	
    template<typename T,
    		typename _Alloc>
    template<typename InputIt>
	typename vector<T, _Alloc>::iterator vector<T, _Alloc>::insert( const_iterator pos, InputIt first, InputIt last)
    {
    	typedef typename is_integral<InputIt>::type integral;
    	return range_insert(pos, first, last, integral());
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::iterator vector<T, _Alloc>::erase( iterator pos )
    {
    	if (pos != end())
    	{
    		if (pos + 1 != end())
				ft::copy(pos + 1, end(), pos);
			_alloc.destroy(_alloc.address(*(end() - 1)));
			--_size;
    	}
        return pos;
    }

    template<typename T,
    		typename _Alloc>
    typename vector<T, _Alloc>::iterator vector<T, _Alloc>::erase( iterator first, iterator last )
    {

		if (first != last)
		{
			size_type range_len = ft::distance(first, last);
			size_type after_pos = ft::distance(last, end());
			if (last != end())
				ft::copy(last, end(), first);
			ft::destroy(first + after_pos, end(), _alloc);
			_size -= range_len;
		}
        return first;
    }

    template<typename T,
    		typename _Alloc>
    void vector<T, _Alloc>::swap( vector& other )
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

