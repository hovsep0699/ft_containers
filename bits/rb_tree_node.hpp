#pragma once

#include "bits/rb_tree_def.hpp"
#include "bits/type_traits.hpp"

namespace ft
{
	/* ============================ */
	/*	    base node structure		*/
	/* ============================ */

	class rb_tree_node_base
	{
		public:

			/* ======================== */
			/*	    base node types		*/
			/* ======================== */

			typedef rb_tree_node_base* 			base_ptr;
			typedef const rb_tree_node_base*	const_base_ptr;			

			
			/* ======================== */
			/*			members			*/
			/* ======================== */

			base_ptr							_left;
			base_ptr							_right;
			base_ptr							_parent;
			bool								_is_nil;
			rb_tree_color						_color;

			rb_tree_node_base(rb_tree_color _color = rb_red);
			rb_tree_node_base(const rb_tree_node_base& node);
			rb_tree_node_base& operator=(const rb_tree_node_base& node);


	};

	/* ============================ */
	/*	      node structure		*/
	/* ============================ */

	template<typename T>
	class rb_tree_node : public rb_tree_node_base
	{
		public:
			T _value;
			typedef rb_tree_node_base::base_ptr base_ptr;
			rb_tree_node(T _value, rb_tree_color _color = rb_red);
			rb_tree_node(const rb_tree_node& node);
			rb_tree_node& operator=(const rb_tree_node& node);
	};

	/* ======================================== */
	/*	      tree implementation structure		*/
	/* ======================================== */

	template<typename T, typename _Allocator>
	class rb_tree_impl
	{
		public:
			/* ========================= */
			/*	    base member types	 */
			/* ========================= */

		   	typedef rb_tree_node_base						base_type;
		   	typedef rb_tree_node_base*						base_ptr;
		   	typedef const rb_tree_node_base*				base_const_ptr;
		   	typedef const rb_tree_node<T>*					const_link_type;
		   	typedef rb_tree_node<T>*						link_type;
		private:		
			/*
		 	 * sentinel node of red-black tree 
			*/
			base_type			_sentinel;
			
			void initialize();

		public:

			/* ========================= */
			/*	      member types		 */
			/* ========================= */
			
			typedef T										value_type;
			typedef _Allocator								allocator_type;
			typedef typename _Allocator::size_type			size_type;
			typedef typename _Allocator::const_reference	const_reference;

			/* ============== */
			/*	   members    */
			/* ============== */

			allocator_type		_alloc;
			base_ptr			_root;
			base_ptr			_begin;
			base_ptr			_nil;
			base_ptr			_end;
			size_type			_size;
			bool				_multivalues;
		
			/* ========================= */
			/*	      constructor		 */
			/* ========================= */

			rb_tree_impl(bool multivalues = false, const allocator_type alloc = allocator_type() );
			rb_tree_impl(const rb_tree_impl& );
			rb_tree_impl& operator=(const rb_tree_impl&);
			virtual ~rb_tree_impl();

			/*!
			 * @function	create_node
			 * @abstract	Creates new red-black tree node
			 * @discussion	This function take a value
			 * 				and creates new node for red-black tree
			 *
			 * @param		value of node
			 *
			 *
			 * @result		A poiner to new node
			 *
			*/
			base_ptr create_node(const_reference _value);

			/*!
			 * @function	increment
			 * @abstract	Get next node of red-black tree
			 * @discussion	This function take a poiner of red-black tree
			 * 				and returns a pointer to next node 
			 * 				of tree
			 *
			 * @param		node pointer to node of red-black tree
			 *
			 *
			 * @result		A poiner to next node of tree
			 *
			*/
			static base_ptr increment(base_ptr node);

			/*!
			 * @function	decrement
			 * @abstract	Get previous node of red-black tree
			 * @discussion	This function take a poiner of red-black tree
			 * 				and returns a pointer to previous node 
			 * 				of tree
			 *
			 * @param		node pointer to node of red-black tree
			 *
			 *
			 * @result		A poiner to previous node of tree
			 *
			*/
			static base_ptr decrement(base_ptr node);

			/*!
			 * @function	min
			 * @abstract	find a leftmost node of red-black tree node
			 * @discussion	This function take a node of red-black tree
			 * 				and returns a pointer to leftmost node 
			 * 				of argument subtree
			 *
			 * @param		base node of red-black tree
			 *
			 *
			 * @result		A poiner to leftmost node of subtree
			 *
			*/
			static base_ptr min(base_ptr base);

			/*!
			 * @function	max
			 * @abstract	find a rightmost node of red-black tree node
			 * @discussion	This function take a node of red-black tree
			 * 				and returns a pointer to rightmost node 
			 * 				of argument subtree
			 *
			 * @param		base node of red-black tree
			 *
			 *
			 * @result		A poiner to rightmost node of subtree
			 *
			*/
			static base_ptr max(base_ptr base);

		
	};
}

#include "bits/rb_tree_node_impl.hpp"
