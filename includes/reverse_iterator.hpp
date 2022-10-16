/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:55:48 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/16 19:16:01 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__

/**
*** https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/iterator/reverse_iterator.html
*** https://en.cppreference.com/w/cpp/iterator/reverse_iterator
**/

# include "iterator_traits.hpp"

namespace ft {

	template <typename T>
	class							reverse_iterator
	{
		public :

			typedef					T																	iterator_type;
    		typedef	typename		iterator_traits<iterator_type>::difference_type						difference_type;
			typedef	typename		iterator_traits<iterator_type>::value_type							value_type;
    		typedef	typename		iterator_traits<iterator_type>::pointer								pointer;
   			typedef	typename		iterator_traits<iterator_type>::reference							reference;
    		typedef	typename		iterator_traits<iterator_type>::iterator_category					iterator_category;
	
    	protected:
      								iterator_type														_current;
		public :
									reverse_iterator() :_current() {}
									explicit reverse_iterator(iterator_type x) : _current(x) {}
									template<class U>
									reverse_iterator(const reverse_iterator<U>& other) : _current(other.base()) {}
									~reverse_iterator() {}
									template<class U>
			reverse_iterator	& 	operator=(const reverse_iterator<U>& other)
									{
										_current = other.base();
										return (*this);
									}
			iterator_type 			base() const {return (_current);}
			reference 				operator*() const {iterator_type tmp = _current; --tmp; return (*tmp);}
			pointer 				operator->() const {return (&(operator*()));}
			reference				operator[](difference_type diff) const {return (*(base() - diff - 1));}
			reverse_iterator 		operator++(int) {return (reverse_iterator(_current--));}
			reverse_iterator 		operator--(int) {return (reverse_iterator(_current++));}								
			reverse_iterator	& 	operator--(void) 
									{
										++_current;
										return (*this);
									}
			reverse_iterator	& 	operator++(void)
									{
										--_current;
										return (*this);
									}
			reverse_iterator		operator+(difference_type diff) const {return (reverse_iterator(_current - diff));}
			reverse_iterator 		operator-(difference_type diff) const {return (reverse_iterator(_current + diff));}
			reverse_iterator	&	operator+=(difference_type diff) 
									{
										this->_current =  _current - diff;
										return (*this);
									}
			reverse_iterator	& 	operator-=(difference_type diff)
									{
										this->_current = _current + diff;
										return (*this);
									}
	};
										template<typename Iterator>
			reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it) {return (reverse_iterator<Iterator>(it.base() - n));}
										template<class Iterator1, class Iterator2>
										typename reverse_iterator<Iterator1>::difference_type
										operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {return (rhs.base() - lhs.base());}
										template<class Iterator1, class Iterator2>
			bool 						operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {return (lhs.base() == rhs.base());}
										template< class Iterator1, class Iterator2 >
			bool 						operator!=(const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator2>& rhs) {return (lhs.base() != rhs.base());}
										template< class Iterator1, class Iterator2 >
			bool 						operator<(const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator2>& rhs) {return (lhs.base() > rhs.base());}
										template< class Iterator1, class Iterator2 >
			bool						operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {return (lhs.base() >= rhs.base());}
										template< class Iterator1, class Iterator2 >
			bool						operator>(const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator2>& rhs) {return (lhs.base() < rhs.base());}
										template< class Iterator1, class Iterator2 >
			bool						operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {return (lhs.base() <= rhs.base());}
}

#endif