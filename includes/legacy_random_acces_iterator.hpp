/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_random_acces_ptrator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:23:04 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/12 09:07:57 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * https://cplusplus.com/reference/iterator/RandomAccessIterator/
**/

#ifndef __LEGACY_RANDOM_ACCESS_ptrATOR_HPP__
# define __LEGACY_RANDOM_ACCESS_ptrATOR_HPP__


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
      							pointer											_ptr;
		public :
    							vector_iterator() : _ptr(iterator()) {};
								vector_iterator(const pointer & iter) : _ptr(iter) {}
    							vector_iterator(const vector_iterator & other) : _ptr(other._ptr) {}
								~vector_iterator() {}

			vector_iterator &	operator=(const vector_iterator & other) 
								{
									this->_ptr = other._ptr;
									return (*this);
								}
			iterator			base() const 
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
			vector_iterator	& 	operator++(void)
								{
									++this->_ptr;
									return (*this);
								}
			vector_iterator 	operator++(int)
								{
									this->_ptr++;
									return (*this);
								}										
			vector_iterator	& 	operator--(void) 
								{
									--this->_ptr;
									return (*this);
								}
			vector_iterator 	operator--(int) 
								{
									this->_ptr--;
									return (*this);
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
			difference_type		operator+(const vector_iterator& other)
								{
									return (this->_ptr + other._ptr);
								}
			difference_type 	operator-(const vector_iterator & other)
								{
									return (this->_ptr - other._ptr);
								}

	};
						template<class T>
	vector_iterator<T> 	operator+(const vector_iterator<T> & lhs, typename iterator_traits<T>::difference_type diff)
						{
							return (lhs.base() + diff);
						}
						template<class T>
	vector_iterator<T> 	operator-(const vector_iterator<T> & lhs, typename iterator_traits<T>::difference_type diff)
						{
							return (lhs.base() - diff);
						}
						template<class T>
	bool				operator==(const vector_iterator<T> & lhs, const vector_iterator<T> & other)
						{
							return (lhs.base() == other.base());
						}
						template<class T>
	bool				operator!=(const vector_iterator<T> & lhs, const vector_iterator<T> & other)
						{
							return (!(lhs.base() == other.base()));
						}
						template<class T>
	bool 				operator>(const vector_iterator<T> & lhs, const vector_iterator<T> & other)
						{
							return (lhs.base() > other.base());
						}
						template<class T>
	bool 				operator<(const vector_iterator<T> & lhs, const vector_iterator<T> & other)
						{
							return (lhs.base() < other.base());
						}
						template<class T>
	bool 				operator>=(const vector_iterator<T> & lhs, const vector_iterator<T> & other)
						{
							return (lhs.base() >= other.base());
						}
						template<class T>
	bool 				operator<=(const vector_iterator<T> & lhs, const vector_iterator<T> & other)
						{
							return (lhs.base() <= other.base());
						}
}

#endif