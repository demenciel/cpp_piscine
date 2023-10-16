/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:13 by acouture          #+#    #+#             */
/*   Updated: 2023/10/16 15:34:58 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

int main()
{
    ClapTrap clap1;
    ClapTrap clap2("YOLO");
    ScavTrap scav1("Scav1");

    scav1.display();
    clap2.display();
    int res = applyDamageScavVSClap(scav1, clap2);
    if (res == -1)
        scav1.~ScavTrap();
    scav1.guardGate();
    clap1.setName("Revenger");
    applyDamageClapVSScav(clap1, scav1);

    return 0;
}
