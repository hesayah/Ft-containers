/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:55:15 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 02:02:39 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
	protected:
		std::string _Name;
		int 		_Hit;
		int			_Energy;
 		int			_Attack;
	public:
		void		attack(const std::string & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	ClapTrap(void);
	ClapTrap(ClapTrap const & src);
	ClapTrap(std::string Name);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & src);
};

#endif