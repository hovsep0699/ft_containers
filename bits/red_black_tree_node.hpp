#pragma once

#include "bits/type_traits.hpp"
namespace ft
{

	enum rb_tree_color
	{
		rb_tree_red = true,
		rb_tree_black = false
	};

	struct rb_tree_node_base
	{
		typedef rb_tree_node_base* base_ptr;
		typedef rb_tree_node_base const* const_base_ptr;
		base_ptr	left;
		base_ptr	right;
		base_ptr	parent;
		rb_tree_color		color;
		rb_tree_node_base(const rb_tree_color& color = rb_tree_red) : left(ft_nullptr), right(ft_nullptr), parent(ft_nullptr), color(color) {}
	};

	template<typename _Tp>
	struct rb_tree_node : rb_tree_node_base
	{
		typedef rb_tree_node<_Tp>* link_type;

	};

}
