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
			Container* container;
		public:
			//
			// type of Container
			//
			typedef Container container_type;
			//
			// only explicit call for container instance
			//
			explicit back_insert_iterator(Container& container) : container(&container) {}
			//
			// insert element to end of container
			//
			back_insert_iterator<Container>& operator=(typename Container::const_reference value)
			{
				container->push_back(value);
				return *this;
			}
			//
			// do nothing for other operations and return current instance 
			//
			back_insert_iterator<Container>& operator*()
			{
				return *this;
			}
			back_insert_iterator<Container>& operator++()
			{
				return *this;
			}
			back_insert_iterator<Container>& operator++(int)
			{
				return *this;
			}
	};
	//
	// Inserts a new element in the container at the beginning of <container>.
	//
	template<typename Container>
	class front_insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
	{
		protected:
			Container* container;
		public:
			//
			// type of Container
			//
			typedef Container container_type;
			//
			// only explicit call for container instance
			//
			explicit front_insert_iterator(Container& container) : container(&container) {}
			//
			// insert element to begining of container
			//
			front_insert_iterator<Container>& operator=(typename Container::const_reference value)
			{
				container->push_front(value);
				return *this;
			}
			//
			// do nothing for other operations and return current instance 
			//
			front_insert_iterator<Container>& operator*()
			{
				return *this;
			}
			front_insert_iterator<Container>& operator++()
			{
				return *this;
			}
			front_insert_iterator<Container>& operator++(int)
			{
				return *this;
			}
	};
	//
	// Insert a new element into position pointed by iterator of <container>.
	//
	template<typename Container>
	class insert_iterator : public ft::iterator<ft::output_iterator_tag, void, void, void, void>
	{
		protected:
			Container* container;
			typename Container::iterator iterator;
		public:
			//
			// type of Container
			//
			typedef Container container_type;
			//
			// only explicit call for container instance
			//
			explicit insert_iterator(Container& container, typename Container::iterator iterator) : container(&container), iterator(iterator) {}
			//
			// insert element to position of container
			//
			insert_iterator<Container>& operator=(typename Container::const_reference value)
			{
				iterator = container->insert(iterator, value);
				++iterator;
				return *this;
			}
			//
			// do nothing for other operations and return current instance 
			//
			insert_iterator<Container>& operator*()
			{
				return *this;
			}
			insert_iterator<Container>& operator++()
			{
				return *this;
			}
			insert_iterator<Container>& operator++(int)
			{
				return *this;
			}

	};
	//
	// Constructs an back_insert_iterator that inserts new elements into end of <container>.
	//
	template <typename Container>
	back_insert_iterator<Container> back_inserter (Container& cont)
	{
		back_insert_iterator<Container> it(cont);
		return it;
	}
	//
	// Constructs an front_insert_iterator that inserts new elements into begining of <container>.
	//
	template <typename Container>
	front_insert_iterator<Container> front_inserter (Container& cont)
	{
		front_insert_iterator<Container> it(cont);
		return it;
	}
	//
	// Constructs an back_insert_iterator that inserts new elements into position pointed by iterator of <container>.
	//
	template <typename Container, typename Iterator>
	insert_iterator<Container> inserter (Container& cont, Iterator it)
	{
		insert_iterator<Container> iter(cont, it);
		return iter;
	}
}

