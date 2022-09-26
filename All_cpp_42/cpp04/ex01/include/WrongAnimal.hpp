/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:12:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 11:01:33 by hesayah          ###   ########.fr       */
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
		std::string	    getType(void) const;
		void		    makeSound(void) const;
	WrongAnimal & operator=(WrongAnimal const & src);
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	virtual ~WrongAnimal(void);

};

#endif
