#pragma once

#include "iterators/adapters/front_insert_iterator.hpp"

namespace ft
{

	template<typename Container>
	front_insert_iterator<Container>::front_insert_iterator(Container& container)
		: _container(&container)
	{}
	//
	// insert element to begining of container
	//
	template<typename Container>
	front_insert_iterator<Container>& front_insert_iterator<Container>::operator=(typename Container::const_reference value)
	{
		_container->push_front(value);
		return *this;
	}
	//
	// do nothing for other operations and return current instance 
	//
	template<typename Container>
	front_insert_iterator<Container>& front_insert_iterator<Container>::operator*()
	{
		return *this;
	}
	template<typename Container>
	front_insert_iterator<Container>& front_insert_iterator<Container>::operator++()
	{
		return *this;
	}
	template<typename Container>
	front_insert_iterator<Container>& front_insert_iterator<Container>::operator++(int)
	{
		return *this;
	}

	template <typename Container>
	front_insert_iterator<Container> front_inserter (Container& cont)
	{
		front_insert_iterator<Container> it(cont);
		return it;
	}
}
