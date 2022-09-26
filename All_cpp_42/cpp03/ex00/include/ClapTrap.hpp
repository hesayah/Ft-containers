/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 04:26:43 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/11 07:48:39 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
	private:
		std::string _Name;
		int 		_Hit;
		int			_Energy;
 		int			_Attack;
	public:
		void attack(const std::string & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	ClapTrap(void);
	ClapTrap(ClapTrap const & src);
	ClapTrap(std::string Name);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & src);
};

#endif