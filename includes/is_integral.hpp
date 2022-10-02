/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:10:35 by hesayah           #+#    #+#             */
/*   Updated: 2022/09/29 03:31:04 by hesayah          ###   ########.fr       */
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
	struct integral_constant {
    	static constexpr T value = v;
    	using value_type = T;
    	using type = integral_constant;
   		operator value_type() const  {return value;}
	};

	typedef integral_constant<bool, true> 	true_type;
	typedef integral_constant<bool, false> 	false_type;
	
			template<class T>
	struct 	is_integral;

			template<>
	struct 	is_integral<bool> : public true_type {};
			template<>
	struct 	is_integral<char> : public true_type {};
			template<>
	struct 	is_integral<wchar_t> : public true_type {};
			template<>
	struct 	is_integral<short> : public true_type {};
			template<>
	struct 	is_integral<int> : public true_type {};			
			template<>
	struct 	is_integral<long> : public true_type {};
			template<>
	struct 	is_integral<long long> : public true_type {};
			template<>
	struct 	is_integral<signed char> : public true_type {};
			template<>
	struct 	is_integral<signed short> : public true_type {};
			template<>	
	struct 	is_integral<signed int> : public true_type {};
			template<>
	struct 	is_integral<signed long> : public true_type {};
			template<>
	struct 	is_integral<signed long long> : public true_type {};		
			template<>
	struct 	is_integral<unsigned char> : public true_type {};
			template<>
	struct 	is_integral<unsigned short> : public true_type {};
			template<>
	struct 	is_integral<unsigned int> : public true_type {};
			template<>
	struct 	is_integral<unsigned long> : public true_type {};
			template<>
	struct 	is_integral<unsigned long long> : public true_type {};
}

#endif