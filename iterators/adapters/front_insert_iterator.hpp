#pragma once

#include "bits/iterator_traits.hpp"


namespace ft
{
	/*
	 * Inserts a new element in the container at the beginning of <container>.
	*/
	template<typename Container>
	class front_insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
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
			explicit				front_insert_iterator(Container& container);
			front_insert_iterator&	operator=(typename Container::const_reference value);
			front_insert_iterator&	operator*();
			front_insert_iterator&	operator++();
			front_insert_iterator&	operator++(int);

		protected:

			/* =================== */
			/*    member objects   */
			/* =================== */

			Container* _container;
	};

	/* @function			back_inserter
	 * 
	 * @abstract			constucts back_insert_iterator from container
	 * 
	 * @discuss				function get container and creates
	 * 						iterator that inserts element into
	 * 						begining of container
	 *
	 * @tparam	Container	any container that have iterator system
	 *
	 * @param	cont		any container object
	 *
	 * @result				returns back_insert_iterator object
	 * 
	*/
	template <typename Container>
	front_insert_iterator<Container> front_inserter (Container& cont);
}

#include "front_insert_iterator_impl.hpp"
