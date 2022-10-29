/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidir_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:26:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/29 23:38:41 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BIDIR_ITERATOR__
# define __BIDIR_ITERATOR__

# include "iterator_traits.hpp"

namespace ft {
									template <typename T>
	class							bidir_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		public :

    		typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::difference_type						difference_type;
			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::value_type							value_type;
    		typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::pointer								pointer;
   			typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::reference							reference;
    		typedef	typename		std::iterator<std::bidirectional_iterator_tag, T>::iterator_category					iterator_category;
	
	
   
    	protected:
      							pointer											_ptr;
		public :
								bidir_iterator() :_ptr(T()) {}
								bidir_iterator(const pointer & iter) : _ptr(iter) {}
    							bidir_iterator(const bidir_iterator & other) : _ptr(other._ptr) {}
								~bidir_iterator() {}

			bidir_iterator &	operator=(const bidir_iterator & other) 
								{
									this->_ptr = other._ptr;
									return (*this);
								}
			pointer				base() const 
								{

									return (this->_ptr);
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
			bidir_iterator	& 	operator++(void)
								{
									++this->_ptr;
									return (*this);
								}
			bidir_iterator		operator++(int)
								{
									this->_ptr++;
									return (*this);
								}										
			bidir_iterator	& 	operator--(void) 
								{
									--this->_ptr;
									return (*this);
								}
			bidir_iterator		operator--(int) 
								{
									this->_ptr--;
									return (*this);
								}
	};
						template<class X, class Y>
	bool				operator==(const bidir_iterator<X> & lhs, const bidir_iterator<Y> & other)
						{
							return (lhs.base() == other.base());
						}
						template<class X, class Y>
	bool				operator!=(const bidir_iterator<X> & lhs, const bidir_iterator<Y> & other)
						{
							return (!(lhs.base() == other.base()));
						}
						template<class X, class Y>
	bool 				operator>(const bidir_iterator<X> & lhs, const bidir_iterator<Y> & other)
						{
							return (lhs.base() > other.base());
						}
						template<class X, class Y>
	bool 				operator<(const bidir_iterator<X> & lhs, const bidir_iterator<Y> & other)
						{
							return (lhs.base() < other.base());
						}
						template<class X, class Y>
	bool 				operator>=(const bidir_iterator<X> & lhs, const bidir_iterator<Y> & other)
						{
							return (lhs.base() >= other.base());
						}
						template<class X, class Y>
	bool 				operator<=(const bidir_iterator<X> & lhs, const bidir_iterator<Y> & other)
						{
							return (lhs.base() <= other.base());
						}
}

#endif