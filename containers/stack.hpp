#pragma once

#include "bits/algorithm.hpp"
#include "bits/utility.hpp"
#include "containers/vector.hpp"

namespace ft
{

    template<typename T, typename Container>
		class stack
		{
			public:
				typedef Container container_type;
				typedef typename Container::value_type value_type;
				typedef typename Container::size_type size_type;
				typedef typename Container::reference reference;
				typedef typename Container::const_reference const_reference;


			explicit stack( const Container& cont = Container() );
			stack( const stack& other );
			stack& operator=( const stack& other );
			reference top();
			const_reference top() const;
			void push( const value_type& value );
			bool empty() const;
			size_type size() const;
			void pop();
			void swap( stack& other );
			template< typename Elem_Type, typename Base_Container >
				friend bool operator==( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );
			template< typename Elem_Type, typename Base_Container >
				friend bool operator!=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );
			template< typename Elem_Type, typename Base_Container >
				friend bool operator>( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );
			template< typename Elem_Type, typename Base_Container >
				friend bool operator<( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );
			template< typename Elem_Type, typename Base_Container >
				friend bool operator>=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );
			template< typename Elem_Type, typename Base_Container >
				friend bool operator<=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );
			protected:
				container_type c;

		};
    
	template< typename Elem_Type, typename Base_Container >
	bool operator==( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );

	template< typename Elem_Type, typename Base_Container >
	bool operator!=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );

	template< typename Elem_Type, typename Base_Container >
	bool operator>( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );

	template< typename Elem_Type, typename Base_Container >
	bool operator<( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );

	template< typename Elem_Type, typename Base_Container >
	bool operator>=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );

	template< typename Elem_Type, typename Base_Container >
	bool operator<=( const ft::stack<Elem_Type, Base_Container>& s1, const ft::stack<Elem_Type,Base_Container>& s2 );
};

#include "stack_impl.hpp"


