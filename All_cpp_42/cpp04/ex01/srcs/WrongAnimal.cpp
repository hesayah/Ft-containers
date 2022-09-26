/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:13:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 10:54:53 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor  called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
    this->_type = src._type;
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return(this->_type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Define type of WrongAnimal to make her type sound" << std::endl;
}