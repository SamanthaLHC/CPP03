/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:19:44 by sle-huec          #+#    #+#             */
/*   Updated: 2022/12/01 15:30:45 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

int main()
{
	{
		std::cout << BCYN << "SCENARIO 1: verifs energy points." << RES << std::endl;
		ClapTrap character_one("Clapy");
		ClapTrap chara_target("target");

		while (character_one.get_energy_points() > 0)
		{
			character_one.attack(chara_target.get_name());
			chara_target.takeDamage(character_one.get_attack_damage());
			std::cout << "energy points: " << character_one.get_energy_points() << std::endl;
		}
		character_one.attack(chara_target.get_name());
	}

	// // Vérifier hits points=========================================================
	// =============================================================================

	// {
	// 	std::cout << BCYN << "SCENARIO 2: verifs hit points." << RES << std::endl;
	// 	ClapTrap character_one("Clapy");
	// 	ClapTrap chara_target("target");

	// 	while (character_one.get_energy_points() > 0)
	// 	{
	// 		character_one.attack(chara_target.get_name());
	// 		chara_target.takeDamage(character_one.get_attack_damage() + 5);
	// 		std::cout << "energy points " << character_one.get_energy_points() << std::endl;
	// 	}
	// 	character_one.attack(chara_target.get_name());

	// 	std::cout << chara_target.get_hit_points() << std::endl;
	// 	chara_target.attack(chara_target.get_name());
	// }

	// Vérifier beRepaired==========================================================
	// =============================================================================

	{
		std::cout << BCYN << "SCENARIO 3: verifs repaired." << RES << std::endl;
		ClapTrap character_one("Clapy");
		ClapTrap chara_target("target");
		character_one.attack(chara_target.get_name());
		chara_target.takeDamage(character_one.get_attack_damage() + 5);
		std::cout << "hit points " << chara_target.get_hit_points() << std::endl;
		chara_target.beRepaired(3);
		std::cout << "hit points " << chara_target.get_hit_points() << std::endl;
	}
}