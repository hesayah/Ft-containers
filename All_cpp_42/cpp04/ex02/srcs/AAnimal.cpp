/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:42:27 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 09:23:08 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor  called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
    this->_type = src._type;
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return(this->_type);
}

void AAnimal::makeSound(void) const
{
    std::cout << "Define type of animal to make her type sound" << std::endl;
}