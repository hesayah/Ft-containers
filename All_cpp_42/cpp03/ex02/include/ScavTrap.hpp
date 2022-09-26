/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:55:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 02:02:35 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
		void 	guardGate(void);
		void	attack(const std::string & target);
	ScavTrap(void);
	ScavTrap(std::string Name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & src);
};

#endif