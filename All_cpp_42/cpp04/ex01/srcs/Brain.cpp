/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:54:22 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 09:23:04 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor  called" << std::endl;
}

Brain & Brain::operator=(Brain const & src)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    return (*this);
}


std::string const &  Brain::getIdeas(size_t nb_idea)
{
    return (this->_ideas[nb_idea]);
}

void        Brain::setIdea(std::string idea, size_t nb_idea)
{
    if (nb_idea >= 100)
    {
        std::cout << "nb_idea >= 100" << std::endl;
        return ;
    }
    this->_ideas[nb_idea] = idea;
}