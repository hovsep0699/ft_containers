#pragma once

#include "insert_iterator.hpp"

namespace ft
{
	//
	// Inserts a new element in the container at the end of <container>.
	//
	template<typename Container>
	back_insert_iterator<Container>::back_insert_iterator(Container& container)
		: _container(&container)
	{}
	//
	// insert element to end of container
	//
	template<typename Container>
	back_insert_iterator<Container>& back_insert_iterator<Container>::operator=(typename Container::const_reference value)
	{
		_container->push_back(value);
		return *this;
	}
	//
	// do nothing for other operations and return current instance 
	//
	template<typename Container>
	back_insert_iterator<Container>& back_insert_iterator<Container>::operator*()
	{
		return *this;
	}
	template<typename Container>
	back_insert_iterator<Container>& back_insert_iterator<Container>::operator++()
	{
		return *this;
	}
	template<typename Container>
	back_insert_iterator<Container>& back_insert_iterator<Container>::operator++(int)
	{
		return *this;
	}
	//
	// Constructs an back_insert_iterator that inserts new elements into end of <container>.
	//
	template <typename Container>
	back_insert_iterator<Container> back_inserter (Container& cont)
	{
		back_insert_iterator<Container> it(cont);
		return it;
	}

}
