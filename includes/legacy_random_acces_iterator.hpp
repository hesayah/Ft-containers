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

/**
 * https://cplusplus.com/reference/iterator/RandomAccessIterator/
**/

#ifndef __LEGACY_RANDOM_ACCESS_ITERATOR_HPP__
# define __LEGACY_RANDOM_ACCESS_ITERATOR_HPP__


# include "iterator_traits.hpp"

namespace ft {

	template <typename  Category, typename T, typename  Distance = std::ptrdiff_t, typename  Pointer = T*, typename Reference = T&>
  	struct					iterator
	{
    	
    	typedef				Distance						difference_type;
		typedef				T								value_type;
    	typedef				Pointer							pointer;
   		typedef				Reference						reference;
    	typedef				Category						iterator_category;
	
   
    	protected:
      						iterator 							_it;

      	typedef 		iterator_traits<iterator>				__traits_type;

   		public:
      				typedef 			iterator						iterator_type;
      				typedef typename	__traits_type::difference_type	difference_type;
      				typedef typename	__traits_type::pointer			pointer;
      				typedef typename	__traits_type::reference		reference;

    		vector_iterator() :  {this->_it = NULL;}
    		vector_iterator(const vector_iterator & other) : _it(other._it) {}
			~vector_iterator();

			vector_iterator	& 	operator=(const vector_iterator & other) 
								{
									this->_it = other._it; 
									return (*this);
								}
			bool				operator==(const vector_iterator & other)
								{
									return (this->_it == other._it)
								}
			bool				operator!=(const vector_iterator & other)
								{
									return (this->_it != other._it)
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
			
			vector_iterator& 	operator+=(difference_type other) 
										{
											this->_it += other;
											return (*this);
										}
			vector_iterator& 	operator-=(difference_type other)
										{
											this->_it -= other;
											return (*this);
										}
			iterator_type& 		operator*() const 
										{
											return (this->_it);
										}
			iterator_type* 		operator->() const 
										{
											return this->_it;
										}
			iterator_type& 		operator[](difference_type other) const 
										{
											return this->_it[other];
										}
			difference_type		operator+(const vector_iterator& other) 
										{
											return vector_iterator(this->_it+other._it);
										}
			difference_type 		operator-(const vector_iterator& other) const 
										{
											return this->_it-other.it;
										}
			vector_iterator 		operator+(difference_type other) const 
										{
											return vector_iterator(this->_it+other);
										}
			vector_iterator 		operator-(difference_type other) const 
										{
											return vector_iterator(this->_it-other);
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