/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 04:26:47 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/11 07:42:26 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void)
{
    ClapTrap test("Soldat");
    ClapTrap hedi("Hedi");
    ClapTrap boubou;
    ClapTrap boubounamed("boubou");
    

    test.attack("test cible");
    boubou.attack("boubou cible");
    hedi.attack("hedi cible");
    
    boubou = boubounamed;

    test.takeDamage(5);
    boubou.takeDamage(10);
    hedi.takeDamage(9);

    test.attack("test cible");
    boubou.attack("boubou cible");
    hedi.attack("hedi cible");

    test.beRepaired(5);
    boubou.beRepaired(5);
    hedi.beRepaired(50);

    test.attack("test cible");
    boubou.attack("boubou cible");
    hedi.attack("hedi cible");
    hedi.attack("hedi cible");
    hedi.attack("hedi cible");
    hedi.attack("hedi cible");
    hedi.attack("hedi cible");
    hedi.attack("hedi cible");
    hedi.attack("hedi cible");
    hedi.attack("hedi cible");

    return (0);
}