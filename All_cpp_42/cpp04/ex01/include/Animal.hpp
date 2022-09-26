/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:39:13 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 13:19:07 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
	virtual void		makeSound(void) const;
		std::string		getType(void) const;
	Animal(void);
	Animal(Animal const & src);
	virtual ~Animal(void);
	Animal & operator=(Animal const & src);
};

#endif
