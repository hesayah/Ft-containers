/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:11:02 by hesayah           #+#    #+#             */
/*   Updated: 2022/11/14 19:11:23 by hesayah          ###   ########.fr       */
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
		typedef T1 			template_one;
		typedef T2 			template_two;

		template_one 		first;
		template_two		second;

		pair() : first(template_one()), second(template_two()) {}
		template<typename U1, typename U2>
		pair(const pair<U1,U2>& p) : first(p.first), second(p.second) {}
		pair(const T1& a,  const T2& b) : first(a), second(b) {}
		~pair() {}

		pair& 				operator=(const pair& other) 
							{
								if (*this != other)
								{
									this->first = other.first;
									this->second = other.second;
								}
								return (*this);
							}
	};
							template<class T1, class T2>
	pair<T1, T2> 			make_pair(T1 x, T2 y) {return (pair<T1,T2>(x,y));}
							template<class T1, class T2>
	bool 					operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return (lhs.first == rhs.first && lhs.second == rhs.second);}
							template<class T1, class T2>
	bool 					operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return (!(lhs == rhs));}
							template<class T1, class T2>
	bool 					operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));}
							template<class T1, class T2>
	bool 					operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return (!(lhs < rhs));}
							template<class T1, class T2>
	bool 					operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return (lhs == rhs || lhs < rhs);}
							template<class T1, class T2>
	bool 					operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return (!(lhs <= rhs));}
}

#endif 