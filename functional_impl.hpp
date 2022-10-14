#pragma once

#include "functional.hpp"

namespace ft
{
	template<typename T>
    T plus<T>::operator()(const T& x, const T& y) const
	{
		return x + y;
	}

	template<typename T>
	T minus<T>::operator()(T const& x, T const& y) const
	{
		return x - y;
	}

	template<typename T>
	T multiplies<T>::operator()(T const& x, T const& y) const
	{
		return x * y;
	}

	template<typename T>
	T divides<T>::operator()(T const& x, T const& y) const
	{
		return x / y;
	}

	template<typename T>
	T modulus<T>::operator()(T const& x, T const& y) const
	{
		return x % y;
	}

	template<typename T>
	T negate<T>::operator()(T const& x) const
	{
		return -x;
	}

	template<typename T>
	bool equal_to<T>::operator()(T const& x, T const& y) const
	{
		return x == y;
	}

	template<typename T>
	bool not_equal_to<T>::operator()(T const& x, T const& y) const
	{
		return x != y;
	}

	template<typename T>
	bool greater<T>::operator()(T const& x, T const& y) const
	{
		return x > y;
	}

	template<typename T>
	bool less<T>::operator()(T const& x, T const& y) const
	{
		return x < y;
	}

	template<typename T>
	bool greater_equal<T>::operator()(T const& x, T const& y) const
	{
		return x >= y;
	}

	template<typename T>
	bool less_equal<T>::operator()(T const& x, T const& y) const
	{
		return x <= y;
	}

	template<typename T>
	bool logical_and<T>::operator()(T const& x, T const& y) const
	{
		return x && y;
	}
	template<typename T>
	bool logical_or<T>::operator()(T const& x, T const& y) const
	{
		return x || y;
	}
	template<typename T>
	bool logical_not<T>::operator()(T const& x) const
	{
		return !x;
	}
	template<typename T>
	T bit_and<T>::operator()(T const& x, T const& y) const
	{
		return x & y;
	}

	template<typename T>
	T bit_or<T>::operator()(T const& x, T const& y) const
	{
		return x | y;
	}
	template<typename T>
	T bit_xor<T>::operator()(T const& x, T const& y) const
	{
		return x ^ y;
	}
	template<typename T>
	T bit_not<T>::operator()(T const& x) const
	{
		return ~x;
	}

	template<typename Arg,
    	typename Result>
	pointer_to_unary_function<Arg, Result>::pointer_to_unary_function( Result (*f)(Arg) )
		: pFunc(f)
	{}
	template<typename Arg,
    	typename Result>
	Result pointer_to_unary_function<Arg, Result>::operator()(Arg x) const
	{
		return (*pFunc)(x);
	}

	template<typename Arg1,
		typename Arg2,
    	typename Result>
	pointer_to_binary_function<Arg1, Arg2, Result>::pointer_to_binary_function( Result (*f)(Arg1, Arg2) )
		: pFunc(f)
	{}
	template<typename Arg1,
		typename Arg2,
    	typename Result>
	Result pointer_to_binary_function<Arg1, Arg2, Result>::operator()(Arg1 x, Arg2 y) const
	{
		return (*pFunc)(x, y);
	}

	template<typename Arg, typename Result >
	pointer_to_unary_function<Arg, Result> ptr_fun( Result (*f)(Arg) )
	{
		return pointer_to_unary_function<Arg, Result>(f);
	}

	template <class Arg1, class Arg2, class Result>
	pointer_to_binary_function<Arg1, Arg2, Result> ptr_fun (Result (*f)(Arg1, Arg2))
	{
		return pointer_to_binary_function<Arg1, Arg2, Result>(f);
	}

	template<typename Predicate>
	unary_negate<Predicate>::unary_negate(const Predicate& pred)
		: fn_(pred)
	{}

	template<typename Predicate>
	bool unary_negate<Predicate>::operator()(const typename Predicate::argument_type& x) const
	{
		return !fn_(x);
	}

	template<typename Predicate>
	binary_negate<Predicate>::binary_negate(const Predicate& pred)
		: fn_(pred)
	{}

	template<typename Predicate>
	bool binary_negate<Predicate>::operator()(const typename Predicate::first_argument_type& x, const typename Predicate::second_argument_type& y) const
	{
		return !fn_(x, y);
	}

	template <class Predicate>
	unary_negate<Predicate> not1 (const Predicate& pred)
	{
		return unary_negate<Predicate>(pred);
	}

	template <class Predicate>
	binary_negate<Predicate> not2 (const Predicate& pred)
	{
		return binary_negate<Predicate>(pred);
	}

	template <typename _Pair>
	typename _Pair::first_type& select1st<_Pair>::operator()(_Pair& p) const
	{
		return p.first;
	}
	template <typename _Pair>
	const typename _Pair::first_type& select1st<_Pair>::operator()(const _Pair& p) const
	{
		return p.first;
	}
	template <typename _Pair>
	typename _Pair::second_type& select2nd<_Pair>::operator()(_Pair& p) const
	{
		return p.second;
	}
	template <typename _Pair>
	const typename _Pair::second_type& select2nd<_Pair>::operator()(const _Pair& p) const
	{
		return p.second;
	}
}	
