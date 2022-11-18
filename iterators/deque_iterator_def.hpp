#pragma once

#include "bits/iterator_traits.hpp"

namespace ft
{

	template<typename T,
			typename _DT>
	struct deque_block_size;
	

	template<typename T,
			typename _Ref = iterator<random_access_iterator_tag, T>::reference,
			typename _Ptr = iterator<random_access_iterator_tag, T>::pointer,
			typename _DT = iterator<random_access_iterator_tag, T>::difference_type,
			_DT _BS = deque_block_size<T, _DT>::value>
	class deque_terator;

	template<typename T>
	bool operator==(const deque_iterator<T>& lhs, const deque_iterator<T>& rhs);

	template <typename T>
	bool operator!=(const deque_iterator<T>& lhs, const deque_iterator<T>& rhs);

	template <typename T>
	bool operator<(const deque_iterator<T>& lhs, const deque_iterator<T>& rhs);

	template <typename T>
	bool operator<=(const deque_iterator<T>& lhs, const deque_iterator<T>& rhs);

	template <typename T>
	bool operator>(const deque_iterator<T>& lhs, const deque_iterator<T>& rhs);

	template <typename T>
	bool operator>=(const deque_iterator<T>& lhs, const deque_iterator<T>& rhs);

	template<typename T1, typename T2>
	bool operator==(const deque_iterator<T1>& lhs, const deque_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator!=(const deque_iterator<T1>& lhs, const deque_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator>(const deque_iterator<T1>& lhs, const deque_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator>=(const deque_iterator<T1>& lhs, const deque_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator<(const deque_iterator<T1>& lhs, const deque_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator<=(const deque_iterator<T1>& lhs, const deque_iterator<T2>& rhs);

	template<typename T>
	typename deque_iterator<T>::difference_type operator-(
			const deque_iterator<T>& rhs,
			const deque_iterator<T>& lhs);

	template<typename LIter, typename RIter>
	typename deque_iterator<LIter>::difference_type operator-(
			const deque_iterator<LIter>& rhs,
			const deque_iterator<RIter>& lhs);

	template<typename T>
	deque_iterator<T> operator+(
			typename deque_iterator<T>::difference_type lhs,
			const deque_iterator<T>& rhs);
}
