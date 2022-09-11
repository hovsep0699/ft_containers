#pragma once

#include "functional_def.hpp"

namespace ft
{
	template<typename Arg1,
		typename Arg2,
		typename Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template<typename Arg, 
		typename Result>
	struct unary_function
	{
		typedef Arg argument_type;
		typedef Result result_type;
	};

	template<typename T>
	struct plus : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct minus : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct multiplies : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct divides : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct modulus : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct negate : unary_function<T, T>
	{
		T operator()(const T& x);
	};

	template<typename T>
    struct equal_to : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
	struct not_equal_to : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
	struct greater : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
	struct less : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
	struct greater_equal : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
	struct less_equal : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
    struct logical_and : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
	struct logical_or : binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y);
	};

	template<typename T>
	struct logical_not : unary_function<T, bool>
	{
		bool operator()(const T& x);
	};

	template<typename T>
    struct bit_and : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct bit_or : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct bit_xor : binary_function<T, T, T>
	{
		T operator()(const T& x, const T& y);
	};

	template<typename T>
	struct bit_not : unary_function<T, T>
	{
		T operator()(const T& x);
	};

	template <typename Predicate>
	class unary_negate : public unary_function<typename Predicate::argument_type, bool>
	{
		public:
			explicit unary_negate (const Predicate& pred);
			bool operator() (const typename Predicate::argument_type& x) const;
		protected:
			Predicate fn_;
	};

	template <typename Predicate>
	class binary_negate
	{
		public:
			explicit binary_negate (const Predicate& pred);
			bool operator() (const typename Predicate::first_argument_type& x,
					const typename Predicate::second_argument_type& y) const;
		protected:
			Predicate fn_;
	};

	template<typename Arg,
    	typename Result>
	class pointer_to_unary_function : public unary_function<Arg, Result>
	{
		public:
			explicit pointer_to_unary_function( Result (*f)(Arg) );
			Result operator()( Arg x ) const;
		protected:
			Result (*pFunc)(Arg);
	};

	template<typename  Arg1, 
    	typename Arg2,
    	typename Result>
	class pointer_to_binary_function : public binary_function<Arg1, Arg2, Result>
	{
		public:
			explicit pointer_to_binary_function( Result (*f)(Arg1, Arg2) );
			Result operator()( Arg1 x, Arg2 y ) const;
		protected:
			Result (*pFunc)(Arg1, Arg2);
	};

	template<typename _Pair>
	struct select1st : unary_function<_Pair, typename _Pair::first_type>
	{
		typename _Pair::first_type& operator()(_Pair& p) const;
		const typename _Pair::first_type& operator()(const _Pair& p) const;
		
	};

	template<typename _Pair>
	struct select2nd : unary_function<_Pair, typename _Pair::second_type>
	{
		typename _Pair::second_type& operator()(_Pair& p) const;
		const typename _Pair::second_type& operator()(const _Pair& p) const;
		
	};
}
