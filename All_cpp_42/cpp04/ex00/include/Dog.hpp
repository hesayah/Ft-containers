/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:12:44 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/14 03:50:34 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog & operator=(Dog const & srt);
	Dog(void);
	Dog(Dog const & src);
	~Dog(void);
		void		makeSound(void) const;
};

#endif