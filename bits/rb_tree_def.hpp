#pragma once

#include "../iterators/iterator.hpp"
#include "utility.hpp"
#include "functional.hpp"
#include <memory>

namespace ft
{
	/* ==================================== */
	/*     definition of red/black node     */
	/* ==================================== */

	enum rb_tree_color
	{
		rb_red = true,
		rb_black = false
	};
	
	/* ================================ */
	/*      red-black tree base node    */
	/* ================================ */

	class rb_tree_node_base;

	/* ================================ */
	/*        red-black tree node       */
	/* ================================ */

	template<typename T>
	class rb_tree_node;

	/* ====================================== */
	/*     red-black tree helper structure    */
	/* ====================================== */

	template<typename T, typename _Allocator>
	class rb_tree_impl;

	/* ======================= */
	/*      red-black tree     */
	/* ======================= */

	template<typename _K, 
			typename _V, 
			typename _KOV, 
			typename _Compare = ft::less<_K>, 
			typename _Allocator = std::allocator<_K> >
	class rb_tree;

	/* ==================================== */
	/*      iterator for red-black tree     */
	/* ==================================== */

	template<typename T>
	class rb_tree_iterator;

	template<typename T>
	class rb_tree_const_iterator;

}


