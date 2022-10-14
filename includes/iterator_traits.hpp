/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:29:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/14 15:47:20 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/iterator/iterator_tags
*** https://en.cppreference.com/w/cpp/iterator/iterator
*** https://cplusplus.com/reference/iterator/iterator_traits/
*** https://cplusplus.com/reference/iterator/iterator/
*** https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/
*** https://forum.hardware.fr/hfr/Programmation/C-2/conception-iterator-introduction-sujet_63686_1.htm
**/

#ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__

namespace ft {

	struct					input_iterator_tag {};
	struct					output_iterator_tag {};
	struct					forward_iterator_tag : public input_iterator_tag {};
	struct					bidirectional_iterator_tag : public forward_iterator_tag {};
	struct					random_access_iterator_tag : public bidirectional_iterator_tag {};

							template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
  	struct 					iterator 
	{
		typedef 			T								value_type;
		typedef 			Distance						difference_type;
		typedef 			Pointer							pointer;
		typedef 			Reference						reference;
		typedef 			Category						iterator_category;
	};

							template<typename Iterator>
	struct					iterator_traits
	{
		typedef typename	Iterator::difference_type		difference_type;
		typedef typename	Iterator::value_type			value_type;
		typedef typename	Iterator::pointer				pointer;
		typedef typename	Iterator::reference				reference;
		typedef typename	Iterator::iterator_category		iterator_category;
	};

							template<typename  T>
	struct					iterator_traits<T*>
	{
		typedef 			std::ptrdiff_t					difference_type;
		typedef 			T								value_type;
		typedef 			T*								pointer;
		typedef 			T&								reference;
		typedef 			std::random_access_iterator_tag		iterator_category;
	};

							template<typename  T>
	struct					iterator_traits<const T*>
	{
		typedef 			std::ptrdiff_t					difference_type;
		typedef				T								value_type;
		typedef const		T*								pointer;
		typedef const		T&								reference;
		typedef				std::random_access_iterator_tag 		iterator_category;
	};
}

#endif