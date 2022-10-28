/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:11:02 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/28 21:53:02 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PAIR_HPP__
# define __PAIR_HPP__

/**
*** https://en.cppreference.com/w/cpp/utility/pair
**/

namespace ft {

	template<typename T1,typename T2> 
	struct pair
	{

		private :

			typedef T1 			template_one;
			typedef T2 			template_two;
		protected :

			template_one 		_value_one;
			template_two		_value_two;

		public :

				pair();	
				pair(const pair<T1,T2>& pr) {*this = pr;}
				pair(const template_one& a, const template_two& b) : _value_one(a), _value_two(b) {}
			~pair() {}

			pair& 				operator=(const pair& other) 
								{
									if (this != other)
									{
										this->_value_one = other._value_one;
										this->_value_two = other._value_two;
									}
									return (*this);
								}
	};
							template<class T1, class T2>
		bool 				operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
							template<class T1, class T2>
		bool 				operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
							template<class T1, class T2>
		bool 				operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
							template<class T1, class T2>
		bool 				operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
							template<class T1, class T2>
		bool 				operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
							template<class T1, class T2>
		bool 				operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
							template<class T1, class T2>
		pair<T1, T2> 		make_pair(T1 x, T2 y) {return (pair<T1,T2>(x,y));}
}

#endif 