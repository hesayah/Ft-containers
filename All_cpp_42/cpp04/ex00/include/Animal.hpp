/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 04:58:01 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/14 04:19:55 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	protected:
		std::string 	_type;
	public:
	Animal & operator=(Animal const & src);
	Animal(void);
	Animal(Animal const & src);
	virtual ~Animal(void);
		std::string		getType(void) const;
	virtual void		makeSound(void) const;	
};

#endif
