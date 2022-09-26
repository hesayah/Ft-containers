/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:42:45 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 10:44:03 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(void) :  Animal() , _brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(Cat const & src) : Animal(src) , _brain(new Brain(*(src._brain)))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete (this->_brain);
}

Cat & Cat::operator=(Cat const & src)
{
    std::cout << "Cat operator = called" << std::endl;
    this->_type = src._type;
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*(src._brain));
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Miaou" << std::endl;
}

Brain* 		Cat::getBrain(void) const
{
    return (this->_brain);
}
