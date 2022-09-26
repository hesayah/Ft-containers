/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:46:22 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 13:02:31 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    std::cout << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;
    const WrongAnimal* wrongan = new WrongAnimal();
    const WrongAnimal* wroncat = new WrongCat();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrongan->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    i->makeSound();
    std::cout << std::endl;
    j->makeSound();
    std::cout << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    wrongan->makeSound();
    std::cout << std::endl;
    wroncat->makeSound();
    std::cout << std::endl;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;
    delete j;
    std::cout << std::endl;
    delete wroncat;
    std::cout << std::endl;
    delete wrongan;
    std::cout << std::endl;
    delete meta;

    return (0);
}