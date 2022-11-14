#pragma once

#include "containers/containers.hpp"
#include "containers/vector.hpp"

namespace ft
{
    
    template<typename T, typename _Container>
    class queue
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

        	explicit	queue (const container_type& cont = container_type());
						queue( const queue& other );
			queue&		operator=(const queue& other);

			/* ========================= */
			/*       element access      */
			/* ========================= */

        	reference			front();
        	const_reference		front() const;
        	reference			back();
        	const_reference		back() const;

			/* ========================= */
			/*          capacity         */
			/* ========================= */

        	bool			empty() const;
        	size_type		size() const;

			/* ========================= */
			/*         modifiers         */
			/* ========================= */

        	void		push (const_reference val);
        	void		pop();
        	void		swap (queue& x);
       	   
			/* ========================= */
			/*    non-member functions   */
			/* ========================= */

			template<typename _V, typename _Cont>
        	friend bool operator== (const queue<_V, _Cont>& lhs, 
        							const queue<_V, _Cont>& rhs);

			template<typename _V, typename _Cont>
        	friend bool operator!= (const queue<_V, _Cont>& lhs, 
        							const queue<_V, _Cont>& rhs);

			template<typename _V, typename _Cont>
        	friend bool operator> (const queue<_V, _Cont>& lhs, 
        							const queue<_V, _Cont>& rhs);

			template<typename _V, typename _Cont>
        	friend bool operator>= (const queue<_V, _Cont>& lhs, 
        							const queue<_V, _Cont>& rhs);

			template<typename _V, typename _Cont>
        	friend bool operator< (const queue<_V, _Cont>& lhs, 
        							const queue<_V, _Cont>& rhs);

			template<typename _V, typename _Cont>
        	friend bool operator<= (const queue<_V, _Cont>& lhs, 
        							const queue<_V, _Cont>& rhs);
    	protected:

			/* =================== */
			/*    member objects   */
			/* =================== */

        	_Container c;
    }; 

	/* ========================= */
	/*    non-member functions   */
	/* ========================= */

	template<typename _V, typename _Cont>
    bool operator== (const queue<_V, _Cont>& lhs, 
        			const queue<_V, _Cont>& rhs);

	template<typename _V, typename _Cont>
    bool operator!= (const queue<_V, _Cont>& lhs, 
        			const queue<_V, _Cont>& rhs);

	template<typename _V, typename _Cont>
    bool operator> (const queue<_V, _Cont>& lhs, 
        			const queue<_V, _Cont>& rhs);

	template<typename _V, typename _Cont>
    bool operator>= (const queue<_V, _Cont>& lhs, 
        			const queue<_V, _Cont>& rhs);

	template<typename _V, typename _Cont>
    bool operator< (const queue<_V, _Cont>& lhs, 
        			const queue<_V, _Cont>& rhs);

	template<typename _V, typename _Cont>
    bool operator<= (const queue<_V, _Cont>& lhs, 
        			const queue<_V, _Cont>& rhs);
}

#include "queue_impl.hpp"
