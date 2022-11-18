#pragma once

#include "bits/iterator_traits_def.hpp"

namespace ft
{

	/* @function			begin
	 * 
	 * @abstract			get iterator pointed to begin of the container
	 * 
	 * @discuss				function get container and returns
	 * 						iterator that pointed to begin of container
	 *
	 * @tparam	Container	any container that have iterator system
	 *
	 * @param	cont		any container object
	 *
	 * @result				returns  iterator object that pointed to end
	 * 						of container
	 * 
	*/
	template<typename Container>
	typename Container::const_iterator begin(const Container& cont);

	template<typename Container>
	typename Container::iterator begin(Container& cont);

	/* @function			end
	 * 
	 * @abstract			get iterator pointed to element after last
	 * 						element of container
	 * 
	 * @discuss				function get container and returns
	 * 						iterator that pointed to element after 
	 * 						last element of container
	 *
	 * @tparam	Container	any container that have iterator system
	 *
	 * @param	cont		any container object
	 *
	 * @result				returns  iterator object that pointed to end
	 * 						of container
	 * 
	*/
	template<typename Container>
	typename Container::const_iterator end(const Container& cont);

	template<typename Container>
	typename Container::iterator end(Container& cont);

	template<typename Container>
	typename Container::const_iterator cbegin(const Container& cont);

	template<typename Container>
	typename Container::const_iterator cend(const Container& cont);

	template <typename BDRIter>
	BDRIter prev (BDRIter it, typename iterator_traits<BDRIter>::difference_type n = 1);

	template <typename BDRIter>
	BDRIter next (BDRIter it, typename iterator_traits<BDRIter>::difference_type n = 1);
}


#include "iterators/adapters/iterator_impl.hpp"
