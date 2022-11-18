#pragma once

#include "bits/iterator_traits.hpp"


namespace ft
{
	/*
	 * Inserts a new element in the container at the end of <container>.
	*/
	template<typename Container>
	class back_insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
	{
		public:

			/* ============================= */
			/*         member types          */
			/* ============================= */ 

			typedef ft::output_iterator_tag	iterator_category;
			typedef void					value_type;
			typedef void					difference_type;
			typedef void					pointer;
			typedef void					reference;
			typedef Container				container_type;

			/* ========================= */
			/*      member functions     */
			/* ========================= */

			/*
			 * only explicit call for container instance
			*/
			explicit				back_insert_iterator(Container& container);
			back_insert_iterator&	operator=(typename Container::const_reference value);
			back_insert_iterator&	operator*();
			back_insert_iterator&	operator++();
			back_insert_iterator&	operator++(int);

		protected:

			/* =================== */
			/*    member objects   */
			/* =================== */

			Container* _container;
	};

	/* @function			back_inserter
	 * 
	 * @abstract			constructs back_insert_iterator from container
	 * 
	 * @discuss				function get container and creates
	 * 						iterator that inserts element into
	 * 						end of container
	 *
	 * @tparam	Container	any container that have iterator system
	 *
	 * @param	cont		any container object
	 *
	 * @result				returns back_insert_iterator object
	 * 
	*/
	template <typename Container>
	back_insert_iterator<Container> back_inserter (Container& cont);
}

#include "iterators/adapters/back_insert_iterator_impl.hpp"
