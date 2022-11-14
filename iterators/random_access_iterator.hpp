#pragma once

#include "bits/iterator_traits.hpp"
#include "bits/type_traits.hpp"
#include "iterators/random_access_iterator_def.hpp"


namespace ft
{
	template<typename T>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
		public:

			/* ================== */
			/*    member types    */
			/* ================== */

			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference				reference;
			typedef const reference																const_reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer				pointer;
			typedef const pointer																const_pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type		difference_type;

			/* ================== */
			/*    constructors    */
			/* ================== */

			random_access_iterator();
			random_access_iterator(pointer ptr);
			random_access_iterator(const random_access_iterator& it);

			operator random_access_iterator<const value_type>() const;

			random_access_iterator& operator=(const random_access_iterator& it);

			/* ======================= */
			/*    access  operators    */
			/* ======================= */

			reference operator*() const;

			pointer operator->() const;

			reference operator[](difference_type n);

			const_reference operator[](difference_type n) const;

			/* =========================== */
			/*    arithmetic  operators    */
			/* =========================== */

			random_access_iterator& operator++();

			random_access_iterator operator++(int);

			random_access_iterator& operator--();

			random_access_iterator operator--(int);

			random_access_iterator& operator+=(difference_type offset);

			random_access_iterator& operator-=(difference_type offset);

			random_access_iterator operator+(difference_type offset) const;

			random_access_iterator operator-(difference_type offset) const;

			/* ======================== */
			/*    compare  operators    */
			/* ======================== */

			bool operator<(const random_access_iterator& it) const;

			bool operator>(const random_access_iterator& it) const;

			bool operator<=(const random_access_iterator& it) const;

			bool operator>=(const random_access_iterator& it) const;

			bool operator==(const random_access_iterator& it) const;

			bool operator!=(const random_access_iterator& it) const;

			/* ================ */
			/*    base access   */
			/* ================ */

			pointer base();

			const_pointer base() const;


		protected:
			pointer _ptr;
	};

}

#include "random_access_iterator_impl.hpp"

