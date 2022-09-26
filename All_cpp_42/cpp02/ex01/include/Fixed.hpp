/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 06:21:33 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/11 00:54:38 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_RawBits;
		int static const	_nb_bit = 8;
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed(int const integer);
		Fixed(float const floater);
		Fixed(Fixed const & src);
		Fixed(void);
		~Fixed(void);
		Fixed & operator=(Fixed const & src);
};

std::ostream &  operator<<(std::ostream & out,  Fixed const & src);

#endif