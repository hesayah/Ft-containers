/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:48:00 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 02:11:03 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("Unamed ClapTrap"), _Hit(10), _Energy(10), _Attack(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _Hit(10), _Energy(10), _Attack(0)
{
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Defaut destructor  called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_Name = src._Name;
	this->_Hit = src._Hit;
	this->_Energy = src._Energy;
	this->_Attack = src._Attack;
	return (*this);
}

void 		ClapTrap::attack(const std::string& target)
{
	if (this->_Hit <= 0)
		return ;
	if (!this->_Energy)
	{
		std::cout << "ClapTrap " << this->_Name << " dont have Energy to attack" << std::endl;
		return ;
	}
	--_Energy;
	std::cout << "ClapTrap " << this->_Name << " attacks " <<  target << ", causing " << this->_Attack << " points of damage!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hit <= 0)
		return ;
	this->_Hit-= amount;
	std::cout 	<< "ClapTrap " << this->_Name << " take " << amount 
	<< " points of damage! Total Hit : " << this->_Hit << " Total Energy : " << this->_Energy 
	<< std::endl;
	if (this->_Hit <= 0)
		std::cout << "ClapTrap " << this->_Name << " died " << std::endl;
}

void 		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hit <= 0)
		return ;
	if (!this->_Energy)
	{
		std::cout << "ClapTrap " << this->_Name << " dont have Energy to be repaired" << std::endl;
		return ;
	}
	--_Energy;
	this->_Hit+= amount;
	std::cout << "ClapTrap " << this->_Name << " take " << amount << " points of hit! Total Hit : " << this->_Hit << std::endl;
}