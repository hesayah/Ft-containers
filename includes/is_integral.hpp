/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:10:35 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/05 11:06:21 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/types/integral_constant
*** https://en.cppreference.com/w/cpp/types/is_integral
**/

#ifndef __IS_INTEGRAL_HPP__
# define __IS_INTEGRAL_HPP__

namespace ft {
	
	template<class T, T v>
	struct integral_constant 
	{
		static const 		T value = v;

    	typedef 			T  						value_type;
    	typedef 			integral_constant<T,v>	type;

   		operator 			value_type() const  {return v;}
	};

	typedef 				integral_constant<bool, true> 	true_type;
	typedef 				integral_constant<bool, false> 	false_type;
	
							template<class T>
	struct 					is_integral : public false_type {};
				
							template<>
	struct 					is_integral<bool> : public true_type {};
							template<>
	struct 					is_integral<char> : public true_type {};
							template<>
	struct 					is_integral<wchar_t> : public true_type {};
							template<>
	struct 					is_integral<short> : public true_type {};
							template<>
	struct 					is_integral<int> : public true_type {};			
							template<>
	struct 					is_integral<long> : public true_type {};
							template<>
	struct 					is_integral<long long> : public true_type {};
							template<>
	struct 					is_integral<signed char> : public true_type {};
							template<>
	struct 					is_integral<unsigned char> : public true_type {};
							template<>
	struct 					is_integral<unsigned short> : public true_type {};
							template<>
	struct 					is_integral<unsigned int> : public true_type {};
							template<>
	struct 					is_integral<unsigned long> : public true_type {};
							template<>
	struct 					is_integral<unsigned long long> : public true_type {};
}				
				
#endif