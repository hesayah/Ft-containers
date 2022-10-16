/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:10:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/16 16:56:00 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
**/

#ifndef __LEXICOGRAPHICAL_COMPARE_HPP__
# define  __LEXICOGRAPHICAL_COMPARE_HPP__

namespace ft {

			template<class InputIt1, class InputIt2>
	bool 	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) 
			{
    			for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    			{
        			if (*first1 < *first2)
            			return true;
        			if (*first2 < *first1)
            			return false;
    			}
    			return (first1 == last1) && (first2 != last2);
			}

			template<class InputIt1, class InputIt2, class Compare>
	bool 	lexicographical_compare(InputIt1 first1, InputIt1 last1,InputIt2 first2, InputIt2 last2, Compare comp)
			{
    			for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    			{
        			if (comp(*first1, *first2))
            			return true;
        			if (comp(*first2, *first1))
            			return false;
    			}
    			return (first1 == last1) && (first2 != last2);
			}
}

#endif