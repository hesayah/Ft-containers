/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 06:22:25 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/11 02:23:14 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(void) : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer) : _RawBits(integer << _nb_bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floater) : _RawBits(roundf(floater * (1 << _nb_bit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_RawBits = src.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_RawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (roundf(this->_RawBits) / (1 << this->_nb_bit));
}

int		Fixed::toInt(void) const
{
	return (this->_RawBits >> this->_nb_bit);
}

std::ostream&  operator<<(std::ostream& out,  Fixed const & src)
{
    out << src.toFloat();
    return (out);
}