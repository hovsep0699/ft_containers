#pragma once


namespace ft
{
	template<typename T>
	class random_access_iterator;

	template<typename T>
	typename random_access_iterator<T>::difference_type operator-(random_access_iterator<T> rhs, random_access_iterator<T> lhs);

	template<typename LIter, typename RIter>
	typename random_access_iterator<LIter>::difference_type operator-(random_access_iterator<LIter> rhs, random_access_iterator<RIter> lhs);
}
