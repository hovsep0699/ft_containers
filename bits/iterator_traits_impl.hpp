#pragma once

#include "bits/iterator_traits_def.hpp"

namespace ft
{
	//
	// Iterator Category tags
	//
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : input_iterator_tag {};
    struct bidirectional_iterator_tag : forward_iterator_tag {};
    struct random_access_iterator_tag : bidirectional_iterator_tag {};
	//
	// Base Iterator class
	//
	template<typename Category, 
		typename T, 
		typename Distance, 
		typename Pointer, 
		typename Reference> 
	struct iterator
	{
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};
	//
	// Trait structure for Iterators
	//
	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};

    template <typename T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
	};

    template <typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
	};
	//
	// Optimization for random access iterator
	//
	template<typename RAIter>
	typename iterator_traits<RAIter>::difference_type distance(RAIter first,
															RAIter last,
															ft::random_access_iterator_tag)
	{
		return last - first;
	}
	//
	// Get distance between 2 input Iterators
	//
	template<typename Iter>
	typename iterator_traits<Iter>::difference_type distance(Iter first,
															Iter last, 
															ft::input_iterator_tag)
	{
		typename iterator_traits<Iter>::difference_type it_distance = 0;
		while (first != last)
		{
			++it_distance;
			++first;
		}
		return it_distance;
	}

	//
	// Optimization for random access iterator
	//
	template<typename RAIter>
	typename iterator_traits<RAIter>::difference_type distance(RAIter first,
															RAIter last,
															std::random_access_iterator_tag)
	{
		return distance(first, last, ft::random_access_iterator_tag());
	}
	//
	// Get distance between 2 input Iterators
	//
	template<typename Iter>
	typename iterator_traits<Iter>::difference_type distance(Iter first,
															Iter last, 
															std::input_iterator_tag)
	{
		return distance(first, last, ft::input_iterator_tag());
	}

	/*
	 * Get distance between 2 input Iterators
	*/
	template<typename Iter>
	typename iterator_traits<Iter>::difference_type distance(Iter first, Iter last)
	{
		return ft::distance(first, last, typename ft::iterator_traits<Iter>::iterator_category());
	}
	/*
	 * Optimization for random access iterator
	*/
	template<typename RAIter, typename Distance>
	void advance(RAIter& it, Distance distance, ft::random_access_iterator_tag)
	{
		it += distance;
	}
	/*
	 * Advance iterator by distance
	*/
	template<typename InputIter, typename Distance>
	void advance(InputIter& it, Distance distance, ft::input_iterator_tag)
	{
		while (distance > 0)
		{
			--distance;
			++it;
		}
	}


	template<typename InputIter, typename Distance>
	void advance(InputIter& it, Distance distance, ft::bidirectional_iterator_tag)
	{
		while (distance > 0)
		{
			--distance;
			++it;
		}
		while (distance < 0)
		{
			++distance;
			--it;
		}
	}

	/*
	 * Optimization for random access iterator
	*/
	template<typename RAIter, typename Distance>
	void advance(RAIter& it, Distance distance, std::random_access_iterator_tag)
	{
		advance(it, distance, ft::random_access_iterator_tag());
	}
	/*
	 * Advance iterator by distance
	*/
	template<typename InputIter, typename Distance>
	void advance(InputIter& it, Distance distance, std::input_iterator_tag)
	{
		advance(it, distance, ft::input_iterator_tag());
	}


	template<typename InputIter, typename Distance>
	void advance(InputIter& it, Distance distance, std::bidirectional_iterator_tag)
	{
		advance(it, distance, ft::bidirectional_iterator_tag());
	}
	/*
	 * Advance iterator by distance
	*/
	template<typename Iter, typename Distance>
	void advance(Iter& it, Distance distance)
	{
		ft::advance(it, distance, typename ft::iterator_traits<Iter>::iterator_category());
	}

}
