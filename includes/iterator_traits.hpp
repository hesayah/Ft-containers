/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:29:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/16 16:55:49 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/iterator/iterator_tags
*** https://cplusplus.com/reference/iterator/iterator_traits/
**/

#ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__

# include <iterator>

namespace ft {
							template<typename Iterator>
	struct					iterator_traits
	{
		typedef typename	Iterator::difference_type				difference_type;
		typedef typename	Iterator::value_type					value_type;
		typedef typename	Iterator::pointer						pointer;
		typedef typename	Iterator::reference						reference;
		typedef typename	Iterator::iterator_category				iterator_category;
	};

							template<typename  T>
	struct					iterator_traits<T*>
	{
		typedef 			std::ptrdiff_t							difference_type;
		typedef 			T										value_type;
		typedef 			T*										pointer;
		typedef 			T&										reference;
		typedef 			std::random_access_iterator_tag			iterator_category;
	};

							template<typename  T>
	struct					iterator_traits<const T*>
	{
		typedef 			std::ptrdiff_t							difference_type;
		typedef				T										value_type;
		typedef const		T*										pointer;
		typedef const		T&										reference;
		typedef				std::random_access_iterator_tag 		iterator_category;
	};
}

#endif