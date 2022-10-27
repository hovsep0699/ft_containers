#pragma once

#include "bits/iterator_traits.hpp"


namespace ft
{
	//
	// Inserts a new element in the container at the beginning of <container>.
	//
	template<typename Container>
	class front_insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
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
			explicit front_insert_iterator(Container& container);
			//
			// insert element to begining of container
			//
			front_insert_iterator& operator=(typename Container::const_reference value);
			//
			// do nothing for other operations and return current instance 
			//
			front_insert_iterator& operator*();

			front_insert_iterator& operator++();

			front_insert_iterator& operator++(int);
	};
	//
	// Constructs an front_insert_iterator that inserts new elements into begining of <container>.
	//
	template <typename Container>
	front_insert_iterator<Container> front_inserter (Container& cont);
}

#include "front_insert_iterator_impl.hpp"
