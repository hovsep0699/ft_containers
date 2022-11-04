#pragma once

#include "bits/algorithm.hpp"

namespace ft
{
	//
	// Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
	//
	template<typename InputIt1, typename InputIt2>
	bool lexicographical_compare(	InputIt1 first1, 
									InputIt1 last1,
									InputIt2 first2, 
									InputIt2 last2 )
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
	//
	// Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
	//
	template<typename InputIt1,
			typename InputIt2, 
			typename Compare>
	bool lexicographical_compare(	InputIt1 first1, 
									InputIt1 last1,
									InputIt2 first2, 
									InputIt2 last2,
									Compare comp )
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
	//
	// Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise.
	//
	template<typename InputIt1, typename InputIt2>
	bool equal( InputIt1 first1, 
				InputIt1 last1,
				InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template< typename InputIt1, typename InputIt2 >
	bool equal( InputIt1 first1,
				InputIt1 last1, 
            	InputIt2 first2, 
            	InputIt2 last2 )
    {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;

    }
	//
	// Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise comapre with Binary Predicate.
	//
	template<typename InputIt1, 
			typename InputIt2, 
			typename BinaryPredicate>
	bool equal( InputIt1 first1, 
				InputIt1 last1,
				InputIt2 first2, 
				BinaryPredicate p )
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}
	/*
	* swap two objects
	*/
	template<typename T>
	void swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
	}
}
