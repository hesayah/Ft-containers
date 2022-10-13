/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:55:48 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/13 11:10:50 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__


# include "iterator_traits.hpp"

namespace ft {

	template <typename T>
	class						reverse_iterator
	{
		public :

    	typedef	typename		iterator_traits<T>::difference_type			difference_type;
		typedef	typename		iterator_traits<T>::value_type				value_type;
    	typedef	typename		iterator_traits<T>::pointer					pointer;
   		typedef	typename		iterator_traits<T>::reference				reference;
    	typedef	typename		iterator_traits<T>::iterator_category		iterator_category;
	
   
    	protected:
      							pointer											_ptr;
		public :
								reverse_iterator(const pointer & iter) : _ptr(iter) {}
    							reverse_iterator(const reverse_iterator & other) : _ptr(other._ptr) {}
								~reverse_iterator() {}

			reverse_iterator &	operator=(const reverse_iterator & other) 
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
			/*operator			reverse_iterator<const pointer>() const
								{
									return reverse_iterator<const pointer>(reverse_iterator(*this));
								}*/

			reference			operator[](difference_type diff) const 
								{
									
									return (*(this->_ptr + diff));
								}
			reverse_iterator	& 	operator--(void)
								{
									++this->_ptr;
									return (*this);
								}
			reverse_iterator 	operator--(int)
								{
									this->_ptr++;
									return (*this);
								}										
			reverse_iterator	& 	operator++(void) 
								{
									--this->_ptr;
									return (*this);
								}
			reverse_iterator 	operator++(int)
								{
									this->_ptr--;
									return (*this);
								}
			reverse_iterator	& 	operator+=(difference_type diff) 
								{
									this->_ptr -= diff;
									return (*this);
								}
			reverse_iterator	& 	operator-=(difference_type diff)
								{
									this->_ptr += diff;
									return (*this);
								}
			difference_type		operator+(const reverse_iterator& other)
								{
									return (this->_ptr - other._ptr);
								}
			difference_type 	operator-(const reverse_iterator & other)
								{
									return (this->_ptr + other._ptr);
								}
	};
						template<class T>
	reverse_iterator<T> 	operator+(const reverse_iterator<T> & lhs, typename iterator_traits<T>::difference_type diff)
						{
							return (lhs.base() - diff);
						}
						template<class T>
	reverse_iterator<T> 	operator-(const reverse_iterator<T> & lhs, typename iterator_traits<T>::difference_type diff)
						{
							return (lhs.base() + diff);
						}
						template<class X, class Y>
	bool				operator==(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (lhs.base() == other.base());
						}
						template<class X, class Y>
	bool				operator!=(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (!(lhs.base() == other.base()));
						}
						template<class X, class Y>
	bool 				operator>(const reverse_iterator<X> & lhs, const reverse_iterator<Y> & other)
						{
							return (lhs.base() > other.base());
						}
						template<class X, class Y>
	bool 				operator<(const reverse_iterator<X> & lhs, const reverse_iterator<Y> & other)
						{
							return (lhs.base() < other.base());
						}
						template<class X, class Y>
	bool 				operator>=(const reverse_iterator<X> & lhs, const reverse_iterator<Y> & other)
						{
							return (lhs.base() >= other.base());
						}
						template<class X, class Y>
	bool 				operator<=(const reverse_iterator<X> & lhs, const reverse_iterator<Y> & other)
						{
							return (lhs.base() <= other.base());
						}
}

#endif