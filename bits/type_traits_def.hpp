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
	struct is_integral<const int>;

	template<>
	struct is_integral<const long int>;

	template<>
	struct is_integral<const unsigned char>;

	template<>
	struct is_integral<const unsigned short int>;

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
	struct is_integral<unsigned int>;

	template<>
	struct is_integral<const bool>;
	
	template<>
	struct is_integral<const char>;
	
	template<>
	struct is_integral<const signed char>;
	
	template<>
	struct is_integral<const short int>;
	
	template<>
	struct is_integral<const unsigned int>;
	
	template<>
	struct is_integral<const unsigned long int>;
	
	template<>
	struct is_integral<volatile char>;
	
	template<>
	struct is_integral<volatile bool>;

	template<>
	struct is_integral<volatile signed char>;

	template<>
	struct is_integral<volatile short int>;

	template<>
	struct is_integral<volatile int>;

	template<>
	struct is_integral<volatile long int>;

	template<>
	struct is_integral<volatile unsigned char>;

	template<>
	struct is_integral<volatile unsigned short int>;

	template<>
	struct is_integral<volatile unsigned int>;

	template<>
	struct is_integral<volatile unsigned long int>;

	template<>
	struct is_integral<const volatile char>;

	template<>
	struct is_integral<const volatile bool>;

	template<>
	struct is_integral<const volatile signed char>;

	template<>
	struct is_integral<const volatile short int>;

	template<>
	struct is_integral<const volatile int>;

	template<>
	struct is_integral<const volatile long int>;

	template<>
	struct is_integral<const volatile unsigned char>;

	template<>
	struct is_integral<const volatile unsigned short int>;

	template<>
	struct is_integral<const volatile unsigned int>;

	template<>
	struct is_integral<const volatile unsigned long int>;

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
