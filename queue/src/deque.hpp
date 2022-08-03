#include <memory>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class deque
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ... iterator;
        typedef ... const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef std::iterator_traits<iterator>::difference_type difference_type;
        typedef std::size_t size_type;
        deque(/* args */);
        ~deque();
    }; // class deque
    
} // namespace ft
