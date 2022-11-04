#pragma once

namespace ft
{

	/* ================================ */
	/*    reverse iterator structure    */
	/* ================================ */

	template<typename Iter>
	class reverse_iterator;

	/* ======================== */
	/*    Compare operations    */
	/* ======================== */

	template<typename Iterator>
	bool operator==(const reverse_iterator<Iterator>& it1, const reverse_iterator<Iterator>& it2);

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

	/* =========================================== */
	/*    Compare operations for const iterators   */
	/* =========================================== */

	template<typename LIter, typename RIter>
	bool operator==(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2);

	template<typename LIter, typename RIter>
	bool operator!=(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2);

	template<typename LIter, typename RIter>
	bool operator>(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2);

	template<typename LIter, typename RIter>
	bool operator>=(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2);

	template<typename LIter, typename RIter>
	bool operator<(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2);

	template<typename LIter, typename RIter>
	bool operator<=(const reverse_iterator<LIter>& it1, const reverse_iterator<RIter>& it2);


	/* ========================== */
	/*    arithmetic operations   */
	/* ========================== */

	template< typename Iter >
	reverse_iterator<Iter> operator+(
			typename reverse_iterator<Iter>::difference_type n,
            const reverse_iterator<Iter>& it );

    template< typename Iter >
	typename reverse_iterator<Iter>::difference_type operator-(
			const reverse_iterator<Iter>& lhs,
			const reverse_iterator<Iter>& rhs );

	template< typename LIter, typename RIter >
	typename reverse_iterator<RIter>::difference_type operator-(
			const reverse_iterator<LIter>& lhs,
            const reverse_iterator<RIter>& rhs);

	/*
	 * @function				make_reverse_iterator
	 *
	 * @abstract				create reverse_iterator from any iterator
	 *
	 * @discussion				function gets any iterator object and 
	 * 							make reverse iterator from it
	 *
	 * @tparam		Iter		iterator type for reverse iterator
	 *
	 * @param		it 			iterator object
	 *
	 * @result					reverse_iterator object from iterator object 
	 *
	 * Create reverse iterator from iterator
	*/

	template< typename Iter >
	reverse_iterator<Iter> make_reverse_iterator( Iter it );

}
