#pragma once

#include "bits/algorithm.hpp"

namespace ft
{
	//
	// Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
	//
	template<typename InputIt1,
			typename InputIt2>
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
	template<typename InputIt1,
			typename InputIt2>
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

	template< typename InputIt1,
			typename InputIt2 >
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

	template<typename ForwardIt,
			typename T>
	void fill( 	ForwardIt first,
				ForwardIt last,
				const T& value)
	{
		for (; first != last; ++first)
        	*first = value;
	}

	template< typename ForwardIt,
			typename Size,
			typename T >
	ForwardIt fill(	ForwardIt first,
				Size count,
				const T& value )
	{
		for ( ; count > 0; --count; ++first)
			*first = value;
		return first;
	}

	template<typename InputIt,
			typename OutputIt>
	OutputIt copy( 	InputIt first,
					InputIt last,
					OutputIt out)
	{
		for (; first != last; ++first, ++out) 
        	*out = *first;
    	return out;
	}

	template< typename BidirIt1,
			typename BidirIt2 >
	BidirIt2 copy_backward( BidirIt1 first,
							BidirIt1 last,
							BidirIt2 out )
	{
		while ( first != last ) 
        	*(--out) = *(--last);
    	return out;
	}

	template<typename ForwardIt,
			typename _Allocator>
	void destroy( 	ForwardIt first,
					ForwardIt last,
					_Allocator _alloc)
	{
		for (; first != last; ++first)
    		_alloc.destroy(_alloc.address(*first));
	}

	template< typename InputIt,
			typename NoThrowForwardIt,
			typename _Allocator>
	NoThrowForwardIt uninitialized_copy(InputIt first,
										InputIt last,
										NoThrowForwardIt out,
										_Allocator _alloc)
    {
    	NoThrowForwardIt current = out;
    	try
    	{
        	for (; first != last; ++first, ++current)
        		_alloc.construct(_alloc.address(*current), *first );
        	return current;
    	}
    	catch (...)
    	{
			ft::destroy(out, current, _alloc);
        	throw;
    	}
    }

	template< typename ForwardIt,
			typename Size,
			typename T,
			typename _Allocator>
	void uninitialized_fill_n(	ForwardIt first,
								Size count,
								const T& value,
								_Allocator _alloc)
    {
    	ForwardIt current = first;
    	try
    	{
        	for ( ; count > 0; ++first, ++current, --count)
        		_alloc.construct(_alloc.address(*current), value );
        	return current;
    	}
    	catch (...)
    	{
			ft::destroy(out, current, _alloc);
        	throw;
    	}
    }

	template< typename ForwardIt,
			typename T,
			typename _Allocator>
	void uninitialized_fill(	ForwardIt first,
								ForwardIt last,
								const T& value,
								_Allocator _alloc)
    {
    	ForwardIt current = first;
    	try
    	{
        	for ( ; first != last; ++current, ++first)
        		_alloc.construct(_alloc.address(*current), *first );
        	return current;
    	}
    	catch (...)
    	{
			ft::destroy(out, current, _alloc);
        	throw;
    	}
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

	template< typename BidirIt >
	void reverse( BidirIt first,
				BidirIt last )
	{
		while (first != last && first != --last)
            ft::iter_swap(first++, last);
	}

	template< typename ForwardIt1,
			typename ForwardIt2 >
	void iter_swap( ForwardIt1 a,
					ForwardIt2 b )
	{
		ft::swap(*a, *b);
	}
}
