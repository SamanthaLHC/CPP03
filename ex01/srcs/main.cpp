/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:21:14 by sle-huec          #+#    #+#             */
/*   Updated: 2022/12/01 15:48:50 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "colors.h"

int main()
{
	{
		std::cout << BRED << "verif clavtrap." << RES << std::endl;
		ScavTrap protector("Tanky");
		protector.guardGate();
	}
	{
		std::cout << BRED << "SCENARIO 1: verifs no more hit points."
				  << RES << std::endl;
		ClapTrap chara_target("target");
		ScavTrap protector("Tanky");

		protector.guardGate();
		while (chara_target.get_hit_points() > 0)
		{
			protector.attack(chara_target.get_name());
			chara_target.takeDamage(protector.get_attack_damage());
			std::cout << "Tanky energy points: " << protector.get_energy_points() << std::endl;
			std::cout << "target hit points: " << chara_target.get_hit_points() << std::endl;
		}
		chara_target.attack(protector.get_name());
	}

	// Vérifier hits points=========================================================
	// =============================================================================

	{
		std::cout << BCYN << "SCENARIO 2: verifs energy points." << RES << std::endl;
		ClapTrap chara_target("target");
		ScavTrap protector("Tanky");

		while (protector.get_energy_points() > 0)
		{
			protector.attack(chara_target.get_name());
			chara_target.takeDamage(protector.get_attack_damage());
			std::cout << "Tanky energy points " << protector.get_energy_points() << std::endl;
		}
		protector.attack(chara_target.get_name());

		std::cout << chara_target.get_hit_points() << std::endl;
		chara_target.attack(protector.get_name());
	}

	// Vérifier beRepaired==========================================================
	// =============================================================================

	{
		std::cout << BCYN << "SCENARIO 3: verifs repaired." << RES << std::endl;
		ClapTrap chara_target("target");
		ScavTrap protector("Tanky");
		
		protector.attack(chara_target.get_name());
		chara_target.takeDamage(protector.get_attack_damage());
		std::cout << "energy points " << protector.get_energy_points() << std::endl;
		std::cout << "hit points " << chara_target.get_hit_points() << std::endl;
		chara_target.beRepaired(3);
		std::cout << "hit points " << chara_target.get_hit_points() << std::endl;
	}
}