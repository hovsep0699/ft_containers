#pragma once

#include "insert_iterator_def.hpp"
#include "insert_iterator.hpp"

namespace ft
{

	template<typename Container>
	insert_iterator<Container>::insert_iterator(Container& container, typename Container::iterator iterator)
		: _container(&container), iterator(iterator)
	{}
	//
	// insert element to position of container
	//
	template<typename Container>
	insert_iterator<Container>& insert_iterator<Container>::operator=(typename Container::const_reference value)
	{
		iterator = _container->insert(iterator, value);
		++iterator;
		return *this;
	}
	//
	// do nothing for other operations and return current instance 
	//
	template<typename Container>
	insert_iterator<Container>& insert_iterator<Container>::operator*()
	{
		return *this;
	}
	template<typename Container>
	insert_iterator<Container>& insert_iterator<Container>::operator++()
	{
		return *this;
	}
	template<typename Container>
	insert_iterator<Container>& insert_iterator<Container>::operator++(int)
	{
		return *this;
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
