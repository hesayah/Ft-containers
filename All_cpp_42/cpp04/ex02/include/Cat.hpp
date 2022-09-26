/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:39:25 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 12:28:44 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat : public AAnimal
{
	private:
		Brain 		*_brain;
	public:
		void		makeSound(void) const;
		Brain* 		getBrain(void) const;
	Cat(void);
	Cat(Cat const & src);
	Cat(Cat & src);
	~Cat(void);
	Cat & operator=(Cat const & srt);
};

#endif