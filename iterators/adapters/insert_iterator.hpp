#pragma once

#include "iterator_traits.hpp"

namespace ft
{
	//
	// Insert a new element into position pointed by iterator of <container>.
	//
	template<typename Container>
	class insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
	{
		protected:
			Container* _container;
			typename Container::iterator iterator;
		public:
			//
			// type of Container
			//
			typedef Container container_type;
			//
			// only explicit call for container instance
			//
			explicit insert_iterator(Container& container, typename Container::iterator iterator);
			//
			// insert element to position of container
			//
			insert_iterator& operator=(typename Container::const_reference value);
			//
			// do nothing for other operations and return current instance 
			//
			insert_iterator& operator*();

			insert_iterator& operator++();

			insert_iterator& operator++(int);

	};
	//
	// Constructs an back_insert_iterator that inserts new elements into position pointed by iterator of <container>.
	//
	template <typename Container, typename Iterator>
	insert_iterator<Container> inserter (Container& cont, Iterator it);
}

#include "insert_iterator_impl.hpp"

