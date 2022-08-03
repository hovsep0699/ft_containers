#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"


namespace ft
{
	template<typename T>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
		public:
			//
			// member types
			//
			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;

			random_access_iterator() : _ptr(ft_nullptr) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const random_access_iterator& it) : _ptr(it._ptr) {}
			random_access_iterator& operator=(const random_access_iterator& it)
			{
				if (&it != this)
					_ptr = it.ptr;
				return *this;
			}
			//
			// dereference operators
			//
			reference operator*() const
			{
				return *_ptr;
			}

			pointer operator->() const
			{
				return _ptr;
			}
			//
			// other operations
			//
			random_access_iterator& operator++()
			{
				++_ptr;
				return *this;
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
				++_ptr;
				return tmp;
			}

			random_access_iterator& operator--()
			{
				--_ptr;
				return *this;
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
				--_ptr;
				return tmp;
			}

			random_access_iterator& operator+=(difference_type offset)
			{
				_ptr += offset;
				return *this;
			}

			random_access_iterator& operator-=(difference_type offset)
			{
				_ptr -= offset;
				return *this;
			}

			random_access_iterator operator+(difference_type offset)
			{
				random_access_iterator tmp(*this);
				tmp += offset;
				return tmp;
			}

			random_access_iterator operator-(difference_type offset)
			{
				random_access_iterator tmp(*this);
				tmp -= offset;
				return tmp;
			}

			value_type operator[](difference_type n)
			{
				return _ptr[n];
			}
			//
			// compare operations
			//
			bool operator<(const random_access_iterator& it)
			{
				return _ptr < it._ptr;
			}

			bool operator>(const random_access_iterator& it)
			{
				return _ptr > it._ptr;
			}

			bool operator<=(const random_access_iterator& it)
			{
				return _ptr <= it._ptr;
			}

			bool operator>=(const random_access_iterator& it)
			{
				return _ptr >= it._ptr;
			}

			bool operator==(const random_access_iterator& it)
			{
				return _ptr == it._ptr;
			}

			bool operator!=(const random_access_iterator& it)
			{
				return _ptr != it._ptr;
			}
		protected:
			pointer	_ptr;

	};

}


