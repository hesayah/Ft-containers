/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:39:44 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/21 04:56:49 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;
	public:
		void		makeSound(void) const;
		Brain* 		getBrain(void) const;
	Dog(void);
	Dog(Dog const & src);
	~Dog(void);
	Dog & operator=(Dog const & src);
};

#endif