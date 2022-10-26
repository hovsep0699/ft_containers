#pragma once

#include "iterator_traits.hpp"


namespace ft
{
	//
	// Inserts a new element in the container at the end of <container>.
	//
	template<typename Container>
	class back_insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
	{
		protected:
			Container* _container;
		public:
			//
			// type of Container
			//
			typedef Container container_type;
			//
			// only explicit call for container instance
			//
			explicit back_insert_iterator(Container& container);
			//
			// insert element to end of container
			//
			back_insert_iterator& operator=(typename Container::const_reference value);
			//
			// do nothing for other operations and return current instance 
			//
			back_insert_iterator& operator*();

			back_insert_iterator& operator++();

			back_insert_iterator& operator++(int);
	};
	//
	// Constructs an back_insert_iterator that inserts new elements into end of <container>.
	//
	template <typename Container>
	back_insert_iterator<Container> back_inserter (Container& cont);
}

#include "back_insert_iterator_impl.hpp"
