/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:55:48 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/14 07:59:10 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__


# include "iterator_traits.hpp"

namespace ft {
			template<typename _Iterator>
    class	reverse_iterator : public iterator<
											typename iterator_traits<_Iterator>::iterator_category,
		      								typename iterator_traits<_Iterator>::value_type,
		      								typename iterator_traits<_Iterator>::difference_type,
		      								typename iterator_traits<_Iterator>::pointer,
                      						typename iterator_traits<_Iterator>::reference>
    {
      				template<typename _Iter>
	friend class	reverse_iterator;

		public :

      			typedef iterator_traits<_Iterator>		__traits_type;

    public:
      			typedef _Iterator								iterator_type;
      			typedef typename __traits_type::pointer			pointer;
      			typedef typename __traits_type::difference_type	difference_type;
      			typedef typename __traits_type::reference		reference;
	
    	protected:
      							iterator_type								_it;
		public :
								reverse_iterator() : _it(iterator_type()) {}
								reverse_iterator(const iterator_type & it) : _it(it) {}
    							reverse_iterator(const reverse_iterator<iterator_type> & other) : _it(other._it) {}
								~reverse_iterator() {}

			reverse_iterator& 	operator=(const reverse_iterator<iterator_type>& other)
								{
									_it = other._it;
								}
			iterator_type		base() const 
								{
									return (this->_it);
								}
			reverse_iterator& 	operator--(void)
								{
									++this->_it;
									return (*this);
								}
			reverse_iterator 	operator--(int)
								{
									this->_it++;
									return (*this);
								}										
			reverse_iterator& 	operator++(void) 
								{
									--this->_it;
									return (*this);
								}
			reverse_iterator 	operator++(int)
								{
									this->_it--;
									return (*this);
								}
			reverse_iterator& 	operator+=(difference_type diff) 
								{
									this->_it -= diff;
									return (*this);
								}
			reverse_iterator& 	operator-=(difference_type diff)
								{
									this->_it += diff;
									return (*this);
								}
			reference 			operator*() const 
								{
									return (this->_it);
								}
			pointer 			operator->() 
								{
									return (this->_it);
								}
			reference			operator[](difference_type diff) const 
								{
									
									return (*(this->_it + diff));
								}
	};
						template<class T>
	reverse_iterator<T> 	operator+(const reverse_iterator<T> & lhs, typename iterator_traits<T>::difference_type diff)
						{
							return (lhs.base() + diff);
						}
						template<class T>
	reverse_iterator<T> 	operator-(const reverse_iterator<T> & lhs, typename iterator_traits<T>::difference_type diff)
						{
							return (lhs.base() - diff);
						}
						template<class X>
	bool				operator==(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (lhs.base() == other.base());
						}
						template<class X>
	bool				operator!=(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (!(lhs.base() == other.base()));
						}
						template<class X>
	bool 				operator>(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (lhs.base() < other.base());
						}
						template<class X>
	bool 				operator<(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (lhs.base() > other.base());
						}
						template<class X>
	bool 				operator>=(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (lhs.base() <= other.base());
						}
						template<class X>
	bool 				operator<=(const reverse_iterator<X> & lhs, const reverse_iterator<X> & other)
						{
							return (lhs.base() >= other.base());
						}
}

#endif