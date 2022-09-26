/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:44:48 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 06:18:43 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        std::string const  & getIdeas(size_t nb_idea);
        void        setIdea(std::string idea, size_t nb_idea);
    Brain(void);
	Brain(Brain const & src);
	~Brain(void);
	Brain & operator=(Brain const & src);
};

#endif