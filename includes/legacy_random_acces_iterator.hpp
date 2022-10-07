/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_random_acces_iterator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:23:04 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/07 04:18:04 by hesayah          ###   ########.fr       */
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
      							pointer 																_it;
		public :
    							vector_iterator() : _it(NULL) {}
								vector_iterator(pointer it) : _it(it) {}
    							vector_iterator(const vector_iterator & other) : _it(other._it) {}
								~vector_iterator() {}

			vector_iterator	& 	operator=(const vector_iterator & other) 
								{
									this->_it = other._it; 
									return (*this);
								}
			bool				operator==(const vector_iterator & other)
								{
									return (this->_it == other._it);
								}
			bool				operator!=(const vector_iterator & other)
								{
									return (this->_it != other._it);
								}
			vector_iterator	& 	operator++() 
								{
									++this->_it;
									return (*this);
								}
			vector_iterator 	operator++(int) const 
								{
									vector_iterator tmp(*this); 
									++this->_it;
									return (tmp);
								}										
			vector_iterator	& 	operator--() 
								{
									--this->_it;
									return (*this);
								}
			vector_iterator 	operator--(int) const 
								{
									vector_iterator tmp(*this);
									--this->_it;
									return (tmp);
								}
			vector_iterator	& 	operator+=(difference_type diff) 
								{
									this->_it += diff;
									return (*this);
								}
			vector_iterator	& 	operator-=(difference_type diff)
								{
									this->_it -= diff;
									return (*this);
								}
			value_type & 		operator*() const 
								{
									return (*(this->_it));
								}
			value_type * 		operator->() const 
								{
									return (this->_it);
								}
			value_type & 		operator[](difference_type other) const 
								{
									
									return (*(*this + other));
								}
			difference_type		operator+(const vector_iterator& other) 
								{
									return vector_iterator(this->_it + other);
								}
			difference_type 	operator-(const vector_iterator& other) const 
								{
									return (this->_it - other);
								}
			vector_iterator 	operator+(difference_type diff) const 
								{
									return vector_iterator(this->_it + diff);
								}
			vector_iterator 	operator-(difference_type diff) const 
								{
									return vector_iterator(this->_it - diff);
								}
			bool 				operator>(const vector_iterator& other) const 
								{
									return this->_it > other._it;
								}
			bool 				operator<(const vector_iterator& other) const 
								{
									return this->_it < other._it;
								}
			bool 				operator>=(const vector_iterator& other) const 
								{
									return this->_it >= other._it;
								}
			bool 				operator<=(const vector_iterator& other) const 
								{
									return this->_it <= other._it;
								}
	};
}

#endif