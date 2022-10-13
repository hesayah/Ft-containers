/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:10:28 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/13 04:52:58 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/algorithm/equal 
**/

#ifndef __EQUAL_HPP__
# define __EQUAL_HPP__

namespace ft {

		template<class InputIt1, class InputIt2>
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
		{
   			for (; first1 != last1; ++first1, ++first2) 
			{
       			if (!(*first1 == *first2)) 
				{
           			return false;
       			}
			}
   			return true;
		}

		template<class InputIt1, class InputIt2, class BinaryPredicate>
bool 	equal(InputIt1 first1, InputIt1 last1,InputIt2 first2, BinaryPredicate p)
		{
			for (; first1 != last1; ++first1, ++first2)
			{
       			if (!p(*first1, *first2))
				{
           			return false;
       			}
    		}
    		return true;
		}
}

#endif