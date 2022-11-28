/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:06 by sam               #+#    #+#             */
/*   Updated: 2022/11/28 21:37:08 by samantha         ###   ########.fr       */
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
		// unsigned int set_hit_points(unsigned int);

		unsigned int get_energy_points(void) const;
		// unsigned int set_energy_points(unsigned int);

		unsigned int get_attack_damage(void) const;
		unsigned int set_attack_damage(unsigned int);

	private:

		std::string _name;
		unsigned int _hit_points;
		unsigned int _energy_points;
		unsigned int _attack_damage;
		
		int check_energy_points(void);
		int check_hit_points(void);
};

#endif
