/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:56:23 by hesayah           #+#    #+#             */
/*   Updated: 2022/05/12 02:03:56 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
		void    highFivesGuys(void);
	FragTrap(void);
	FragTrap(std::string Name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & src);
};

#endif