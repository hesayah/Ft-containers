/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:48:04 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 01:41:04 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Unamed ScavTrap")
{
    this->_Hit = 100;
    this-> _Energy = 50;
    this->_Attack = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    this->_Hit = 100;
    this-> _Energy = 50;
    this->_Attack = 20;
	std::cout << "ScavTrap parametric constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap defaut destructor  called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
	this->_Name = src._Name;
	this->_Hit = src._Hit;
	this->_Energy = src._Energy;
	this->_Attack = src._Attack;
	return (*this);
}

void 		ScavTrap::attack(const std::string& target)
{
	if (!this->_Hit)
		return ;
	if (!this->_Energy)
	{
		std::cout << "ScavTrap " << this->_Name << " dont have Energy to attack" << std::endl;
		return ;
	}
	--_Energy;
	std::cout << "ScavTrap " << this->_Name << " attacks " <<  target << ", causing " << this->_Attack << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << this->_Name <<  " : mode Gate keeper" << std::endl;
}