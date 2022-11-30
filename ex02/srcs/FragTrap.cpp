#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << BGRN << " FragTrap default constructor called." << RES << std::endl;
	this->_name = "";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BGRN << this->_name << " FragTrap name in param constructor called." << RES << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	return;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap()
{
	std::cout << BGRN << " FragTrap copy constructor called." << RES << std::endl;
	*this = cpy;
}

FragTrap::~FragTrap(void)
{
	std::cout << BGRN << this->_name << " FragTrap destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
	this->_name = rhs._name;
	return (*this);
}

// members functions===========================================================
//=============================================================================

int FragTrap::check_energy_points(void)
{
	if (this->_energy_points > 0)
		return 1;
	else
	{
		std::cout << BRED << this->_name << " FragTrap has no more energy points." << RES << std::endl;
		return 0;
	}
}

int FragTrap::check_hit_points(void)
{
	if (this->_hit_points > 0)
		return 1;
	else
	{
		std::cout << BRED << this->_name << " FragTrap has no more hit points." << RES << std::endl;
		return 0;
	}
}

void FragTrap::attack(const std::string &target)
{
	if (!check_energy_points() || !check_hit_points())
		return;
	this->_energy_points -= 1;
	std::cout << BGRN << "FragTrap " << this->_name << " attacks " << target << ", causing "
			  << this->_attack_damage << " points of damage!" << RES << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	if (!check_energy_points() || !check_hit_points())
		return;
	std::cout << BGRN << "FragTrap " << this->_name << " Yeaaah! Asking for a high five!" << RES << std::endl;
}

