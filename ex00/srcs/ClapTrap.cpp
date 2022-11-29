/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:19:28 by sle-huec          #+#    #+#             */
/*   Updated: 2022/11/29 18:19:33 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

ClapTrap::ClapTrap(void) : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << BWHT << "ClapTrap default constructor called." << RES << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << BWHT << this->_name << "ClapTrap name in param constructor called." << RES << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	std::cout << BWHT << "ClapTrap copy constructor called." << RES << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BWHT << "ClapTrap destructor called" << RES << std::endl;
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

unsigned int ClapTrap::get_attack_damage(void) const
{
	return this->_attack_damage;
}

unsigned int ClapTrap::set_attack_damage(unsigned int damage_points)
{
	return this->_attack_damage = damage_points;
}

std::string ClapTrap::get_name(void) const
{
	return this->_name;
}

void ClapTrap::attack(const std::string &target)
{
	if (!check_energy_points() || !check_hit_points())
		return;
	this->_energy_points -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
			  << this->_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!check_energy_points() || !check_hit_points())
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
		std::cout << BRED << this->_name << " ClapTrap has no more energy points." << RES << std::endl;
		return 0;
	}
}

int ClapTrap::check_hit_points(void)
{
	if (this->_hit_points > 0)
		return 1;
	else
	{
		std::cout << BRED << this->_name << " ClapTrap has no more hit points." << RES << std::endl;
		return 0;
	}
}


