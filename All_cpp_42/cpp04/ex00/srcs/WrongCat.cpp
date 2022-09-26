/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:17:23 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 12:17:23 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    this->_type = src._type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Miaou" << std::endl;
}