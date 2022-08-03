#pragma once

#include "algorithm.hpp"

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
			pair() : first(), second() {}
			pair(const first_type& first, const second_type& second) : first(first), second(second) {}
			template<typename K, typename V>
			pair(const pair<K,V>& p) : first(p.first), second(p.second) {}
			pair(const pair& p) : first(p.first), second(p.second) {}
			pair& operator=(const pair& p)
			{
				if (&p != this)
				{
					first = p.first;
					second = p.second;
				}
				return *this;
			}
			// 
			// swap pair contents
			//
			void swap(pair& p)
			{
				ft::swap(first, p.first);
				ft::swap(second, p.second);
			}

		};
	//
	// compare operations
	//
	template< typename T1, typename T2 >
		bool operator==( const ft::pair<T1,T2>& p1, const ft::pair<T1,T2>& p2 )
		{
			return p1.first == p2.first && p1.second == p2.second;	
		}

	template< typename T1, typename T2 >
		bool operator!=( const ft::pair<T1,T2>& p1, const ft::pair<T1,T2>& p2 )
		{
			return !(p1 == p2);	
		}

	template< typename T1, typename T2 >
		bool operator>( const ft::pair<T1,T2>& p1, const ft::pair<T1,T2>& p2 )
		{
			return p1.first > p2.first && p1.second > p2.second ;	
		}

	template< typename T1, typename T2 >
		bool operator>=( const ft::pair<T1,T2>& p1, const ft::pair<T1,T2>& p2 )
		{
			return !(p1 > p2);	
		}

	template< typename T1, typename T2 >
		bool operator<( const ft::pair<T1,T2>& p1, const ft::pair<T1,T2>& p2 )
		{
			return p1.first < p2.first && p1.second < p2.second ;	
		}

	template< typename T1, typename T2 >
		bool operator<=( const ft::pair<T1,T2>& p1, const ft::pair<T1,T2>& p2 )
		{
			return !(p1 < p2);	
		}
	//
	// creates a pair object of type, defined by the argument types.
	//
	template< typename T1, typename T2 >
		pair<T1,T2> make_pair( T1 t, T2 u )
		{
			return ft::pair<T1, T2>(t, u);
		}

}
