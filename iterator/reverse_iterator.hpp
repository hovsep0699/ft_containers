#pragma once

#include "iterator_traits.hpp"

namespace ft
{

	template<typename Iter>
	class reverse_iterator
	{
		Iter _base;
		//
		// default constructor illegal
		//
		reverse_iterator();
		public:
			//
			// member types
			//
			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;
			//
			// constructurs
			//
			reverse_iterator(Iter base);
			reverse_iterator(const reverse_iterator& rev);
			reverse_iterator& operator=(const reverse_iterator& rev);
			//
			//	destructor
			//
			~reverse_iterator();
			//
			// get base iterator
			//
			Iter base() const;
			//
			// dereference operators
			//
			reference operator*() const;
			pointer operator->() const;
			//
			// iteration operators
			//
			reverse_iterator<Iter>& operator++();
			reverse_iterator<Iter> operator++(int);
			reverse_iterator<Iter>& operator--();
			reverse_iterator<Iter> operator--(int);
			reverse_iterator<Iter>& operator+=(difference_type offset);
			reverse_iterator<Iter>& operator-=(difference_type offset);
			//
			// access operator
			//
			reference operator[](difference_type n) const;
		};
		//
		// compare operations
		//
		template<typename Iterator>
			bool operator==(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2);
		template<typename Iterator1, typename Iterator2>
			bool operator==(const reverse_iterator<Iterator1>& it1, const reverse_iterator<Iterator2>& it2);
		template <typename Iterator>
			bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

		template <typename Iterator>
			bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

		template <typename Iterator>
			bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

		template <typename Iterator>
			bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

		template <typename Iterator>
			bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
		//
		// Create reverse iterator from iterator
		//
		template< typename Iter >
			ft::reverse_iterator<Iter> make_reverse_iterator( Iter it );

};

#include "reverse_iterator_impl.hpp"

