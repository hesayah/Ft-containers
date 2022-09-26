/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:17:18 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/14 03:50:17 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WrongCat_HPP__
# define __WrongCat_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat & operator=(WrongCat const & srt);
	WrongCat(void);
	WrongCat(WrongCat const & src);
	~WrongCat(void);
		void		makeSound(void) const;
};

#endif