#pragma once

#include "bits/iterator_traits_def.hpp"

namespace ft
{

	template<typename Container>
	typename Container::const_iterator begin(const Container& cont);

	template<typename Container>
	typename Container::iterator begin(Container& cont);

	template<typename Container>
	typename Container::const_iterator end(const Container& cont);

	template<typename Container>
	typename Container::iterator end(Container& cont);

	template<typename Container>
	typename Container::const_iterator cbegin(const Container& cont);

	template<typename Container>
	typename Container::const_iterator cend(const Container& cont);

	template <typename BDRIter>
	BDRIter prev (BDRIter it, typename iterator_traits<BDRIter>::difference_type n = 1);

	template <typename BDRIter>
	BDRIter next (BDRIter it, typename iterator_traits<BDRIter>::difference_type n = 1);
}
