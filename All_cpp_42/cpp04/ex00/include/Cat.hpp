/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:10:27 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/14 03:50:09 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat & operator=(Cat const & srt);
	Cat(void);
	Cat(Cat const & src);
	~Cat(void);
		void		makeSound(void) const;
};

#endif