#pragma once

#include "bits/utility.hpp"

namespace ft
{

	template<typename T1,typename T2>
	pair<T1, T2>::pair()
		: first(), second()
	{}

	template<typename T1,typename T2>
	pair<T1, T2>::pair(const first_type& first, const second_type& second)
		: first(first), second(second)
	{}

	template<typename T1,typename T2>
	template<typename K, typename V>
	pair<T1, T2>::pair(const pair<K,V>& p)
		: first(p.first), second(p.second)
	{}

	template<typename T1,typename T2>
	pair<T1, T2>::pair(const pair<T1, T2>& p)
		: first(p.first), second(p.second)
	{}

	template<typename T1,typename T2>
	pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& p)
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
	template<typename T1,typename T2>
	void pair<T1, T2>::swap(pair& p)
	{
		swap(first, p.first);
		swap(second, p.second);
	}
	template< typename T1, typename T2 >
	bool operator==( const pair<T1, T2>& p1, const pair<T1, T2>& p2 )
	{
		return p1.first == p2.first && p2.second == p2.second;
	}

	template< typename T1, typename T2 >
	bool operator!=( const pair<T1, T2>& p1, const pair<T1, T2>& p2 )
	{
		return !(p1 == p2);
	}

	template< typename T1, typename T2 >
	bool operator<( const pair<T1,T2>& p1, const pair<T1,T2>& p2 )
	{
		if (p1.first < p2.first)
			return true;
		else if (p1.first > p2.first)
			return false;
		else if (p1.second < p2.second)
			return true;
		else
			return false;
	}

	template< typename T1, typename T2 >
	bool operator>=( const pair<T1, T2>& p1, const pair<T1, T2>& p2 )
	{
		return !(p1 < p2);
	}


	template< typename T1, typename T2 >
	bool operator>( const pair<T1, T2>& p1, const pair<T1, T2>& p2 )
	{
		if (p1.first > p2.first)
			return true;
		else if (p1.first < p2.first)
			return false;
		else if (p1.second > p2.second)
			return true;
		else
			return false;
	}

	template< typename T1, typename T2 >
	bool operator<=( const pair<T1, T2>& p1, const pair<T1, T2>& p2 )
	{
		return !(p1 > p2);
	}

	template< typename T1, typename T2 >
	pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return pair<T1, T2>(t, u);
	}


	template< typename T, typename Alloc >
	void swap( vector<T, Alloc>& lhs, vector<T, Alloc>& rhs );

	template< typename T1, typename T2 >
	void swap(pair<T1, T2>& lhs, pair<T1, T2>& rhs )
	{
		lhs.swap(rhs);
	}
}
