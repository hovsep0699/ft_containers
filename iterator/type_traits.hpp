#pragma once


namespace ft
{
	//
	// Wrapper structure for enable or disable template
	//
	template<bool B, typename T = void>
		struct enable_if {};

	template<typename T>
		struct enable_if<true, T> { typedef T type; };
	//
	// Wrapper structure for integral types
	// 
	template<typename T, T v>
		struct integral_constant
		{
			static const T value = v;
			typedef T value_type;
			typedef integral_constant type; 
			operator value_type() const { return value; }
		};
	//
	//   
	//
	template<typename T>
		struct is_integral : integral_constant<T, false> {};

	template<>
		struct is_integral<char> : integral_constant<bool, true> {};

	template<>
		struct is_integral<signed char> : integral_constant<bool, true> {};

	template<>
		struct is_integral<unsigned char> : integral_constant<bool, true> {};

	template<>
		struct is_integral<wchar_t> : integral_constant<bool, true> {};

	template<>
		struct is_integral<char16_t> : integral_constant<bool, true> {};

	template<>
		struct is_integral<char32_t> : integral_constant<bool, true> {};

	template<>
		struct is_integral<short int> : integral_constant<bool, true> {};

	template<>
		struct is_integral<unsigned short> : integral_constant<bool, true> {};

	template<>
		struct is_integral<int> : integral_constant<bool, true> {};

	template<>
		struct is_integral<long> : integral_constant<bool, true> {};

	template<>
		struct is_integral<unsigned long> : integral_constant<bool, true> {};

	template<>
		struct is_integral<long long> : integral_constant<bool, true> {};

	template<>
		struct is_integral<unsigned long long> : integral_constant<bool, true> {};

	template<>
		struct is_integral<bool> : integral_constant<bool, true> {};

	template<bool B, typename T, typename F>
		struct conditional { typedef T type; };

	template<typename T, typename F>
		struct conditional<false, T, F> { typedef F type; };

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
