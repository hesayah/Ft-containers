/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:15:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 11:31:51 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
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
    this->_brain = src._brain;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "WafWaf" << std::endl;
}

Brain* 		WrongCat::getBrain(void) const
{
    return (this->_brain);
}
