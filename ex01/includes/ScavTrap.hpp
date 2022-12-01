/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:20:06 by sle-huec          #+#    #+#             */
/*   Updated: 2022/12/01 13:17:34 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream> 
#include <string>

class ScavTrap : public ClapTrap
{
	public:
	
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& cpy);
		ScavTrap& operator=(ScavTrap const& rhs);
		~ScavTrap();
		
		void attack(const std::string &target);
		void guardGate();

	private:

		int check_energy_points(void);
		int check_hit_points(void);
};

#endif