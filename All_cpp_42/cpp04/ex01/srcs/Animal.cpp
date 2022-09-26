/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:42:27 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 09:23:08 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor  called" << std::endl;
}

Animal & Animal::operator=(Animal const & src)
{
    this->_type = src._type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return(this->_type);
}

void Animal::makeSound(void) const
{
    std::cout << "Define type of animal to make her type sound" << std::endl;
}