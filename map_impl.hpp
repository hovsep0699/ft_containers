#include "map.hpp"

namespace ft
{

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	map<_K, _V, _Compare, _Allocator>::map()
		: _tree()
	{}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	map<_K, _V, _Compare, _Allocator>::map(const allocator_type& alloc )
		: _tree(alloc)
	{}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	template<typename InputIt>
	map<_K, _V, _Compare, _Allocator>::map( InputIt first, InputIt last,
     	 	 	 const key_compare& comp,
     	 	 	 const allocator_type& alloc )
		: _tree(first, last, comp, alloc)
	{}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	map<_K, _V, _Compare, _Allocator>::map( const map& other )
		: _tree(other._tree)
	{}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	map<_K, _V, _Compare, _Allocator>::~map()
	{
		_tree.clear();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	map<_K, _V, _Compare, _Allocator>& map<_K, _V, _Compare, _Allocator>::operator=(const map& other)
	{
		if (this != &other)
			_tree = other._tree;
		return *this;
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::begin()
	{
		return _tree.begin();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_iterator map<_K, _V, _Compare, _Allocator>::begin() const
	{
		return _tree.begin();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_iterator map<_K, _V, _Compare, _Allocator>::cbegin() const
	{
		return _tree.begin();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::end()
	{
		return _tree.end();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_iterator map<_K, _V, _Compare, _Allocator>::end() const
	{
		return _tree.end();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_iterator map<_K, _V, _Compare, _Allocator>::cend() const
	{
		return _tree.cend();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::reverse_iterator map<_K, _V, _Compare, _Allocator>::rbegin()
	{
		return _tree.rbegin();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_reverse_iterator map<_K, _V, _Compare, _Allocator>::rbegin() const
	{
		return _tree.rbegin();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_reverse_iterator map<_K, _V, _Compare, _Allocator>::crbegin() const
	{
		return _tree.crbegin();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::reverse_iterator map<_K, _V, _Compare, _Allocator>::rend()
	{
		return _tree.rend();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_reverse_iterator map<_K, _V, _Compare, _Allocator>::rend() const
	{
		return _tree.rend();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_reverse_iterator map<_K, _V, _Compare, _Allocator>::crend() const
	{
		return _tree.crend();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	bool map<_K, _V, _Compare, _Allocator>::empty() const
	{
		return _tree.empty();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::size_type map<_K, _V, _Compare, _Allocator>::size() const
	{
		return _tree.size();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::size_type map<_K, _V, _Compare, _Allocator>::max_size() const
	{
		return _tree.max_size();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	void map<_K, _V, _Compare, _Allocator>::clear()
	{
		_tree.clear();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	ft::pair<typename map<_K, _V, _Compare, _Allocator>::iterator, bool> map<_K, _V, _Compare, _Allocator>::insert(const value_type& value)
	{
		return _tree.insert(value);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::insert(iterator pos, const value_type& value)
	{
		return _tree.insert(pos, value);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	template<typename InputIt>
	void map<_K, _V, _Compare, _Allocator>::insert(InputIt first, InputIt last)
	{
		_tree.insert(first, last);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::erase(iterator pos)
	{
		return _tree.erase(pos);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::erase(iterator first, iterator last)
	{
		return _tree.erase(first, last);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::size_type map<_K, _V, _Compare, _Allocator>::erase(const key_type& key)
	{
		return _tree.erase(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::size_type map<_K, _V, _Compare, _Allocator>::count(const key_type& key) const
	{
		return _tree.count(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::find(const key_type& key)
	{
		return _tree.find(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_iterator map<_K, _V, _Compare, _Allocator>::find(const key_type& key) const
	{
		return _tree.find(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	ft::pair<typename map<_K, _V, _Compare, _Allocator>::iterator, typename map<_K, _V, _Compare, _Allocator>::iterator> map<_K, _V, _Compare, _Allocator>::equal_range(const key_type& key)
	{
		return _tree.equal_range(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	ft::pair<typename map<_K, _V, _Compare, _Allocator>::const_iterator, typename map<_K, _V, _Compare, _Allocator>::const_iterator> map<_K, _V, _Compare, _Allocator>::equal_range(const key_type& key) const
	{
		return _tree.equal_range(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::lower_bound(const key_type& key)
	{
		return _tree.lower_bound(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_iterator map<_K, _V, _Compare, _Allocator>::lower_bound(const key_type& key) const
	{
		return _tree.lower_bound(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::iterator map<_K, _V, _Compare, _Allocator>::upper_bound(const key_type& key)
	{
		return _tree.upper_bound(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::const_iterator map<_K, _V, _Compare, _Allocator>::upper_bound(const key_type& key) const
	{
		return _tree.upper_bound(key);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	void map<_K, _V, _Compare, _Allocator>::swap(map& other)
	{
		if (this != &other)
			_tree.swap(other);
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::mapped_type& map<_K, _V, _Compare, _Allocator>::at( const key_type& key )
	{
		iterator it = find(key);
		if (it == end())
			throw std::out_of_range("map: no such key");
		return it->second;
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	const typename map<_K, _V, _Compare, _Allocator>::mapped_type& map<_K, _V, _Compare, _Allocator>::at( const key_type& key ) const
	{
		iterator it = find(key);
		if (it == end())
			throw std::out_of_range("map: no such key");
		return it->second;
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::mapped_type& map<_K, _V, _Compare, _Allocator>::operator[]( const key_type& key )
	{
		iterator it = find(key);
		if (it == end())
		{
			value_type _value = ft::make_pair(key, mapped_type());
			return insert(_value).first->second;
		}
		return it->second;
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::key_compare map<_K, _V, _Compare, _Allocator>::key_comp() const
	{
		return _tree.key_comp();
	}

	template< typename _K,
		typename _V,
		typename _Compare,
		typename _Allocator >
	typename map<_K, _V, _Compare, _Allocator>::value_compare map<_K, _V, _Compare, _Allocator>::value_comp() const
	{
		return _tree.value_comp();
	}

	template< typename _K,
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	bool operator==( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs )
    {
		return equal(lhs.begin(), lhs.end(), rhs.begin());
    }

	template< typename _K, 
			typename _V,
			typename _Compare, 
			typename _Allocator >
	bool operator!=( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs )
    {
    	return !(lhs == rhs);
    }

	template< typename _K, 
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	bool operator>( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs )
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), greater<typename map<_K, _V, _Compare, _Allocator>::value_type>());
	}

	template< typename _K, 
			typename _V, 
			typename _Compare,
			typename _Allocator >
	bool operator<( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs )
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< typename _K, 
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	bool operator>=( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs )
	{
		return (lhs > rhs || lhs == rhs);
	}
	template< typename _K, 
			typename _V,
			typename _Compare, 
			typename _Allocator >
	bool operator<=( const map<_K, _V, _Compare, _Allocator>& lhs,
                 	 const map<_K, _V, _Compare, _Allocator>& rhs )
	{
		return (lhs < rhs || lhs == rhs);
	}

	template< typename _K, 
			typename _V, 
			typename _Compare, 
			typename _Allocator >
	void swap( map<_K, _V, _Compare, _Allocator>& lhs, 
           		map<_K, _V, _Compare, _Allocator>& rhs )
    {
    	lhs.swap(rhs);
    }
}
