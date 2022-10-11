/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_random_acces_iterator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:23:04 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/10 07:11:44 by hesayah          ###   ########.fr       */
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
	class						vector_iterator
	{
		public :

    	typedef					T													iterator;
    	typedef	typename		iterator_traits<iterator>::difference_type			difference_type;
		typedef	typename		iterator_traits<iterator>::value_type				value_type;
    	typedef	typename		iterator_traits<iterator>::pointer					pointer;
   		typedef	typename		iterator_traits<iterator>::reference				reference;
    	typedef	typename		iterator_traits<iterator>::iterator_category		iterator_category;
	
   
    	protected:
      							pointer											_iter;
		public :
    							vector_iterator() : _iter(iterator()) {};
								vector_iterator(const pointer & iter) : _iter(iter) {}
    							vector_iterator(const vector_iterator & other) : _iter(other._iter) {}
								~vector_iterator() {}

			vector_iterator &	operator=(const vector_iterator & other) 
								{
									this->_iter = other._iter;
									return (*this);
								}
	const	vector_iterator		base() const 
								{

									return (this->_iter);
								}			
			reference 			operator*() const 
								{
									return (*this->_iter);
								}
			pointer 			operator->() const 
								{
									return (this->_iter);
								}
			reference			operator[](difference_type diff) const 
								{
									
									return (*(this->_iter + diff));
								}
			vector_iterator	& 	operator++(void)
								{
									++this->_iter;
									return (*this);
								}
			vector_iterator 	operator++(int)
								{
									this->_iter++;
									return (*this);
								}										
			vector_iterator	& 	operator--(void) 
								{
									--this->_iter;
									return (*this);
								}
			vector_iterator 	operator--(int) 
								{
									this->_iter--;
									return (*this);
								}
			vector_iterator	& 	operator+=(difference_type diff) 
								{
									this->_iter += diff;
									return (*this);
								}
			vector_iterator	& 	operator-=(difference_type diff)
								{
									this->_iter -= diff;
									return (*this);
								}		
			vector_iterator 	operator+(difference_type diff) const 
								{
									return (vector_iterator(this->_iter + diff));
								}
			vector_iterator 	operator-(difference_type diff) const 
								{
									return (vector_iterator(this->_iter - diff));
								}
	friend	difference_type		operator+(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._iter + other._iter);
								}
	friend	difference_type 	operator-(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._iter - other._iter);
								}
	friend	bool				operator==(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._iter == other._iter);
								}
	friend	bool				operator!=(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (!(lhs._iter == other._iter));
								}
	friend	bool 				operator>(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._iter > other._iter);
								}
	friend	bool 				operator<(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._iter < other._iter);
								}
	friend	bool 				operator>=(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._iter >= other._iter);
								}
	friend	bool 				operator<=(const vector_iterator & lhs, const vector_iterator & other)
								{
									return (lhs._iter <= other._iter);
								}
	};
}
#endif