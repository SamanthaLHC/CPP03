/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:52 by sam               #+#    #+#             */
/*   Updated: 2022/11/25 18:34:36 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

//constructs ans destruct======================================================
//=============================================================================

ClapTrap::ClapTrap(void) : _name(""), _hit_points(10), _energy_points(10), _attack_dammage(0)
{
	std::cout << BWHT << "Default constructor called." << RES << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_dammage(0)
{
	std::cout << BWHT << " Name in param constructor called." << RES << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const& cpy)
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

ClapTrap& ClapTrap::operator=( ClapTrap const& rhs)
{
	this->_attack_dammage = rhs._attack_dammage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
	this->_name = rhs._name;
	return (*this);
}

// members functions===========================================================
//=============================================================================

//		get / set ?? (on a besoin d'un getter que si on a besoin d'y acceder
// depuis l'extérieur de la classe (dans le main pou un autre objet qui n'est pas
// de  la mm classe) )

// int _hit_points

// int _energy_points

// int _attack_dammage

void ClapTrap::attack(const std::string &target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}