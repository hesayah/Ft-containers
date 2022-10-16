/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:11:02 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/16 16:56:07 by hesayah          ###   ########.fr       */
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

			template_one 		_value_one;
			template_two		_value_two;

		public :
			pair() : _value_one(), _value_two {}
			pair(const T1& x, const T2& y) : _value_one(x), _value_two(y) {}
			template<class U1, class U2>
			pair(const pair<U1, U2>& p) : _value_one(p._value_one), _value_two(p._value_two) {}
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
		pair<T1, T2> 		make_pair(T1 t, T2 u);
}

#endif 