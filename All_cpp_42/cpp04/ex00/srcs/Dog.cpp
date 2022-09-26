/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:27:05 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 10:24:16 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(Dog const & src)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & src)
{
    this->_type = src._type;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "WafWaf" << std::endl;
}
