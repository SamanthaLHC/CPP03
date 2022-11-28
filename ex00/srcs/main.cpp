/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:57 by sam               #+#    #+#             */
/*   Updated: 2022/11/28 20:57:30 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


// gérer le nombre max de hit points et la perte de tous les energy points
int main()
{
	ClapTrap character_one("Clapy");
	ClapTrap chara_target("target");
	
	character_one.attack(chara_target.get_name());
	chara_target.takeDamage(character_one.get_attack_damage());
	std::cout << character_one.get_energy_points() << std::endl;
}