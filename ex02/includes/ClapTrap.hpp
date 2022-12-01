/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:19:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/12/01 13:57:26 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &cpy);
		ClapTrap &operator=( ClapTrap const &rhs);
		~ClapTrap(void);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string get_name(void) const;

		unsigned int get_hit_points(void) const;

		unsigned int get_energy_points(void) const;

		unsigned int get_attack_damage(void) const;
		// unsigned int set_attack_damage(unsigned int);

	protected:

		std::string _name;
		unsigned int _hit_points;
		unsigned int _energy_points;
		unsigned int _attack_damage;
		
		int check_energy_points(void);
		int check_hit_points(void);
};

#endif
