#pragma once

namespace ft
{

	//
	// Reverse iterator structure
	//
	template<typename Iter>
	class reverse_iterator;

	//
	// Compare operations
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

}
