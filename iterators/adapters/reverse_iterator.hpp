#pragma once

#include "bits/iterator_traits.hpp"
#include "iterators/adapters/reverse_iterator_def.hpp"

namespace ft
{

	template<typename Iter>
	class reverse_iterator
	{
		protected:
			Iter current;
		//
		// default constructor illegal
		//
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
			reverse_iterator();
			reverse_iterator(iterator_type base);
			template<typename U>
			reverse_iterator(const reverse_iterator<U>& rev);
			template<typename U>
			reverse_iterator& operator=(const reverse_iterator<U>& rev);
			//
			// get base iterator
			//
			iterator_type base() const;
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
			reverse_iterator operator+( difference_type offset ) const;
			reverse_iterator operator-( difference_type offset ) const;
			//
			// access operator
			//
			reference operator[](difference_type n) const;

			template<typename IterBase>
			friend typename reverse_iterator<IterBase>::difference_type operator-(reverse_iterator<IterBase> rhs, reverse_iterator<IterBase> lhs);
			template<typename LIter, typename RIter>
			friend typename reverse_iterator<LIter>::difference_type operator-(reverse_iterator<LIter> rhs, reverse_iterator<RIter> lhs);
		}; // class reverse_iterator
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
} // namespace ft


#include "reverse_iterator_impl.hpp"

