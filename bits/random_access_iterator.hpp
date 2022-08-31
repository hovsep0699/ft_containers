#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include "random_access_iterator_def.hpp"


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
			typedef const pointer const_pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;

			random_access_iterator();
			random_access_iterator(pointer ptr);
			random_access_iterator(const random_access_iterator& it);

			template<typename Iter>
			random_access_iterator(const random_access_iterator<Iter>& it);

			operator random_access_iterator<const value_type>();

			random_access_iterator& operator=(const random_access_iterator& it);
			//
			// dereference operators
			//
			reference operator*() const;

			pointer operator->() const;
			//
			// other operations
			//
			random_access_iterator& operator++();

			random_access_iterator operator++(int);

			random_access_iterator& operator--();

			random_access_iterator operator--(int);

			random_access_iterator& operator+=(difference_type offset);

			random_access_iterator& operator-=(difference_type offset);

			random_access_iterator operator+(difference_type offset);

			random_access_iterator operator-(difference_type offset);

			value_type operator[](difference_type n);
			//
			// compare operations
			//
			bool operator<(const random_access_iterator& it);

			bool operator>(const random_access_iterator& it);

			bool operator<=(const random_access_iterator& it);

			bool operator>=(const random_access_iterator& it);

			bool operator==(const random_access_iterator& it);

			bool operator!=(const random_access_iterator& it);

			pointer base();
			const_pointer base() const;

			template<typename IType>
			friend typename random_access_iterator<IType>::difference_type operator-(random_access_iterator<IType> rhs, 
							random_access_iterator<IType> lhs);

			template<typename LIter, typename RIter>
			friend typename random_access_iterator<LIter>::difference_type operator-(random_access_iterator<LIter> rhs, 
							random_access_iterator<RIter> lhs);

		protected:
			pointer _ptr;
	};

}

#include "random_access_iterator_impl.hpp"

