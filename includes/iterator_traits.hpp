/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:29:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/09/26 03:53:35 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*** https://cplusplus.com/reference/iterator/iterator/
*** https://cplusplus.com/reference/iterator/iterator_traits/
**/

#ifndef __ITERATOR_TRAITS__HPP__
# define __ITERATOR_TRAITES_HPP__

# include  <cstddef>

namespace ft {

	struct random_access_iterator_tag {};

	template <class iterator_category, class value_type, class difference_type = std::ptrdiff_t ,class pointer = value_type*, class reference = value_type&>
	struct iterator 
	{
    	
    	typedef difference_type					difference_type;
		typedef value_type						value_type;
    	typedef pointer							pointer;
   		typedef reference						reference;
    	typedef iterator_category				iterator_category;
	};

	template<class iterators>
	struct iterator_traits
	{
		typedef iterators::difference_type		difference_type;
		typedef iterators::value_type			value_type;
		typedef iterators::pointer				pointer;
		typedef iterators::reference			reference;
		typedef iterators::iterator_category	iterator_category;
	};

	template<class T >
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};

	template<class T >
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef random_access_iterator_tag 		iterator_category;
	};
}

#endif