#pragma once

#include "iterators/adapters/reverse_iterator.hpp"

namespace ft
{
	/*
	 * reverse_iterator base constructur
	*/
	template<typename Iter>
	reverse_iterator<Iter>::reverse_iterator(iterator_type base) : current(base)
	{}

	template<typename Iter>
	reverse_iterator<Iter>::reverse_iterator() : current()
	{}

	/*
	 * reverse_iterator copy constructor
	*/
	template<typename Iter>
	template<typename U>
	reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U>& rev) : current(rev.base()) {}

	/*
	 * reverse_iterator assign
	*/
	template<typename Iter>
	template<typename U>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator=(const reverse_iterator<U>& rev)
	{
		current = rev.base();
		return *this;
	}

	/*
	 * get base iterator
	*/
	template<typename Iter>
	typename reverse_iterator<Iter>::iterator_type reverse_iterator<Iter>::base() const
	{
		return current;
	}

	/*
	 * dereference operator
	*/
	template<typename Iter>
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator*() const
	{
		Iter iter(current);
		--iter;
		return *iter;
	}

	/*
	 * access operator
	*/
	template<typename Iter>
	typename reverse_iterator<Iter>::pointer reverse_iterator<Iter>::operator->() const
	{
		Iter iter(current);
		--iter;
		return iter.operator->();
	}

	/*
	 * prefix increment operator
	*/
	template<typename Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
	{
		--current;
		return *this;
	}

	/*
	 * postfix increment operator
	*/
	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
	{
		reverse_iterator<Iter> iter(*this);
		--current;
		return iter;
	}

	/*
	 * prefix decrement operator
	*/
	template<typename Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator--()
	{
		++current;
		return *this;
	}

	/*
	 * postfix decrement operator
	*/
	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
	{
		reverse_iterator<Iter> iter(*this);
		++current;
		return iter;
	}

	/*
	 * operator increase
	*/
	template<typename Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator+=(typename reverse_iterator<Iter>::difference_type offset)
	{
		current -= offset;
		return *this;
	}

	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator+( difference_type offset ) const
	{
		reverse_iterator tmp(*this);
		tmp += offset;
		return tmp;
	}

	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator-( difference_type offset ) const
	{
		reverse_iterator tmp(*this);
		tmp -= offset;
		return tmp;
	}

	/*
	 * operator decrease
	*/
	template<typename Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator-=(typename reverse_iterator<Iter>::difference_type offset)
	{
		current += offset;
		return *this;
	}

	/*
	 *  operator subscript
	*/
	template<typename Iter>
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator[](typename reverse_iterator<Iter>::difference_type n) const
	{
		return base()[-n-1]; 
	}

	/*
	 * compare operations
	*/
	template<typename Iter>
	bool operator==(const reverse_iterator<Iter>& it1, const reverse_iterator<Iter>& it2)
	{
		return it2.base() == it1.base();
	}

	template <typename Iterator>
	bool operator!=(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it2.base() != it1.base();
	}

	template <typename Iterator>
	bool operator<(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it2.base() < it1.base();
	}

	template <typename Iterator>
	bool operator<=(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it2.base() <= it1.base();
	}

	template <typename Iterator>
	bool operator>(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it2.base() > it1.base();
	}

	template <typename Iterator>
	bool operator>=(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it2.base() >= it1.base();
	}

	template<typename LIter, typename RIter>
	bool operator==(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2)
	{
		return it2.base() == it1.base();
	}


	template<typename LIter, typename RIter>
	bool operator!=(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2)
	{
		return it2.base() != it1.base();
	}

	template<typename LIter, typename RIter>
	bool operator>(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2)
	{
		return it2.base() > it1.base();
	}

	template<typename LIter, typename RIter>
	bool operator>=(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2)
	{
		return it2.base() >= it1.base();
	}

	template<typename LIter, typename RIter>
	bool operator<(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2)
	{
		return it2.base() < it1.base();
	}

	template<typename LIter, typename RIter>
	bool operator<=(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2)
	{
		return it2.base() <= it1.base();
	}

	template< typename Iter >
	reverse_iterator<Iter> make_reverse_iterator( Iter it )
	{
		return reverse_iterator<Iter>(it);
	}

	template<typename Iter>
	typename reverse_iterator<Iter>::difference_type operator-(
			const reverse_iterator<Iter>& rhs, 
			const reverse_iterator<Iter>& lhs)
	{
		return lhs.base() - rhs.base();
	}

	template<typename LIter, typename RIter>
	typename reverse_iterator<RIter>::difference_type operator-(
			const reverse_iterator<LIter>& rhs, 
			const  reverse_iterator<RIter>& lhs)
	{
		return lhs.base() - rhs.base();
	}

	template<typename Iter>
	reverse_iterator<Iter> operator+( 
			typename reverse_iterator<Iter>::difference_type rhs, 
			const reverse_iterator<Iter>& lhs)
	{
		return lhs + rhs;
	}
}
