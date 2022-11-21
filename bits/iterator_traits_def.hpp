#pragma once

#include <cstddef>

namespace ft
{
	//
	// Iterator Category tags
	//
    struct input_iterator_tag;
    struct output_iterator_tag;
    struct forward_iterator_tag;
    struct bidirectional_iterator_tag;
    struct random_access_iterator_tag;
	//
	// Base Iterator class
	//
	template<typename Category, 
			typename T, 
			typename Distance = std::ptrdiff_t, 
			typename Pointer = T*, 
			typename Reference = T& > 
	struct iterator;
	//
	// Trait structure for Iterators
	//
	template <typename Iterator>
	struct iterator_traits;

    template <typename T>
	struct iterator_traits<T*>;

    template <typename T>
	struct iterator_traits<const T*>;

	//
	// Optimization for random access iterator
	//
	template<typename RAIter>
	typename iterator_traits<RAIter>::difference_type distance(RAIter first,
															RAIter last,
															ft::random_access_iterator_tag);

	//
	// Get distance between 2 input Iterators
	//
	template<typename Iter>
	typename iterator_traits<Iter>::difference_type distance(Iter first,
															Iter last,
															ft::input_iterator_tag);

	//
	// Get distance between 2 input Iterators
	//
	template<typename Iter>
	typename iterator_traits<Iter>::difference_type distance(Iter first, Iter last);

	//
	// Optimization for random access iterator
	//
	template<typename RAIter, typename Distance>
	void advance(RAIter& it, Distance distance, ft::random_access_iterator_tag);

	template<typename InputIter, typename Distance>
	void advance(InputIter& it, Distance distance, ft::bidirectional_iterator_tag);
	//
	// Advance iterator by distance
	//
	template<typename InputIter, typename Distance>
	void advance(InputIter& it, Distance distance, ft::input_iterator_tag);

	//
	// Advance iterator by distance
	//
	template<typename Iter,
			typename Distance>
	void advance(Iter& it, Distance distance);
}
