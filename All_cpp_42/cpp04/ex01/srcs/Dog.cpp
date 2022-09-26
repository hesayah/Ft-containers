/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:43:02 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 11:17:53 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void) :  Animal() , _brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(Dog const & src) : Animal(src) , _brain(new Brain(*(src._brain)))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete (this->_brain);
}

Dog & Dog::operator=(Dog const & src)
{
    std::cout << "Dog operator = called" << std::endl;
    this->_type = src._type;
    delete this->_brain;
    this->_brain = new Brain(*(src._brain));
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "WafWaf" << std::endl;
}

Brain* 		Dog::getBrain(void) const
{
    return (this->_brain);
}
