#pragma once

#include "iterators/deque_iterator.hpp"

namespace ft
{
	template<typename T,
			typename _DT>
	const _DT deque_block_size<T, _DT>::value = sizeof(T) < 256 ? 4096 / sizeof(T) : 16;

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	deque_iterator<T, _Ref, _Ptr, _DT, _BS>::deque_iterator()
		:	_node(0),
			_begin(0);
			_end(0);
			_current(0);
	{}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	deque_iterator<T, _Ref, _Ptr>::deque_iterator(pointer ptr, map_pointer _mp)
		:	_node(_mp),
			_begin(*mp);
			_end(*mp + _BS);
			_current(ptr);
	{}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	deque_iterator<T, _Ref, _Ptr, _DT, _BS>::deque_iterator(const deque_iterator& it)
		:	_node(it._node),
			_begin(it._begin);
			_end(it._end);
			_current(it._current);
	{}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	deque_iterator<T, _Ref, _Ptr, _DT, _BS>& deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator=(const deque_iterator& it)
	{
		if (this != &it)
		{
			_node = it._node;
			_begin = it._begin;
			_end = it._end;
			_current = it._current;
		}
		return *this;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator  const_iterator()
	 {
	 	 return const_iterator(_current, _node);
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT	_BS>
	void deque_iterator<T, _Ref, _Ptr, _DT, _BS>::set_node(map_pointer _mp)
	{
		_node = _mp;
		_begin = *_mp;
		_end = begin + _BS;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::reference deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator*()
	 {
	 	 return *_current;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator->()
	 {
	 	 return _current;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS>& deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator++()
	 {
	 	 ++_current;
	 	 if (_current == _end)
	 	 {
			set_node(_node + 1);	 	 	 
			_current = _begin;
	 	 }
	 	 return *this;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator++(int)
	 {
	 	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> it(*this);
	 	 ++*this;
	 	 return it;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS>& deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator--()
	 {
	 	 if (_current == _begin)
	 	 {
			set_node(_node - 1);	 	 	 
			_current = _end;
	 	 }
	 	 --_current;
	 	 return *this;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator--(int)
	 {
	 	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> it(*this);
	 	 --*this;
	 	 return it;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS>& deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator+=(difference_type offset)
	 {
		difference_type _offset = offset + (_curr - _begin);
		if (_offset >= 0 && offset < _BS)
			_current += offset;
		else
		{
			difference_type node_offset = _offset > 0 ? offset / _BS : -( (-offset - 1) / _BS) - 1;
			set_node(_node + node_offset);
			_current = _begin + (_offset - node_offset * _BS);
		}
		return *this;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS>& deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator-=(difference_type offset)
	 {
	 	 return *this += -offset;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator-(difference_type offset) const
	 {
	 	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> it(*this);
	 	 it -= offset;
	 	 return it;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator+(difference_type offset) const
	 {
	 	 deque_iterator<T, _Ref, _Ptr, _DT, _BS> it(*this);
	 	 it += offset;
	 	 return it;
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::reference deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator[](difference_type offset)
	 {
	 	 return *(*this + offset);
	 }

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	 typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::const_reference deque_iterator<T, _Ref, _Ptr, _DT, _BS>::operator[](difference_type offset) const
	{
	 	 return *(*this + offset);
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::current()
	{
		return _current;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::const_pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::current() const
	{
		return _current;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::begin()
	{
		return _begin;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::const_pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::begin() const
	{
		return _begin;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::end()
	{
		return _end;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::const_pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::end() const
	{
		return _end;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::map_pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::node()
	{
		return _node;
	}

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT,
			_DT _BS>
	typename deque_iterator<T, _Ref, _Ptr, _DT, _BS>::const_map_pointer deque_iterator<T, _Ref, _Ptr, _DT, _BS>::node() const
	{
		return _node;
	}
}
