/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:27:06 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/11 00:50:15 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed
{
	private:
		int _RawBits;
		int static const _nb_bit = 8;
	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed(Fixed const & src);
		Fixed(void);
		~Fixed(void);
		Fixed & operator=(Fixed const & src);
};

#endif
