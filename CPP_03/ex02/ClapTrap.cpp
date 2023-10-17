/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:34:54 by acouture          #+#    #+#             */
/*   Updated: 2023/10/16 15:25:58 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ------------------------------------------------------ */
/* -------------------- CONSTRUCTORS -------------------- */
/* ------------------------------------------------------ */
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
};
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
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
	std::cout << "Overload operator=  called." << std::endl;
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

/* ------------------------------------------------------ */
/* -------------------- MEMBER FUNCTIONS --------------- */
/* ------------------------------------------------------ */
void ClapTrap::attack(std::string const &target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		std::cout << this->name << " attacks " << target
				  << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points -= 1;
	}
	else
	{
		std::cout << this->name << " has no energy points left or is out of life" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
		this->hit_points = std::max(0, this->hit_points - static_cast<int>(amount));
		std::cout << this->name << " takes " << amount
				  << " points of damage! Now has " << this->hit_points << " hit points left." << std::endl;
	}
	else
	{
		std::cout << this->name << " is already out of life" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->hit_points += amount;
		this->energy_points -= 1;
		std::cout << this->name << " is repaired for " << amount
				  << " points! Now has " << this->hit_points << " hit points." << std::endl;
	}
	else
	{
		std::cout << this->name << " has no energy points left or is out of life" << std::endl;
	}
}

void ClapTrap::display(void)
{
	std::cout << this->name << " has "
			  << this->hit_points << " hit points, and " << this->energy_points
			  << " energy points!" << std::endl;
}

std::string ClapTrap::getName() const
{
	return name;
}

void ClapTrap::setName(const std::string& newName)
{
	if (!newName.empty())
	{
		this->name = newName;
	}
	else
	{
		std::cout << "Name cannot be an empty string." << std::endl;
	}
}

int ClapTrap::getAttackDamage() const
{
	return attack_damage;
}

int ClapTrap::getHitPoints() const
{
	return hit_points;
}
