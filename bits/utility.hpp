#pragma once

#include "containers/containers.hpp"
#include "bits/algorithm.hpp"

namespace ft
{
	template<typename T1,typename T2>
	struct pair
	{
		//
		// type of pair elements
		//
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;
		pair();
		pair(const first_type& first, const second_type& second);
		template<typename K, typename V>
		pair(const pair<K,V>& p);
		pair(const pair& p);
		pair& operator=(const pair& p);
		// 
		// swap pair contents
		//
		void swap(pair& p);

	};
	//
	// compare operations
	//
	template< typename T1, typename T2 >
	bool operator==( const pair<T1,T2>& p1, const pair<T1,T2>& p2 );

	template< typename T1, typename T2 >
	bool operator!=( const pair<T1,T2>& p1, const pair<T1,T2>& p2 );

	template< typename T1, typename T2 >
	bool operator>( const pair<T1,T2>& p1, const pair<T1,T2>& p2 );

	template< typename T1, typename T2 >
	bool operator>=( const pair<T1,T2>& p1, const pair<T1,T2>& p2 );

	template< typename T1, typename T2 >
	bool operator<( const pair<T1,T2>& p1, const pair<T1,T2>& p2 );

	template< typename T1, typename T2 >
	bool operator<=( const pair<T1,T2>& p1, const pair<T1,T2>& p2 );
	//
	// creates a pair object of type, defined by the argument types.
	//
	template< typename T1, typename T2 >
	pair<T1,T2> make_pair( T1 t, T2 u );


	template< typename T, typename Alloc >
	void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs );

	template< typename T1, typename T2 >
	void swap(pair<T1, T2>& lhs, pair<T1, T2>& rhs );

	template<typename T>
	inline T* addressof(T& arg);

}
#include "utility_impl.hpp"
