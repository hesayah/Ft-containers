/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_random_acces_iterator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:23:04 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/08 07:40:40 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * https://cplusplus.com/reference/iterator/RandomAccessIterator/
**/

#ifndef __LEGACY_RANDOM_ACCESS_ITERATOR_HPP__
# define __LEGACY_RANDOM_ACCESS_ITERATOR_HPP__


# include "iterator_traits.hpp"

namespace ft {

	template <class T>
	struct						vector_iterator : public iterator<random_access_iterator_tag, T>
	{
    	
    	typedef	typename		iterator<random_access_iterator_tag, T>::difference_type				difference_type;
		typedef	typename		iterator<random_access_iterator_tag, T>::value_type						value_type;
    	typedef	typename		iterator<random_access_iterator_tag, T>::pointer						pointer;
   		typedef	typename		iterator<random_access_iterator_tag, T>::reference						reference;
    	typedef	typename		iterator<random_access_iterator_tag, T>::iterator_category				iterator_category;
	
   
    	protected:
      							pointer 																_ptr;
		public :
    							vector_iterator() {this->_ptr = NULL;}
								vector_iterator(pointer ptr) : _ptr(ptr) {}
    							vector_iterator(const vector_iterator & other) : _ptr(other._ptr) {}
								~vector_iterator() {}

			operator			vector_iterator<const value_type>() const 
								{

									return (vector_iterator<const value_type>(this->_ptr));
								}
			vector_iterator &	operator=(const vector_iterator & other) 
								{

									if (this == &other)
										return (*this);
									this->_ptr = other._ptr;
									return (*this);
								}
			vector_iterator	& 	operator++(void)
								{
									++(this->_ptr);
									return (*this);
								}
			vector_iterator 	operator++(int)
								{
									vector_iterator tmp(*this); 
									++(this->_ptr);
									return (tmp);
								}										
			vector_iterator	& 	operator--(void) 
								{
									--(this->ptr);
									return (*this);
								}
			vector_iterator 	operator--(int) 
								{
									vector_iterator tmp(*this);
									--(this->_ptr);
									return (tmp);
								}
			vector_iterator	& 	operator+=(difference_type diff) 
								{
									this->_ptr += diff;
									return (*this);
								}
			vector_iterator	& 	operator-=(difference_type diff)
								{
									this->_ptr -= diff;
									return (*this);
								}
			reference 			operator*() const 
								{
									return (*(this->_ptr));
								}
			pointer 			operator->() const 
								{
									return (this->_ptr);
								}
			reference			operator[](difference_type diff) const 
								{
									
									return (*(this->_ptr + diff));
								}			
			vector_iterator 	operator+(difference_type diff) const 
								{
									return (vector_iterator(this->_ptr + diff));
								}
			vector_iterator 	operator-(difference_type diff) const 
								{
									return (vector_iterator(this->_ptr - diff));
								}
			difference_type		operator+(const vector_iterator & other) 
								{
									return (this->_ptr + other._ptr);
								}
			difference_type 	operator-(const vector_iterator & other) const 
								{
									return (this->_ptr - other._ptr);
								}
	friend		bool				operator==(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._ptr == other._ptr);
								}
	friend		bool				operator!=(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (!(lhs._ptr == other._ptr));
								}
	/*friend		bool 				operator>(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._ptr > other._ptr);
								}
	friend		bool 				operator<(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._ptr < other._ptr);
								}
	friend		bool 				operator>=(const vector_iterator & lhs, const vector_iterator & other) 
								{
									return (lhs._ptr >= other._ptr);
								}
	friend		bool 				operator<=(const vector_iterator & lhs, const vector_iterator & other) 
								{
									return (lhs._ptr <= other._ptr);
								}*/
	};
}

#endif