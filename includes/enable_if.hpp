/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:10:21 by hesayah           #+#    #+#             */
/*   Updated: 2022/09/29 03:28:59 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ENABLE_IF_HPP
# define __ENABLE_IF_HPP__


namespace ft {

	template <class T> 
	struct is_integral : std::integral_constant 
	{

		private :
			bool	_value_type;
			typedef integral_constant<bool,true> true_type;
			typedef integral_constant<bool,false> false_type;
	};
}

#endif