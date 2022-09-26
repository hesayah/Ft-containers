/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 07:19:25 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/11 02:39:07 by hesayah          ###   ########.fr       */
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
		static Fixed const & max(Fixed const & one, Fixed const &two);
		static Fixed & max(Fixed & one, Fixed &two);
		static Fixed const & min(Fixed const & one, Fixed const & two);
		static Fixed & min(Fixed & one, Fixed & two);
		Fixed(int const integer);
		Fixed(float const floater);
		Fixed(Fixed const& src);
		Fixed(void);
		~Fixed(void);
		Fixed &	operator=(Fixed const& src);
		/**
		*** Arithmetic operators
		**/
		Fixed	operator+(Fixed const & src) const;
		Fixed	operator-(Fixed const & src) const;
		Fixed	operator/(Fixed const & src) const;
		Fixed	operator*(Fixed const & src) const;
		/**
		*** Comparison operators
		**/
		bool	operator==(Fixed const & src) const;
		bool	operator!=(Fixed const & src) const;
		bool	operator>(Fixed const & src) const;
		bool	operator<(Fixed const & src) const;
		bool	operator>=(Fixed const & src) const;
		bool	operator<=(Fixed const & src) const;
		/**
		*** Increment operators
		**/
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);
};

std::ostream &  operator<<(std::ostream & out,  Fixed const & src);

#endif