/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:29:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/10/09 20:12:02 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://en.cppreference.com/w/cpp/iterator/iterator_tags
*** https://en.cppreference.com/w/cpp/iterator/iterator
*** https://cplusplus.com/reference/iterator/iterator_traits/
*** https://cplusplus.com/reference/iterator/iterator/
*** https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/
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

							template<class Iterator>
	struct					iterator_traits
	{
		typedef typename	Iterator::difference_type		difference_type;
		typedef typename	Iterator::value_type			value_type;
		typedef typename	Iterator::pointer				pointer;
		typedef typename	Iterator::reference				reference;
		typedef typename	Iterator::iterator_category		iterator_category;
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