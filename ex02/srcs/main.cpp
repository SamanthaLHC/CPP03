/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:21:14 by sle-huec          #+#    #+#             */
/*   Updated: 2022/12/01 16:11:33 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "colors.h"

int main()
{
	{
		std::cout << BRED << "verif FragTrap." << RES << std::endl;
		FragTrap clone("Buddy");
		clone.highFivesGuys();
	}

	// Vérifier hits points=========================================================
	// =============================================================================

	{
		std::cout << BCYN << "SCENARIO 2: verifs hit points." << RES << std::endl;
		ClapTrap chara_target("target");
		FragTrap clone("Buddy");

		while (chara_target.get_hit_points() > 0)
		{
			clone.attack(chara_target.get_name());
			chara_target.takeDamage(clone.get_attack_damage());
			std::cout << "target hit points " << chara_target.get_hit_points() << std::endl;
		}
		clone.attack(chara_target.get_name());

		std::cout << chara_target.get_hit_points() << std::endl;
		chara_target.attack(chara_target.get_name());
	}

	// Vérifier beRepaired==========================================================
	// =============================================================================

	{
		std::cout << BRED << "SCENARIO 3: verifs repaired." << RES << std::endl;
		ClapTrap chara_target("target");
		FragTrap clone("Buddy");
		std::cout << "Target hit points " << chara_target.get_hit_points() << std::endl;
		clone.attack(chara_target.get_name());
		chara_target.takeDamage(clone.get_attack_damage());
		std::cout << "Buddy energy points " << clone.get_energy_points() << std::endl;
		std::cout << "Target hit points " << chara_target.get_hit_points() << std::endl;
		chara_target.beRepaired(3);
	}
}