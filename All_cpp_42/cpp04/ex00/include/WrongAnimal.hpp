/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:13:42 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/14 03:49:32 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal
{
	protected:
		std::string     _type;
	public:
	WrongAnimal & operator=(WrongAnimal const & src);
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	~WrongAnimal(void);
		std::string	    getType(void) const;
		void		    makeSound(void) const;
};

#endif
