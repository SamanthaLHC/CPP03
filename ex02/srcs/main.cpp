/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:21:14 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/30 19:23:51 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "colors.h"

int main()
{
	{
		std::cout << BRED << "verif clavtrap."<< RES << std::endl;
		FragTrap clone("Buddy");
		clone.highFivesGuys();
	}
	{
		std::cout << BRED << "SCENARIO 1: Buddy attacks target with a spoon until he has no more energy points."
				  << RES << std::endl;
		ClapTrap chara_target("target");
		FragTrap clone("Buddy");

		clone.highFivesGuys();
		while (clone.get_energy_points() > 0)
		{
			clone.attack(chara_target.get_name());
			chara_target.takeDamage(clone.get_attack_damage());
			std::cout << clone.get_energy_points() << std::endl;
		}
		clone.attack(chara_target.get_name());
	}

	// Vérifier hits points=========================================================
	// =============================================================================

	// {
	// 	std::cout << BCYN << "SCENARIO 2: Clapy hits target with a club until target has no more hit points."
	// 			  << RES << std::endl;
	// 	ClapTrap clone("Clapy");
	// 	ClapTrap chara_target("target");
	// 	const int club_damage = 2;
	// 	const int repair_points = 5;
	// 	clone.set_attack_damage(club_damage);

	// 	while (chara_target.get_hit_points() > 0)
	// 	{
	// 		clone.attack(chara_target.get_name());
	// 		chara_target.takeDamage(clone.get_attack_damage());
	// 		std::cout << chara_target.get_hit_points() << std::endl;
	// 	}
	// 	chara_target.beRepaired(repair_points);
	// }
}