/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:13:55 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/15 11:31:02 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WrongCat_HPP__
# define __WrongCat_HPP__

#include "Brain.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain *_brain;
	public:
	WrongCat & operator=(WrongCat const & src);
	WrongCat(void);
	WrongCat(WrongCat const & src);
	~WrongCat(void);
	void		makeSound(void) const;
	Brain* 		getBrain(void) const;
	void		setBrain(Brain & brain){
		_brain = &brain;
	};
};

#endif