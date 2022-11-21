#pragma once

#include "bits/type_traits_def.hpp"

namespace ft
{
	/*
	 * Wrapper structure for enable or disable template
	*/
	template<bool B, typename T>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	/*
	 * Wrapper structure for integral types
	*/ 
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

	template<typename T,
			typename U>
	struct is_same
	{
		static const bool value = false;
	};
	
	/*
	 * specialization for check if type is same
	*/
	template<typename T>
	struct is_same<T, T>  
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

	/*
	 * trait structure for check if type is integral   
	*/
	template<typename T>
	struct is_integral : 									false_type {};

	template<>
	struct is_integral<const int> :							true_type {};

	template<>
	struct is_integral<const long int> :					true_type {};

	template<>
	struct is_integral<const unsigned char> :				true_type {};

	template<>
	struct is_integral<const unsigned short int> :			true_type {};

	template<>
	struct is_integral<char> : 								true_type {};

	template<>
	struct is_integral<signed char> : 						true_type {};

	template<>
	struct is_integral<unsigned char> : 					true_type {};

	template<>
	struct is_integral<wchar_t> : 							true_type {};

	template<>
	struct is_integral<char16_t> : 							true_type {};

	template<>
	struct is_integral<char32_t> : 							true_type {};

	template<>
	struct is_integral<short int> : 						true_type {};

	template<>
	struct is_integral<unsigned int> : 						true_type {};

	template<>
	struct is_integral<const bool> : 						true_type {};
	
	template<>
	struct is_integral<const char> : 						true_type {};
	
	template<>
	struct is_integral<const signed char> : 				true_type {};
	
	template<>
	struct is_integral<const short int> : 					true_type {};
	
	template<>
	struct is_integral<const unsigned int> : 				true_type {};
	
	template<>
	struct is_integral<const unsigned long int> : 			true_type {};
	
	template<>
	struct is_integral<volatile char> : 					true_type {};
	
	template<>
	struct is_integral<volatile bool> : 					true_type {};

	template<>
	struct is_integral<volatile signed char> : 				true_type {};

	template<>
	struct is_integral<volatile short int> : 				true_type {};

	template<>
	struct is_integral<volatile int> : 						true_type {};

	template<>
	struct is_integral<volatile long int> : 				true_type {};

	template<>
	struct is_integral<volatile unsigned char> : 			true_type {};

	template<>
	struct is_integral<volatile unsigned short int> : 		true_type {};

	template<>
	struct is_integral<volatile unsigned int> : 			true_type {};

	template<>
	struct is_integral<volatile unsigned long int> : 		true_type {};

	template<>
	struct is_integral<const volatile char> : 				true_type {};

	template<>
	struct is_integral<const volatile bool> : 				true_type {};

	template<>
	struct is_integral<const volatile signed char> : 		true_type {};

	template<>
	struct is_integral<const volatile short int> : 			true_type {};

	template<>
	struct is_integral<const volatile int> : 				true_type {};

	template<>
	struct is_integral<const volatile long int> : 			true_type {};

	template<>
	struct is_integral<const volatile unsigned char> : 		true_type {};

	template<>
	struct is_integral<const volatile unsigned short int> :	true_type {};

	template<>
	struct is_integral<const volatile unsigned int> : 		true_type {};

	template<>
	struct is_integral<const volatile unsigned long int> :	true_type {};

	template<>
	struct is_integral<unsigned short> : 					true_type {};

	template<>
	struct is_integral<int> : 								true_type {};

	template<>
	struct is_integral<long> : 								true_type {};

	template<>
	struct is_integral<unsigned long> : 					true_type {};

	template<>
	struct is_integral<long long> : 						true_type {};

	template<>
	struct is_integral<unsigned long long> : 				true_type {};

	template<>
	struct is_integral<bool> : 								true_type {};

	template<bool B,
			typename T,
			typename F>
	struct conditional
	{
		typedef T type;
	};

	template<typename T,
			typename F>
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
