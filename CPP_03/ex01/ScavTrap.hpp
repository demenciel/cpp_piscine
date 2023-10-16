/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:42:21 by acouture          #+#    #+#             */
/*   Updated: 2023/10/16 15:33:31 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &copy);
    ~ScavTrap();
	ScavTrap &operator=(ScavTrap const &rhs);

    void attack(std::string const &target);
    void guardGate();
};
int applyDamageClapVSScav(ClapTrap &attacker, ScavTrap &target);
int applyDamageScavVSClap(ScavTrap &attacker, ClapTrap &target);

#endif
