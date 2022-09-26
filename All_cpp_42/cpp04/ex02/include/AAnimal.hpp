/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:39:13 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 12:26:10 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
	AAnimal(void);
	AAnimal(AAnimal const & src);
	virtual ~AAnimal(void);
	AAnimal & operator=(AAnimal const & src);
		std::string		getType(void) const;
		virtual void		makeSound(void) const = 0;
		
};

#endif
