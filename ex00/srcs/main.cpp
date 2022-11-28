/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:57 by sam               #+#    #+#             */
/*   Updated: 2022/11/28 21:23:10 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// gérer le nombre max de hit points et la perte de tous les energy points

// points de vie de ClapTrap à zéro

// points d'énergie à zéro ?

int main()
{
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