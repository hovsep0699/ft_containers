#pragma once

#include "iterators/adapters/reverse_iterator.hpp"

namespace ft
{
	//
	// reverse_iterator base constructur
	//
	template<typename Iter>
	reverse_iterator<Iter>::reverse_iterator(iterator_type base) : current(base)
	{}
	template<typename Iter>
	reverse_iterator<Iter>::reverse_iterator() : current()
	{}
	//
	// reverse_iterator copy constructor
	//
	template<typename Iter>
	template<typename U>
	reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U>& rev) : current(rev.base()) {}
	//
	// reverse_iterator assign
	//
	template<typename Iter>
	template<typename U>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator=(const reverse_iterator<U>& rev)
	{
		std::cout << "operator=()\n";
		if (this != &rev)
			current = rev.base();
		return *this;
	}
	//
	// get base iterator
	//
	template<typename Iter>
	typename reverse_iterator<Iter>::iterator_type reverse_iterator<Iter>::base() const
	{
		return current;
	}
	//
	// dereference operator
	//
	template<typename Iter>
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator*() const
	{
		Iter iter(current);
		--iter;
		return *iter;
	}
	//
	// access operator
	//
	template<typename Iter>
	typename reverse_iterator<Iter>::pointer reverse_iterator<Iter>::operator->() const
	{
		Iter iter(current);
		--iter;
		return iter.operator->();
	}
	//
	// prefix increment operator
	//
	template<typename Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
	{
		--current;
		return *this;
	}
	//
	// postfix increment operator
	//
	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
	{
		reverse_iterator<Iter> iter(current--);
		return *this;
	}
	//
	// prefix decrement operator
	//
	template<typename Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator--()
	{
		++current;
		return *this;
	}
	//
	// postfix decrement operator
	//
	template<typename Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
	{
		reverse_iterator<Iter> iter(current++);
		return *this;
	}
	//
	// operator increase
	//
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
	//
	// operator decrease
	//
	template<typename Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator-=(typename reverse_iterator<Iter>::difference_type offset)
	{
		current += offset;
		return *this;
	}
	//
	// access operator
	//
	template<typename Iter>
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator[](typename reverse_iterator<Iter>::difference_type n) const
	{
		return base()[-n-1]; 
	}
	//
	// compare operations
	//
	template<typename Iter>
	bool operator==(const reverse_iterator<Iter>& it1, const reverse_iterator<Iter>& it2)
	{
		return it1.base() == it2.base();
	}

	template<typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& it1, const reverse_iterator<Iterator2>& it2)
	{
		return it1.base() == it2.base();
	}

	template <typename Iterator>
	bool operator!=(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it1.base() != it2.base();
	}

	template <typename Iterator>
	bool operator<(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it1.base() < it2.base();
	}

	template <typename Iterator>
	bool operator<=(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it1.base() <= it2.base();
	}

	template <typename Iterator>
	bool operator>(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it1.base() > it2.base();
	}

	template <typename Iterator>
	bool operator>=(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2)
	{
		return it1.base() >= it2.base();
	}
	template< typename Iter >
	ft::reverse_iterator<Iter> make_reverse_iterator( Iter it )
	{
		return ft::reverse_iterator<Iter>(it);
	}
	template<typename Iter>
	typename reverse_iterator<Iter>::difference_type operator-(reverse_iterator<Iter> rhs, reverse_iterator<Iter> lhs)
	{
		return rhs.base() - lhs.base();
	}
	template<typename LIter, typename RIter>
	typename reverse_iterator<LIter>::difference_type operator-(reverse_iterator<LIter> rhs, reverse_iterator<RIter> lhs)
	{
		return rhs.base() - lhs.base();
	}
	template<typename LIter, typename RIter>
	typename reverse_iterator<LIter>::difference_type operator+(reverse_iterator<LIter> rhs,  typename reverse_iterator<LIter>::size_type lhs)
	{
		return rhs.base()  + lhs;
	}
}
