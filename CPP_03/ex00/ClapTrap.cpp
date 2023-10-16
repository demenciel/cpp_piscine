/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:34:54 by acouture          #+#    #+#             */
/*   Updated: 2023/10/13 15:51:14 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ------------------------------------------------------ */
/* -------------------- CONSTRUCTORS -------------------- */
/* ------------------------------------------------------ */
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
};
ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
};
/* ------------------------------------------------------ */
/* -------------------- DESTRUCTORS --------------------- */
/* ------------------------------------------------------ */
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
};

/* ------------------------------------------------------ */
/* -------------------- OPERATOR OVERLOAD --------------- */
/* ------------------------------------------------------ */
ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this == &rhs)
		return *this;
	std::string tempName = rhs.name;
	int tempHitPoints = rhs.hit_points;
	int tempEnergyPoints = rhs.energy_points;
	int tempAttackDamage = rhs.attack_damage;

	this->name = tempName;
	this->hit_points = tempHitPoints;
	this->energy_points = tempEnergyPoints;
	this->attack_damage = tempAttackDamage;
	return *this;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		takeDamage(this->attack_damage);
		this->energy_points -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << "has no energy points left" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " has " << this->hit_points << " hit points left." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points of damage!" << std::endl;
		this->hit_points += amount;
		this->energy_points -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << "has no energy points left" << std::endl;
	}
}