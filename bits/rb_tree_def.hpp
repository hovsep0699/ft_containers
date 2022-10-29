#pragma once

#include "bits/functional.hpp"
#include "bits/allocator.hpp"

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
			typename _Compare = less<_K>, 
			typename _Allocator = allocator<_K> >
	class rb_tree;

	/* ==================================== */
	/*      iterator for red-black tree     */
	/* ==================================== */

	template<typename T>
	class rb_tree_iterator;

	/* ========================================= */
	/*      const_iterator for red-black tree	 */
	/* ========================================= */

	template<typename T>
	class rb_tree_const_iterator;

}

#include "rb_tree_node.hpp"

