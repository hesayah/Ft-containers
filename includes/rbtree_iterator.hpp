/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:26:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/30 02:13:25 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BIDIR_ITERATOR__
# define __BIDIR_ITERATOR__

# include "iterator_traits.hpp"

namespace ft {
									template <typename T>
	class							rbtree_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		public :
			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::difference_type						difference_type;
			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::value_type							value_type;
    		typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::pointer								pointer;
   			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::reference							reference;
    		typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::iterator_category					iterator_category;
	
	
   
    	protected:
      							T*												_ptr;
		public :
								rbtree_iterator() :_ptr(T()) {}
								rbtree_iterator(const value_type & iter) : _ptr(iter) {}
    							rbtree_iterator(const rbtree_iterator & other) : _ptr(other._ptr) {}
								~rbtree_iterator() {}

			rbtree_iterator &	operator=(const rbtree_iterator & other) 
								{
									this->_ptr = other._ptr;
									return (*this);
								}
			pointer				base() const 
								{
									return (_ptr);
								}			
			reference 			operator*() const 
								{
									return (*this->_ptr);
								}
			pointer 			operator->() 
								{

									return (this->_ptr);
								}
			reference			operator[](difference_type diff) const 
								{
									
									return (*(this->_ptr + diff));
								}
			rbtree_iterator	& 	operator++(void)
								{
									this->_ptr.successor();
									return (*this);
								}
			rbtree_iterator		operator++(int)
								{
									this->_ptr.successor();
									return (*this);
								}										
			rbtree_iterator	& 	operator--(void) 
								{
									this->_ptr.predecessor();
									return (*this);
								}
			rbtree_iterator		operator--(int) 
								{
									this->_ptr.predecessor();
									return (*this);
								}
			
	};
						template<class X, class Y>
	bool				operator==(const rbtree_iterator<X> & lhs, const rbtree_iterator<Y> & other)
						{
							return (lhs.base() == other.base());
						}
						template<class X, class Y>
	bool				operator!=(const rbtree_iterator<X> & lhs, const rbtree_iterator<Y> & other)
						{
							return (!(lhs.base() == other.base()));
						}
						template<class X, class Y>
	bool 				operator>(const rbtree_iterator<X> & lhs, const rbtree_iterator<Y> & other)
						{
							return (lhs.base() > other.base());
						}
						template<class X, class Y>
	bool 				operator<(const rbtree_iterator<X> & lhs, const rbtree_iterator<Y> & other)
						{
							return (lhs.base() < other.base());
						}
						template<class X, class Y>
	bool 				operator>=(const rbtree_iterator<X> & lhs, const rbtree_iterator<Y> & other)
						{
							return (lhs.base() >= other.base());
						}
						template<class X, class Y>
	bool 				operator<=(const rbtree_iterator<X> & lhs, const rbtree_iterator<Y> & other)
						{
							return (lhs.base() <= other.base());
						}
}

#endif