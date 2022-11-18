#pragma once

#include "containers/containers.hpp"
#include "bits/algorithm.hpp"

namespace ft
{
	template<typename T1,typename T2>
	struct pair
	{
		/* =================== */
		/*    member types     */
		/* =================== */

		typedef T1	first_type;
		typedef T2	second_type;

		/* ========================= */
		/*      member functions     */
		/* ========================= */

		template<typename K,
				typename V>
				pair(const pair<K, V>& p);
				pair();
				pair(const first_type& first,
					const second_type& second);
				pair(const pair& p);
		pair&	operator=(const pair& p);
		void	swap(pair& p);

		/* ========================= */
		/*      member objects       */
		/* ========================= */

		T1	first;
		T2	second;

	};

	/* ========================= */
	/*    non-member functions   */
	/* ========================= */

	template< typename T,
			typename U >
	bool operator==( const pair<T, U>& p1,
					const pair<T, U>& p2 );

	template< typename T,
			typename U >
	bool operator!=( const pair<T, U>& p1,
					const pair<T, U>& p2 );

	template< typename T,
			typename U >
	bool operator>( const pair<T, U>& p1,
					const pair<T, U>& p2 );

	template< typename T,
			typename U >
	bool operator>=( const pair<T, U>& p1,
					const pair<T, U>& p2 );

	template< typename T,
			typename U >
	bool operator<( const pair<T, U>& p1,
					const pair<T, U>& p2 );

	template< typename T,
			typename U >
	bool operator<=( const pair<T, U>& p1,
					const pair<T, U>& p2 );

	/*
	 * @function		make_pair
	 *
	 * @abstract		creates a pair object from params
	 *
	 * @discuss			function creates a pair object, deducing 
	 * 					the target type from the types of arguments
	 *
	 * @tparam	T		any type
	 * @tparam	U		any type
	 *
	 * @param	t 		object of type T		
	 * @param	u 		object of type U		
	 *
	 * @result			pair object from t and u params
	 *
	*/
	template< typename T,
			typename U >
	pair<T, U>	make_pair( T t, U u );


	/*
	 * @function		addressof
	 *
	 * @abstact			returns actual address of param
	 * 
	 * @discuss			function gets object of any type and returns
	 * 					actual address of param
	 *
	 * @tparam	T		any type
	 *
	 * @param	arg		object of T type
	 *
	 * @result			actual address of arg
	*/
	template<typename T>
	inline T*	addressof(T& arg);

}
#include "utility_impl.hpp"
