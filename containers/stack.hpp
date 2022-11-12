#pragma once

#include "bits/algorithm.hpp"
#include "bits/utility.hpp"
#include "containers/vector.hpp"

namespace ft
{
    template<typename T,
    		typename _Container>
	class stack
	{
		public:

			/* =================== */
			/*    member types     */
			/* =================== */

			typedef _Container								container_type;
			typedef typename _Container::value_type			value_type;
			typedef typename _Container::size_type			size_type;
			typedef typename _Container::reference			reference;
			typedef typename _Container::const_reference	const_reference;


		/* ========================= */
		/*      member functions     */
		/* ========================= */

		explicit	stack( const container_type& cont = container_type() );
					stack( const stack& other );
		stack&		operator=( const stack& other );

		/* ========================= */
		/*       element access      */
		/* ========================= */

		reference			top();
		const_reference		top() const;

		/* ========================= */
		/*          capacity         */
		/* ========================= */

		bool		empty() const;
		size_type	size() const;

		
		/* ========================= */
		/*         modifiers         */
		/* ========================= */

		void	push( const value_type& value );
		void	pop();
		void	swap( stack& other );

		/* ========================= */
		/*    non-member functions   */
		/* ========================= */

		template< typename _V,
				typename _Cont>
		friend bool operator==( const stack<_V, _Cont>& s1,
								const stack<_V, _Cont>& s2 );

		template< typename _V,
				typename _Cont>
		friend bool operator!=( const stack<_V, _Cont>& s1,
								const stack<_V, _Cont>& s2 );
		template< typename _V,
				typename _Cont>
		friend bool operator>( const stack<_V, _Cont>& s1,
								const stack<_V, _Cont>& s2 );
		template< typename _V,
				typename _Cont>
		friend bool operator>=( const stack<_V, _Cont>& s1,
								const stack<_V, _Cont>& s2 );
		template< typename _V,
				typename _Cont>
		friend bool operator<( const stack<_V, _Cont>& s1,
								const stack<_V, _Cont>& s2 );
		template< typename _V,
				typename _Cont>
		friend bool operator<=( const stack<_V, _Cont>& s1,
								const stack<_V, _Cont>& s2 );
		protected:

			/* =================== */
			/*    member objects   */
			/* =================== */

			container_type c;

	};
    
	/* ========================= */
	/*    non-member functions   */
	/* ========================= */

	template< typename _T,
			typename _Container>
	bool operator==( const stack<_T, _Container>& s1,
					const stack<_T, _Container>& s2 );

	template< typename _T,
			typename _Container>
	bool operator!=( const stack<_T, _Container>& s1,
					const stack<_T, _Container>& s2 );

	template< typename _T,
			typename _Container>
	bool operator>( const stack<_T, _Container>& s1,
					const stack<_T, _Container>& s2 );

	template< typename _T,
			typename _Container>
	bool operator>=( const stack<_T, _Container>& s1,
					const stack<_T, _Container>& s2 );

	template< typename _T,
			typename _Container>
	bool operator<( const stack<_T, _Container>& s1,
					const stack<_T, _Container>& s2 );

	template< typename _T,
			typename _Container>
	bool operator<=( const stack<_T, _Container>& s1,
					const stack<_T, _Container>& s2 );
};

#include "stack_impl.hpp"


