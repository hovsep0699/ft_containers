#pragma once

namespace ft
{

	//
	// Inserts a new element in the container at the end of <container>.
	//
	template<typename Container>
	class back_insert_iterator;

	//
	// Inserts a new element in the container at the beginning of <container>.
	//
	template<typename Container>
	class front_insert_iterator;

	//
	// Insert a new element into position pointed by iterator of <container>.
	//
	template<typename Container>
	class insert_iterator;

	//
	// Constructs an back_insert_iterator that inserts new elements into end of <container>.
	//
	template <typename Container>
	back_insert_iterator<Container> back_inserter (Container& cont);

	//
	// Constructs an front_insert_iterator that inserts new elements into begining of <container>.
	//
	template <typename Container>
	front_insert_iterator<Container> front_inserter (Container& cont);

	//
	// Constructs an back_insert_iterator that inserts new elements into position pointed by iterator of <container>.
	//
	template <typename Container, typename Iterator>
	insert_iterator<Container> inserter (Container& cont, Iterator it);
}
