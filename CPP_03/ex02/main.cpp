/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:13 by acouture          #+#    #+#             */
/*   Updated: 2023/10/17 15:47:13 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void applyDamage(ClapTrap &attacker, ClapTrap &target)
{
    std::string targetName = target.getName();
    attacker.attack(targetName);
    target.takeDamage(attacker.getAttackDamage());
    if (target.getHitPoints() <= 0)
        std::cout << target.getName() << " is now dead" << std::endl;
}

int applyDamageScavVSClap(ScavTrap &attacker, ClapTrap &target)
{
    std::string targetName = target.getName();
    attacker.attack(targetName);
    target.takeDamage(attacker.getAttackDamage());
    if (target.getHitPoints() <= 0)
    {
        std::cout << target.getName() << " is now dead" << std::endl;
        return -1;
    }
    return 0;
}
int applyDamageClapVSScav(ClapTrap &attacker, ScavTrap &target)
{
    std::string targetName = target.getName();
    attacker.attack(targetName);
    target.takeDamage(attacker.getAttackDamage());
    if (target.getHitPoints() <= 0)
    {
        std::cout << target.getName() << " is now dead" << std::endl;
        return -1;
    }
    return 0;
}
int applyDamageFragVSScav(FragTrap &attacker, ScavTrap &target)
{
    std::string targetName = target.getName();
    attacker.attack(targetName);
    target.takeDamage(attacker.getAttackDamage());
    if (target.getHitPoints() <= 0)
    {
        std::cout << target.getName() << " is now dead" << std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    ClapTrap clap1("Clap1");
    FragTrap frag1;
    ScavTrap scav1("Scav1");

    scav1.guardGate();
    frag1.setName("Frag1");
    scav1.setName("Scav1");
    applyDamageScavVSClap(scav1, clap1);
    clap1.attack("Frag1");
    frag1.highFivesGuys();
    return 0;
}
