#pragma once


namespace ft
{
	template<typename Arg1,
			typename Arg2,
			typename Result>
	struct binary_function;

	template<typename Arg, typename Result>
	struct unary_function;

	template<typename _Tp = void>
    struct plus;

	template<typename _Tp = void>
	struct minus;

	template<typename _Tp = void>
	struct multiplies;

	template<typename _Tp = void>
	struct divides;

	template<typename _Tp = void>
	struct modulus;

	template<typename _Tp = void>
	struct negate;

	template<typename _Tp = void>
    struct equal_to;

	template<typename _Tp = void>
	struct not_equal_to;

	template<typename _Tp = void>
	struct greater;

	template<typename _Tp = void>
	struct less;

	template<typename _Tp = void>
	struct greater_equal;

	template<typename _Tp = void>
	struct less_equal;

	template<typename _Tp = void>
    struct logical_and;

	template<typename _Tp = void>
	struct logical_or;

	template<typename _Tp = void>
	struct logical_not;

	template<typename _Tp = void>
    struct bit_and;

	template<typename _Tp = void>
	struct bit_or;

	template<typename _Tp = void>
	struct bit_xor;

	template<typename _Tp = void>
	struct bit_not;

	template <class Predicate>
	class unary_negate;

	template <class Predicate>
	class binary_negate;

	template <class Predicate>
	unary_negate<Predicate> not1 (const Predicate& pred);

	template <class Predicate>
	binary_negate<Predicate> not2 (const Predicate& pred);

	template<typename Arg,
    	typename Result>
	class pointer_to_unary_function;

	template<typename  Arg1, 
    	typename Arg2,
    	typename Result>
	class pointer_to_binary_function;

	template<typename Arg, typename Result >
	pointer_to_unary_function<Arg, Result> ptr_fun( Result (*f)(Arg) );

	template <class Arg1, class Arg2, class Result>
	pointer_to_binary_function<Arg1, Arg2, Result> ptr_fun (Result (*f)(Arg1, Arg2));

	template<typename _Pair>
	struct select1st;

	template<typename _Pair>
	struct select2nd;
}

