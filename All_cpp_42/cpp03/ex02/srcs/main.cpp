/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:00:34 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 02:07:45 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main(void)
{
	ScavTrap 	scav_one("[momonoske]");
	std::cout << std::endl;
	ClapTrap	clap_one("[the clap]");
    std::cout << std::endl;
	FragTrap 	frag_one("[Hedi the frag]");

	std::cout << std::endl;
	std::cout << std::endl;
	clap_one.attack("clap_one cible");
	scav_one.attack("scav_one cible");
	frag_one.attack("Frag cible");
	std::cout << std::endl;
	clap_one.beRepaired(10);
	scav_one.beRepaired(10);
	frag_one.beRepaired(10);
	std::cout << std::endl;
	clap_one.takeDamage(10);
	scav_one.takeDamage(150);
	frag_one.takeDamage(10);
	std::cout << std::endl;
	scav_one.guardGate();
    frag_one.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}