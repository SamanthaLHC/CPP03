/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:57 by sam               #+#    #+#             */
/*   Updated: 2022/11/29 11:38:28 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

int main()
{
	{
		std::cout << BCYN << "SCENARIO 1: Clapy attacks target with a spoon until he has no more energy points." 
		<< RES << std::endl;
		ClapTrap character_one("Clapy");
		ClapTrap chara_target("target");

		while (character_one.get_energy_points() > 0)
		{
			character_one.attack(chara_target.get_name());
			chara_target.takeDamage(character_one.get_attack_damage());
			std::cout << character_one.get_energy_points() << std::endl;
		}
		character_one.attack(chara_target.get_name());
	}
	{
		std::cout << BCYN << "SCENARIO 2: Clapy hits target with a club until target has no more hit points."
				  << RES << std::endl;
		ClapTrap character_one("Clapy");
		ClapTrap chara_target("target");
		const int club_damage = 2;
		const int repair_points = 5;
		character_one.set_attack_damage(club_damage);

		while (chara_target.get_hit_points() > 0)
		{
			character_one.attack(chara_target.get_name());
			chara_target.takeDamage(character_one.get_attack_damage());
			std::cout << chara_target.get_hit_points() << std::endl;
		}
		chara_target.beRepaired(repair_points);
	}
	{
		std::cout << BCYN << "SCENARIO 3: Clapy get hits from target with a club and tries to repair himself until he has no more hit points."
				  << RES << std::endl;
		
		ClapTrap character_one("Clapy");
		ClapTrap chara_target("target");
		const int club_damage = 5;
		const int repair_points = 2;

		chara_target.set_attack_damage(club_damage);
		while (character_one.get_hit_points() > 0)
		{
			chara_target.attack(character_one.get_name());
			character_one.takeDamage(chara_target.get_attack_damage());
			character_one.beRepaired(repair_points);
		}
		// chara_target.attack(character_one.get_name());
		// character_one.takeDamage(chara_target.get_attack_damage());
		std::cout << character_one.get_hit_points() << std::endl;
		character_one.beRepaired(repair_points);
	}
}