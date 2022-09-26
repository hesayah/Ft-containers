/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:58:32 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 02:04:21 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Unamed FragTrap")
{
    this->_Hit = 100;
    this-> _Energy = 100;
    this->_Attack = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    this->_Hit = 100;
    this-> _Energy = 100;
    this->_Attack = 30;
	std::cout << "FragTrap parametric constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap defaut destructor  called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	std::cout << "FragTrap copy assignement operator called" << std::endl;
	this->_Name = src._Name;
	this->_Hit = src._Hit;
	this->_Energy = src._Energy;
	this->_Attack = src._Attack;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_Name <<  " : want high fives" << std::endl;
}