/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:45:03 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 13:36:36 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main(void)
{
   std::cout << std::endl;

    AAnimal *animal[4];

    /**
    ***AAnimal *test = new AAnimal();
    **/

    WrongAnimal *wrong[2];
    wrong[0] = new WrongCat();
    wrong[1] = new WrongCat();

    animal[0] = new Cat();
    animal[1] = new Cat();
    animal[2] = new Dog();
    animal[3] = new Dog();
    Brain brain = Brain();

    std::cout << std::endl;
    std::cout << std::endl;

    animal[0]->getBrain()->setIdea("first Catous", 0);
    std::cout << ((Cat *)animal[0])->getBrain()->getIdeas(0) << std::endl;

    ((Dog *)animal[2])->getBrain()->setIdea("first Dog", 0);
    std::cout << ((Dog *)animal[2])->getBrain()->getIdeas(0) << std::endl;
   
    ((WrongCat *)wrong[0])->setBrain(brain);
    ((WrongCat *)wrong[0])->getBrain()->setIdea("first WCat", 0);
    std::cout << ((WrongCat *)wrong[0])->getBrain()->getIdeas(0) << std::endl;

    std::cout << std::endl;
    (*(Cat *)animal[1]) = (*(Cat *)animal[0]);
    (*(Dog *)animal[3]) = (*(Dog *)animal[2]);
    (*(WrongCat *)wrong[1]) = (*(WrongCat *)wrong[0]);
    std::cout << std::endl;
    std::cout << "brain cat 0 address :" << ((Cat *)animal[0])->getBrain() << std::endl;
    std::cout << "brain cat 1 address :" << ((Cat *)animal[1])->getBrain() << std::endl;
    std::cout << "brain dog 0 address :" << ((Dog *)animal[2])->getBrain() << std::endl;
    std::cout << "brain dog 1 address :" << ((Dog *)animal[3])->getBrain() << std::endl;
    std::cout << "brain Wcat 0 address :" << ((WrongCat *)wrong[0])->getBrain() << std::endl;
    std::cout << "brain Wcat 1 address :" << ((WrongCat*)wrong[1])->getBrain() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "brain dog basic address :" << basic.getBrain() << std::endl;
        std::cout << "brain dog tmp address :" << tmp.getBrain() << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        delete animal[i];
   for (int i = 0; i < 2; i++)
        delete wrong[i];
    return (0);
}