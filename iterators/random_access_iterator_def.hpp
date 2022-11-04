#pragma once


namespace ft
{
	template<typename T>
	class random_access_iterator;

	// compare operations
	//
	template<typename T>
	bool operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);

	template <typename T>
	bool operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);

	template <typename T>
	bool operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);

	template <typename T>
	bool operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);

	template <typename T>
	bool operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);

	template <typename T>
	bool operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);

	template<typename T1, typename T2>
	bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator>(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator<(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs);

	template<typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs);

	template<typename T>
	typename random_access_iterator<T>::difference_type operator-(
			const random_access_iterator<T>& rhs,
			const random_access_iterator<T>& lhs);

	template<typename LIter, typename RIter>
	typename random_access_iterator<LIter>::difference_type operator-(
			const random_access_iterator<LIter>& rhs,
			const random_access_iterator<RIter>& lhs);

	template<typename T>
	random_access_iterator<T> operator+(
			typename random_access_iterator<T>::difference_type lhs,
			const random_access_iterator<T>& rhs);

}
