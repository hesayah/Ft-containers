/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:26:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/13 03:18:38 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(void) : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(Cat const & src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
    this->_type = src._type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Miaou" << std::endl;
}