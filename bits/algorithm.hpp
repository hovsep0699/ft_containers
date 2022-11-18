#pragma once


namespace ft
{
	//
	// Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
	//
	template<typename InputIt1, typename InputIt2>
	bool lexicographical_compare(	InputIt1 first1,
									InputIt1 last1,
									InputIt2 first2, 
									InputIt2 last2 );
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
									Compare comp );
	//
	// Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise.
	//
	template<typename InputIt1, typename InputIt2>
	bool equal( InputIt1 first1,
				InputIt1 last1,
				InputIt2 first2 );

	template< typename InputIt1, typename InputIt2 >
	bool equal( InputIt1 first1,
				InputIt1 last1, 
            	InputIt2 first2, 
            	InputIt2 last2 );
	//
	// Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise comapre with Binary Predicate.
	//
	template<typename InputIt1,
			typename InputIt2,
			typename BinaryPredicate>
	bool equal(	InputIt1 first1, 
				InputIt1 last1,
				InputIt2 first2, 
				BinaryPredicate p );

	template< typename ForwardIt,
			typename T >
	void fill(	ForwardIt first,
				ForwardIt last,
				const T& value );


	template< typename InputIt,
			typename OutputIt >
	OutputIt copy(  InputIt first,
					InputIt last,
					OutputIt out );

	template< typename ForwardIt,
			typename _Allocator>
	void destroy( 	ForwardIt first,
					ForwardIt last,
					_Allocator _alloc);

	template< typename InputIt,
			typename NoThrowForwardIt,
			typename _Allocator>
	NoThrowForwardIt uninitialized_copy(InputIt first,
										InputIt last,
                                     	NoThrowForwardIt out,
                                     	_Allocator _alloc);
	//
	// swap two objects
	//
	template<typename T>
	void swap(T& a, T& b);
	
}


#include "algorithm_impl.hpp"
