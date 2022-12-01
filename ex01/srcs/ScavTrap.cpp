/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:24:56 by sle-huec          #+#    #+#             */
/*   Updated: 2022/12/01 13:17:48 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << BBLU << " ScavTrap default constructor called." << RES << std::endl;
	this->_name = "";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << BBLU << this->_name << " ScavTrap name in param constructor called." << RES << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap()
{
	std::cout << BBLU << " ScavTrap copy constructor called." << RES << std::endl;
	*this = cpy;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << BBLU << this->_name << " ScavTrap destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
	this->_name = rhs._name;
	return (*this);
}

// members functions===========================================================
//=============================================================================

int ScavTrap::check_energy_points(void)
{
	if (this->_energy_points > 0)
		return 1;
	else
	{
		std::cout << BRED << this->_name << " ScavTrap has no more energy points." << RES << std::endl;
		return 0;
	}
}

int ScavTrap::check_hit_points(void)
{
	if (this->_hit_points > 0)
		return 1;
	else
	{
		std::cout << BRED << this->_name << " ScavTrap has no more hit points." << RES << std::endl;
		return 0;
	}
}


void ScavTrap::attack(const std::string &target)
{
	if (!check_energy_points() || !check_hit_points())
		return;
	this->_energy_points -= 1;
	std::cout << BBLU << "ScavTrap " << this->_name << " attacks " << target << ", causing "
			  << this->_attack_damage << " points of damage!" << RES << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BBLU << "ScavTrap " << this->_name << " Gate keeper mode activate!."
			  << RES << std::endl;
}
