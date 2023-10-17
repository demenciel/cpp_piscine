/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:03 by acouture          #+#    #+#             */
/*   Updated: 2023/10/16 15:28:15 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &copy);
	~ClapTrap(void);
	ClapTrap &operator=(ClapTrap const &rhs);
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void display(void);
	std::string getName() const;
    void setName(const std::string& newName);
	int getAttackDamage() const;
	int getHitPoints() const;
};

void applyDamage(ClapTrap &attacker, ClapTrap &target);
#endif