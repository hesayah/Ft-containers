/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:48:06 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 02:00:29 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	ScavTrap 	scav_one("momonoske");
	std::cout << std::endl;
	ScavTrap 	scav_two("Hedi");
	std::cout << std::endl;
	ClapTrap	clap_one("the clap");

	std::cout << std::endl;
	std::cout << std::endl;
	clap_one.attack("clap_one cible");
	scav_one.attack("scav_one cible");
	scav_two.attack("scav_two cible");
	std::cout << std::endl;
	clap_one.beRepaired(10);
	scav_two.beRepaired(10);
	std::cout << std::endl;
	scav_one.guardGate();
	std::cout << std::endl;
	
	return (0);
}