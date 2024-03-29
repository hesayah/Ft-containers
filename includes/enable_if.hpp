/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:10:21 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/10 06:32:11 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/types/enable_if
*** https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html
**/

#ifndef __ENABLE_IF_HPP__
# define __ENABLE_IF_HPP__

namespace ft {

	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> 
	{ 
		typedef T type; 
	};
}

#endif