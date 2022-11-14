#pragma once

#include "bits/iterator_traits.hpp"

namespace ft
{

	template<typename T,
			typename _DT>
	struct deque_block_size;
	

	template<typename T,
			typename _Ref,
			typename _Ptr,
			typename _DT = iterator<random_access_iterator_tag, T>::difference_type,
			_DT _BS = deque_block_size<T, _DT>::value>
	class deque_terator;
}
