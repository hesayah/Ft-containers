/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_random_acces_vector_iterator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:23:04 by hesayah           #+#    #+#             */
/*   Updated: 2022/09/29 02:26:52 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEGACY_RANDOM_ACCESS_ITERATOR_HPP__
# define __LEGACY_RANDOM_ACCESS_ITERATOR_HPP__

# include "iterator_traits.hpp"

namespace ft {

template<typename iterartor_type>
class vector_iterator 
{
    protected :
    										iterartor_type* 									_ptr;
    public :		   
   			typedef typename				iterator_traits<iterartor_type>::difference_type  	difference_type;
			typedef typename				iterator_traits<iterartor_type>::value_type 		value_type;
    		typedef typename				iterator_traits<iterartor_type>::pointer  			pointer;
   			typedef typename				iterator_traits<iterartor_type>::reference			reference;
   			typedef typename				iterator_traits<iterartor_type>::iterator_category 	iterator_category;

    		vector_iterator() : _ptr(nullptr) {}
    		vector_iterator(iterartor_type* rhs) : _ptr(rhs) {}
    		vector_iterator(const vector_iterator &rhs) : _ptr(rhs._ptr) {}
			~vector_iterator();

    		inline vector_iterator& 		operator=(iterartor_type* rhs) 
											{
												this->_ptr = rhs; return *this;
											}
	    	inline vector_iterator& 		operator=(const vector_iterator & rhs) 
											{
												this->_ptr = rhs._ptr; return *this;
											} 
    		inline vector_iterator& 		operator+=(difference_type rhs) 
											{
												this->_ptr += rhs;
												return (*this);
											}
			inline vector_iterator& 		operator-=(difference_type rhs)
											{
												this->_ptr -= rhs;
												return *this;
											}
			inline iterartor_type& 			operator*() const 
											{
												return *this->_ptr;
											}
			inline iterartor_type* 			operator->() const 
											{
												return this->_ptr;
											}
			inline iterartor_type& 			operator[](difference_type rhs) const 
											{
												return this->_ptr[rhs];
											}
			inline vector_iterator& 		operator++() 
											{
												++this->_ptr;
												return *this;
											}
			inline vector_iterator& 		operator--() 
											{
												--this->_ptr;
												return *this;
											}
			inline vector_iterator 			operator++(int) const 
											{
												vector_iterator tmp(*this); 
												++this->_ptr;
												return tmp;
											}
			inline vector_iterator 			operator--(int) const 
											{
												vector_iterator tmp(*this);
												--this->_ptr;
												return tmp;
											}
			inline difference_type			operator+(const vector_iterator& rhs) 
											{
												return vector_iterator(this->_ptr+rhs._ptr);
											}
			inline difference_type 			operator-(const vector_iterator& rhs) const 
											{
												return this->_ptr-rhs.ptr;
											}
			inline vector_iterator 			operator+(difference_type rhs) const 
											{
												return vector_iterator(this->_ptr+rhs);
											}
			inline vector_iterator 			operator-(difference_type rhs) const 
											{
												return vector_iterator(this->_ptr-rhs);
											}
			inline bool 					operator==(const vector_iterator& rhs) const 
											{
												return this->_ptr == rhs._ptr;
											}
			inline bool 					operator!=(const vector_iterator& rhs) const 
											{
												return this->_ptr != rhs._ptr;
											}
			inline bool 					operator>(const vector_iterator& rhs) const 
											{
												return this->_ptr > rhs._ptr;
											}
			inline bool 					operator<(const vector_iterator& rhs) const 
											{
												return this->_ptr < rhs._ptr;
											}
			inline bool 					operator>=(const vector_iterator& rhs) const 
											{
												return this->_ptr >= rhs._ptr;
											}
			inline bool 					operator<=(const vector_iterator& rhs) const 
											{
												return this->_ptr <= rhs._ptr;
											}
	};	
}

#endif