#pragma once

#include "bits/type_traits_def.hpp"

namespace ft
{
	//
	// Wrapper structure for enable or disable template
	//
	template<bool B, typename T>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	//
	// Wrapper structure for integral types
	// 
	template<typename T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant type; 
		operator value_type() const 
		{
			return value;
		}
	};
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template<typename T, typename U>
	struct is_same
	{
		static const bool value = false;
	};

	template<typename T>
	struct is_same<T,T>  //specialization
	{
	   static const bool value = true;
	};

	template<typename T >
	struct remove_const
	{
		typedef T type;
	};

	template<typename T>
	struct remove_const<const T>
	{
		typedef T type;
	};
	//
	//   
	//
	template<typename T>
	struct is_integral : false_type {};

	template<>
	struct is_integral<char> : true_type {};

	template<>
	struct is_integral<signed char> : true_type {};

	template<>
	struct is_integral<unsigned char> : true_type {};

	template<>
	struct is_integral<wchar_t> : true_type {};

	template<>
	struct is_integral<char16_t> : true_type {};

	template<>
	struct is_integral<char32_t> : true_type {};

	template<>
	struct is_integral<short int> : true_type {};

	template<>
	struct is_integral<unsigned short> : true_type {};

	template<>
	struct is_integral<int> : true_type {};

	template<>
	struct is_integral<long> : true_type {};

	template<>
	struct is_integral<unsigned long> : true_type {};

	template<>
	struct is_integral<long long> : true_type {};

	template<>
	struct is_integral<unsigned long long> : true_type {};

	template<>
	struct is_integral<bool> : true_type {};

	template<bool B, typename T, typename F>
	struct conditional
	{
		typedef T type;
	};

	template<typename T, typename F>
	struct conditional<false, T, F>
	{
		typedef F type;
	};

	class ft_nullptr_t
	{
		void operator&() const {} 
		public:
			template<typename T>
				operator T*() const
				{
					return 0;
				}
			template<typename I, typename T>
				operator T I::*() const
				{
					return 0;
				}
	} ft_nullptr;



}
