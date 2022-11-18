#pragma once

#include "bits/iterator_traits.hpp"

namespace ft
{
	/*
	 * Insert a new element into position pointed by iterator of <container>.
	*/
	template<typename Container>
	class insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
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
			explicit			insert_iterator(Container& container, typename Container::iterator iterator);
			insert_iterator&	operator=(typename Container::const_reference value);
			insert_iterator&	operator*();
			insert_iterator&	operator++();
			insert_iterator&	operator++(int);

		protected:

			/* =================== */
			/*    member objects   */
			/* =================== */

			Container* _container;
			typename Container::iterator iterator;
	};

	/* @function			inserter
	 * 
	 * @abstract			constructs insert_iterator from container
	 * 
	 * @discuss				function get container and creates
	 * 						iterator that inserts element into
	 * 						position pointed by iterator of container
	 *
	 * @tparam	Container	any container that have iterator system
	 *
	 * @tparam	Iterator	iterator pointed by any position of container
	 *
	 * @param	cont		any container object
	 *
	 * @result				returns insert_iterator object
	 * 
	*/
	template <typename Container, typename Iterator>
	insert_iterator<Container> inserter (Container& cont, Iterator it);
}

#include "insert_iterator_impl.hpp"

