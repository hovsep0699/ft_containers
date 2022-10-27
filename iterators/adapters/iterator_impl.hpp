#pragma once

#include "bits/iterator_traits.hpp"

namespace ft
{
	template<typename Container>
	typename Container::const_iterator begin(const Container& cont)
	{
		return cont.begin();
	}

	template<typename Container>
	typename Container::iterator begin(Container& cont)
	{
		return cont.begin();
	}

	template<typename Container>
	typename Container::const_iterator end(const Container& cont)
	{
		return cont.end();
	}

	template<typename Container>
	typename Container::iterator end(Container& cont)
	{
		return cont.end();
	}
	template<typename Container>
	typename Container::const_iterator cbegin(const Container& cont)
	{
		return cont.begin();
	}

	template<typename Container>
	typename Container::const_iterator cend(const Container& cont)
	{
		return cont.end();
	}

	template <typename BDRIter>
	BDRIter prev (BDRIter it, typename iterator_traits<BDRIter>::difference_type n)
	{
		typename iterator_traits<BDRIter>::difference_type count  = 0;
		while (count < n) --it;
		return it;
	}

	template <typename BDRIter>
	BDRIter next (BDRIter it, typename iterator_traits<BDRIter>::difference_type n)
	{
		typename iterator_traits<BDRIter>::difference_type count  = 0;
		while (count < n) ++it;
		return it;
	}
}
