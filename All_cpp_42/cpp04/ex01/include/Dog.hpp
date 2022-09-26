/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:39:44 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 13:19:51 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		void		makeSound(void) const;
		Brain* 		getBrain(void) const;
	Dog(void);
	Dog(Dog const & src);
	virtual ~Dog(void);
	Dog & operator=(Dog const & srt);
};

#endif