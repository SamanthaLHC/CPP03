/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:06 by sam               #+#    #+#             */
/*   Updated: 2022/11/25 18:27:27 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:

		ClapTrap::ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &cpy);
		ClapTrap &operator=( ClapTrap const &rhs);
		~ClapTrap(void);


		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:

		int _hit_points;
		int _energy_points;
		int _attack_dammage;
		std::string _name;
};

#endif
