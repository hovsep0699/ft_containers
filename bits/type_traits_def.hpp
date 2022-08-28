#pragma once

namespace ft
{

	//
	// Wrapper structure for enable or disable template
	//
	template<bool B, typename T = void>
	struct enable_if;

	template<typename T>
	struct enable_if<true, T>;
	//
	// Wrapper structure for integral types
	// 
	template<typename T, T v>
	struct integral_constant;

	template<typename T, typename U>
	struct is_same;

	template<typename T>
	struct is_same<T,T>;  //specialization

	template<typename T >
	struct remove_const;

	template<typename T>
	struct remove_const<const T>;
	//
	//   
	//
	template<typename T>
	struct is_integral;

	template<>
	struct is_integral<char>;

	template<>
	struct is_integral<signed char>;

	template<>
	struct is_integral<unsigned char>;

	template<>
	struct is_integral<wchar_t>;

	template<>
	struct is_integral<char16_t>;

	template<>
	struct is_integral<char32_t>;

	template<>
	struct is_integral<short int>;

	template<>
	struct is_integral<unsigned short>;

	template<>
	struct is_integral<int>;

	template<>
	struct is_integral<long>;

	template<>
	struct is_integral<unsigned long>;

	template<>
	struct is_integral<long long>;

	template<>
	struct is_integral<unsigned long long>;

	template<>
	struct is_integral<bool>;

	template<bool B, typename T, typename F>
	struct conditional;

	template<typename T, typename F>
	struct conditional<false, T, F>;

	class ft_nullptr_t;
}
