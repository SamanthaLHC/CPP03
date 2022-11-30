/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:21:14 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/30 18:14:21 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "colors.h"

int main()
{
	{
		std::cout << BRED << "verif clavtrap."<< RES << std::endl;
		ScavTrap protector("Tanky");
		protector.guardGate();
	}
	{
		std::cout << BRED << "SCENARIO 1: Tanky attacks target with a spoon until he has no more energy points."
				  << RES << std::endl;
		ClapTrap chara_target("target");
		ScavTrap protector("Tanky");

		protector.guardGate();
		while (protector.get_energy_points() > 0)
		{
			protector.attack(chara_target.get_name());
			chara_target.takeDamage(protector.get_attack_damage());
			std::cout << protector.get_energy_points() << std::endl;
		}
		protector.attack(chara_target.get_name());
	}

	// Vérifier hits points=========================================================
	// =============================================================================

	// {
	// 	std::cout << BCYN << "SCENARIO 2: Clapy hits target with a club until target has no more hit points."
	// 			  << RES << std::endl;
	// 	ClapTrap protector("Clapy");
	// 	ClapTrap chara_target("target");
	// 	const int club_damage = 2;
	// 	const int repair_points = 5;
	// 	protector.set_attack_damage(club_damage);

	// 	while (chara_target.get_hit_points() > 0)
	// 	{
	// 		protector.attack(chara_target.get_name());
	// 		chara_target.takeDamage(protector.get_attack_damage());
	// 		std::cout << chara_target.get_hit_points() << std::endl;
	// 	}
	// 	chara_target.beRepaired(repair_points);
	// }
}