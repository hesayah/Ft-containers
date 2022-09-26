/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:29:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/09/26 04:45:08 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/iterator/iterator_tags
*** https://cplusplus.com/reference/iterator/iterator_traits/
*** https://cplusplus.com/reference/iterator/iterator/
**/

#ifndef __ITERATOR_TRAITS__HPP__
# define __ITERATOR_TRAITES_HPP__

# include <cstddef>

namespace ft {

	struct					input_iterator_tag {};
	struct					output_iterator_tag {};
	struct					forward_iterator_tag : public input_iterator_tag {};
	struct					bidirectional_iterator_tag : public forward_iterator_tag {};
	struct					random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
  	struct					iterator 
	{
    	
    	typedef				Distance						difference_type;
		typedef				T								value_type;
    	typedef				Pointer							pointer;
   		typedef				Reference						reference;
    	typedef				Category						iterator_category;
	};

	template<class iterators>
	struct					iterator_traits
	{
		typedef typename	iterators::difference_type		difference_type;
		typedef typename	iterators::value_type			value_type;
		typedef typename	iterators::pointer				pointer;
		typedef typename	iterators::reference			reference;
		typedef typename	iterators::iterator_category	iterator_category;
	};

	template<class T>
	struct					iterator_traits<T*>
	{
		typedef 			std::ptrdiff_t					difference_type;
		typedef 			T								value_type;
		typedef 			T*								pointer;
		typedef 			T&								reference;
		typedef 			random_access_iterator_tag		iterator_category;
	};

	template<class T>
	struct					iterator_traits<const T*>
	{
		typedef 			std::ptrdiff_t					difference_type;
		typedef				T								value_type;
		typedef const		T*								pointer;
		typedef const		T&								reference;
		typedef				random_access_iterator_tag 		iterator_category;
	};
}

#endif