/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:52 by sam               #+#    #+#             */
/*   Updated: 2022/11/28 21:20:53 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

ClapTrap::ClapTrap(void) : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << BWHT << "Default constructor called." << RES << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << BWHT << this->_name << " Name in param constructor called." << RES << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	std::cout << BWHT << "Copy constructor called." << RES << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BWHT << "Destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
	this->_name = rhs._name;
	return (*this);
}

// members functions===========================================================
//=============================================================================

unsigned int ClapTrap::get_hit_points(void) const
{
	return this->_hit_points;
}

// unsigned int ClapTrap::set_hit_points(unsigned int)
// {

// }

unsigned int ClapTrap::get_energy_points(void) const
{
	return this->_energy_points;
}

// unsigned int ClapTrap::set_energy_points(unsigned int)
// {

// }

unsigned int ClapTrap::get_attack_damage(void) const
{
	return this->_attack_damage;
}

// unsigned int ClapTrap::set_attack_damage(unsigned int )
// {

// }

std::string ClapTrap::get_name(void) const
{
	return this->_name;
}

void ClapTrap::attack(const std::string &target)
{
	if (!check_energy_points())
		return;
	this->_energy_points -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
			  << this->_attack_damage << " points of damage!" << std::endl;
}

// il perd <amount > sur <hit points> (ses points de vie)
void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages." << std::endl;
}

// il regagne <amount> (nombre de points de soin)
void ClapTrap::beRepaired(unsigned int amount)
{
	if (!check_energy_points())
		return;
	this->_energy_points -= 1;
	this->_hit_points += amount;
	std::cout << "ClapTrap " << this->_name << " gains " << amount << " hits points." << std::endl;
}

int ClapTrap::check_energy_points(void)
{
	if (this->_energy_points > 0)
		return 1;
	else
	{
		std::cout << BRED << this->_name << " has no more energy points." << RES << std::endl;
		return 0;
	}
}
