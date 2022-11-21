#pragma once

#include "iterators/iterator.hpp"
#include "bits/utility.hpp"

namespace ft
{
	template<typename T,
			typename Allocator>
	class vector
	{
		public:

			/* =================== */
			/*    member types     */
			/* =================== */

			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef ft::random_access_iterator<value_type>						iterator;
			typedef ft::random_access_iterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;


			/* ========================= */
			/*      member functions     */
			/* ========================= */

			template <typename InputIterator>
							vector (InputIterator first, InputIterator last, 
									const allocator_type& alloc = allocator_type() );
			explicit		vector(const allocator_type& alloc = allocator_type());
			explicit		vector(size_type n, 
									const_reference val = value_type(), 
									const allocator_type& alloc = allocator_type());
							vector(const vector& vec);
							vector& operator= (const vector& x);
			virtual			~vector();
			void			assign( size_type count, const_reference value );
			template< typename InputIt >
			void			assign( InputIt first, InputIt last);
			allocator_type	get_allocator() const;

			/* ========================= */
			/*       element access      */
			/* ========================= */

			reference			at (size_type _n);
			const_reference		at (size_type _n) const;
			reference			operator[] (size_type n);
			const_reference		operator[] (size_type n) const;
			reference			back();
			const_reference		back() const;
			reference			front();
			const_reference		front() const;
			pointer				data();
			const_pointer		data() const;

			/* ========================= */
			/*         iterators         */
			/* ========================= */

			iterator				begin();
			const_iterator			begin() const;
			const_iterator			cbegin() const;
			iterator				end();
			const_iterator			end() const;
			const_iterator			cend() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			const_reverse_iterator	crbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			const_reverse_iterator	crend() const;

			/* ========================= */
			/*          capacity         */
			/* ========================= */

			size_type	size() const;
			size_type	max_size() const;
			size_type	capacity() const;
			bool		empty() const;
			void		reserve(size_type new_capacity);
			void		shrink_to_fit();

			/* ========================= */
			/*         modifiers         */
			/* ========================= */

			void		clear();
			iterator	insert( const_iterator pos, const_reference value );
			iterator	insert( const_iterator pos, size_type count, const_reference value );
			template<typename InputIt>
			iterator	insert( const_iterator pos, InputIt first, InputIt last);
			iterator	erase( iterator pos );

			iterator	erase( iterator first, iterator last );
			void		push_back(const_reference val );
			void		pop_back();
			void		resize( size_type count, value_type value = value_type() );
			void		swap( vector& other );

		protected:

			/* =================== */
			/*    member objects   */
			/* =================== */

			allocator_type	_allocator;
			pointer			_data;
			size_type		_size;
			size_type		_capacity;
			size_type		_max_size;
		private:

			
			size_type update_size(size_type _new_capacity);

			template<typename IntegralType>
			void range_assign(IntegralType count, IntegralType value, ft::true_type);

			template<typename InputIterator>
			void range_assign(InputIterator first, InputIterator last, ft::false_type);

			iterator range_insert(const_iterator pos, size_type count, const_reference value, ft::true_type);

			template<typename InputIterator>
			iterator range_insert(const_iterator pos, InputIterator first, InputIterator last, ft::false_type);

	};

	/* ========================= */
	/*    non-member functions   */
	/* ========================= */

	template< typename T,
			typename _Alloc >
	bool operator==(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T,
			typename _Alloc >
	bool operator!=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T,
			typename _Alloc >
	bool operator>(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T,
			typename _Alloc >
	bool operator>=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T,
			typename _Alloc >
	bool operator<(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

	template< typename T,
			typename _Alloc >
	bool operator<=(
			const vector<T, _Alloc>& lhs,
            const vector<T, _Alloc>& rhs );

}


#include "containers/vector_impl.hpp"


