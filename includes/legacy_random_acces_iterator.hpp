/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_random_acces_itator.hpp                   :+:      :+:    :+:   */
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

#ifndef __LEGACY_RANDOM_ACCESS_itATOR_HPP__
# define __LEGACY_RANDOM_ACCESS_itATOR_HPP__

# include "iterator_traits.hpp"

namespace ft {

								template <typename T>
	class						vector_iterator
	{
		public :

			typedef					T													iterator;
    		typedef	typename		iterator_traits<T>::difference_type					difference_type;
			typedef	typename		iterator_traits<T>::value_type						value_type;
    		typedef	typename		iterator_traits<T>::pointer							pointer;
   			typedef	typename		iterator_traits<T>::reference						reference;
    		typedef	typename		iterator_traits<T>::iterator_category				iterator_category;
	
    	protected:
      								iterator											_it;
		public :
									vector_iterator() :_it(iterator()) {}
									vector_iterator(const pointer & ptr) : _it(ptr) {}
									vector_iterator(const vector_iterator<iterator> & other) : _it(other._it) {}
									~vector_iterator() {}
			/*operator				vector_iterator() const
									{
										return (vector_iterator(*this));
									}*/
  			operator const vector_iterator<iterator_traits<T> >() const {return vector_iterator<iterator_traits<T> >(_it);}

			vector_iterator<iterator> &	operator=(const vector_iterator & other) 
									{
										this->_it = other._it;
										return (*this);
									}
			pointer					base() const 
									{
										return (this->_it);
									}			
			reference 				operator*() const 
									{
										return (*this->_it);
									}
			pointer 				operator->() 
									{
										return (this->_it);
									}
			reference				operator[](difference_type diff) const 
									{	
										return (*(this->_it + diff));
									}
			vector_iterator	& 		operator++(void)
									{
										++this->_it;
										return (*this);
									}
			vector_iterator 		operator++(int)
									{
										this->_it++;
										return (*this);
									}										
			vector_iterator	& 		operator--(void) 
									{
										--this->_it;
										return (*this);
									}
			vector_iterator 		operator--(int) 
									{
										this->_it--;
										return (*this);
									}
			vector_iterator	& 		operator+=(difference_type diff) 
									{
										this->_it += diff;
										return (*this);
									}
			vector_iterator	& 		operator-=(difference_type diff)
									{
										this->_it -= diff;
										return (*this);
									}
			difference_type			operator+(const vector_iterator& other)
									{
										return (this->_it + other._it);
									}
			difference_type 		operator-(const vector_iterator & other)
									{
										return (this->_it - other._it);
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
						template<class X, class Y>
	bool				operator==(const vector_iterator<X> & lhs, const vector_iterator<Y> & other)
						{
							return (lhs.base() == other.base());
						}
						template<class X, class Y>
	bool				operator!=(const vector_iterator<X> & lhs, const vector_iterator<Y> & other)
						{
							return (!(lhs.base() == other.base()));
						}
						template<class X, class Y>
	bool 				operator>(const vector_iterator<X> & lhs, const vector_iterator<Y> & other)
						{
							return (lhs.base() > other.base());
						}
						template<class X, class Y>
	bool 				operator<(const vector_iterator<X> & lhs, const vector_iterator<Y> & other)
						{
							return (lhs.base() < other.base());
						}
						template<class X, class Y>
	bool 				operator>=(const vector_iterator<X> & lhs, const vector_iterator<Y> & other)
						{
							return (lhs.base() >= other.base());
						}
						template<class X, class Y>
	bool 				operator<=(const vector_iterator<X> & lhs, const vector_iterator<Y> & other)
						{
							return (lhs.base() <= other.base());
						}
}

#endif