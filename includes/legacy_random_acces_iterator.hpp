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

# include <iterator>

namespace ft {

								template <typename T>
	class						vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public :

    		typedef	typename		std::iterator<std::random_access_iterator_tag, T>::difference_type						difference_type;
			typedef	typename		std::iterator<std::random_access_iterator_tag, T>::value_type							value_type;
    		typedef	typename		std::iterator<std::random_access_iterator_tag, T>::pointer								pointer;
   			typedef	typename		std::iterator<std::random_access_iterator_tag, T>::reference							reference;
    		typedef	typename		std::iterator<std::random_access_iterator_tag, T>::iterator_category					iterator_category;
	
    	protected:
      								pointer											_it;
		public :
									vector_iterator() :_it(NULL) {}
									vector_iterator(const pointer & ptr) : _it(ptr) {}
									vector_iterator(const vector_iterator<T> & other) : _it(other._it) {}
									~vector_iterator() {}
  			operator 				vector_iterator<const value_type>() const {return vector_iterator<const value_type>(_it);}
			vector_iterator<T> &	operator=(const vector_iterator & other) 
									{
										this->_it = other._it;
										return (*this);
									}
			reference 				operator*() const {return (*this->_it);}
			pointer 				operator->() const {return (this->_it);}
			reference				operator[](difference_type diff) const {return (*(this->_it + diff));}
			vector_iterator 		operator++(int) {return (this->_it++);}
			vector_iterator 		operator--(int) {return (this->_it--);}								
			vector_iterator	& 		operator--(void) 
									{
										--this->_it;
										return (*this);
									}
			vector_iterator	& 		operator++(void)
									{
										++this->_it;
										return (*this);
									}
			vector_iterator			operator+(difference_type diff) const {return (_it + diff);}
			vector_iterator 		operator-(difference_type diff) const {return (_it - diff);}
			vector_iterator	& 		operator+=(difference_type diff) 
									{
										this->_it =  _it + diff;
										return (*this);
									}
			vector_iterator	& 		operator-=(difference_type diff)
									{
										this->_it = _it - diff;
										return (*this);
									}

			friend	vector_iterator<T>	operator+(difference_type diff, vector_iterator<T> x) {return (x += diff);}
			friend	vector_iterator<T>	operator-(difference_type diff, vector_iterator<T> x) {return (x -= diff);}
			friend	difference_type		operator+(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it + rhs._it);}
			friend	difference_type		operator-(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it - rhs._it);}
			friend	bool				operator==(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it == rhs._it);}
			friend	bool				operator!=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it != rhs._it);}
			friend	bool				operator<(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it < rhs._it);}
			friend	bool				operator<=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it <= rhs._it);}
			friend	bool				operator>(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it > rhs._it);}
			friend	bool				operator>=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {return (lhs._it >= rhs._it);}
	};
}

#endif