/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:24:56 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/30 18:11:40 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << BCYN << " ScavTrap default constructor called." << RES << std::endl;
	this->_name = "";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << BCYN << this->_name << " ScavTrap name in param constructor called." << RES << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap()
{
	std::cout << BCYN << " ScavTrap copy constructor called." << RES << std::endl;
	*this = cpy;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << BCYN << this->_name << " ScavTrap destructor called" << RES << std::endl;
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
