/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:13 by acouture          #+#    #+#             */
/*   Updated: 2023/10/13 16:23:28 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void applyDamage(ClapTrap &attacker, ClapTrap &target)
{
    std::string targetName = target.getName();
    attacker.attack(targetName);
    target.takeDamage(attacker.getAttackDamage());
}

int main()
{
    ClapTrap theClapitain;
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");

    theClapitain = clap1;
    theClapitain.setName("Ragnar");
    theClapitain.display();
    clap1.display();
    applyDamage(theClapitain, clap2);
    clap2.beRepaired(10);
    theClapitain.display();
    clap2.display();

    return 0;
}
